/*****
检修某一路段导致公路网不畅通的原因必然是该段公路在图中是桥（割边），
因此完全畅通的方法就是，加最若干条边，使图中不存在桥。先找出图中所有的双连通分量，
将双连通分量进行缩点，得到一个树形图，求出这个树形图中度为1的点的个数，
新加边的条数即是（度为1的点数目+1）/2，考虑到题目只要求求度为1的点数目，
因此可以部分缩点，利用并查集，保存每个割边的顶点，
统计每个顶点在并查集中的代表元的度数即可
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
		if(vis[u][v]||vis[v][u]) continue;
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
