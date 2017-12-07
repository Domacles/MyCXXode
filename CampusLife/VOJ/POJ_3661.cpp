/*****************
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
#define maxn  11000
int N,K,s[maxn],dp[maxn][555];

int main()
{
	scanf("%d%d",&N,&K);
	for(int i=1;i<=N;i++) scanf("%d",&s[i]);
	for(int i=1;i<=N;i++){
		dp[i][0]=dp[i-1][0];
		for(int j=1;j<=K;j++){
			if(j<i) dp[i][0]=max(dp[i][0],dp[i-j][j]);
			//第i分钟前的j分钟用来休息，此时疲劳为0
			dp[i][j]=dp[i-1][j-1]+s[i];
			//第i分钟前的j-1分钟用来跑步，此时疲劳不可能为0
		}
	}
	printf("%d\n",dp[N][0]);
	return 0;
}
*****************/
#include<cstdio>

int N,M,i,j,dist[10005],best[10005];
int main ()
{
    scanf("%d%d",&N,&M);
    for(i=0;i<N;i++)
        scanf("%d",dist+i);
    for(i=0;i<N;i++)
    {
        if(best[i]>best[i+1]) best[i+1]=best[i];
        int sum=best[i],pos=i;
        for(j=0;j<M&&pos<N;j++)
        {
            sum+=dist[i+j];
            pos+=2;//一分钟作为跑步，一分钟作为休息
            if(sum>best[pos]) best[pos]=sum;
        }
    }
    printf("%d\n",best[N]);
}
