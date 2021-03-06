#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;
#define MAX_N (310)
#define ll long long

int n, m, d;
ll a[MAX_N], b[MAX_N], c[MAX_N];
ll dp[2][150010];
ll *pre = dp[0], *cur = dp[1];

int main()
{
    scanf("%d %d %d", &n, &m, &d);
    for(int i=1; i<=m; ++i)
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
    for(int i=1; i<=m; ++i)
    {
        int dist = min((ll)n, (ll)d*(c[i]-c[i-1]));
        deque<int> dq;
        for(int j=1, k=1; j<=n; ++j)
        {
            while(k<=n&&k<=j+dist)
            {
                while(!dq.empty()&&pre[dq.back()]<=pre[k])
                    dq.pop_back();
                dq.push_back(k);
                ++k;
            }
            while(!dq.empty()&&dq.front()<j-dist)
                dq.pop_front();
            cur[j] = pre[dq.front()]+b[i]-abs(a[i]-j);
        }
        swap(pre, cur);
    }
    ll ans = pre[1];
    for(int i=2; i<=n; ++i)
        ans = max(ans, pre[i]);
    printf("%I64d\n", ans);
    return 0;
}