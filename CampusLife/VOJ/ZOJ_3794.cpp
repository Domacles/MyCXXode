/********
    终点最短路 + 起点BFS
********/
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

const int maxn =1111;
const ll INF=((1<<30)-1)*2;

vector<PII> G[maxn],rG[maxn];
bool fuel[maxn];
int N,M,C,Q;

int maxs[maxn],vis[maxn];
int dis[maxn];

void init()
{
    for(int i=0; i<=N; i++)
        G[i].clear(),rG[i].clear();
    memset(fuel,0,sizeof(fuel));
}

bool BFS()
{
    memset(vis,0,sizeof(vis));
    memset(maxs,-1,sizeof(maxs));
    queue<int>q;
    q.push(1), maxs[1]=C, vis[1]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=0; i<(int)G[u].size(); i++)
        {
            int v=G[u][i].first;
            int c=G[u][i].second;
            if(maxs[u]-c<0) continue;
            if(fuel[v])
            {
                if(maxs[v]<C)//!!!!!!!!!!!!!!!!!!!!!
                {
                    maxs[v]=C;
                    if(!vis[v]) q.push(v),vis[v]=1;
                }
            }
            else if(maxs[v]<maxs[u]-c)
            {
                maxs[v]=maxs[u]-c;
                if(!vis[v]) q.push(v),vis[v]=1;
            }
        }
    }
    if(maxs[N]<0) return 0;
    return 1;
}

void SPFA()
{
    memset(vis,0,sizeof(vis));
    memset(dis,32,sizeof(dis));
    queue<int>q;
    q.push(N), dis[N]=0, vis[N]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=0; i<(int)rG[u].size(); i++)
        {
            int v=rG[u][i].first;
            int c=rG[u][i].second;
            if(dis[u]+c>C) continue;
            if(fuel[v])
            {
                if(dis[v]>0)//!!!!!!!!!!!!!!!!!!!!!!!!
                {
                    dis[v]=0;
                    if(!vis[v]) q.push(v),vis[v]=1;
                }
            }
            else if(dis[v]>dis[u]+c)
            {
                dis[v]=dis[u]+c;
                if(!vis[v]) q.push(v),vis[v]=1;
            }
        }
    }
}

int main()
{
    //freopen("r.txt","r",stdin);
    while(~scanf("%d%d%d",&N,&M,&C))
    {
        init();
        for(int i=0; i<M; i++)
        {
            int u,v,l;
            scanf("%d%d%d",&u,&v,&l);
            G[u].push_back(PII(v,l));
            rG[v].push_back(PII(u,l));
        }
        scanf("%d",&Q);
        for(int i=0; i<Q; i++)
        {
            int x;
            scanf("%d",&x);
            fuel[x]=1;
        }

        bool flag=BFS();
        if(flag) SPFA();

        scanf("%d",&Q);
        int ans=0;
        for(int i=0; i<Q; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(maxs[x]<0 || dis[x]>C) continue;//!!!!!!!!!!!!!!!!!!!!
            if(fuel[x]) ans=max(ans,y*C);
            else
                ans=max(ans,y*(maxs[x]-dis[x]));
        }
        if(!flag) printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}
