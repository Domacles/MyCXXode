#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;
#define maxn 220
const int mod=1000000007;
int s1,s2,n;
int a[maxn],dp[2][110000];

int main()
{
	while(~scanf("%d%d%d",&s1,&s2,&n))
	{
		if(s1>s2) swap(s1,s2);
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		int now=0,pre=1;
		
		dp[0][0]=1;
		for(int i=0;i<n;i++)
		{
			swap(now,pre);// 0 1 -> 1 0
			for(int v=0;v<=s1;v++)
			{
				dp[now][v]=dp[pre][v];
				if(v>=a[i]) dp[now][v]=(dp[now][v]+dp[pre][v-a[i]])%mod;
				//第i个广场放上a[i]个人的种数(等于前面i-1个装上v-a[i]个人的种数) + 第i个广场一个人也不放(等于钱i-1个装v个人)
				if(a[i]%2==0&&v>=a[i]/2) dp[now][v]=(dp[now][v]+dp[pre][v-a[i]/2])%mod;//dp+可以放一半
			}
		}
		printf("%d\n",dp[now][s1]);
	}
	return 0;
}