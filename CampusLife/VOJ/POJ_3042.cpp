/**
dp[1][N][L..R]
第一个走的距离，会被计算n次，第二个走的距离，会被计算n-1次
**/
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#include <stack>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;
#define maxn 1111
const int L=0,R=1;
int dp[maxn][maxn][2];
int a[maxn],N,X;

int main()
{
	scanf("%d%d",&N,&X);
	for(int i=1;i<=N;i++)scanf("%d",&a[i]);
	N++;a[N]=X;
	sort(a+1,a+1+N);
	int st,StepSum=N-1;//start
	for(int i=1;i<=N;i++)
		if(a[i]==X) st=i;
	memset(dp,50,sizeof(dp));//[init !!!!]
	dp[st][st][L]=dp[st][st][R]=0;
	for(int step=0;step<N-1;step++)//移动次数
		for(int i=max(1,st-step);i<=min(N,st+step);i++){
			dp[i-1][i+step][L]=min( dp[i][i+step][L]+(a[i]-a[i-1])*(StepSum-step),//N为原N+1
									dp[i][i+step][R]+(a[i+step]-a[i-1])*(StepSum-step));
			dp[i][i+step+1][R]=min( dp[i][i+step][L]+(a[i+step+1]-a[i])*(StepSum-step), //N为原N+1
									dp[i][i+step][R]+(a[i+step+1]-a[i+step])*(StepSum-step));
	}
	printf("%d\n",min(dp[1][N][L],dp[1][N][R]));
	return 0;
}