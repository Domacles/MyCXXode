/**
	DP + DFS with fingers . 
**/
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int maxn =111; 

int N,K,a[maxn][maxn];
int  dp[maxn][maxn];

int DFS(int r,int c)
{
	int r1,c1,Max=0;
	if(dp[r][c]!=-1) return dp[r][c];
	for(int i=1;i<=K;i++){
		r1=r-i;
		if(r1>=1&&r1<=N&&a[r1][c]>a[r][c])
			Max = max(Max , DFS(r1,c));
		r1=r+i;
		if(r1>=1&&r1<=N&&a[r1][c]>a[r][c])
			Max = max(Max , DFS(r1,c));
		c1=c-i;
		if(c1>=1&&c1<=N&&a[r][c1]>a[r][c])
			Max = max(Max , DFS(r,c1));
		c1=c+i;
		if(c1>=1&&c1<=N&&a[r][c1]>a[r][c])
			Max = max(Max , DFS(r,c1));
	}
	dp[r][c]=Max+a[r][c];
	return dp[r][c];
}

int main()
{
	while(~scanf("%d%d",&N,&K)&&N!=-1)
	{
		memset(a,0,sizeof(a)),memset(dp,-1,sizeof(dp));
		for(int i=1;i<=N;i++) 	for(int j=1;j<=N;j++)
			scanf("%d",&a[i][j]);
		printf("%d\n",DFS(1,1));
	}
	return 0;
}