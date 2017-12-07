#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
#define inf 0x7ffffff
int dp[111],low[111],high[111];
int N,C,a[100005],Maxh;

int main()
{
	scanf("%d%d",&N,&C);
	for(int i=1;i<=N;i++){
		scanf("%d",&a[i]);
		Maxh=max(Maxh,a[i]);
	}
	
	for(int i=0;i<=Maxh;i++){
		if(i<a[1]) 
			dp[i]=inf;
	    else 
			dp[i]=(i-a[1])*(i-a[1]);
	}
	
	int ans=inf;
	for(int i=2;i<=N;i++){
		low[0]=inf;
		for(int j=1;j<=Maxh;j++) 
			low[j] =min(dp[j]-C*j, low[j-1]);
		high[Maxh+1]=inf;
		for(int j=Maxh;j>=1;j--) 
			high[j]=min(dp[j]+C*j,high[j+1]);
		for(int j=0;j<=Maxh;j++){
			if(j<a[i]) 
				dp[j]=inf;
			else 
				dp[j]=min(low[j]+(j-a[i])*(j-a[i])+j*C , high[j]+(j-a[i])*(j-a[i])-j*C);
			if(i==N) ans=min(dp[j],ans);
		}
	}
	printf("%d\n",ans);
	return 0;
}