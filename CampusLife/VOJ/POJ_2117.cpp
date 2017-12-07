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

vector<int>G[maxn];
int cnt[maxn],N,M;
int dfn[maxn],low[maxn],is[maxn],index,rt;

void init()
{
    index=0;
    memset(is,0,sizeof(is));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<=N;i++) G[i].clear();
}

void DFS(int u,int f)//root is 1 , low
{
    dfn[u]=low[u]=++index;
    int s=0;
    for(int i=0;i<(int)G[u].size();i++){
        int v=G[u][i];
        if(!dfn[v]){
            DFS(v,u); s++;

            low[u]=min(low[u],low[v]);//update low

            if(u==rt && s>=2) is[u]=1, cnt[u]++;//count
            if(u!=rt && low[v]>=dfn[u])//count
                is[u]=1, cnt[u]++;
        }else if(v!=f)
            low[u]=min(dfn[v],low[u]);//update low
    }
}


int main()
{
    freopen("r.txt","r",stdin);
    while(~scanf("%d%d",&N,&M)){
        init();
        if(N==0&&M==0) break;
        if(M==0){
            printf("%d\n",N-1);
            continue;
        }
        for(int i=0;i<M;i++){
            int u,v; scanf("%d%d",&u,&v);
            u++,v++;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int ans=0,t=0;
        for(int i=1;i<=N;i++)
            if(!dfn[i])
                t++, rt=i, DFS(i,0);
        for(int i=1;i<=N;i++)
            ans=max(t+cnt[i],ans);
        printf("%d\n",ans);
    }
    return 0;
}
