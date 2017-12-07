#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;
#define maxn 322
#define INF 0x7ffffff

typedef pair<int ,int> P;
struct edge{int to,cap,cost,rev;
	edge(){};
	edge(int a1,int a2,int a3,int a4){
		to=a1;cap=a2;cost=a3;rev=a4;
	};
};
int V;
vector<edge>G[maxn];//图的邻接表
int h[maxn];//顶点的势
int dist[maxn];//最短距离
int prevv[maxn],preve[maxn];//最短路的前驱节点和对应的边

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
			if(dist[v]<p.first) continue;
	  	    //用dist[v]更新以v为起点的边，如果if成立，则当前状态已经不是最短，舍弃该状态，进行下一个状态
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

struct Node{int x,y;};
Node n1[111],n2[111];
int N,M,num1,num2;

int ABS(int x){if(x<0)x*=-1; return x;}

int read()
{
	scanf("%d%d",&N,&M);
	if(N==0&&M==0) return 0;

	num1=0,num2=0;
	for(int i=1;i<=N;i++){
		char Map[222];
		scanf("%s",Map);
		for(int j=1;j<=M;j++){
			if(Map[j-1]=='H')
				n2[++num2].x=i,n2[num2].y=j;
			if(Map[j-1]=='m')
				n1[++num1].x=i,n1[num1].y=j;
		}
	}
	return 1;
}

int deal()
{
	for(int i=0;i<maxn;i++) G[i].clear();
	
	for(int i=1;i<=num1;i++) for(int j=1;j<=num2;j++){
		int Cost = ABS(n1[i].x-n2[j].x) + ABS(n1[i].y-n2[j].y) ;
		add_edge(i,j+num1,1,Cost);
	}
	
	V=num1+num2+2;
	for(int i=1;i<=num1;i++) add_edge(0,i,1,0);
	for(int i=1;i<=num2;i++) add_edge(i+num1,V-1,1,0);
	
	return min_cost_flow(0,V-1,num1);
}

int main()
{
	while(read())
		printf("%d\n",deal());
	return 0;
}