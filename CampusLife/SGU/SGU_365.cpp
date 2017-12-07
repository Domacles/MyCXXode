/*****
	数位统计
*****/
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
ll  dp[22][11];
int N;

int main()
{
    //freopen("r.txt","r",stdin);
    cin>>N;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<10;i++)
        dp[1][i]=1;
    dp[0][0]=1;
    for(int i=1;i<N;i++)
        for(int j=0;j<10;j++){
            if(!dp[i][j]) continue;
        for(int k=j;k<10;k++)
            dp[i+1][k]+=dp[i][j];
    }
    ll ans=1;
    for(int i=0;i<=N;i++){
        int first=i,second=N-i;
        for(int j=0;j<10;j++)
            for(int k=j-1;k>=0;k--)//必须是k<j,否则会算重
            ans+=dp[first][k]*dp[second][j];
    }
    cout<<ans<<endl;
    return 0;
}
