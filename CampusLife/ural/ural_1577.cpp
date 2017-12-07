/**
 给出两个串A,B <=2000，构造一个新串，使得该新串的子序列是A,B，且长度最短
    求新串的方案数
    显然是最小长度n+m-lcs (?????????????)
dp[i,j]表示以A[i]或者B[j]结尾的串的个数

    如果A[i] = B[j]，则dp[i,j] = dp[i-1,j-1]   因为这时必须匹配A[i],B[j]
    否则，lcs[i-1,j] > lcs[i,j-1] 则dp[i,j] = dp[i-1,j]   这时新串肯定是A[i]结尾，因为取的是dp[i-1,j]
           lcs[i-1,j] < lcs[i,j-1] 则dp[i,j] = dp[i,j-1]      这时新串肯定是B[i-1]结尾
           lcs[i-1,j] = lcs[i,j-1] 则dp[i,j] = dp[i-1,j] +dp[i,j-1]  这时新串可以是A[i]或B[j]结尾，但不会重复，因为尾部不同
    
    坑得，当时比赛时，没想打如果取dp[i-1,j]，自然是以A[i]结尾的！！！
    结尾不同，不会导致重复计数的！！
**/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;
#define maxn 2222
#define mod 1000000007

int lcs[maxn][maxn];
int  dp[maxn][maxn];
char  A[maxn],B[maxn];
int n,m;

int main()
{
	scanf("%s%s",A+1,B+1);
	n=strlen(A+1),m=strlen(B+1);
	for(int i=0;i<=n;i++) dp[i][0]=1;
	for(int i=0;i<=m;i++) dp[0][i]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(A[i]==B[j]){
				lcs[i][j]=lcs[i-1][j-1]+1;
				dp[i][j]=dp[i-1][j-1];
			}
			else if(lcs[i-1][j]>lcs[i][j-1]){
				lcs[i][j]=lcs[i-1][j];
				dp[i][j]=dp[i-1][j];
			}
			else if(lcs[i-1][j]<lcs[i][j-1]){
				lcs[i][j]=lcs[i][j-1];
				dp[i][j]=dp[i][j-1];
			}
			else{
				lcs[i][j]=lcs[i-1][j];//lcs[i-1][j]==lcs[i][j-1]
				dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
			}
		}
	}
	printf("%d\n",dp[n][m]);
	return 0;
}