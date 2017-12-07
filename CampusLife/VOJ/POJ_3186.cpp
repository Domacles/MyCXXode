#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>
#include <iostream>

using namespace std;
#define maxn 2222

typedef long long LL;
typedef pair<int,int> P;
const int INF = 0x3fffffff;
int dp[maxn][maxn],N,sum[maxn];
//dp[i][j]表示卖从i到j的东西的最大值
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		int x; scanf("%d",&x);
		sum[i]=sum[i-1]+x;
	}
	for(int k=0;k<=N;k++)
		for(int i=1;i<=N;i++){
			int j=i+k;
			if(i==j) dp[i][j]=sum[j]-sum[i-1];
			else 
				if(i<j)
					 dp[i][j]=max(dp[i+1][j],dp[i][j-1])+sum[j]-sum[i-1];
	}//无论是选择从[i+1,j]还是[i,j-1],sum[i+1,j-1]都要增加一次因为天数增加了
	printf("%d\n",dp[1][N]);
	return 0;
}