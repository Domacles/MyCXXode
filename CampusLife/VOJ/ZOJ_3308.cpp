/******
	赤裸裸的网络流，
	注意，题目中说明所有马都在黑色格子上，这意味着一只马不会跳到另外一只马的初始位置
******/
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
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int,int> PII;
typedef long long ll;

#define foreach(it,V) for(vector<int>::iterator it=V.begin(); it!=V.end();++it)

const double eps= 1e-5;

#define INF 0x7ffffff
const int maxn = 555;

typedef pair<int,int> P;
struct edge{int to,cap,cost,rev;
	edge(){}
	edge(int a1,int a2,int a3,int a4){
		to=a1;cap=a2;cost=a3;rev=a4;}
};
//int V;//节点数
vector<edge>G[maxn];//图的邻接表
int vis[maxn];//是否在SPFA的队列里
int dist[maxn];//最短距离
int prevv[maxn],preve[maxn];//最短路中的前驱节点和对应的边

///
int R,C,N,K;
int c[22][22];
bool used[maxn];
///

void add_edge(int from,int to,int cap,int cost)
{
	G[from].push_back(edge(to,cap,cost,G[to].size()));
	G[to].push_back(edge(from,0,-cost,G[from].size()-1));
}

int min_cost_flow(int s,int t,int f)
{
	int res=0;
	while(f>0){
		queue<int> que;
		while(!que.empty()) que.pop();
		fill(dist,dist+maxn,INF);
		fill(vis,vis+maxn,0);
		dist[s]=0;
		que.push(s);vis[s]=1;
		while(!que.empty()){
			int v=que.front();que.pop();vis[v]=0;
			for(int i=0;i<(int)G[v].size();i++){
				edge &e=G[v][i];
				if(e.cap >0 && dist[e.to] > dist[v] + e.cost){
					dist[e.to] = dist[v] + e.cost;
					prevv[e.to]=v, preve[e.to]=i;
					if(!vis[e.to])
						vis[e.to]=1, que.push(e.to);
				}
			}
		}

		if(dist[t]==INF) return -1;

		int d=f;
		for(int v=t;v!=s;v=prevv[v])
			d=min(d,G[prevv[v]][preve[v]].cap);

		f-=d;
		res+=dist[t]*d;

		for(int v=t;v!=s;v=prevv[v]){
			edge &e=G[prevv[v]][preve[v]];
			e.cap-=d;
			G[v][e.rev].cap+=d;
		}
	}
	return res;
}

void init()
{
    for(int i=0;i<maxn;i++)
        G[i].clear();
    memset(used,0,sizeof(used));
}

int f(int x,int y)
{
    return (x-1)*C+(y-1)+1;
}

int dx[]={1,1,-1,-1,2,-2,2,-2};
int dy[]={2,-2,2,-2,1,1,-1,-1};

int main()
{
    //freopen("1.in","r",stdin);
    while(~scanf("%d%d%d%d",&R,&C,&N,&K)){
        init();
        for(int i=1;i<=R;i++)
            for(int j=1;j<=C;j++)
                scanf("%d",&c[i][j]);

        for(int i=0;i<N;i++){
            int t,x,y; scanf("%d%d%d",&t,&x,&y);
            add_edge(0,f(x,y),1,0);
            for(int j=0;j<8;j++){
                int xx=dx[j]+x, yy=dy[j]+y;
                int cost=0;
                if(xx<1 || xx>R) continue;
                if(yy<1 || yy>C) continue;
                if(t==1) cost=c[x][y]*c[xx][yy];
                if(t==2) cost=c[x][y]+c[xx][yy];
                if(t==3) cost=max(c[x][y],c[xx][yy]);
                add_edge(f(x,y),f(xx,yy),1,cost);
                used[f(xx,yy)]=1;
            }
        }
        for(int i=1;i<=R;i++)
            for(int j=1;j<=C;j++)
                if(used[f(i,j)])
                    add_edge(f(i,j),maxn-1,1,0);
        int S=0,T=maxn-1;
        int ans=min_cost_flow(S,T,K);
        printf("%d\n",ans);
    }
    return 0;
}

