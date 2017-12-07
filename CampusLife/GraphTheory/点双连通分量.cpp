/******{双连通分量}标号从0起*****/
#include<cstdio>
#include<cstring>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=100000*2;
const int MAXM=200000;
struct edges
{
	int to,next;
	bool cut,visit;
} edge[MAXM<<1];
int head[MAXN],low[MAXN],dpt[MAXN],L;
bool visit[MAXN],cut[MAXN];
void init(int n)
{
	L=0;
	memset(head,-1,4*n);
	memset(visit,0,n);
}
void add_edge(int u,int v)
{
	edge[L].cut=edge[L].visit=0;
	edge[L].to=v;
	edge[L].next=head[u];
	head[u]=L++;
}
int idx;
stack<int> st;
int bcc[MAXM];
void dfs(int u,int fu,int deg)
{
	cut[u]=0;
	visit[u]=1;
	low[u]=dpt[u]=deg;
	int tot=0;
	for (int i=head[u]; i!=-1; i=edge[i].next)
	{
		int v=edge[i].to;
		if (edge[i].visit)
			continue;
		st.push(i/2);
		edge[i].visit=edge[i^1].visit=1;
		if (visit[v])
		{
			low[u]=dpt[v]>low[u]?low[u]:dpt[v];
			continue;
		}
		dfs(v,u,deg+1);
		edge[i].cut=edge[i^1].cut=(low[v]>dpt[u] || edge[i].cut);
		if (u!=fu) cut[u]=low[v]>=dpt[u]?1:cut[u];
		if (low[v]>=dpt[u] || u==fu)
		{
			while (st.top()!=i/2)
			{
				int x=st.top()*2,y=st.top()*2+1;
				bcc[st.top()]=idx;
				st.pop();
			}
			bcc[i/2]=idx++;
			st.pop();
		}
		low[u]=low[v]>low[u]?low[u]:low[v];
		tot++;
	}
	if (u==fu && tot>1) cut[u]=1;
}
int main()
{
	int n,m;
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		init(n);
		for (int i=0; i<m; i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add_edge(u,v);
			add_edge(v,u);
		}
		idx=0;
		for (int i=0; i<n; i++)
			if (!visit[i])
				dfs(i,i,0);
	}
	return 0;
}
