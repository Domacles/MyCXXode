#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
#define maxn 1111
struct Point{int x,y;};
vector<Point>a;
vector<int>G[maxn],G1[maxn];
double dist[maxn][maxn],dist1[maxn][maxn];
int N,M,n,vis[maxn];
double dis[maxn];

double Dist(int x1,int y1,int x2,int y2){return sqrt((ll)(x1-x2)*(x1-x2)+(ll)(y1-y2)*(y1-y2));}

void BFS(int now,int num)
{
	queue<int>q;
	q.push(now);
	vis[now]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		G1[num].push_back(u);
		for(int i=0;i<(int)G[u].size();i++){
			int v=G[u][i];
			if(!vis[v]){
				vis[v]=1;
				q.push(v);
			}
		}
	}
}

double Prim()
{
	double val=0;
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++) for(int j=0;j<i;j++){
		double temp=0x3fffffff;
		for(int k1=0;k1<(int)G1[i].size();k1++)
			for(int k2=0;k2<(int)G1[j].size();k2++){
				int u=G1[i][k1],v=G1[j][k2];
				temp=min(temp,dist[u][v]);
			}
		dist1[i][j]=dist1[j][i]=temp;
	}
	
	for(int i=0;i<n;i++) dis[i]=dist1[0][i];
	vis[0]=1;
	
	int pos=0;
	for(int i=1;i<n;i++){
		double Min=0x3fffffff;
		for(int j=0;j<n;j++)
			if(!vis[j] && dis[j]<Min){
				Min=dis[j];
				pos=j;
			}
		vis[pos]=1;
		val+=Min;
		for(int j=0;j<n;j++)
			if(!vis[j] && dis[j]>dist1[pos][j])
				dis[j]=dist1[pos][j];
	}
	return val;
}

int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++){
		Point p; scanf("%d%d",&p.x,&p.y);
		a.push_back(p);
		for(int j=0;j<i;j++) 
			dist[i][j]=dist[j][i]=Dist(a[i].x,a[i].y,a[j].x,a[j].y);
	}
	for(int i=0;i<M;i++){
		int x,y; scanf("%d%d",&x,&y);
		x--,y--;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(int i=0;i<N;i++)
		if(!vis[i]) BFS(i,n++);
	double ans=Prim();
	printf("%.2f\n",ans);
	return 0;
}