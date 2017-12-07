/****
先做一遍连通块缩点，这样构成的无向图就是一个二分图，每次的操作变成了“选择一个点，把这个点以及其有边相连的点都缩为一个点”。
于是我们可以枚举以每个点为起点，并不断选择它来缩点所需要的步数。然后取最小值就是答案。
****/
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int maxn = 44;
const int INF = 0x7fffffff;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

char Map[maxn][maxn];
vector<int> G[maxn*maxn];
int N, M, Num, dis[maxn*maxn], vis[maxn][maxn] ,mp[maxn*maxn][maxn*maxn];//vis == belong

void init()
{
	Num=0;
	memset(mp, 0,sizeof(mp) );
	memset(Map,0,sizeof(Map));
	memset(vis,0,sizeof(vis));
	for(int i=0;i<=N*M;i++)
		G[i].clear();
}

bool check(int i,int j)
{
	if(i<=0 || i>N) return 0;
	if(j<=0 || j>M) return 0;
	return 1;
}

void Add_edge(int x,int y)
{
	G[x].push_back(y);
	G[y].push_back(x);
	mp[x][y]=mp[y][x]=1;
}

void DFS(int x,int y,char k)
{
	if(!check(x,y) || vis[x][y] || Map[x][y]!=k) return ;
	
	vis[x][y]=Num;
	
	DFS(x+1,y,k);
	DFS(x-1,y,k);
	DFS(x,y+1,k);
	DFS(x,y-1,k);
}

void deal()
{
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			if(!vis[i][j]) Num++,DFS(i,j,Map[i][j]);

	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			for(int k=0;k<4;k++){
				int x=i+dx[k] , y=j+dy[k];
				if(!check(x,y) || vis[i][j]==vis[x][y]) 
					continue;
				if(!mp[ vis[i][j] ][ vis[x][y] ])
					Add_edge(vis[i][j],vis[x][y]);
			}
}

int BFS(int s)
{
	memset(dis,-1,sizeof(dis));
	queue<int>q;
	int ret=0;
	
	dis[s]=0;
	q.push(s);

	while(!q.empty()){
		int u=q.front();
		q.pop();
		ret=max(ret,dis[u]);
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i];
				if(dis[v]==-1) 
					dis[v]=dis[u]+1 , q.push(v);
		}
	}
	return ret;
}

void solve()
{
	int ans=INF;
	for(int i=1;i<=Num;i++)
		ans=min(ans,BFS(i));
	printf("%d\n",ans);
}

int main()
{
	// freopen("r1.txt","r",stdin);
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&M);
		init();
		for(int i=1;i<=N;i++) scanf("%s",Map[i]+1);
		deal();
		solve();
	}
	return 0;
}