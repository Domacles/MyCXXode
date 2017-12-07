#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 55000; 
int M, N, t[maxn][11], dp[11][maxn];

int main()
{
    //freopen("r1.txt","r",stdin);
    scanf("%d%d",&M,&N);
    for(int i=1;i<=M;i++)
        for(int j=1;j<=N;j++)
                scanf("%d",&t[i][j]);
    for(int i=1;i<=M;i++)
        dp[1][i] = dp[1][i-1] + t[i][1];
    for(int i=2;i<=N;i++)
        for(int j=1;j<=M;j++){
        	if(j==1)//题意： 1号作品前面不需要前提
            	dp[i][j] = dp[i-1][j] + t[j][i];
            else//其他是需要的
            	dp[i][j] = max(dp[i][j-1],dp[i-1][j]) + t[j][i];
        }
    for(int i=1;i<=M;i++)
        printf("%d ",dp[N][i]);
    return 0;
}