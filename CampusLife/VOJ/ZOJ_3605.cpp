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

int N, M, K, S, x, y;
ll dp[55][55][55];

void solve()
{
}

int is(int u)
{
    if (u == x) return y;
    if (u == y) return x;
    return u;
}
/*
猜弹珠在哪个杯子里的游戏，总共交换了m次，但是只看见了k次。
只要把所有的情况都写出来即可，C(m,k)
用动规来实现，最后只要找出最多的那个数就好了。
*/

void init()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(dp, 0, sizeof(dp));
        scanf("%d%d%d%d", &N, &M, &K, &S);
        for (int i = 0; i <= M; i++) dp[i][0][S] = 1;
        for (int i = 1; i <= M; i++)
        {
            scanf("%d%d", &x, &y);
            for (int j = 1; j <= min(i, K); j++)
                for (int k = 1; k <= N; k++)
                    dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][is(k)];
        }
        int ans = 1;
        for (int i = 1; i <= N; i++)
            if (dp[M][K][ans] < dp[M][K][i])
                ans = i;
        printf("%d\n", ans);
    }
}

int main()
{
    freopen("1.in", "r", stdin);
    //freopen("1.out","w",stdout);
    init();
    //solve();
    return 0;
}

