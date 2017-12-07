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
#define maxn 1111
typedef pair<int,int> PII;
vector<int>G[maxn];
int pre[maxn],vis[maxn],dis[maxn];
int N,K;

void dfs(int x){
	if(pre[x]) dfs(pre[x]);
	printf("%d\n",x);
}

int SPFA()
{
	for(int i=2;i<=K;i++) dis[i]=0x3fffffff;
	queue<int>q;
	q.push(1); vis[1]=1;
	while(!q.empty()){
		int u=q.front(); q.pop();
		vis[u]=0;
		for(int i=0;i<(int)G[u].size();i++){
			int v=G[u][i];
			if(dis[v]>dis[u]+1){
				pre[v]=u;
				dis[v]=dis[u]+1;
				if(!vis[v]) vis[v]=1,q.push(v);
			}
		}
	}
	return dis[K]+1;
}

int main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
	}
	int ans=SPFA();
	if(ans>=0x3fffffff) 
		puts("-1");
	else {
		printf("%d\n",ans);
		dfs(K);
	}
	return 0;
}