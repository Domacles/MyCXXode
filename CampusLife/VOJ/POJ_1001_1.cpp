/****
	差分约束系统
****/
#include<cstdio>
#include<queue>
#include<vector>
#include<iostream>

using namespace std;

#define maxn  55000

int low=maxn,high=0;
int vis[maxn];
int dis[maxn];
struct Edge
{
	int to,len;
}Temp;
vector<Edge>Map[maxn];

void SPFA()
{
	for(int i=0;i<maxn;i++) dis[i]=-maxn;
	queue<int>q;
	dis[low]=0;
	vis[low]=1;
	q.push(low);
	while(!q.empty())
	{
		int u=q.front();
		vis[u]=0;
		q.pop();
		int num=Map[u].size();
		for(int i=0;i<num;i++)
		{
			int v=Map[u][i].to;
			if(dis[u]+Map[u][i].len>dis[v])
			{
				dis[v]=dis[u]+Map[u][i].len;
				if(!vis[v]) vis[v]=1,q.push(v);
			}
		}
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int l,r,c;
		scanf("%d%d%d",&l,&r,&c);
		if(l<low) low=l;
		if(r+1>high)high=r+1;
		Temp.to=r+1,Temp.len=c;
		Map[l].push_back(Temp);
	}
	for(int i=low;i<=high;i++)
	{
		Temp.to=i+1,Temp.len=0;
		Map[i].push_back(Temp);
		Temp.to=i,Temp.len=-1;
		Map[i+1].push_back(Temp);
	}
	SPFA();
	printf("%d\n",dis[high]);
	return 0;
}