#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;
const double inf = 0xfffffff;
const double PI = 3.1415926;
 
int main(){
    double l, n, c;
    while(scanf("%lf%lf%lf", &l, &n, &c) != EOF){
        if(l < 0) break;
        if(n * c < 0.000001){    //  没能构造出圆的情况，这点一定要考虑周全。
            printf("0.000\n");
            continue;
        }
        double seg = (1+n*c)*l, tmp;
        double mid, low = 0, high = inf;
        while(high - low > 0.000001){    //  以半径r，（即mid）去做二分。
            mid = (high + low) / 2;
            double angle = asin(0.5*l / mid);
            tmp = 2*angle*mid;
            if(tmp < seg)  high = mid;
            else low = mid;
        }
        double ans = mid - sqrt(mid*mid-l*l/4);    //  由半径推出高h。
        printf("%.3f\n", ans);
    }
    return 0;
}