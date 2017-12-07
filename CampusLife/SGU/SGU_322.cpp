/****
    set 求交+添加+删除
    给定两棵树，每次能够连接一棵树的一条边，并且删除当钱形成环的其中一条边，问经过最少多少次能够使得两棵树的边是一样的。
    每次在第二棵中增加一条第一棵树没有的边这样就成为一个环，在环里找到一个没有在第一棵树中的边删掉。
****/
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int,int> PII;
typedef long long ll;

const int maxn = 2222;

set<int>Edge[maxn];
int N,s[maxn][maxn],pre[maxn],dep[maxn];

void init()
{
    scanf("%d",&N);
    for(int i=1;i<N;i++){
        int u,v; scanf("%d%d",&u,&v);
        Edge[u].insert(v);
        Edge[v].insert(u);
        s[u][v]++,s[v][u]++;
    }
    for(int i=1;i<N;i++){
        int u,v; scanf("%d%d",&u,&v);
        s[u][v]--,s[v][u]--;
    }
    int ans=0;
    for(int i=1;i<=N;i++)
        for(int j=1;j<i;j++)
            ans+=(s[i][j]>0);//选择在第一棵树添加第二棵树有的边
    printf("%d\n",ans);
}

void dfs(int u,int f)
{
    pre[u]=f;
    dep[u]=dep[f]+1;
    for(set<int>::iterator i=Edge[u].begin();i!=Edge[u].end();++i)
        if(*i!=f) dfs(*i,u);
}

void deal()
{
    for(int i=1;i<=N;i++) for(int j=1;j<i;j++){
            if(s[i][j]<0){ dfs(1,0);//i->j需要添加，更新深度
                bool flag=0;
                for(int x=i,y=j;!flag;){
                    if(dep[x]<dep[y]) swap(x,y);//由深度高的向上走，依次删除第二棵树没有的边
                    if(s[x][pre[x]]>0){//第二棵树没有的边
                        flag=1;//找到之后，添加，添加之后树的结构改变，需要重新再从下到上进行删除
                        Edge[x].erase(pre[x]);
                        Edge[pre[x]].erase(x);
                        s[x][pre[x]]--,s[pre[x]][x]--;
                        printf("1 %d %d %d %d\n",i,j,x,pre[x]);
                    } else
                    x=pre[x];//向上
                }
                Edge[i].insert(j);//添加i->j
                Edge[j].insert(i);
                s[i][j] ++;
                s[j][i] ++;
            }
        }
}

int main()
{
    //freopen("r.txt","r",stdin);
    init();
    deal();
    return 0;
}
