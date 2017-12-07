HDU 3853

/*
HDU 3853

������
��dp[i][j]��ʾ(i,j)��(R,C)��Ҫ���ĵ�����
��
dp[i][j]=p1[i][j]*dp[i][j]+p2[i][j]*dp[i][j+1]+p3[i][j]*dp[i+1][j]+2;
����õ���
dp[i][j]=p2[i][j]*dp[i][j+1]/(1-p1[i][j])+p3[i][j]*dp[i+1][j]/(1-p1[i][j])+2/(1-p1[i][j]);
ע��һ���������p1[i][j]==1�������
��Ŀֻ�Ǳ�֤��С��1000000.�����еĵ������Զ�������ܵ���ġ�
���������ĵ����p1[i][j]������ġ�
����ͻ�WA�ˡ�
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
