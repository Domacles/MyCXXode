/****
    ÆÚÍû,  st = dp[n][s]
           ed = dp[0][0]
****/
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

int N,S;
double dp[1111][1111];

int main()
{
    freopen("r.txt","r",stdin);
    while(~scanf("%d%d",&N,&S)){
        memset(dp,0,sizeof(dp));
        dp[N][S]=0;
        for(int i=N;i>=0;i--)
        for(int j=S;j>=0;j--){
//dp[i,j] = p1*dp[i,j] + p2*dp[i+1,j] + p3*dp[i,j+1] + p4*dp[i+1,j+1] + 1 --->
            if(i==N && j==S) continue;
            double p1=1.0*i*j/(N*S);
            double p2=1.0*(N-i)*j/(N*S);
            double p3=1.0*i*(S-j)/(N*S);
            double p4=1.0*(N-i)*(S-j)/(N*S);
            dp[i][j]=(p2*dp[i+1][j]+p3*dp[i][j+1]+p4*dp[i+1][j+1]+1.0)/(1.0-p1);
        }
        printf("%.4f\n",dp[0][0]);
    }
    return 0;
}
