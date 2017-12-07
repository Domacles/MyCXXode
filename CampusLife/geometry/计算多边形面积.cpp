int x[11], y[11];

struct point {
    double x, y;
    point(double _x = 0, double _y = 0): x(_x), y(_y) {
    }
    void input() {
        scanf("%lf%lf", &x, &y);
    }
};

double operator*(const point& p1, const point& p2) {
    return p1.x * p2.y - p1.y * p2.x;
}

double area()//逆
{
    double s = 0;
    for (int i = 0; i < N; i++)
        s += 1.0 * x[i] * y[i + 1] - 1.0 * x[i + 1] * y[i];
    return s / 2;
}