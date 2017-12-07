/***
	DFS
***/
#include <cstdio>
#include <queue>
#include <vector>
#include <stack>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
#define maxn 1005
vector<int>G[maxn];
int K,N,M,Q[maxn],vis[maxn],sum[maxn];

void DFS(int u){
	vis[u]=1;
	for(int i=0;i<(int)G[u].size();i++)
		if(!vis[G[u][i]]) DFS(G[u][i]);
}

void add_edge(int u,int v){
	G[u].push_back(v);
}

void solve()
{
	for(int i=0;i<K;i++){
		memset(vis,0,sizeof(vis));
		DFS(Q[i]);
		for(int i=1;i<=N;i++)
			sum[i]+=vis[i];
	}
		int ans=0;
	for(int i=1;i<=N;i++)
		if(sum[i]==K) ans++;
	printf("%d\n",ans);
}

int main()
{
	scanf("%d%d%d",&K,&N,&M);
	for(int i=0;i<K;i++) scanf("%d",&Q[i]);
	for(int i=0;i<M;i++){
		int u,v; scanf("%d%d",&u,&v);
		add_edge(u,v);
	}
	solve();
	return 0;
}