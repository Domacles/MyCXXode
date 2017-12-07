/********
    思路同：Codeforces Round #260 (Div. 2) C
********/
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int,int> PII;
typedef long long ll;

#define foreach(it,V) for(vector<int>::iterator it=V.begin(); it!=V.end();++it)

#define INF 0x7ffffff
const int maxn = 1e6+1e3;
const double eps= 1e-5;

int dp[maxn], a[maxn], N;
//dp[i] 代表取到i位置为止的最大值
int main()
{
    //freopen("1.in","r",stdin);
    while(~scanf("%d",&N)){
        for(int i=1;i<=N;i++)
            scanf("%d",&a[i]);
        int ans=0;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=N-1;i++){
            if(i==1) dp[i]=a[i];
            else dp[i]=max(dp[i-1],dp[i-2]+a[i]);
        }//dp[i] 代表从1取到i位置为止的最大值，因为是从1开始的，所以，N是一定不能取的
        ans=dp[N-1];
        memset(dp,0,sizeof(dp));
        for(int i=2;i<=N;i++){
            if(i==2) dp[i]=a[i];
            else dp[i]=max(dp[i-1],dp[i-2]+a[i]);
        }//dp[i] 代表从2取到i位置为止的最大值，因为是从2开始的，所以，N是可以取的
        ans=max(dp[N],ans);
        printf("%d\n",ans);
    }
    return 0;
}

