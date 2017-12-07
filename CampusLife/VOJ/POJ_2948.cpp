#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;
const int maxn=555;

int N,M,a[maxn][maxn],b[maxn][maxn];
int dp[maxn][maxn];
int sumA[maxn][maxn],sumB[maxn][maxn];

void init()
{
	memset(dp,0,sizeof(dp));
	memset(sumA,0,sizeof(sumA));
	memset(sumB,0,sizeof(sumB));
}

int main()
{
	while(~scanf("%d%d",&N,&M)&&N&&M){
		init();
		for(int i=N;i>0;i--) for(int j=M;j>0;j--)//从右下角作为起始点，向左有效
			scanf("%d",&a[i][j]);
		for(int i=N;i>0;i--) for(int j=M;j>0;j--)//从右下角作为起始点，向上有效
			scanf("%d",&b[i][j]);
		for(int i=1;i<=N;i++) for(int j=1;j<=M;j++)//从右下角作为起始点
			sumA[i][j]=sumA[i-1][j]+a[i][j],
			sumB[i][j]=sumB[i][j-1]+b[i][j];
	/*以包含右下角的矩形为单位进行考虑，若矩形左上角第i行第j列取向左，
										则第i行（到当前位置为止）都向左，
		sumA[i][j]为第j列从1行到第i行的和；
		若向上，
										则第j列（到当前位置为止）都向上，
		sumB[i][j]为第i行从1列到第j列的和。
	*/
		for(int i=1;i<=N;i++) for(int j=1;j<=M;j++)//从右下角作为起始点
			dp[i][j]=max(dp[i][j-1]+sumA[i][j] , dp[i-1][j]+sumB[i][j]);
		printf("%d\n",dp[N][M]);
	}
	return 0;
}