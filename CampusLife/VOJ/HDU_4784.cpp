/****
    action归类很重要，本题，移动和转移空间算一类
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

struct Edge
{
    int u,v,t,m;
    Edge() {}
    Edge(int uu,int vv,int tt,int mm):u(uu),v(vv),t(tt),m(mm) {}
};
struct State
{
    int N,B,K,T;
    State() {}
    State(int n,int b,int k,int t)
    {
        N=n;
        B=b;
        K=k;
        T=t;
    }
};

bool operator<(State a,State b)
{
    return a.T>b.T;
}

int N,M,B,K,R,T;
vector<Edge>G[111];
int  p[111][6];
int dp[111][5][6][222];
int vis[111][5][6][222];
/*at bag K Time*/
priority_queue<State>q;

void init()
{
    for(int i=0; i<=N; i++) G[i].clear();
    memset(p,0,sizeof(p));
    memset(dp,-1,sizeof(dp));
    memset(vis,0,sizeof(vis));
}

void deal()
{
    dp[1][0][0][0]=R;
    vis[1][0][0][0]=1;

    while(!q.empty()) q.pop();
    q.push(State(1,0,0,0));

    while(!q.empty())
    {
        State now=q.top();
        q.pop();
        if(now.N==N) continue;
        for(int i=0; i<(int)G[now.N].size(); i++) //移动
        {
            Edge &e=G[now.N][i];
            int tempM=dp[now.N][now.B][now.K][now.T]-e.m;
            int tempT=e.t+now.T;

            if(tempM<0 || tempT>T) continue;
            if(e.v==N && now.K!=0) continue;

            if(e.v!=1 && e.v!=N) //buy or sale
            {
                if(now.B+1<=B)
                    if(tempM-p[e.v][now.K]>=0 && tempM-p[e.v][now.K]>dp[e.v][now.B+1][now.K][tempT])
                    {
                        dp[e.v][now.B+1][now.K][tempT]=tempM-p[e.v][now.K];
                        if(!vis[e.v][now.B+1][now.K][tempT])
                            q.push(State(e.v,now.B+1,now.K,tempT)),vis[e.v][now.B+1][now.K][tempT]=1;
                    }
                if(now.B-1>=0)
                    if(tempM+p[e.v][now.K]>=0 && tempM+p[e.v][now.K]>dp[e.v][now.B-1][now.K][tempT])
                    {
                        dp[e.v][now.B-1][now.K][tempT]=tempM+p[e.v][now.K];
                        if(!vis[e.v][now.B-1][now.K][tempT])
                            q.push(State(e.v,now.B-1,now.K,tempT)),vis[e.v][now.B-1][now.K][tempT]=1;
                    }
            }
            if(tempM>dp[e.v][now.B][now.K][tempT]) //nothing
            {
                dp[e.v][now.B][now.K][tempT]=tempM;
                if(!vis[e.v][now.B][now.K][tempT])
                    q.push(State(e.v,now.B,now.K,tempT)),vis[e.v][now.B][now.K][tempT]=1;
            }
        }

        if(now.N!=1 && now.N!=N)
        {
            int tempT=now.T+1;
            int tempM=dp[now.N][now.B][now.K][now.T];
            int k=(now.K+1)%K;
            if(tempT>T) continue;

            if(now.B+1<=B)
                if(tempM-p[now.N][k]>=0 && tempM-p[now.N][k]>dp[now.N][now.B+1][k][tempT])
                {
                    dp[now.N][now.B+1][k][tempT]=tempM-p[now.N][k];
                    if(!vis[now.N][now.B+1][k][tempT])
                        q.push(State(now.N,now.B+1,k,tempT)),vis[now.N][now.B+1][k][tempT]=1;
                }
            if(now.B-1>=0)
                if(tempM+p[now.N][k]>=0 && tempM+p[now.N][k]>dp[now.N][now.B-1][k][tempT])
                {
                    dp[now.N][now.B-1][k][tempT]=tempM+p[now.N][k];
                    if(!vis[now.N][now.B-1][k][tempT])
                        q.push(State(now.N,now.B-1,k,tempT)),vis[now.N][now.B-1][k][tempT]=1;
                }
            if(tempM>dp[now.N][now.B][k][tempT])
            {
                dp[now.N][now.B][k][tempT]=tempM;
                if(!vis[now.N][now.B][k][tempT])
                    q.push(State(now.N,now.B,k,tempT)),vis[now.N][now.B][k][tempT]=1;
            }
        }
    }

    int ans=-1;
    for(int i=0; i<=B; i++)
        for(int j=0; j<=T; j++)
            if(dp[N][i][0][j]>=0)
                ans=max(dp[N][i][0][j],ans);
    if(ans>=0)
        printf("%d\n",ans);
    else
        puts("Forever Alone");
}

int main()
{
    freopen("r.txt","r",stdin);
    int Cas;
    cin>>Cas;
    for(int t=1; t<=Cas; t++)
    {
        init();
        cin>>N>>M>>B>>K>>R>>T;

        for(int i=0; i<K; i++)
            for(int j=1; j<=N; j++)
                cin>>p[j][i];

        for(int i=0; i<M; i++)
        {
            int u,v,t,m;
            cin>>u>>v>>t>>m;
            G[u].push_back(Edge(u,v,t,m));
        }
        printf("Case #%d: ",t);
        deal();
    }
    return 0;
}
