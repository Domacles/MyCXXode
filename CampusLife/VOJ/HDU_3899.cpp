/****
给定n个点
每个点的人数
n-1条边和边权。
选取任意一点u，然后让所有人都移动到u点
问最小的移动距离和是多少

后一个用BFS，否则爆栈
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

struct Edge{
    int v,l;
    Edge(){}
    Edge(int vv,int ll):v(vv),l(ll){}
};
vector<Edge> G[maxn];
int N,t[maxn];
int s[maxn],vis[maxn];
ll dp[maxn],minc[maxn];

void dfs(int u,int f)
{
    dp[u]=0, s[u]=t[u];
    for(int i=0;i<(int)G[u].size();i++){
        Edge &e=G[u][i];
        if(e.v==f) continue;
        dfs(e.v,u);
        s[u]+=s[e.v], dp[u]+=dp[e.v]+(ll)s[e.v]*e.l;
    }
}

void BFS(int u)
{
    queue<int> q;
    q.push(u),vis[u]=1;
    minc[1]=dp[1];
    while(!q.empty()){
        u=q.front(); q.pop();
            //minc[u]=minc[f]+(s[1]-s[u])*(ll)c-s[u]*c;
        for(int i=0;i<(int)G[u].size();i++){
            int v=G[u][i].v;
            ll c=G[u][i].l;
            if(vis[v]) continue;
            minc[v]=minc[u]+(s[1]-s[v])*c-s[v]*c;
            vis[v]=1, q.push(v);
        }
    }
}

int main()
{
    //freopen("r.txt","r",stdin);
    while(~scanf("%d",&N)){
        for(int i=0;i<=N;i++) G[i].clear();
        for(int i=1;i<=N;i++) scanf("%d",&t[i]);
        for(int i=1;i<N;i++){
            int u,v,l; scanf("%d%d%d",&u,&v,&l);
            G[u].push_back(Edge(v,l));
            G[v].push_back(Edge(u,l));
        }
        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));
        memset(minc,0,sizeof(minc));
        dfs(1,0);
        BFS(1);
        ll ans=minc[1];
        for(int i=1;i<=N;i++)
            ans=min(ans,minc[i]);
        printf("%I64d\n",ans);
    }
    return 0;
}
