#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#include <stack>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int a,b;
    while(~scanf("%d%d",&a,&b))
    {
        double ans=1e6;
        double tar=a*1.0/b;//所給值
        int na,nb;
        for(int i=1;i<=32767;i++)//枚舉分母
        {
            double u=i*1.0/b*1.0*a;//分子
            int ta=int(u);//分子1
            int tta=int(u+1);//分子2
            if(fabs(ta*1.0/i-tar)<ans&&fabs(ta*1.0/i-tar)>=1e-10)//控制精度
            {
                ans=fabs(ta*1.0/i-tar);//漸近差值
                na=ta;
                nb=i;
            }
            if(fabs(tta*1.0/i-tar)<ans&&fabs(ta*1.0/i-tar)>=1e-10)//控制精度
            {
                ans=fabs(tta*1.0/i-tar);//漸近差值
                na=tta;
                nb=i;
            }
        }
        printf("%d %d\n",na,nb);
    }
    return 0;
}