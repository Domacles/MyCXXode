/*********
    题目要求一个从最大的从左下到右上的最大的矩阵，
    因此，设状态dp[i][j]为以(i,j)为左下角的最大符合要求的矩阵规模，
    则，
        假如我们在求dp[i+1][j-1]时，
            如果通过简单匹配发现(i+1,j-1)向上和向右的匹配长度大于dp[i][j]+1，
            则我们可以得到以(i+1,j-1)为左下角的新矩阵，但受到以(i,j)为左下角的最大符合要求的矩阵所限，
            规模只是dp[i][j]+1的；
            但(i+1,j-1)向上和向右的匹配长度小于dp[i][j]+1，则以(i+1,j-1)为左下角的新矩阵的规模
            只能是向上和向右的匹配长度。
        转移方程既得。

*********/
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

int N, dp[1111][1111];
char s[1111][1111];

int main()
{
    freopen("r.txt","r",stdin);
    while(~scanf("%d",&N) && N){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=N;i++) scanf("%s",s[i]+1);

        int ans=0;
        for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++){
            int up=i, right=j, t=0;
            while(up>=1 && right<=N && s[up][j]==s[i][right])
                t++, up--, right++;
            if(t>=dp[i-1][j+1]+1) dp[i][j]=dp[i-1][j+1]+1;
            else dp[i][j]=t;
            ans=max(ans,dp[i][j]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
