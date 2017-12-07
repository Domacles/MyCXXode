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

const int maxn =1024+10;
int w[11][11],dp[maxn],N;

int dfs(int s){
    if(s==((1<<N)-1)) return 0;
    if(dp[s]) return dp[s];

    for(int i=0;i<N;i++){//lost
        int last=(1<<i)|s;
        if(s==last) continue;
        int ret=dfs(last);
        for(int j=0;j<N;j++){
            if(i!=j && s&(1<<j))
                dp[s]=max(dp[s],ret+w[j][i]);
        }
    }
    return dp[s];
}

int main()
{
    //freopen("D://r1.txt","r",stdin);
    while(~scanf("%d",&N) && N){
        memset(w,0,sizeof(w));
        for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            scanf("%d",&w[i][j]);
        }
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int i=1;i<=(1<<(N-1));i*=2)
            ans=max(ans,dfs(i));
        printf("%d\n",ans);
    }
    return 0;
}

