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
#define rson m+1,r,rt<<1|1
#define All 1,N,1

const ll  INFll = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x7ffffff;
const int maxn = 300000;
const int mod = 1000000007;

//const double pi = acos(-1);
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

/*****/
int n, m, l[maxn], r[maxn];
int type[maxn];
map<pair<int, int>, int>f, cnt;

void solve()
{
    memset(type, 0, sizeof(type));

    ll ans = 0;
    queue<int>q;
    vector<int>A;
    q.push(1);
    while (!q.empty())
    {
        int u = q.front();
        A.push_back(u), q.pop();
        if (l[u] > 0) q.push(l[u]);
        if (r[u] > 0) q.push(r[u]);
    }
    reverse(A.begin(), A.end());
    for (int i = 0; i < (int)A.size(); i++)
    {
        int u = A[i];
        int x = l[u] > 0 ? type[l[u]] : 0;
        int y = r[u] > 0 ? type[r[u]] : 0;
        PII now=PII(x, y);
        if (f[now] == 0)
        {
            type[u] = -1;
            continue;
        }
        type[u] = f[PII(x, y)];//获取第一颗树对应的编号
        ans += cnt[now];
    }
    printf("%lld\n", ans);
}

void Build()
{
    f.clear(), cnt.clear();

    memset(type, 0, sizeof(type));
    queue<int>q;
    vector<int>A;
    q.push(1);
    while (!q.empty())
    {
        int u = q.front();
        A.push_back(u), q.pop();
        if (l[u] > 0) q.push(l[u]);
        if (r[u] > 0) q.push(r[u]);
    }
    reverse(A.begin(), A.end());
    int s=0;
    for (int i = 0; i < (int)A.size(); i++)
    {
        int u = A[i];
        int x = l[u] > 0 ? type[l[u]] : 0;
        int y = r[u] > 0 ? type[r[u]] : 0;
        PII now = PII(x, y);
        if (f[now] == 0) f[now] = ++s;
        type[u] = f[now];
        cnt[now]++;
    }
}

void init()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(l, -1, sizeof(l));
        memset(r, -1, sizeof(r));
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            l[i] = x, r[i] = y;
        }
        Build();
        memset(l, -1, sizeof(l));
        memset(r, -1, sizeof(r));
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            l[i] = x, r[i] = y;
        }
        solve();
    }
}

int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    init();
    //solve();
    return 0;
}

