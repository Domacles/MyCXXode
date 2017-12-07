#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;
const int maxn = 3001000;
ll x[5555],y[5555];//注意
int dp[maxn];

int main()
{
	int T;scanf("%d",&T);
	while(T--){
		int n;
		memset(dp,1,sizeof(dp));
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%lld%lld",&x[i],&y[i]);
		dp[x[0]]=0;
		for(int i=1;i<n;i++)
			for(int j=x[i]-1;j>=x[0];j--){
				ll d1=(y[i]-y[0])*(y[i]-y[0]);
				ll d2=(j-x[i])*(j-x[i]),d3=y[i]*y[i];
				if(d1+d2>d3) break;//保证不着地
				dp[2*x[i]-j]=min(dp[2*x[i]-j],dp[j]+1);
			}
		int ans=11000;
        for(int i=x[n-1];i<=2*x[n-1];i++)  
            ans=min(ans,dp[i]);
        if(ans>=11000) ans=-1;  
        printf("%d\n",ans); 
	}
	return 0;
}