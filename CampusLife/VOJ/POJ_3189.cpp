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
#define maxn 1333
struct edge{int to,rev;
			int cap;
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

int N,B,rank[maxn][22],cap[22];

int deal(int R)
{
	for(int st=1;st+R-1<=B;st++){
		memset(level,0,sizeof(level));
		memset(iter,0,sizeof(iter));
		for(int i=0;i<=N+B+1;i++) G[i].clear();
		//start = 0 , end = N+B+1 
		for(int i=1;i<=N;i++) add_edge(0,i,1);
		for(int i=1;i<=N;i++) for(int j=st;j<=st+R-1;j++){
			add_edge(i,rank[i][j]+N,1);
		}
		for(int i=N+1;i<=N+B;i++)
			add_edge(i,N+B+1,cap[i-N]);
		if(max_flow(0,N+B+1)==N) 
			return 1;
	}
	return 0;
}

void solve()
{
	int l=1,r=B;
	while(l<r){//二分枚举区间差值
		int m=(l+r)>>1;
		if(deal(m)) r=m;
		else l=m+1;
	}
	printf("%d\n",r);
}

int main()
{
	scanf("%d%d",&N,&B);
	for(int i=1;i<=N;i++) for(int j=1;j<=B;j++){
		scanf("%d",&rank[i][j]);
	}
	for(int i=1;i<=B;i++) scanf("%d",&cap[i]);
	solve();
	return 0;
}