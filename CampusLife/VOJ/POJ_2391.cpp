//Floyd + 二分 + 网络流
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
#define maxn 1005
const long long inf = 9999999999999999;
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

typedef long long ll;
int  N,P,csum,cow[maxn],host[maxn];
ll   psum,Map[maxn][maxn];

void init() {for(int i=0;i<maxn;i++) G[i].clear();}

void Floyd(){
	for(int mid=1;mid<=N;mid++)
		for(int i=1;i<=N;i++) for(int j=1;j<=N;j++)
		if(Map[i][mid]<inf&&Map[mid][j]<inf&&Map[i][j]>Map[i][mid]+Map[mid][j])
		Map[i][j]=Map[i][mid]+Map[mid][j];
}

int deal(ll M)
{
	init();
	for(int i=1;i<=N;i++) for(int j=1;j<=N;j++){
		if(Map[i][j]>M) continue;
		add_edge(i,j+N,INF);
	}
	for(int i=1;i<=N;i++){
		add_edge(0,i,cow[i]);
		add_edge(i+N,2*N+1,host[i]);
	}
	return max_flow(0,2*N+1);
}

int main()
{
	for(int i=0;i<maxn;i++) for(int j=i+1;j<maxn;j++)
		Map[i][j]=Map[j][i]=inf;
	scanf("%d%d",&N,&P);
	for(int i=1;i<=N;i++) 
		scanf("%d%d",&cow[i],&host[i]),csum+=cow[i];
	for(int i=1;i<=P;i++){
		int x,y,z; scanf("%d%d%d",&x,&y,&z);
		if(Map[x][y]>z) Map[y][x]=Map[x][y]=z;
		psum+=z;
	}
	Floyd();
	ll l=0,r=psum+1;
	bool OK=0;
	while(l<r){
		ll mid=(l+r)>>1;
		if(deal(mid)==csum)
			r=mid,OK=1;
		else l=mid+1;
	}
	if(OK) printf("%I64d\n",r);
	else puts("-1");
	return 0;
}