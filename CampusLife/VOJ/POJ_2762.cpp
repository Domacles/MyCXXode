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

const int maxn = 1e6;
int Stack[maxn],InStack[maxn],top;
int Belong[maxn],dfn[maxn],low[maxn],index;
vector<int>  G[maxn];
vector<int>SCC[maxn];
int scc;

int N,M;

void init()
{
    for(int i=0;i<=N;i++)
        G[i].clear(),SCC[i].clear();
    scc=0;
    top=0;
    index=0;
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(Belong,0,sizeof(Belong));
    memset(Stack,0,sizeof(Stack));
    memset(InStack,0,sizeof(InStack));
}

void DFS(int u,int f)
{
    dfn[u]=low[u]=++index;
    Stack[top++]=u, InStack[u]=1;
    for(int i=0;i<(int)G[u].size();i++){
        int v=G[u][i];
        if(!dfn[v]){
            DFS(v,u);
            low[u]=min(low[u],low[v]);
        }else if(InStack[v])
            low[u]=min(low[u],dfn[v]);
    }
    int j;
    if(dfn[u]==low[u]){
        scc++;
        while((j=Stack[--top])){//node >=1
            InStack[j]=0;
            Belong[j]=scc;
            SCC[scc].push_back(j);
            if(j==u) break;
        }
    }
}

int g[1100][1100],d[maxn];

void solve()
{
    memset(g,0,sizeof(g));
    memset(d,0,sizeof(d));
    for(int i=1;i<=N;i++)
        if(!dfn[i]) DFS(i,0);

    for(int u=1;u<=N;u++)
        for(int j=0;j<(int)G[u].size();j++){
            int v=G[u][j];
            if(Belong[v]!=Belong[u] && !g[Belong[u]][Belong[v]])
                g[Belong[u]][Belong[v]]=1,d[Belong[v]]++;
        }
    int flag=1;
    for(int i=1;i<scc;i++){//拓扑排序
        int s=0,u;
        for(int j=1;j<=scc;j++)
            if(d[j]==0) s++,u=j;
        if(s>1) {flag=0;break;}//新图必须为1条链才能满足题意
        for(int v=1;v<=scc;v++)
            if(g[u][v]) d[v]--;
        d[u]=-1;
    }
    if(flag) puts("Yes");
    else puts("No");
}

int main()
{
    //freopen("r.txt","r",stdin);
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&M);
        init();
        for(int i=0;i<M;i++){
            int u,v; scanf("%d%d",&u,&v);
            G[u].push_back(v);
        }
        solve();
    }
    return 0;
}
