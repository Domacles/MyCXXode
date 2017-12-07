/****
	DP + CountNum
****/
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 13;

int len,bit[maxn],dp[maxn][maxn];

int abs(int X){
	if(X<0) X*=-1;
	return X;
}

int dfs(int now)
{
	if(now==0) return 0;
	int ans=0;
	for(int i=bit[now-1]+1;i<=9;i++)
		if(abs(bit[now]-i)>=2)
			ans+=dp[now-1][i];
	if(abs(bit[now-1]-bit[now])>=2)
		ans+=dfs(now-1);
	return ans;
}

int NumDp(int X)
{
	if(X<=9) return X;
	while(X){
		bit[len++]=X%10;
		X/=10;
	}
	for(int i=0;i<=9;i++) dp[0][i]=1;
	for(int i=1;i<len;i++)
		for(int j=0;j<=9;j++){
			dp[i][j]=0;
			for(int k=0;k<=9;k++)
				if(abs(j-k)>=2) dp[i][j]+=dp[i-1][k];
		}
	int ans=0;
	for(int i=0;i<len-1;i++)
		for(int j=1;j<=9;j++)
			ans+=dp[i][j];
	for(int i=1;i<=bit[len-1];i++)
		ans+=dp[len-1][i];
	ans-=dfs(len-1);//减掉大于X的
	return ans;
}

int main()
{
	//freopen("r1.txt","r",stdin);
	int A,B;
	scanf("%d%d",&A,&B);
	printf("%d\n",NumDp(B)-NumDp(A-1));
	return 0;
}

/*

*/