/*********************************
	关键：最优解可以不出现新的数字
	dp[i][j]:到第i个数位置非降（升）且第i个数为第j小（大）
	方程：
	dp[i][j]=min(dp[i-1][k]) + abs(a[i]-s[j]) , k=1~n ; //s为排好序的a数组
	空间可优化至一维; min(dp[i-1][k])可在前方记录，时间优化。
*********************************/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
#define maxn 2222
const int INF = 0x7fffffff;
int dp[maxn];
int N,a[maxn],s[maxn],mid[maxn];

bool cmp1(int x,int y) {return x<y;}
bool cmp2(int x,int y) {return x>y;}

int DP()//非降
{
	int val=INF;
	memset(dp,0,sizeof(dp));
	memset(mid,0,sizeof(mid));
	for(int i=0;i<N;i++) for(int j=0;j<N;j++){
		dp[j]=mid[j]+abs(a[i]-s[j]);
		if(j==0) 
			mid[j]=dp[j];
		else 
			mid[j]=min(dp[j],mid[j-1]);
	}
	for(int i=0;i<N;i++) val=min(val,dp[i]);
	return val;
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++) 
		scanf("%d",&a[i]),s[i]=a[i];
	sort(s,s+N,cmp1);
	int ans1=DP();
	sort(s,s+N,cmp2);
	int ans2=DP();
	printf("%d\n",min(ans1,ans2));
	return 0;
}