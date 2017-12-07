#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int maxn = 111111;
int col[maxn<<2];
int sum[maxn<<2];
void PushUp(int rt) {
        sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void PushDown(int rt,int m) {
        if (col[rt]) {
                col[rt<<1] = col[rt<<1|1] = col[rt];
                sum[rt<<1] = (m - (m >> 1)) * col[rt];
                sum[rt<<1|1] = (m >> 1) * col[rt];
                col[rt] = 0;
        }
}
void build(int l,int r,int rt) {
        col[rt] = 0;
        sum[rt] = 1;
        if (l == r) return ;
        int m = (l + r) >> 1;
        build(lson);
        build(rson);
        PushUp(rt);
}
void update(int L,int R,int c,int l,int r,int rt) {
        if (L <= l && r <= R) {
                col[rt] = c;
                sum[rt] = c * (r - l + 1);
                return ;
        }
        PushDown(rt , r - l + 1);
        int m = (l + r) >> 1;
        if (L <= m) update(L , R , c , lson);
        if (R > m) update(L , R , c , rson);
        PushUp(rt);
}

//Ë«±ê¼Ç
#define All 1,N,1

int N, M;
int col[maxn << 2];
ll sum[maxn << 2];
int cls[maxn << 2];

void PushUp(int rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void PushDown(int rt, int m)
{
    if (cls[rt] != -1)
    {
        col[rt << 1] = col[rt << 1 | 1] = 0;
        sum[rt << 1] = sum[rt << 1 | 1] = 0;
        cls[rt << 1] = cls[rt << 1 | 1] = cls[rt];
        cls[rt] = -1;
    }

    if (col[rt])
    {
        col[rt << 1] += col[rt];
        col[rt << 1 | 1] += col[rt];
        sum[rt << 1] += 1LL * (m - (m >> 1)) * col[rt];
        sum[rt << 1 | 1] += 1LL * (m >> 1) * col[rt];
        col[rt] = 0;
    }
}

void update(int L, int R, int c, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        sum[rt] += c * (r - l + 1);
        col[rt] += c;
        cls[rt] = -1;
        return ;
    }
    PushDown(rt , r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(L , R , c , lson);
    if (R > m) update(L , R , c , rson);
    PushUp(rt);
}

void update(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        col[rt]=sum[rt] = cls[rt] = 0;
        return ;
    }
    PushDown(rt , r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(L , R , lson);
    if (R > m) update(L , R , rson);
    PushUp(rt);
}

ll query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
        return sum[rt];
    PushDown(rt , r - l + 1);
    int m = (l + r) >> 1;
    ll res = 0;
    if (L <= m) res += query(L , R , lson);
    if (R > m)  res += query(L , R , rson);
    PushUp(rt);
    return res;
}

int main()
{
    //freopen("1.in", "r", stdin);
    //freopen("1.out","w",stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &N, &M);
        memset(sum, 0, sizeof(sum));
        memset(col, 0, sizeof(col));
        memset(cls, -1, sizeof(cls));
        int last = 0;
        ll ans = 0;
        for (int i = 0; i < M; i++)
        {
            int t, l, r;
            scanf("%d%d%d", &t, &l, &r);
            int x = t - last;
            last = t;
            update(1, N, x, All);
            ans += query(l, r, All);
            update(l, r, All);
        }
        printf("%lld\n", ans);
    }
    return 0;
}

