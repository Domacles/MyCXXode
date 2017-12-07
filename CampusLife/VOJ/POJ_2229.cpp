/****
1. n为奇数，则肯定其中有1的组成，所以dp[n] = dp[n-1]
2. n为偶数，根据1的存在划分为2种情况：
   a, 有1的组成，则肯定有2个1，dp[n]的一部分是dp[n-2]
   b, 没有1的组成，这时候如果把组成的每个数都除以2，则dp[n]的另一部分就变成dp[n/2]
****/
#include <cstdio>
#include <iostream>

using namespace std;
#define maxn   1100000
#define mod 1000000000
typedef long long ll;
ll dp[maxn];

int main()
{	
	int N; cin>>N;
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=N;i++){
		if(i&1) dp[i]=dp[i-1];
		else
			dp[i]=(dp[i-2]+dp[i>>1])%mod;
	}
	cout<<dp[N]<<endl;
	return 0;
}