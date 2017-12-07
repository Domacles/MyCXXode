#include <cstdio>
#include <iostream>

using namespace std;
/***
	D:喂兔子问题,要喂一串兔子(喂完之后吃掉),每个兔子有且仅喂一次.....
	已知,兔子好吃与否与左右两边的兔子是否喂饱有关.
	input
	兔子的个数,
	每只兔子两边的兔子都没喂的情况下,兔子的好吃度;
	每只兔子两边的兔子恰有一只被喂的情况下,兔子的好吃度;
	每只兔子两边的兔子都被喂了的情况下,兔子的好吃度;
	output
	Max好吃度
***/
int s[3][3333];
int dp[2][3333];
int n;
const int a=0,b=1,c=2;
//a b c 在好吃度s集合中,表示两边有0 ,1 ,2 只被喂....
/*a b   在dp[a|b][i]集合中,表示喂的先后顺序:
		a:  先喂的是i,后喂的是i-1.
		b:  先喂的是i-1,后喂的是i.
*/
int main()
{	
	scanf("%d",&n);
	for(int i=0;i<3;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&s[i][j]);
	dp[a][n]=s[a][n];
	dp[b][n]=s[b][n];
	for(int i=n-1;i>=1;i--)
	{//每次转移时,只需要考虑i是否在i+1前被喂
		dp[a][i]=max(dp[b][i+1]+s[a][i],dp[a][i+1]+s[b][i]);
		dp[b][i]=max(dp[b][i+1]+s[b][i],dp[a][i+1]+s[c][i]);
	}
	printf("%d\n",dp[a][1]);
	return 0;
}