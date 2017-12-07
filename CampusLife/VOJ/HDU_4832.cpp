/************
    棋盘上的移动，x轴和y轴上的移动是独立的。
    因此，只需要分别算出x,y轴上移动1~k次的种数，然后，x轴移动+y轴移动共K次，
    即K次中选出i次走x轴，
    ans=sigma(C[K][i]*sumx[i]*sumy[K-i])
************/
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
const int mod= 9999991;

int C[1111][1111];  //组合数
int dp[1111][1111];//dp[i][j] 到第j点走了i步的种类数
int sum1[1111];//从起点，在x轴方向走i步的种类数
int sum2[1111];//从起点，在y轴方向走i步的种类数
int N,M,K,x,y;

void init()
{
    for(int i=0;i<=1000;i++){
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
}

void GetSum(int a,int limit,int sum[]){
    memset(dp,0,sizeof(dp));
    dp[0][a]=1;
    for(int i=1;i<=K;i++)
    for(int j=1;j<=limit;j++){
        if(j-1>=1)     dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
        if(j+1<=limit) dp[i][j]=(dp[i][j]+dp[i-1][j+1])%mod;
        if(j-2>=1)     dp[i][j]=(dp[i][j]+dp[i-1][j-2])%mod;
        if(j+2<=limit) dp[i][j]=(dp[i][j]+dp[i-1][j+2])%mod;
    }
    for(int i=0;i<=K;i++)
        for(int j=1;j<=limit;j++)
            sum[i]=(sum[i]+dp[i][j])%mod;
}

int main()
{
    freopen("r.txt","r",stdin);
    init();
    int t=0,T; scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d%d",&N,&M,&K,&x,&y);
        printf("Case #%d:\n",++t);

        memset(sum1,0,sizeof(sum1));
        memset(sum2,0,sizeof(sum2));

        GetSum(x,N,sum1);
        GetSum(y,M,sum2);
        ll ans=0;
        for(int i=0;i<=K;i++){
            ans=ans+((ll)C[K][i]*sum1[i]%mod)*sum2[K-i]%mod;
            ans%=mod;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
