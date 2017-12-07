#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;
const int ZERO=1000;
int dp[ZERO+1001],a[111],b[111],c[111],n,K;
//和式   SUM_0<=i<=m_(Ai-Bi*k)=0
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>K;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) c[i]=a[i]-b[i]*K;
	memset(dp,-1,sizeof(dp));
	dp[ZERO]=0;
	for(int i=1;i<=n;i++)
	{
		if(c[i]<0){
			for(int k=0;k<=2000;k++)//取决该物品的size的正负
				if(c[i]+k>=0&&c[i]+k<=2000&&dp[k]!=-1)
					dp[c[i]+k]=max(dp[c[i]+k],dp[k]+a[i]);
		}
		else{
			for(int k=2000;k>=0;k--)//取决该物品的size的正负
				if(c[i]+k>=0&&c[i]+k<=2000&&dp[k]!=-1)
					dp[c[i]+k]=max(dp[c[i]+k],dp[k]+a[i]);
		}
	}
	if(dp[ZERO]<=0) cout<<"-1"<<endl;
	else cout<<dp[ZERO]<<endl;
	return 0;
}