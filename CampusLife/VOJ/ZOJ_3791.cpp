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
const int mod=1000000009;
int C[111][111];
void init()
{
    for(int i=0;i<=100;i++){
        C[i][i]=C[i][0]=1;
        for(int j=1;j<i;j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
}

ll dp[111][111];
int N,K,M;

int main()
{
    //freopen("r.txt","r",stdin);
    init();
    while(~scanf("%d%d%d",&N,&K,&M)){
        char str1[111],str2[111];
        scanf("%s%s",str1,str2);
        int S=0;
        for(int i=0;i<N;i++)
            if(str1[i]!=str2[i]) S++;
        memset(dp,0,sizeof(dp));
        dp[0][S]=1;
        for(int i=0;i<K;i++){
            for(int j=0;j<=N;j++){
                if(!dp[i][j]) continue;
                for(int k=0;k<=M && k<=j;k++){
                    if(M-k>N-j) continue;
                    if(j+M-2*k<0 || j+M-2*k>N) continue;
                    ll temp=(ll)C[j][k]*(ll)C[N-j][M-k]%mod;
                    dp[i+1][j+M-2*k]=dp[i+1][j+M-2*k]%mod+temp*dp[i][j]%mod;
                    dp[i+1][j+M-2*k]%=mod;
                }
            }
        }
        printf("%lld\n",dp[K][0]);
    }
    return 0;
}
