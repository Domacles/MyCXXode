#include <math.h>
#include <stdio.h>
#define pi acos(-1.0)
 
int main()
{
       int test, num = 1;
       double r, c, t, d;
 
       scanf("%d", &test);
       while (test--)
       {
              scanf("%lf%lf%lf%lf", &r, &c, &t, &d);
              double area, area1, area2, area3, area4;
              area = r * c * t * t;
              area1 = 4*(t-d/2.0)*(t-d/2.0)+2*(r-2+c-2)*(t-d/2.0)*(t-d)+(c-2)*(r-2)*(t-d)*(t-d);//1  四角  两列(行) 内部
              area2 = (c-1)*d*r*t+(r-1)*d*c*t-2*(c-1)*(r-1)*d*d;//2  上下左右四条边位置
              area3 = (d*d-pi*(d/2.0)*(d/2.0))*(c-1)*(r-1);//3
              area4 = pi*(d/2.0)*(d/2.0)*(c-1)*(r-1);//4
              printf("Case %d:\n", num++);
              printf("Probability of covering 1 tile  = %.4f%*%\n", 100 * (area1 / area));//G++
              printf("Probability of covering 2 tiles = %.4f%*%\n", 100 * (area2 / area));
              printf("Probability of covering 3 tiles = %.4f%*%\n", 100 * (area3 / area));
              printf("Probability of covering 4 tiles = %.4f%*%\n\n", 100 * (area4 / area));
       }
       return 0;
}