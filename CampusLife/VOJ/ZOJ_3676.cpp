#include <cstdio>
#include <algorithm>

using namespace std;

struct Cola
{
    int p, q;
}A[100005];

int N, T, Sumq[100005], Sump[100005];

bool Cmp(const Cola &a, const Cola &b)
{
    return ((a.q - a.p) < (b.q - b.p));
}

void Solve()
{
    sort(A + 1, A + 1 + N, Cmp);
    for (int i = 1; i <= N; i ++)
    {
        Sump[i] = Sump[i - 1] + A[i].p;
        Sumq[i] = Sumq[i - 1] + A[i].q;
    }
    for (int i = 1, M; i <= T; ++i)
    {
        scanf("%d", &M);
        int l = 1, r = N + 1, ans = -1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (A[m].q - A[m].p < M) l = m + 1;
            else
            {
                ans = m; r = m - 1;
            }
        }
        if (ans == -1) printf("%d\n", Sump[N]);
        else printf("%d\n", Sump[ans - 1] + Sumq[N] - Sumq[ans - 1] - M * (N - ans + 1));
    }
}

void Init()
{
    for (int i = 1; i <= N; ++i) scanf("%d%d", &A[i].p, &A[i].q);
}

int main()
{
    while (scanf("%d%d", &N, &T) != EOF)
    {
        Init();
        Solve();
    }
    return 0;
}