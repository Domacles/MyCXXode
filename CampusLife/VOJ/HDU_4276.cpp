/***
	首先，dfs一次，将1~N的路径的值T求出，并将路径耗时置为0；
	M-=T;
	DFS(1,0) 背包解决，距离一律按乘2算。
***/
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

struct Edge{
    int u,v,c;
    Edge(){}
    Edge(int uu,int vv,int cc):u(uu),v(vv),c(cc){}
};
vector<Edge>G[111];
int N, M, a[111], dp[111][555];
int T;

void init()
{
    for(int i=0;i<=N;i++) G[i].clear();
    memset(dp,0,sizeof(dp));
}

void add_edge(int u,int v,int c)
{
    G[u].push_back(Edge(u,v,c));
    G[v].push_back(Edge(v,u,c));
}

bool dfs(int u,int f)
{
    if(u==N) return 1;
    for(int i=0;i<(int)G[u].size();i++){
        Edge &e=G[u][i];
        if(e.v==f) continue;
        if(dfs(e.v,u)){
            T+=e.c, e.c=0;
            return 1;
        }
    }
    return 0;
}

int DFS(int u,int f)
{
    for(int i=0;i<(int)G[u].size();i++){
        Edge &e=G[u][i];
        if(e.v==f) continue;
        DFS(e.v,u);
        int d=e.c*2;
        for(int t=M;t>=d;t--)
            for(int j=0;j+d<=t;j++)
                dp[u][t]=max(dp[u][t],dp[u][t-j-d]+dp[e.v][j]);
    }
    for(int t=M;t>=0;t--) dp[u][t]+=a[u];
    return 0;
}

void Print()
{
    for(int i=1;i<=N;i++)
    for(int j=0;j<(int)G[i].size();j++){
            Edge e=G[i][j];
            printf("%d %d %d\n", e.u, e.v, e.c);
    }
}

int main()
{
    //freopen("r.txt","r",stdin);
    while(~scanf("%d%d",&N,&M)){
        init();
        for(int i=1;i<N;i++){
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            add_edge(u,v,c);
        }
        for(int i=1;i<=N;i++)
            scanf("%d",&a[i]);
        T=0;
        dfs(1,0);//Print();
        if(T>M) {
            puts("Human beings die in pursuit of wealth, and birds die in pursuit of food!");
            continue;
        }
        else {
            M-=T;
            DFS(1,0);
            printf("%d\n",dp[1][M]);
        }
    }
    return 0;
}
