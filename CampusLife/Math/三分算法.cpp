const double eps = 1e-5;

double a, b, c, x, y;

void init()
{
    int aa, bb, cc, xx, yy;
    scanf("%d%d%d%d%d", &aa, &bb, &cc, &xx, &yy);
    a = aa, b = bb, c = cc, x = xx, y = yy;
}

double cal(double xx)
{
    double yy = a * xx * xx + b * xx + c;
    return sqrt((xx - x) * (xx - x) + (yy - y) * (yy - y));
}

int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    double d = 0;
    init();
    if (a == 0)
        d = abs(b * x - y + c) / sqrt(b * b + 1.0);
    else
    {
        double l, r, m, mm;
        if (x >= -b / (2 * a)) l = -b / (2 * a), r = 222;
        else l = -222, r = -b / (2 * a);
        while (r - l >= eps)
        {
            m = (l + r) / 2;
            mm = (m + r) / 2;
            if (cal(m) <= cal(mm))
                r = mm;
            else
                l = m;
        }
        d=cal(m);
    }
    printf("%.3lf\n",d);
    return 0;
}


