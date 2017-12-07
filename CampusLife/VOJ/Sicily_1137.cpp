#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int a[33000],dp[33000][101];//dp[i][j]表示从i往前，落差为j最多的个数

int ABS(int x)
{
	if(x<0) return -x;
	else return x;
}

int main()
{
	int n,m;
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	while(~scanf("%d%d",&n,&m))
	{
		int ans=1;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		
		dp[1][0]=1;
		for(int i=2;i<=n;i++)
		{
			for(int j=0;j<=m;j++)
			{ 
				int x=j-( a[i]-a[i-1]);//用于求出i-1的落差下限，下限即为(a[i-1]-x==a[i]-j).
				if(x>=0&&x<=m) dp[i][j]=dp[i-1][x]+1;
				else dp[i][j]=1;
				if(dp[i][j]>ans) ans=dp[i][j];
			}
		}
		for(int i=1;i<=n;i++) for(int j=0;j<=m;j++)
			printf("dp[%d][%d]=%d%s",i,j,dp[i][j],j<m?",  ":"\n");
			
		printf("%d\n",ans);
	}
	return 0;
}