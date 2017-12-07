/****
给一个地图，机器人要从左上角走到右下角，机器人重复一定的指令序列，
指令只包含向下走和向右走两种，问指令序列的最短长度。

枚举指令序列中向下和向右的个数，然后地图重叠过去。判断能否走到最后的终点，再由终点走到右下角。
****/
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int,int> PII;
typedef long long ll;

#define foreach(it,V) for(vector<int>::iterator it=V.begin(); it!=V.end();++it)

#define INF 0x7ffffff
const int maxn = 1e6+1e3;
const double eps= 1e-5;

const int MAXN = 221;
char buf[MAXN][MAXN];
bool a[MAXN][MAXN], b[MAXN][MAXN];

void prepare(int x, int y, int z)
{
    for (int i = 0; i <= x; ++i) {
        for (int j = 0; j <= y; ++j) {
            a[i][j] = true;
        }
    }
    for (int k = 0; k <= z; ++k) {
        for (int i = 0; i <= x; ++i) {
            for (int j = 0; j <= y; ++j) {
                if (buf[k * x + i][k * y + j] == 'X') {
                    a[i][j] = false;
                }
            }
        }
    }
}

bool check(int x1, int y1, int x2, int y2)
{
    for (int i = x1; i <= x2; ++i) {
        for (int j = y1; j <= y2; ++j) {
            b[i][j] = a[i][j] &&
                      ((i == x1 && j == y1) ||
                       (i > x1 && b[i - 1][j]) ||
                       (j > y1 && b[i][j - 1]));
        }
    }
    return b[x2][y2];
}

int main()
{
    int n, m, ans;

    while (scanf("%d%d", &m, &n) != EOF) {
        memset(buf, 0, sizeof(buf));
        for (int i = 0; i < n; ++i) {
            scanf("%s", buf[i]);
        }
        ans = -1;
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (ans != -1 && i + j >= ans) {
                    continue;
                }
                int k = min((n - 1) / i, (m - 1) / j);
                int x = n - 1 - k * i, y = m - 1 - k * j;
                if (x <= i && y <= j) {
                    prepare(i, j, k);
                    if (check(0, 0, x, y) && check(x, y, i, j)) {
                        ans = i + j;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}

