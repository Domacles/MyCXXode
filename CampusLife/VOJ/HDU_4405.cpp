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
const double eps = 1e-8;

double dp[maxn];
int N,M,f[maxn],vis[maxn];

int main()
{
    //freopen("r.txt","r",stdin);
    while(~scanf("%d%d",&N,&M)){
        if(N==0 && M==0) break;
        memset(f,-1,sizeof(f));
        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));

        for(int i=1;i<=M;i++){
            int u,v; scanf("%d%d",&u,&v);
            f[u]=v;
        }
        for(int i=N-1;i>=0;i--){
            if(f[i]!=-1) dp[i]=dp[f[i]];
            else{
                for(int j=1;j<=6;j++)
                    dp[i]+=(dp[min(N,i+j)]+1)/6.0;
            }
        }
        printf("%.4lf\n",dp[0]);
    }
    return 0;
}
