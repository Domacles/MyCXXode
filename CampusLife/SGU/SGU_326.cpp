/*****
        题目大意:
        已知小组内各球队的目前得分，小组各球队将要比赛的场数(既包括小组内的，还包括小组外的)。
        已知小组内i与j将要比赛的场数。
        问:1号队伍能否取得第一或者并列第一。

        思路： 最大流问题
        需要使1号球队获胜最多次，然后使得其他球队获胜场数最大者最小。
        采用相减比较的策略，用1号与其他队伍目前得分的差作为其他队伍得分的上界upi。
        构图，
        源点作为1号队伍，然后有N-1个点作为其他队伍，从源点到其他队伍连一条流量位upi的边;
        然后，对于每一组有比赛的i，j队伍，建一个点作为分配i,j比赛场数的点，
        i和j到该点有一条流量为s[i][j]的边，然后该点到汇点连一条流量为s[i][j]的边，结束。

        若满流，则说明所有的比赛都可分配从而达到目标，否则输出NO。
*****/
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int,int> PII;
typedef long long ll;

const int maxn =222;

int N;
int score[maxn],r[maxn],a[maxn][maxn];

#define INF 1e8
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
	//有向图中反向边为0，无向图中反向边为cap
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

void init()
{
	for(int i=0;i<maxn;i++)
		G[i].clear();
}

int s[maxn];
bool solve(int st,int ed)
{
    int sum=0;
    for(int i=1;i<N;i++){
        s[i]=score[0]-score[i];
        if(s[i]<0) return 0;
    }
    init();

    for(int i=1;i<N;i++) add_edge(0,i,s[i]);
    int V=N;
    for(int i=1;i<N;i++) for(int j=i+1;j<N;j++){
        s[V]=a[i][j];
        sum+=s[V];
        add_edge(i,V,a[i][j]);
        add_edge(j,V,a[i][j]);
        V++;
    }
    for(int i=N;i<V;i++) add_edge(i,V,s[i]);
    int ret=max_flow(0,V);
    return ret==sum;
}

int main()
{
    //freopen("r.txt","r",stdin);
    while(~scanf("%d",&N)){
        for(int i=0;i<N;i++) scanf("%d",&score[i]);
        for(int i=0;i<N;i++) scanf("%d",&r[i]);
        score[0]+=r[0];
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                scanf("%d",&a[i][j]);
        if(solve(1,N-1)) puts("YES");
        else puts("NO");
    }
    return 0;
}
