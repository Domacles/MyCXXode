/***
建个自动机...只有4种状态的自动机. 0表示没有666且当前没有6, 1表示没有666且当前有一个6, 2表示没有666且当前有两个6, 3表示有666,
 于是可以人肉出转移表trans. 定义f[i][j]为在j状态的字符串后输入i个字符能达到目标的方案数. 初始态是f[0][3] = 1, 转移方程f[i][j] = sigma(f[i-1][trans[j][k]]),
 k为10种转移. 构造答案时先算出位数dig, 再从dig高位往低位一位一位确定就好了.
***/

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
const int NUM = 10;
const int S = 4;

int trans[S][NUM]={
    {0,0,0,0,0,0,1,0,0,0},
    {0,0,0,0,0,0,2,0,0,0},
    {0,0,0,0,0,0,3,0,0,0},
    {3,3,3,3,3,3,3,3,3,3}
};

const int MAXL = 10;

ll dp[MAXL+1][S];

void init()
{
    dp[0][3]=1;
    for(int i=1;i<=MAXL;i++) for(int j=0;j<S;j++)
        for(int k=0;k<NUM;k++){
            dp[i][j]+=dp[i-1][trans[j][k]];
        }//是在原串(即长度为i-1的串)前面+1变成长度为i的串
}

int main()
{
    //freopen("r.txt","r",stdin);
    init();
    int T; scanf("%d",&T);
    for(int t=1;t<=T;t++){
        int N; scanf("%d",&N);

        int len=0;
        for(int i=1;i<=MAXL;i++){
            if(dp[i][0]>=N){
                len=i;break;
            }
        }

        int now=0;
        for(int i=len;i>=1;i--){
            ll cnt=0;
            for(int j=0;j<NUM;j++){
                cnt+=dp[i-1][trans[now][j]];
                if(cnt>=N){
                    printf("%d",j);
                    cnt-=dp[i-1][trans[now][j]];
                    N-=cnt;
                    now=trans[now][j];
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
