/*
POJ 2151
���⣺
ACM�����У���M���⣬T���ӣ�pij��ʾ��i�ӽ����j��ĸ���
�� ÿ�����ٽ��һ���ҹھ������ٽ��N����ĸ��ʡ�

������DP
��dp[i][j][k]��ʾ��i������ǰj�����н��k���ĸ���
��
dp[i][j][k]=dp[i][j-1][k-1]*p[j][k]+dp[i][j-1][k]*(1-p[j][k]);
�ȳ�ʼ�����dp[i][0][0]��dp[i][j][0];
��s[i][k]��ʾ��i����������С�ڵ���k�ĸ���
��s[i][k]=dp[i][M][0]+dp[i][M][1]+``````+dp[i][M][k];

��ÿ������������һ�������ΪP1=(1-s[1][0])*(1-s[2][0])*```(1-s[T][0]);
ÿ������������������1~N-1�ĸ���ΪP2=(s[1][N-1]-s[1][0])*(s[2][N-1]-s[2][0])*```(s[T][N-1]-s[T][0]);

���Ĵ𰸾���P1-P2
*/
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
typedef pair<int,int> PII;
typedef long long ll;

const int maxn =1e6;

double p[1111][33],dp[33][33],S[1111][33];
int M,N,maxt;

int main()
{
    //freopen("r.txt","r",stdin);
    while(~scanf("%d%d%d",&M,&N,&maxt)){
        if(N==0 && M==0) break;
        for(int i=1;i<=N;i++)
            for(int j=1;j<=M;j++)
                scanf("%lf",&p[i][j]);

        for(int i=1;i<=N;i++){
            memset(dp,0,sizeof(dp));
            dp[0][0]=1;
            for(int j=1;j<=M;j++){
                dp[j][0]=dp[j-1][0]*(1-p[i][j]);
                for(int k=1;k<=j;k++)
                    dp[j][k]=dp[j-1][k-1]*p[i][j]+dp[j-1][k]*(1-p[i][j]);
            }
            for(int j=0;j<=M;j++)
                if(j==0) S[i][j]=dp[M][0];
                else S[i][j]=S[i][j-1]+dp[M][j];
        }
        double P1=1,P2=1;
        for(int i=1;i<=N;i++){
            P1*=1-S[i][0];
            P2*=(S[i][maxt-1]-S[i][0]);
        }
        printf("%.3lf\n",P1-P2);
    }
    return 0;
}
