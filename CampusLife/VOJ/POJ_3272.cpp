/****
	组合，反向图，拓扑序
****/
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;
const int maxn = 5555;
vector<int>G[maxn],rG[maxn];
int sum[maxn],rsum[maxn];
int N,M,deg[maxn],ans;

int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		rG[y].push_back(x);
		deg[y]++;
	}
	for(int i=1;i<=N;i++) if(!deg[i])
		sum[i]=1;
	for(int u=1;u<=N;u++)//u->v
		for(int i=0;i<(int)G[u].size();i++){
			int v=G[u][i];
			sum[v]+=sum[u];
		}
	rsum[N]=1;
	for(int v=N;v>=1;v--)//u->v
		for(int i=0;i<(int)rG[v].size();i++){
			int u=rG[v][i];
			rsum[u]+=rsum[v];
			ans=max(ans,rsum[v]*sum[u]);
		}
	printf("%d\n",ans);
	return 0;
}