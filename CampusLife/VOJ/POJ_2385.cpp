///dp[i][j]表示第i个苹果掉下的时候，走了j次收到的最多苹果。
///dp[i][j] = max{dp[i-1][j-1],dp[i-1][j]} + （Ti == 当前位置）? 1 : 0
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[1001][31];//dp[i][j]表示第i个苹果掉下的时候，走了j次收到的最多苹果。（可能最优解不用j次）
int P[31];
int T[1001];
int maxT, maxW;

int main()
{
    for(int i=0;i<31;i++) P[i]=((i%2==0)?1:2);
    cin>>maxT>>maxW;
    for(int i=1;i<=maxT;i++)
    {
        cin>>T[i];
        dp[i][0]=dp[i-1][0]+(T[i]==P[0]?1:0);
    }
    for(int j = 1;j<=maxW;j++)
        for(int i=1;i<=maxT;i++)
            dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+(T[i]==P[j]?1:0);

    cout<<dp[maxT][maxW]<<endl;
    return 0;
}

