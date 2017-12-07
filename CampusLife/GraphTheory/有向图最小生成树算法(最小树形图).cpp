#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
/*
* ��С����ͼ
* ���Ӷ�O(NM),�и��Ӷȸ��õ�O(M+Nlog(N))�㷨,����
* ���±�[0,n-1] ���±�[0,m-1]
* ����߱�ʾ��u->v ����Ϊcost
* ������С����ͼ�ı�Ȩ�ͣ�-1��ʾ��������С����ͼ
*/
const int INF = 100000000;
const int MAXN = 1010; //����
const int MAXM = 1010000;//����
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
ll zhuliu(int root,int n,int m,Edge edge[])//����(ע������������������������) ���� ���� edge
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
					return -1;//��������С����ͼ
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
			if(tn == 0)break;//û������
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
	return res; //-1Ϊ��������С����ͼ
}
void init(){
	edgenum = 0;
}
