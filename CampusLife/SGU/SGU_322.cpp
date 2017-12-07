/****
    set ��+���+ɾ��
    ������������ÿ���ܹ�����һ������һ���ߣ�����ɾ����Ǯ�γɻ�������һ���ߣ��ʾ������ٶ��ٴ��ܹ�ʹ���������ı���һ���ġ�
    ÿ���ڵڶ���������һ����һ����û�еı������ͳ�Ϊһ�������ڻ����ҵ�һ��û���ڵ�һ�����еı�ɾ����
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
            ans+=(s[i][j]>0);//ѡ���ڵ�һ������ӵڶ������еı�
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
            if(s[i][j]<0){ dfs(1,0);//i->j��Ҫ��ӣ��������
                bool flag=0;
                for(int x=i,y=j;!flag;){
                    if(dep[x]<dep[y]) swap(x,y);//����ȸߵ������ߣ�����ɾ���ڶ�����û�еı�
                    if(s[x][pre[x]]>0){//�ڶ�����û�еı�
                        flag=1;//�ҵ�֮����ӣ����֮�����Ľṹ�ı䣬��Ҫ�����ٴ��µ��Ͻ���ɾ��
                        Edge[x].erase(pre[x]);
                        Edge[pre[x]].erase(x);
                        s[x][pre[x]]--,s[pre[x]][x]--;
                        printf("1 %d %d %d %d\n",i,j,x,pre[x]);
                    } else
                    x=pre[x];//����
                }
                Edge[i].insert(j);//���i->j
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
