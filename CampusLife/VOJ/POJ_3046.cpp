//思路： dp [i] [j] :=前i种 构成个数为j的方法数。
#include <cstdio>
#include <cstring>
#include <iostream>
int T,A,S,B;
int hash[1010];
int dp[1010][10100];

const int MOD=1e6;
using namespace std;
int main(){

    while(cin>>T>>A>>S>>B){
        memset(hash,0,sizeof(hash));
        for(int i = 1; i <= A; i++){
            int u;
            cin>>u;
            hash[u]++;
        }
        memset(dp,0,sizeof(dp));
        for(int i = 0; i <= hash[1]; i++) dp[1][i] = 1;//第一种取1~k
        for(int i = 2; i <= T; i++)
            for(int j = 0; j <= B; j ++){
                for(int k = 0; k <= hash[i]; k++)
                    if(j >= k) {
                        dp[i][j] += dp[i-1][j-k];
                        dp[i][j] %= MOD;
                    }else break;
            }
        int sum = 0;
        for(int i = S; i <= B; i++){
            sum+= dp[T][i];
            sum %= MOD;
        }
       cout<<sum<<endl;
    }
    return 0;
}
