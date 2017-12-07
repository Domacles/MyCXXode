/*******
设dp[i][j]为有白老鼠i只，黑老鼠j只时轮到公主取时，公主赢的概率。
那么当i = 0 时，为0
当j = 0时，为1
公主可直接取出白老鼠一只赢的概率为i/(i+j)
公主取出了黑老鼠，龙必然也要取出黑老鼠公主才能赢，跑出来的老鼠有两种可能
跑出来的是黑老鼠，公主赢的概率为dp[i][j] += j/（i+j）*（j-1）/(i+j-1)*(j-2)/(i+j-2)*dp[i][j-3].（j>=3）
跑出来的是白老鼠，公主赢的概率为dp[i][j] += j/（i+j）*（j-1）/(i+j-1)*i/(i+j-2)*dp[i-1][j-2].（j>=2)
*******/
#include <cstdio>

#define N 1005
double dp[N][N];
int main()
{
//    freopen("in.c","r",stdin);
    int w,b;
    scanf("%d%d",&w,&b);
    for(int i=0; i<=w; ++i) dp[i][0] =1;
    for(int i=0; i<=b; ++i) dp[0][i] =0;
    for(int i=1; i<=w; ++i)
    {
        for(int j=1; j<=b; ++j)
        {
            dp[i][j] = (double)i/(i+j);
            if(j >= 3) dp[i][j] += (double)j/(i+j)*(double)(j-1)/(i+j-1)*(double)(j-2)/(i+j-2)*dp[i][j-3];
            if(j >= 2) dp[i][j] += (double)j/(i+j)*(double)(j-1)/(i+j-1)*(double)i/(i+j-2)*dp[i-1][j-2];
        }
    }
    printf("%.9lf\n",dp[w][b]);
    return 0;
}