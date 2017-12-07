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
//dp[i][k] : 第i支队伍赢了k场的概率
double dp[1<<8][11],p[1<<8][1<<8];
int n,N;
bool vis[1<<8][1<<8];

int main()
{
    //freopen("r.txt","r",stdin);
    while(~scanf("%d",&n) && n!=-1){
        N=1<<n;
        memset(vis,0,sizeof(vis));
        memset(dp,0,sizeof(dp));
        memset(p,0,sizeof(p));

        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                scanf("%lf",&p[i][j]);

        for(int i=1;i<=N;i++) dp[i][0]=1;
        for(int L=1;L<=n;L++){
            int len=1<<L;
            for(int i=1;i<=N;i++)
                for(int j=1;j<=N;j++){
                    if(i==j) continue;
                    if((i-1)/len==(j-1)/len && !vis[i][j]){
                        vis[i][j]=1;
                        dp[i][L]+=dp[i][L-1]*dp[j][L-1]*p[i][j];
                    }
                }
        }
        int pos=1;
        for(int i=1;i<=N;i++)
            if(dp[i][n]>dp[pos][n])
                pos=i;
        printf("%d\n",pos);
    }
    return 0;
}
