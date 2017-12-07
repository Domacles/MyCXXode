#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;
#define maxn 1111
const int INF = 0x3fffffff;
struct Edge{int st,ed,len;};
vector<Edge>edge;
int N,M,K,map[maxn][maxn],dist[maxn];
bool operator<(Edge a,Edge b){return a.len<b.len;}

int SPFA()
{
	for(int i=0;i<=N;i++) dist[i]=INF;
	queue<int>q;
	q.push(1); dist[1]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v=1;v<=N;v++){
			if(v==u) continue;
			if(dist[v]>dist[u]+map[u][v]){
				dist[v]=dist[u]+map[u][v];
				q.push(v);
			}
		}
	}
	return dist[N];
}

int deal(int len)
{
	for(int i=0;i<=N;i++){map[i][i]=0; 
		for(int j=i+1;j<=N;j++)
			map[i][j]=map[j][i]=INF;
	}
	for(int i=0;i<M;i++){
		int u=edge[i].st,v=edge[i].ed;
		if(edge[i].len>len) 
			map[u][v]=map[v][u]=1;
		else map[u][v]=map[v][u]=0;
	}
	return SPFA();
}

int Binary()
{
	int l=0,r=M-1;
	while(l<r){
		int m=(l+r)>>1;
		if(deal(edge[m].len)>K) l=m+1;
		else r=m;
	}
	return edge[r].len;
}

int main()
{
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<M;i++){
		Edge e;
		scanf("%d%d%d",&e.st,&e.ed,&e.len);
		edge.push_back(e);
	}
	sort(edge.begin(),edge.end());
	
	deal(0);
	int dis=SPFA();
	if(dis==INF)  puts("-1");
	else if(dis<K) puts("0");
	else printf("%d\n",Binary());
	
	return 0;
}