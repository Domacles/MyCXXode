/*
POJ 2151
题意：
ACM比赛中，共M道题，T个队，pij表示第i队解出第j题的概率
问 每队至少解出一题且冠军队至少解出N道题的概率。

解析：DP
设dp[i][j][k]表示第i个队在前j道题中解出k道的概率
则：
dp[i][j][k]=dp[i][j-1][k-1]*p[j][k]+dp[i][j-1][k]*(1-p[j][k]);
先初始化算出dp[i][0][0]和dp[i][j][0];
设s[i][k]表示第i队做出的题小于等于k的概率
则s[i][k]=dp[i][M][0]+dp[i][M][1]+``````+dp[i][M][k];

则每个队至少做出一道题概率为P1=(1-s[1][0])*(1-s[2][0])*```(1-s[T][0]);
每个队做出的题数都在1~N-1的概率为P2=(s[1][N-1]-s[1][0])*(s[2][N-1]-s[2][0])*```(s[T][N-1]-s[T][0]);

最后的答案就是P1-P2
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
