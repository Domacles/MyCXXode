#include <cstdio>
#include <queue>
#include <vector>
#include <stack>
#include <cstring>
#include <utility>
#include <iostream>
#include <cmath>

using namespace std;
#define maxn 3222
const int INF = 0x3fffffff;

char s[maxn];
int N,M,cost[33];
int dp[maxn][maxn];

int main()
{
	scanf("%d%d%s",&M,&N,s);
	for(int i=0;i<M;i++){
		char str[4];
		int x,y;
		scanf("%s%d%d",str,&x,&y);
		cost[str[0]-'a']=min(x,y);
	}
	
	for(int len=1;len<N;len++)
		for(int l=0;l+len<N;l++){
			int r=l+len;
			dp[l][r]=min( dp[l+1][r]+cost[s[l]-'a'] , dp[l][r-1]+cost[s[r]-'a']);
			if(s[l]==s[r])
				dp[l][r]=min(dp[l][r],dp[l+1][r-1]);
		}
	printf("%d\n",dp[0][N-1]);
	return 0;
}