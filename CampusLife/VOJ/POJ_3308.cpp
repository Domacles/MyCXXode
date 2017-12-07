#include <cstdio>
#include <queue>
#include <vector>
#include <stack>
#include <cstring>
#include <utility>
#include <iostream>
#include <cmath>

using namespace std;
#define INF 1e8
#define maxn 555
struct edge{int to,rev;
			double cap;
	edge(){}
	edge(int a1,double a2,int a3){to=a1;cap=a2;rev=a3;}
};

vector<edge>G[maxn];//图的邻接表
int level[maxn];//顶点到源点的距离编号
int iter[maxn];//当前弧，在其之前的边已经没用了

void add_edge(int from,int to,double cap){
	G[from].push_back(edge(to,cap,G[to].size()));
	G[to].push_back(edge(from,0,G[from].size()-1));
}

//通过bfs从源点出发的距离标号
void bfs(int s){
	memset(level,-1,sizeof(level));
	queue<int> que;
	level[s]=0;
	que.push(s);
	while(!que.empty()){
		int v=que.front();que.pop();
		for(int i=0;i<(int)G[v].size();i++){
			edge &e=G[v][i];
			if(e.cap > 0 && level[e.to] <0){
				level[e.to]=level[v]+1;
				que.push(e.to);
			}
		}
	}
}

//通过DFS寻找增广路
double dfs(int v,int t,double f){
	if(v==t) return f;
	for(int &i=iter[v];i<(int)G[v].size();i++){
		edge &e=G[v][i];
		if(e.cap > 0 && level[v] < level[e.to]){
			double d=dfs(e.to,t,min(f,e.cap));
			
			if(d>0){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}

//求s到t的最大流
double max_flow(int s,int t){
	double flow=0;
	while(1){
		bfs(s);
		if(level[t]<0) return flow;
		memset(iter,0,sizeof(iter));
		double f;
		while((f=dfs(s,t,INF))>0){
			flow+=f;
		}
	}
}

int N,M,L;

void init()
{
	for(int i=0;i<maxn;i++) 
		G[i].clear();
}

void read()
{
	init();
	scanf("%d%d%d",&N,&M,&L);
	for(int i=1;i<=N;i++)
	{
		double flow;
		scanf("%lf",&flow);
		add_edge(0,i,log(flow));
	}
	for(int i=1;i<=M;i++)
	{
		double flow;
		scanf("%lf",&flow);
		add_edge(N+i,N+M+1,log(flow));
	}
	for(int i=1;i<=L;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add_edge(x,y+N,INF);
	}
}


int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		read();
		printf("%.4f\n",exp(max_flow(0,N+M+1)));
	}
	return 0;
}