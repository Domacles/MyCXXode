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

int N, M;

int has[1111][1111];

inline int lowbit(int x)
{
    return x & (-x);
}

void init()
{
    memset(has, 0, sizeof(has));
}

void Add(int x, int y)
{
    for (int i = x; i <= N; i += lowbit(i))
        for (int j = y; j <= N; j += lowbit(j))
            has[i][j] = (has[i][j] + 1) % 2;
}

int Query(int x, int y)
{
    int res = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        for (int j = y; j > 0; j -= lowbit(j))
            res = (res + has[i][j]) % 2;
    return res;
}

char op[2];

int main()
{
    //freopen("1.in", "r", stdin);
    //freopen("1.out","w",stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        init();
        scanf("%d%d", &N, &M);
        for (int i = 0; i < M; i++)
        {
            scanf("%s", op);
            int x1, x2, y1, y2;
            if (op[0] == 'Q')
            {
                scanf("%d%d", &x1, &y1);
                printf("%d\n", Query(x1, y1));
            }
            else
            {
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                x1++, y1++, x2++, y2++;
                Add(x2, y2), Add(x1 - 1, y1 - 1);
                Add(x2, y1 - 1), Add(x1 - 1, y2);
            }
        }
        printf("\n");
    }
    return 0;
}

