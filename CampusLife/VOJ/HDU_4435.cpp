#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<cmath>  
#include<map>  
#include<queue>  
#include<stack>  
#include<vector>  
#include<set>  
#include<cctype>  
#include<algorithm>  
#include<string>  

using namespace std;// using ceil function
#define maxn 138
struct Node
{
	int x,y;
}p[maxn];
int n,D,TD;
bool val[maxn];
int dis[maxn][maxn];

int Dis(Node a,Node b)
{
	return ceil(sqrt((double)((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))));
}

bool BFS(int x)
{
	int vis[maxn]={0};
	queue<int>q;
	int num=1;
	while(!q.empty()) q.pop(); 
	
	vis[x]=1,q.push(x);
	
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int v=1;v<=n;v++)
		{
			if(vis[v]||!val[u]) continue;
			if(val[v])
			{
				if(dis[u][v]<=D)
					vis[v]=1,num++,q.push(v);
			}
			else
			{
				if(dis[u][v]<=TD)
					vis[v]=1,num++,q.push(v);
			}
		}
	}
	if(num==n) return 1;
	return 0;
}

void init()
{
	memset(p,0,sizeof(p));
	for(int i=1;i<=n;i++) scanf("%d%d",&p[i].x,&p[i].y);
	
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=i;j++)
			dis[j][i]=dis[i][j]=Dis(p[i],p[j]);
	
	TD=D/2;
}

void deal()
{
	for(int i=1;i<=n;i++) val[i]=1; // 初始化，认为每个城市都有加油站   
	int OK=BFS(1);
	if(!OK)
	{
		puts("-1");
		return ;
	}
	
	for(int i=n;i>=2;i--)
	{
		val[i]=0;
		if(!BFS(1)) val[i]=1;//printf("%d is ok!\n",i);
	}
	
	int first=0;
	for(int i=n;i>=1;i--)
	{	
		if(val[i]) first=1;
		if(first) printf("%d",val[i]);
	}
		
	printf("\n");
}

int main()
{
	while(~scanf("%d%d",&n,&D))
	{
		init();
		deal();
	}
	return 0;
}