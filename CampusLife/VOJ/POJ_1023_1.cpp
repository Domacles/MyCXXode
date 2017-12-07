/***
题目大意：不要小看ACM竞赛的组织者们，他们很不容易的！现在准备举办一场有M（0 < M ≤ 30）个问题，
同时有T（1 < T ≤ 1,000）个队伍参加的竞赛。一场成功的竞赛，需要满足以下的两个条件：
一、任何一个参赛的队伍都至少做出来一个题。
二、取得冠军的队伍至少要做出来N（0 < N ≤ M）个题。
记P(i, j)为队伍i做出问题j的可能性。现在根据这些队伍的参赛经验，给出所有的P(i, j)。
你需要计算一下竞赛是“成功的竞赛”的概率，保留三位小数。
这个题在数学方面还是比较简单的。记
P(A) = P(任何一个队伍都至少做出一个题)
P(B) = P(所有的队伍都做出的题数都属于[1, N - 1])
而答案为P。显然有
P = P(A) - P(B)
所以说求P(A)和P(B)就成为了问题的关键，而这里最直接的方法就是求出任意一个队伍i做出j道题的概率。
记S(i, j, k)为队伍i在前j个题中做出k个题的概率，显然有
S(i, j, 0) = S(i, j - 1, 0) * (1 - P(i, j))
S(i, j, j) = S(i, j - 1, j - 1) * P(i, j)
这是极端的情况——前j个题都会做或者都不会做。对于通常的情况，就要讨论第j个题会不会做：
S(i, j, k) = S(i, j - 1, k) * (1 - P(i, j)) + S(i, j - 1, k - 1) * P(i, j)
之后求P(A)和P(B)就变得简单了，其中“Π”表示求积：
P(A) = Π(1 - S(i, M, 0), 1 ≤ i ≤ T)
P(B) = Π(∑(S(i, M, k), 1 ≤ k ≤ N - 1), 1 ≤ i ≤ T)
然后计算P就可以了。
***/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define maxn 1010
double p[maxn][44];
double dp[44][44];
int N,T,M;

int main()
{
    while(~scanf("%d%d%d",&N,&T,&M))
    {
        if(T==0) break;
        for(int i=1;i<=T;i++)
            for(int j=1;j<=N;j++)
                scanf("%lf",&p[i][j]);
        double p1=1,p2=1;
        for(int i=1;i<=T;i++)
        {
            dp[0][0]=1;
            for(int j=1;j<=N;j++)
            {
                dp[j][0]=dp[j-1][0]*(1-p[i][j]);
                dp[j][j]=dp[j-1][j-1]*p[i][j];
                for(int k=1;k<j;k++)
                    dp[j][k]=dp[j-1][k]*(1-p[i][j])+dp[j-1][k-1]*p[i][j];
            }
            p1*=(1-dp[N][0]);
            double sum=0;
            for(int k=1;k<M;k++)
                sum+=dp[N][k];
            p2*=sum;
        }
        printf("%.3f\n",p1-p2);
    }
    return 0;
}
