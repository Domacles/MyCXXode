/****
	在dfs中进行初始化
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
vector<int>G[1111];
int N,M;
int dp[1111][3],f[1111][3];

void init()
{
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<1111;i++) G[i].clear();
}

void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}

void DFS(int u,int fa,int c)
{
    if(dp[u][c]!=-1) return;
    dp[u][c]=c; f[u][c]=0;//!!!
    for(int i=0;i<(int)G[u].size();i++){
        int v=G[u][i];
        if(v==fa) continue;
        if(!c){
            DFS(v,u,1);
            dp[u][c]+=dp[v][1];
            f[u][c]+=f[v][1];
        }else{
            DFS(v,u,1);
            DFS(v,u,0);
            if(dp[v][0]<dp[v][1] || (dp[v][0]==dp[v][1] && f[v][0]>f[v][1]+1))
                dp[u][c]+=dp[v][0], f[u][c]+=f[v][0];
            else
                dp[u][c]+=dp[v][1], f[u][c]+=f[v][1]+1;
        }
    }
}

int main()
{
    freopen("r.txt","r",stdin);
    int T; scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d%d",&N,&M);
        init();
        for(int i=0;i<M;i++){
            int u,v; scanf("%d%d",&u,&v);
            add_edge(u,v);
        }
        int ans1=0,ans2=0;
        for(int i=0;i<N;i++)
            if(dp[i][0]==-1 && dp[i][1]==-1){
                DFS(i,-1,0);
                DFS(i,-1,1);
                if(dp[i][0]<dp[i][1] || (dp[i][0]==dp[i][1] && f[i][0]>f[i][1]))
                    ans1+=dp[i][0], ans2+=f[i][0];
                else
                    ans1+=dp[i][1], ans2+=f[i][1];
            }

        printf("Case %d: %d %d %d\n",t,ans1,ans2,M-ans2);
    }
    return 0;
}
