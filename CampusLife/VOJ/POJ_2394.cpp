#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
#define maxn 2222
const int inf = 0x7ffffff;
struct Edge{int to,t;
	Edge(){}
	Edge(int a1,int a2){to=a1;t=a2;}
};
vector<Edge>G[maxn];
int dis[maxn],At[maxn],F,P,C,M;

void add_edge(int u,int v,int t){
	G[u].push_back(Edge(v,t));
	G[v].push_back(Edge(u,t));
}

void SPFA(int st){
	for(int i=0;i<=F;i++) dis[i]=inf;
	dis[st]=0;
	queue<int>q;
	q.push(st);
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(int i=0;i<(int)G[u].size();i++){
			int v=G[u][i].to;
			int t=G[u][i].t;
			if(dis[v]>dis[u]+t){
				dis[v]=dis[u]+t;
				q.push(v);
			}
		}
	}
	
}

int main()
{
	scanf("%d%d%d%d",&F,&P,&C,&M);
	for(int i=0;i<P;i++){
		int u,v,t; scanf("%d%d%d",&u,&v,&t);
		add_edge(u,v,t);
	}
	for(int i=1;i<=C;i++) scanf("%d",&At[i]);
	SPFA(1);
	int ans=0;
	vector<int>Cow;
	for(int i=1;i<=C;i++) if(dis[At[i]]<=M)
		ans++,Cow.push_back(i);
	printf("%d\n",ans);
	for(int i=0;i<(int)Cow.size();i++)
		printf("%d\n",Cow[i]);
	return 0;
}