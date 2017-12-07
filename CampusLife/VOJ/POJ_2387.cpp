#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
#define maxn 1111
#define INF  0x3fffffff
struct Edge{int v,w;
	Edge(){}
	Edge(int vv,int ww){v=vv;w=ww;}
};
vector<Edge>G[maxn];
int T,N;

void add_edge(int u,int v,int w){
	G[u].push_back(Edge(v,w));
	G[v].push_back(Edge(u,w));
}

int dis[maxn],vis[maxn];
int SPFA(){
	queue<int>q;
	for(int i=0;i<maxn;i++) dis[i]=INF;
	dis[1]=0;
	vis[1]=1;
	q.push(1);
	while(!q.empty()){
		int u=q.front(); 
		q.pop();
		vis[u]=0;
		for(int i=0;i<(int)G[u].size();i++){
			int v=G[u][i].v , w=G[u][i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(!vis[v])
					vis[v]=1 , q.push(v);
			}
		}
	}
	return dis[N];
}

int main()
{
	scanf("%d%d",&T,&N);
	for(int i=0;i<T;i++){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w);
	}
	printf("%d\n",SPFA());
	return 0;
}