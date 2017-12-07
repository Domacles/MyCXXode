#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <complex>
#include <cassert>
#include <utility>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;
///#pragma comment(linker, "/STACK:102400000,102400000")
typedef pair<int, int> PII;
typedef long long ll;

int size01(int x)
{
    return __builtin_popcount(x);
}
#define lson l,m,rt<<1
#define rson m+1,r,rt<<11
#define All 1,N,1

const ll  INFll = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x7ffffff;
const int maxn = 1e5 + 3e4 + 100;
const int mod = 1000000007;

const double pi = acos(-1);
const double eps = 1e-10;

typedef complex<double> Point;
typedef complex<double> Vector;
typedef vector<int> intV;
typedef vector<double> intD;
#define X real()
#define Y imag()
Vector rotate(Vector v, double a)
{
    return v * polar(1.0, a);
}
int dx[] = {0 , -1,  0, 1};
int dy[] = { -1, 0,  1, 0};

int N, M, dp[1111],sum[1111],p[1111];

void init()
{
    memset(dp,0,sizeof(dp));
    memset(p,0,sizeof(p));
    memset(sum,0,sizeof(sum));
}
/***
    最终形成[1,x1],[x1+1,x2],[x2+1,x3]....
    的替换区间，每一段都由最后一个去替换
    http://blog.csdn.net/lyy289065406/article/details/6648131
***/

int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        init();
        scanf("%d",&N);
        for(int i=1;i<=N;i++)
            scanf("%d%d",&sum[i],&p[i]),sum[i]+=sum[i-1];
        for(int i=1;i<=N;i++){
            dp[i]=(sum[i]+10)*p[i];
            for(int j=1;j<i;j++)
                dp[i]=min(dp[i],dp[j]+(sum[i]-sum[j]+10)*p[i]);
        }
        printf("%d\n",dp[N]);
    }
    return 0;
}

