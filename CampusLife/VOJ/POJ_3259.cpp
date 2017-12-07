#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;
#define INT_MAX 1e9
#define maxn 1055
struct Edge{
	int v,w;
	Edge(){}
	Edge(int to1,int w1){v=to1;w=w1;}
};
vector<Edge>G[maxn];
int F,N,M,W;

void add_edge(int u,int v,int w){G[u].push_back(Edge(v,w));}
queue<int>q;
int vis[maxn],num[maxn],dis[maxn];
bool SPFA(){
	
	while(!q.empty()) q.pop();
	for(int i=0;i<=N;i++) dis[i]=INT_MAX;
	memset(vis,0,sizeof(vis));
	memset(num,0,sizeof(num));
	
	dis[1]=0; num[1]++; vis[1]=1; q.push(1);
	while(!q.empty()){
		int u=q.front(); q.pop(); vis[u]=0;
		for(unsigned int i=0;i<G[u].size();i++){
			Edge &e=G[u][i];
			int v=e.v , w=e.w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(!vis[v]){
					vis[v]=1; num[v]++; q.push(v);
					if(num[v]>=N) return 1;
				}
			}
		}
	}
	return 0;
}

int main()
{
	scanf("%d",&F);
	while(F--){
		scanf("%d%d%d",&N,&M,&W);
		for(int i=0;i<maxn;i++) G[i].clear();
		for(int i=0;i<M;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			add_edge(u,v,w);
			add_edge(v,u,w);
		}
		for(int i=0;i<W;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			add_edge(u,v,-w);
		}
		if(SPFA()) puts("YES");
		else puts("NO");
	}
	return 0;
}