#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
 
int cnt, stk[150];
long long dp[15][2050];
 
bool ok(int n, int x){//1表示竖着放，0表示横着放，则0的话至少在同一行应该成对出现，比如11011，01100就是不合理的
    int i = 0;
    while(i < n){
        if(x & (1<<i)) i ++;
        else{
            if(x & (1<<(i+1))) return 0;
            if(i == n-1) return 0;
            i += 2;
        }
    }
    return 1;
}
 
void findStk(int n){
    for(int i = 0; i < (1<<n); i ++)
        if(ok(n, i))
            stk[cnt ++] = i;
}
 
int main(){
    int row, col, r, i, k;
    while(cin >> row >> col && row){
        if(row * col == 3){
            cout << 0 << endl; continue;
        }
        memset(dp, 0, sizeof(dp));
        cnt = 0;       
        findStk(col);
        for(i = 0; i < cnt; i ++)
            dp[0][stk[i]] = 1;
        for(r = 1; r < row; r ++)
            for(i = 0; i < cnt; i ++){
                for(k = 0; k < (1<<col); k ++){//上一行相同位置为1，本行必须为1，上一行为0，本行可以为0也可以为1
                    if((stk[i] & k) != k) continue;
                    dp[r][stk[i]^k] += dp[r-1][k];
                }
            }
        printf("%lld\n", dp[row-1][0]);
    }
    return 0;
}