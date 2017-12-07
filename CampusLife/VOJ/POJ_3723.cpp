/****
    最大生成森林，实际为最多能减少的花费。
****/
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
const int nMax = 20050;
const int eMax = 50050;



struct data
{
    int u, v, w;
} edge[eMax];
int n, m, pa[nMax];

bool cmp(data a, data b)
{
    return a.w > b.w;
}

void make_set()
{
    for(int x = 0; x < n; x ++)
        pa[x] = x;
}

int find_set(int x)
{
    if(x != pa[x])
        pa[x] = find_set(pa[x]);
    return pa[x];
}

int kruskal()
{
    int i, ans = n * 10000;
    make_set();
    sort(edge, edge + m, cmp);
    for(i = 0; i < m; i ++)
    {
        int x = find_set(edge[i].u);
        int y = find_set(edge[i].v);
        if(x != y)
        {
            pa[y] = x;
            ans -= edge[i].w;
        }
    }
    return ans;
}

int main()
{
    int testCase, N, M, R, x, y, d;
    scanf("%d", &testCase);
    while(testCase --)
    {
        scanf("%d%d%d", &N, &M, &R);
        n = N + M;
        m = R;
        for(int i = 0; i < R; i ++)
        {
            scanf("%d%d%d", &x, &y, &d);
            edge[i].u = x;
            edge[i].v = N + y;
            edge[i].w = d;
        }
        printf("%d\n", kruskal());
    }
    return 0;
}
