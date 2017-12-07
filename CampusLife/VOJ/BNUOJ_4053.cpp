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

const int maxn = 1e6;
const int mod = 10111009;

int C[1111][1111],N;

void init()
{
    C[0][0]=1;
    for(int i=1;i<=1000;i++){
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    }
}

void solve()
{
    int res=0;
    for(int i=N-1;i>=1;i--){
        res=(res+C[N][i]-1)%mod;
    }
    printf("%d\n",res);
}

int main()
{
    //freopen("r.txt","r",stdin);
    init();
    scanf("%d",&N);
    solve();
    return 0;
}
