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

int dp[maxn][2];

int main()
{
    //freopen("r.txt","r",stdin);
    int T; scanf("%d",&T);
    for(int t=1;t<=T;t++){
        memset(dp,0,sizeof(dp));
        int N, ans=0; scanf("%d",&N);
        for(int i=1;i<=N;i++){
            int x; scanf("%d",&x);
            if(x==0) dp[i][0]=dp[i][1]=0;
            if(x==2){//dp[i][1]此时必>=1
                dp[i][1]=dp[i-1][1]+1;
                if(dp[i-1][0]) dp[i][0]=dp[i-1][0]+1;
            }
            if(x==-2){//dp[i][0]此时必>=1
                dp[i][0]=dp[i-1][1]+1;
                if(dp[i-1][0]) dp[i][1]=dp[i-1][0]+1;
            }
            ans=max(ans,dp[i][1]);
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
