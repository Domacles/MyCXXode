/*****
	若需求在一维情况下，取所有坐标的中位数即可；
	若需求在二维情况下，取x坐标的中位数,y坐标的中位数所形成的点或区域（
									原因为点个数为偶数或者最小点被占用）；
	从所求区域中，去掉已知点。
*****/
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

const int N = 10000;

struct point
{
    int x, y;
};

int n;
point p[N];
int x[N], y[N];
int x1, x2, y1, y2;
set<int> table;

inline int f(int x, int y)
{
    return (x + 10000) * 100000 + (y + 10000);
}

inline bool find(int x, int y)
{
    return table.find(f(x, y)) != table.end();
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", x + i, y + i);
        p[i].x = x[i];
        p[i].y = y[i];
        table.insert(f(x[i], y[i]));
    }
    sort(x, x + n);
    sort(y, y + n);

    int sum = 0, cnt = 0;
    if (n & 1)
    {
        x1 = x[n / 2];
        y1 = y[n / 2];
        if (find(x1, y1))
        {//此位置已被占用
            for (int i = 0; i < n; ++i)
            {
                sum += abs(x1 - x[i]);
                sum += abs(y1 - y[i]);
            }
            ++sum;//此位置已被占用，退而求其次

            x1 = x[n / 2 - 1];
            x2 = x[n / 2 + 1];
            for (int i = x1; i <= x2; ++i)
                if (!find(i, y1))//固定y坐标，同行找cow不在的位置
                    ++cnt;

            y1 = y[n / 2 - 1];
            y2 = y[n / 2 + 1];
            for (int i = y1; i <= y2; ++i)
                if (!find(x1, i))//固定x坐标，同列找cow不在的位置
                    ++cnt;
        }
        else
        {//此位置未被占用
            for (int i = 0; i < n; ++i)
            {
                sum += abs(x1 - x[i]);
                sum += abs(y1 - y[i]);
            }
            cnt = 1;//唯一位置
        }
    }
    else
    {
        x1 = x[n / 2 - 1];/**取中位数**/
        x2 = x[n / 2];
        y1 = y[n / 2 - 1];
        y2 = y[n / 2];      /**END**/
        cnt = (x2 - x1 + 1) * (y2 - y1 + 1);//坐标区域大小
        for (int i = 0; i < n; ++i)
        {
            sum += abs(x1 - x[i]);
            sum += abs(y1 - y[i]);
        }
        for (int i = 0; i < n; ++i)
        {
            if (p[i].x >= x1 && p[i].x <= x2 && p[i].y >= y1 && p[i].y <= y2)
                --cnt;
        }//排除cow已在区域中的可能
    }
    printf("%d %d\n", sum, cnt);
    return 0;
}