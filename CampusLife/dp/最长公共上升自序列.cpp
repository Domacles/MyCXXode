int N, M, a[1111], b[1111];

int main()
{
    //freopen("1.in", "r", stdin);
    //freopen("1.out","w",stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
        scanf("%d", &M);
        for (int i = 1; i <= M; i++) scanf("%d", &b[i]);
        int dp[1111], ans = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= N; i++)
        {
            int x = 0;
            for (int j = 1; j <= M; j++)
            {
                if (a[i] > b[j] && dp[j] > dp[x])
                    x = j;
                else if (a[i] == b[j])
                    dp[j] = max(dp[j], dp[x] + 1);
                ans = max(ans, dp[j]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}