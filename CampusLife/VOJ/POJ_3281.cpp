//Dinic
#include <cstdio>
#include <queue>
#include <vector>
#include <stack>
#include <cstring>
#include <utility>
#include <iostream>
#include <cmath>

using namespace std;
#define INF 1e7
#define maxn 555
struct edge{int to,rev,cap;
	edge(){}
	edge(int a1,int a2,int a3){to=a1;cap=a2;rev=a3;}
};

vector<edge>G[maxn];//图的邻接表
int level[maxn];//顶点到源点的距离编号
int iter[maxn];//当前弧，在其之前的边已经没用了

void add_edge(int from,int to,int cap){
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
int dfs(int v,int t,int f){
	if(v==t) return f;
	for(int &i=iter[v];i<(int)G[v].size();i++){
		edge &e=G[v][i];
		if(e.cap > 0 && level[v] < level[e.to]){
			int d=dfs(e.to,t,min(f,e.cap));
			
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
int max_flow(int s,int t){
	int flow=0;
	while(1){
		bfs(s);
		if(level[t]<0) return flow;
		memset(iter,0,sizeof(iter));
		int f;
		while((f=dfs(s,t,INF))>0){
			flow+=f;
		}
	}
}
int N,F,D;
vector<int>CowF[maxn];
vector<int>CowD[maxn];

void init()
{
	for(int i=0;i<maxn;i++)
		CowF[i].clear(),CowD[i].clear();
	for(int i=0;i<maxn;i++)
		G[i].clear();
}

void read()
{
	for(int i=1;i<=N;i++){
		int n1,n2,x;
		scanf("%d%d",&n1,&n2);
		for(int j=0;j<n1;j++)
			scanf("%d",&x),CowF[i].push_back(x);
		for(int j=0;j<n2;j++)
			scanf("%d",&x),CowD[i].push_back(x);
	}
}

void deal()
{
	int num=0,V=F+D+2*N+1;
	for(int i=1;i<=F;i++) add_edge(0,num+i,1);
	num+=F;
	for(int i=1;i<=D;i++) add_edge(num+i,V,1);
	num+=D;
	for(int i=1;i<=N;i++) add_edge(num+i,num+N+i,1);
	for(int i=1;i<=N;i++){
		int x=num+i;
		for(int j=0;j<(int)CowF[i].size();j++){
			int from=CowF[i][j];
			add_edge(from,x,1);
		}
		x+=N;
		for(int j=0;j<(int)CowD[i].size();j++){
			int to=F+CowD[i][j];
			add_edge(x,to,1);
		}
	}
	printf("%d\n",max_flow(0,V));
}

int main()
{
	while(~scanf("%d%d%d",&N,&F,&D)){
		init();
		read();
		deal();
	}
	return 0;
}