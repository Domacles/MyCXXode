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

const int maxn = 1148576;
int dp[2][maxn] , w[22][22];
int N;
vector<int>s;

void init0(){
    for(int i=0;i<(1<<20);i++)
        if((i&(i<<1))==0 && (i&(i>>1))==0) s.push_back(i);
}

int Sum(int now,int k)
{
    int ret=0;
    for(int i=0;i<N;i++)
        if((1<<i)&s[now]) ret+=w[k][i];
    return ret;
}

void init()
{
    memset(dp,0,sizeof(dp));
    for(int i=0;i<(int)s.size() && s[i]<(1<<N);i++)
        dp[0][i]=Sum(i,0);
}

bool check(int i,int j)
{
    if(s[i]&s[j]) return 0;
    return 1;
}

int main()
{
    //freopen("D://r1.txt","r",stdin);
    init0();
    while(~scanf("%d",&N)){
        for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%d",&w[i][j]);
        init();
        for(int i=1;i<N;i++){
            int last=(i-1)&1 , now=i&1;
            for(int j=0;j<(int)s.size() && s[j]<(1<<N);j++){
                int ret=0;
                for(int k=0;k<(int)s.size() && s[k]<(1<<N);k++)
                    if(check(j,k)) ret=max(ret,dp[last][k]);
                dp[now][j]=ret+Sum(j,i);
            }
        }
        int ans=0;
        for(int i=0;i<(int)s.size() && s[i]<(1<<N);i++)
            ans=max(ans,dp[(N-1)&1][i]);
        printf("%d\n",ans);
    }
    return 0;
}
