#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;
#define INF 0x7ffffff
const int maxn = 5555;

typedef pair<int,int> P;
struct edge{int to,cap,cost,rev;
	edge(){}
	edge(int a1,int a2,int a3,int a4){
		to=a1;cap=a2;cost=a3;rev=a4;}
};
int V;//节点数
vector<edge>G[maxn];//图的邻接表
int h[maxn];//顶点的势
int vis[maxn];//是否在SPFA的队列里
int dist[maxn];//最短距离
int prevv[maxn],preve[maxn];//最短路中的前驱节点和对应的边

void add_edge(int from,int to,int cap,int cost)
{
	G[from].push_back(edge(to,cap,cost,G[to].size()));
	G[to].push_back(edge(from,0,-cost,G[from].size()-1));
}

int max_cost_flow(int s,int t,int f)//min_cost_flow(int s,int t,int f)
{
	int res=0;
	fill(h,h+V,0);
	while(f>0){
	/****
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
		****/
		queue<int> que;
		while(!que.empty()) que.pop();
		fill(dist,dist+V,-INF);
		fill(vis,vis+maxn,0);
		dist[s]=0;
		que.push(s);vis[s]=1;
		while(!que.empty()){
			int v=que.front();que.pop();vis[v]=0;
			for(int i=0;i<(int)G[v].size();i++){
				edge &e=G[v][i];
				if(e.cap >0 && dist[e.to] < dist[v] + e.cost){
					dist[e.to] = dist[v] + e.cost;
					prevv[e.to]=v;
					preve[e.to]=i;
					if(!vis[e.to]){
						vis[e.to]=1;
						que.push(e.to);
					}
				}
			}
		}
		//cout<<dist[t]<<endl;
		if(dist[t]==-INF) return res;
		
		int d=f;
		for(int v=t;v!=s;v=prevv[v])
			d=min(d,G[prevv[v]][preve[v]].cap);
			
		f-=d;
		//res+=d*h[t];
		res+=dist[t];
		
		for(int v=t;v!=s;v=prevv[v]){
			edge &e=G[prevv[v]][preve[v]];
			e.cap-=d;
			G[v][e.rev].cap+=d;
		}
	}
	return res;
}

int N,K;
int Cost[5555];

int deal()
{
	V=N*N*2+2;
	int next=N*N;
	for(int i=0;i<N;i++) for(int j=1;j<=N;j++){
		int now=i*N+j;
		add_edge(now,now+next,1,Cost[now]);//好思路
		add_edge(now,now+next,K-1,0);//好思路
		if(i!=N-1)
			add_edge(now+next,now+N,INF,0); 
		if(j!=N)
			add_edge(now+next,now+1,INF,0);
	}
	add_edge(0,1,K,0);
	add_edge(N*N+next,V-1,K,0);
	return max_cost_flow(0,V-1,K);
}

int main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++) for(int j=1;j<=N;j++)
		scanf("%d",&Cost[i*N+j]);
	int ans=deal();
	printf("%d\n",ans);
}