/****
!!!!!!!!!!!题目设计的思路巧妙!!!!!!!!!!!!!

只要白边优先和黑边优先两种顺序做两次最小生成树。

得到白边数量的区间，然后枚举斐波那契数列就可以了。

注意如果一开始是非连通的，输出NO
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

const int maxn =1e6;

int N,M,f[maxn],fa[maxn];
struct Edge{
    int u,v,c;
    Edge(){}
    Edge(int uu,int vv,int cc){u=uu;v=vv;c=cc;}
};
vector<Edge> G;

int Find(int x)
{
    if(fa[x] == -1) return x;
    return fa[x] = Find(fa[x]);
}

bool cmp1(Edge a,Edge b){return a.c<b.c;}
bool cmp2(Edge a,Edge b){return a.c>b.c;}

void init()
{
    memset(f,0,sizeof(f));
    f[0]=f[1]=1,f[2]=2;
    for(int i=3;f[i-1]<=1e5+111;i++)
        f[i]=f[i-1]+f[i-2];
}

void init1()
{
    memset(fa,-1,sizeof(fa));
}

int main()
{
    //freopen("r.txt","r",stdin);
    int T; scanf("%d",&T);
    init();
    for(int t=1;t<=T;t++){
        G.clear();
        scanf("%d%d",&N,&M);
        for(int i=0;i<M;i++){
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            G.push_back(Edge(u,v,c));
        }
        int low=0,high=0;
        init1();
        sort(G.begin(),G.end(),cmp1);
        for(int i=0;i<M;i++){
            int u=G[i].u,v=G[i].v;
            int a=Find(u),b=Find(v);
            if(a==b) continue;
            fa[a]=b;
            low+=G[i].c;
        }

        init1();
        sort(G.begin(),G.end(),cmp2);
        for(int i=0;i<M;i++){
            int u=G[i].u,v=G[i].v;
            int a=Find(u),b=Find(v);
            if(a==b) continue;
            fa[a]=b;
            high+=G[i].c;
        }

        int flag=1;
        for(int i=1;i<=N;i++)
        if(Find(i)!=Find(1)){
            flag=0;break;
        }
        if(!flag){
                printf("Case #%d: No\n",t);continue;
        }
        flag=0;
        for(int i=1;f[i]!=0;i++)
        if(f[i]>=low && f[i]<=high){
            flag=1;break;
        }
        if(flag) printf("Case #%d: Yes\n",t);
        else printf("Case #%d: No\n",t);
    }
    return 0;
}
