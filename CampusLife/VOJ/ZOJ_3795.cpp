/*****
    缩点求最大数目的链
*****/
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

#define ms(x) memset(x,0,sizeof(x))
#define foreach(v,x) for(vector<int>::iterator v=x.begin();v!=x.end();++v)

const int maxn =2e5;

vector<int> G[maxn],SCC[maxn];
int dfn[maxn],low[maxn],Index;
int Stack[maxn],InStack[maxn],top;
int scc,Belong[maxn];

vector<int>nG[maxn];
int d[maxn];
int N,M;

void init()
{
    for(int i=0;i<=N;i++)
        G[i].clear(),SCC[i].clear(),nG[i].clear();
    ms(dfn); ms(low); ms(Stack); ms(InStack); ms(d);
    scc=top=Index=0;
}

void DFS(int u,int v)
{
    dfn[u]=low[u]=++Index;
    Stack[top++]=u, InStack[u]=1;
    foreach(now,G[u]){
        int v=*now;
        if(!dfn[v]){
            DFS(v,u);
            low[u]=min(low[u],low[v]);
        }else if(InStack[v])
            low[u]=min(low[u],dfn[v]);
    }
    int j;
    if(dfn[u]==low[u]){
        scc++;
        while((j=Stack[--top])){
            InStack[j]=0;
            Belong[j]=scc;
            SCC[scc].push_back(j);
            if(j==u) break;
        }
    }
}

int  dis[maxn];
int BFS(){//拓扑排序
    queue<int>q;
    for(int i=1;i<=scc;i++)
        if(d[i]==0) {q.push(i);dis[i]=SCC[i].size();}
        else dis[i]=0;
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int i=0;i<(int)nG[u].size();i++){
            int v=nG[u][i];
            dis[v]=max(dis[u]+(int)SCC[v].size(),dis[v]);
            d[v]--;
            if(d[v]==0) q.push(v);
        }
    }
    int ans=1;
    for(int i=1;i<=scc;i++) ans=max(ans,dis[i]);
    return ans;
}

int Node;
class myClass{
public:
    void operator() (int x){
            int u=Node, v=Belong[x];
            if(u==v) return;
            nG[u].push_back(v);
            d[v]++;
    }
};

void Build()
{
    for(int i=1;i<=N;i++){
        Node=Belong[i];
        for_each(G[i].begin(),G[i].end(),myClass());
    }
}

int main()
{
    //freopen("r.txt","r",stdin);
    while(~scanf("%d%d",&N,&M)){
        init();
        for(int i=1;i<=M;i++){
            int u,v; scanf("%d%d",&u,&v);
            G[u].push_back(v);
        }

        for(int i=1;i<=N;i++)
            if(!dfn[i]) DFS(i,0);
        Build();
        int ans=BFS();
        printf("%d\n",ans);
    }
    return 0;
}
