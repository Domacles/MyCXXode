/*****
	同POJ3352 ，求添加多少条边后成为边双联通块
*****/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 5001;
vector< vector<int> > adj;
int vis[MAXN][MAXN];
int cnt,low[MAXN],pre[MAXN],visit[MAXN],degree[MAXN];

void dfs(int u,int v){
    visit[u]=1;
    pre[u]=cnt++,//所属边连通块
	low[u]=pre[u];
    int i,len=adj[u].size();
    for(i=0;i<len;i++){
        if(adj[u][i]==v) continue;
        if(!visit[adj[u][i]]) 
			dfs(adj[u][i],u);
        if(low[adj[u][i]]<low[u]) 
			low[u]=low[adj[u][i]];
    }
    visit[u]=2;
}
int main(){
    int i,j,u,v,n,m,len,ans;
    scanf("%d %d",&n,&m);
    adj.assign(n+1,vector<int>());
    while(m--){
        scanf("%d %d",&u,&v);
		if(vis[u][v]||vis[v][u]) continue;//小心有重复输入
        adj[u].push_back(v),adj[v].push_back(u);
		vis[u][v]=vis[v][u]=1;
    }
    memset(visit,0,sizeof(visit));
    cnt=0,dfs(1,1);
    memset(degree,0,sizeof(degree));
    for(i=1;i<=n;i++){
        len=adj[i].size();
        for(j=0;j<len;j++)
            if(low[i]!=low[adj[i][j]])
                degree[low[i]]++;
    }
    for(ans=i=0;i<=n;i++)
        if(degree[i]==1) ans++;
    printf("%d\n",(ans+1)/2);
    return 0;
}
