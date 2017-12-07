/************
    �����ϵ��ƶ���x���y���ϵ��ƶ��Ƕ����ġ�
    ��ˣ�ֻ��Ҫ�ֱ����x,y�����ƶ�1~k�ε�������Ȼ��x���ƶ�+y���ƶ���K�Σ�
    ��K����ѡ��i����x�ᣬ
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

int C[1111][1111];  //�����
int dp[1111][1111];//dp[i][j] ����j������i����������
int sum1[1111];//����㣬��x�᷽����i����������
int sum2[1111];//����㣬��y�᷽����i����������
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
