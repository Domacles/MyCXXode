/****
	Õÿ∆À≈≈–Ú
****/
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

#define maxN 110
struct node{
	int v,next;
}po[4*maxN*maxN];
int num,head[maxN];
int q[maxN],indeg[maxN];

void insert(int u,int v)
{
	po[num].v=v;
	po[num].next=head[u];
	head[u]=num++;
}
void topsort(int n)
{
	int hd=0,tail=0;
	for(int i=1;i<=n;i++)
		if(indeg[i]==0)
			q[hd++]=i;
	while(hd!=tail)
	{
		int u=q[tail++];
		for(int i=head[u];i!=-1;i=po[i].next)
		{
			int v=po[i].v;
			indeg[v]--;
			if(indeg[v]==0)q[hd++]=v;
		}
	}
}

int main()
{
	freopen("1.txt","r",stdin);
	int n,m,v;
	while(~scanf("%d",&n))
	{
		memset(head,-1,sizeof(head));
		memset(indeg,0,sizeof(indeg));
		num=0;
		for(int i=1;i<=n;i++)
			while(scanf("%d",&v)&&v)
			{
				insert(i,v);
				indeg[v]++;
			}
		topsort(n);
		for(int i=0;i<n;i++)
			printf("%d ",q[i]);
		printf("\n");
	}
}