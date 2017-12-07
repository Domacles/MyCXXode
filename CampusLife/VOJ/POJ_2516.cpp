#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;
#define INF 0x7ffffff
const int maxn = 55*3;

typedef pair<int,int> P;
struct edge{int to,cap,cost,rev;
	edge(){}
	edge(int a1,int a2,int a3,int a4){
		to=a1;cap=a2;cost=a3;rev=a4;}
};
int V;
vector<edge>G[maxn];//图的邻接表
int h[maxn];//顶点的势
int dist[maxn];//最短距离
int prevv[maxn],preve[maxn];//最短路中的前驱节点和对应的边
 
int N,M,K;
int Flow[55][55],Store[55][55],Cost[55][55][55];

int read()
{	
	scanf("%d%d%d",&N,&M,&K);
	if(N==0&&M==0&&K==0) return 0;
	for(int i=1;i<=N;i++) for(int j=1;j<=K;j++) 
		scanf("%d", &Flow[i][j]);
	for(int i=1;i<=M;i++) for(int j=1;j<=K;j++) 
		scanf("%d",&Store[i][j]);
	for(int l=1;l<=K;l++){
	for(int i=1;i<=N;i++) for(int j=1;j<=M;j++)
		scanf("%d",&Cost[l][i][j]);
	}
	
	return 1;
}

void add_edge(int from,int to,int cap,int cost)
{
	G[from].push_back(edge(to,cap,cost,G[to].size()));
	G[to].push_back(edge(from,0,-cost,G[from].size()-1));
}

int min_cost_flow(int s,int t,int f)
{
	int res=0;
	fill(h,h+V,0);
	while(f>0){
		//puts("DEBUG");
		priority_queue< P, vector<P>, greater<P> >que;
		fill(dist,dist+V,INF);
		dist[s]=0;
		que.push(P(0,s));
		while(!que.empty()){
			P p=que.top();que.pop();
			int v=p.second;		//用dist[v]更新以v为起点的边
			if(dist[v]<p.first) continue;//用dist[v]更新以v为起点的边，如果if成立，则当前状态已经不是最短，舍弃该状态，进行下一个状态
			//puts("DEBUG");
			for(int i=0;i<(int)G[v].size();i++){
				edge &e=G[v][i];
				if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
					dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
					prevv[e.to]=v;
					preve[e.to]=i;
					que.push(P(dist[e.to],e.to));
				}
			}
		}
		
		if(dist[t]==INF) return -1;
		
		for(int v=0;v<V;v++) h[v]+=dist[v];
		
		int d=f;
		for(int v=t;v!=s;v=prevv[v])
			d=min(d,G[prevv[v]][preve[v]].cap);
			
		f-=d;
		res+=d*h[t];
		
		for(int v=t;v!=s;v=prevv[v]){
			edge &e=G[prevv[v]][preve[v]];
			e.cap-=d;
			G[v][e.rev].cap+=d;
		}
	}
	return res;
}

int deal(int k)
{
	V=N+M+2;

	for(int i=0;i<maxn;i++) G[i].clear();
	
	for(int j=1;j<=N;j++) for(int i=1;i<=M;i++)
		add_edge(i,M+j,Store[i][k],Cost[k][j][i]);
	for(int i=1;i<=M;i++)
		add_edge(0, i,Store[i][k],0);
	for(int i=1;i<=N;i++)
		add_edge(M+i,V-1,Flow[i][k],0);
	
	int sumflow=0;
	for(int i=1;i<=N;i++) sumflow+=Flow[i][k];
	
	return min_cost_flow(0,V-1,sumflow);
}

int main()
{
	while(read()){
		int ans=0;
		for(int i=1;i<=K;i++){
			int temp=deal(i);
			ans+=temp;
			if(temp==-1){ans=-1; break;}
		}
		printf("%d\n",ans);
	}
	return 0;
}