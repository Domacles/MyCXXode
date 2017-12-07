#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
#define INT_MAX 999999
int n,m;
int cap[210][210];//残余流量
int E_K(int s,int t)
{
	int flow[210][210];//已用流量
	int f=0,a[210],p[210];
	queue<int> q;
	memset(flow,0,sizeof(flow));
	while(1)
	{
		memset(a,0,sizeof(a));
		a[s]=INT_MAX;
		q.push(s);
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			for(int v=1;v<=n;v++)
			{
				if(!a[v] && cap[u][v]>flow[u][v])
				{
					q.push(v);
					a[v]= (a[u]<cap[u][v]-flow[u][v]) ? a[u] : (cap[u][v]-flow[u][v]);
					p[v]=u;
				}
			}
		}
		if(a[t]==0)
			break;
		for(int u=t;u!=s;u=p[u])
		{
			flow[p[u]][u]+=a[t];
	     	flow[u][p[u]]-=a[t];
		}
		f+=a[t];
	}
	return f;
}
int main()
{
	int i,from,to,w;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		memset(cap,0,sizeof(cap));
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&from,&to,&w);
			cap[from][to]+=w;//可能有重边,需叠加
		}
		printf("%d\n",E_K(1,n));
	}
	return 0;
}