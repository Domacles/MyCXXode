HDU 3853

/*
HDU 3853

解析：
设dp[i][j]表示(i,j)到(R,C)需要消耗的能量
则：
dp[i][j]=p1[i][j]*dp[i][j]+p2[i][j]*dp[i][j+1]+p3[i][j]*dp[i+1][j]+2;
化简得到：
dp[i][j]=p2[i][j]*dp[i][j+1]/(1-p1[i][j])+p3[i][j]*dp[i+1][j]/(1-p1[i][j])+2/(1-p1[i][j]);
注意一种情况就是p1[i][j]==1的情况。
题目只是保证答案小于1000000.但是有的点可能永远都不可能到达的。
所以这样的点出现p1[i][j]是允许的。
否则就会WA了。
*/
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
const int MAXN=1010;
const double eps=1e-5;
double dp[MAXN][MAXN];
double p1[MAXN][MAXN];
double p2[MAXN][MAXN];
double p3[MAXN][MAXN];

int main()
{
    int R,C;
    while(scanf("%d%d",&R,&C)!=EOF)
    {
        for(int i=1;i<=R;i++)
          for(int j=1;j<=C;j++)
            scanf("%lf%lf%lf",&p1[i][j],&p2[i][j],&p3[i][j]);
        dp[R][C]=0;
        for(int i=R;i>=1;i--)
          for(int j=C;j>=1;j--)
          {
              if(i==R&&j==C)continue;
              if(fabs(1-p1[i][j])<eps)continue;
              dp[i][j]=p2[i][j]/(1-p1[i][j])*dp[i][j+1]+p3[i][j]/(1-p1[i][j])*dp[i+1][j]+2/(1-p1[i][j]);
          }
        printf("%.3lf\n",dp[1][1]);
    }
    return 0;
}
