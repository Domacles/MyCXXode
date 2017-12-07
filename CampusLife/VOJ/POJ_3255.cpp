/**********
	次短路
	Dijkstra(正反两次)+枚举每条边
**********/
#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;
#define maxn 55555

typedef long long LL;
typedef pair<int,int> P;
const int INF = 0x3fffffff;
struct Edge{int to,cost;
	Edge(){}
	Edge(int a,int b){to=a;cost=b;}
};
vector<Edge>G[maxn];
int dis[maxn],dis2[maxn];
int N,R,x,y,c;

void add_edge(int from,int to,int cost){
	G[from].push_back(Edge(to,cost));
	G[to].push_back(Edge(from,cost));
}

int Dijkstra(int start)
{
	fill(dis,dis+N+1,INF);
	fill(dis2,dis2+N+1,INF);
	priority_queue< P, vector<P>, greater<P> > q;
	dis[start]=0;
	q.push(P(0,start));
	while(!q.empty()){
		P p=q.top(); q.pop();
		int v=p.second,d=p.first;
		if(dis2[v]<p.first) continue;//!!!!!!!!
		for(int i=0;i<(int)G[v].size();i++){
			Edge e=G[v][i];
			int d2=d+e.cost;
			if( dis[e.to]>d2 ){
				swap(dis[e.to],d2);//!!!!!!!!!!!!!
				q.push(P(dis[e.to],e.to));
			}
			if( dis2[e.to]>d2 && dis[e.to]<d2 ){
				dis2[e.to]=d2;
				q.push(P(dis2[e.to],e.to));//!!!!!!!!!!!
			}
		}
	}
	return dis2[N];
}

int main()
{
	scanf("%d%d",&N,&R);
	for(int i=0;i<R;i++){
		scanf("%d%d%d",&x,&y,&c);
		add_edge(x,y,c);
	}
	printf("%d\n",Dijkstra(1));
	return 0;
}