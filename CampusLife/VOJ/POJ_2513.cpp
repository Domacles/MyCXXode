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

struct Node
{
    int next[26];
    int num;
    Node()
    {
        memset(next, -1, sizeof(next));
        num = 0;
    }
} node[5005];

char s[11], p[11];
int has, cnt, sum[5555], f[5555];

void init()
{
    cnt = has = 0;
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= 5010; i++) f[i] = i;
}

int Trie(char *str)
{
    int i = 0, rt = 0;
    while (str[i])
    {
        int id = str[i] - 'a';
        if (node[rt].next[id] == -1) node[rt].next[id] = ++cnt;
        rt = node[rt].next[id];
        i++;
    }
    if(!node[rt].num) node[rt].num=++has;
    return node[rt].num;
}

inline int findw(int x)
{
    if (f[x] == x) return x;
    return f[x] = findw(f[x]);
}

void solve()
{
    int flag = 0;
    while (~scanf("%s%s", s, p))
    {
        int a = Trie(s) , b = Trie(p);
        int x = findw(a), y = findw(b);
        f[y] = x, sum[a]++, sum[b]++;
    }

    int rt = findw(1);
    for (int i = 2; i <= has; i++)
        if (findw(i) != rt)
        {
            flag = 1000;
            break;
        }

    for (int i = 1; i <= has; i++)
        if (sum[i] % 2) flag++;

    if (flag == 0 || flag == 2)
        printf("Possible\n");
    else
        printf("Impossible\n");
}

int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    init();
    solve();
    return 0;
}

