/***
		Ha  Ha  Ha
***/
#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;
#define MaxS  90000
const int maxn =1000;

int n,sn,tn,m;
int map[maxn][maxn];

int E_K(int s,int t)
{
	int flow[111][111];//已用流量
	int f=0,a[maxn],p[maxn];
	
	queue<int>q;
	memset(flow,0,sizeof(flow));
	
	while(1){
		memset(a,0,sizeof(a));
		a[s]=MaxS;
		q.push(s);
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int v=0;v<=n+1;v++)
			{
				if(!a[v] && map[u][v] > flow[u][v]){
					q.push(v);
					a[v] =(a[u]<map[u][v]-flow[u][v]) ? a[u] : (map[u][v]-flow[u][v]);
					p[v]=u;
				}
			}
		}
		
		if(a[t]==0) break;
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
	while(~scanf("%d%d%d%d",&n,&sn,&tn,&m)){
		memset(map,0,sizeof(map));
		int from,to,w;
		while(m--){
			while(getchar()!='(');
			scanf("%d,%d)%d",&from,&to,&w);
			map[from][to]+=w;
		}
		while(sn--){
			while(getchar()!='(');
			scanf("%d)%d",&to,&w);
			from=n;
			map[from][to]+=w;
		}
		while(tn--){
			while(getchar()!='(');
			scanf("%d)%d",&from,&w);
			to=n+1;
			map[from][to]+=w;
		}
		printf("%d\n",E_K(n,n+1));
	}
	return 0;
}