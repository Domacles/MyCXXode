#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
#define maxn 11111
vector<int>G[maxn];
bool vis[maxn];
int Gx[111][111];

void add_edge(int from,int to)
{
	G[from].push_back(to);
	G[to].push_back(from);
}

int N,M,K;

void deal()
{
	for(int i=1;i<=N;i++) for(int j=1;j<=M;j++){
		if(!Gx[i][j]) continue;
		if(i-1>=1&&Gx[i-1][j]&&!vis[Gx[i-1][j]])
			add_edge(Gx[i-1][j],Gx[i][j]);
		if(i+1<=N&&Gx[i+1][j]&&!vis[Gx[i+1][j]])
			add_edge(Gx[i+1][j],Gx[i][j]);
		if(j-1>=1&&Gx[i][j-1]&&!vis[Gx[i][j-1]])
			add_edge(Gx[i][j-1],Gx[i][j]);
		if(j+1<=M&&Gx[i][j+1]&&!vis[Gx[i][j+1]])
			add_edge(Gx[i][j+1],Gx[i][j]);
		vis[Gx[i][j]]=1;
	}
}

int BFS(int now)
{
	int val=0;
	queue<int>q;
	vis[now]=1;
	q.push(now);
	while(!q.empty()){
		int u=q.front();
		val++; q.pop();
		for(int i=0;i<(int)G[u].size();i++){
			int v=G[u][i];
			if(!vis[v])
				q.push(v),vis[v]=1;
		}
	}
	return val;
}

int main()
{
	scanf("%d%d%d",&N,&M,&K);
	for(int i=1;i<=K;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		Gx[x][y]=i;
	}
	deal();
	memset(vis,0,sizeof(vis));
	int ans=0;
	for(int i=1;i<=K;i++)
		if(!vis[i]) ans=max(ans,BFS(i));
	printf("%d\n",ans);
	return 0;
}