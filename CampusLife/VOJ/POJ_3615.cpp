#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;
#define inf 0x7fffffff
#define maxn 1100
typedef long long ll;
int G[333][333];
int N,M,T;

void init()
{
	for(int i=0;i<=300;i++)
		for(int j=0;j<=300;j++)
			G[i][j]=inf;
}

void Floyd()
{
	for(int k=1;k<=N;k++)
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++){
				int temp=max(G[i][k],G[k][j]);
				G[i][j]=min(temp,G[i][j]);
			}
}

int main()
{	
	init();
	scanf("%d%d%d",&N,&M,&T);
	for(int i=0;i<M;i++){
		int x,y,h;
		scanf("%d%d%d",&x,&y,&h);
		G[x][y]=h;
	}
	Floyd();
	for(int i=0;i<T;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(G[x][y]==inf) printf("-1\n");
		else printf("%d\n",G[x][y]);
	}
	return 0;
}