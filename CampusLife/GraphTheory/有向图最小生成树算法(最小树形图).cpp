#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
/*
* 最小树形图
* 复杂度O(NM),有复杂度更好的O(M+Nlog(N))算法,暂无
* 点下标[0,n-1] 边下标[0,m-1]
* 有向边表示：u->v 花费为cost
* 返回最小树形图的边权和，-1表示不存在最小树形图
*/
const int INF = 100000000;
const int MAXN = 1010; //点数
const int MAXM = 1010000;//边数
#define ll int
struct Edge{
	int u,v;
	ll cost;
}edge[MAXM];        
int pre[MAXN],id[MAXN],visit[MAXN],edgenum;
void addedge(int u, int v, ll cost){
	Edge E = {u, v, cost}; edge[edgenum++] = E;
}

ll in[MAXN];
ll zhuliu(int root,int n,int m,Edge edge[])//树根(注意是有向树，树根不能任意) 点数 边数 edge
{
	int u,v;
	ll res=0;
	while(1)
	{
		for(int i = 0;i < n;i++)
			in[i] = INF;
		for(int i = 0;i < m;i++)
			if(edge[i].u != edge[i].v && edge[i].cost < in[edge[i].v])
			{
				pre[edge[i].v] = edge[i].u;
				in[edge[i].v] = edge[i].cost;
			}
			for(int i = 0;i < n;i++)
				if(i != root && in[i] == INF)
					return -1;//不存在最小树形图
			int tn = 0;
			memset(id,-1,sizeof(id));
			memset(visit,-1,sizeof(visit));
			in[root] = 0;
			for(int i = 0;i < n;i++)
			{
				res += in[i];
				v = i;
				while( visit[v] != i && id[v] == -1 && v != root)
				{
					visit[v] = i;
					v = pre[v];
				}
				if( v != root && id[v] == -1 )
				{
					for(int u = pre[v]; u != v ;u = pre[u])
						id[u] = tn;
					id[v] = tn++;
				}
			}
			if(tn == 0)break;//没有有向环
			for(int i = 0;i < n;i++)
				if(id[i] == -1)
					id[i] = tn++;
			for(int i = 0;i < m;)
			{
				v = edge[i].v;
				edge[i].u = id[edge[i].u];
				edge[i].v = id[edge[i].v];
				if(edge[i].u != edge[i].v)
					edge[i++].cost -= in[v];
				else
					swap(edge[i],edge[--m]);
			}
			n = tn;
			root = id[root];
	}
	return res; //-1为不存在最小树形图
}
void init(){
	edgenum = 0;
}
