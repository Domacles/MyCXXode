/****
	差分约束系统
 	s[i]-s[i-1]>=0     (s[i]表示从0时刻到i时刻一共雇佣的人数)
    s[i-1]-s[i]>=-t[i]
    s[23]-s[-1]>=sum
    s[i]-s[j]=r[i]     (i>j ,i=(j+8-1)%24+1)
    s[i]-s[j]=r[i]-sum (i<j, i=(j+8-1)%24+1
****/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define maxn 25

struct Edge
{
	int to;
	int val;
	int next;
}edge[maxn*100];
int num,head[maxn];
int dis[maxn];
int r[maxn],t[maxn],sum;
int n;

void init()
{
	memset(t,0,sizeof(t));
}

void AddEdge(int from,int to,int w)
{
	edge[num].to=to,edge[num].val=w;
	edge[num].next=head[from];
	head[from]=num++;
}

void Add()
{
	num=0;
	memset(head,-1,sizeof(head));
	for(int i=1;i<=24;i++)
	{
		AddEdge(i-1,i,0);
		AddEdge(i,i-1,-t[i]);
	}
	AddEdge(0,24,sum);
	for (int i=1;i<=16;i++)
        AddEdge(i,i+8,r[i+8]);
    for (int i=1;i<=8;i++)
        AddEdge(i+16,i,r[i]-sum);
}

bool SPFA()
{
	queue<int>q;
	int vis[maxn]={0},count[maxn]={0};
	for(int i=1;i<=24;i++) 
		dis[i]=-1000000000;
	dis[0]=0;
	q.push(0);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[u];i!=-1;i=edge[i].next)
		{
			int v=edge[i].to;
			int val=edge[i].val;
			if(dis[v]<dis[u]+val)
			{
				dis[v]=dis[u]+val;
				if(!vis[v])
				{
					vis[v]=1,q.push(v),count[v]++;
					if(count[v]>25)	return 0;
				}
			}
		}
	}
	if(dis[24]==sum) return 1;
	else return 0;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		init();
		for(int i=1;i<=24;i++) scanf("%d",&r[i]);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int time;
			scanf("%d",&time);
			t[time+1]++;
		}
		for(sum=0;sum<=n;sum++)
		{
			Add();
			if(SPFA()) break;
		}
		if(sum<=n) printf("%d\n",sum);
		else printf("No Solution\n");
	}
	return 0;
}