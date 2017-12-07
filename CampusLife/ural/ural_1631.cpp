//floorl(x) 用于截断浮点数的小数部分,存在于math库里
#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stdlib.h>
#include<cmath>
using namespace std;
#define N 1000000
#define LL long long
#define lowbit(x) x&(-x)
LL re[N+10];
void add(int x,int d)
{
    while(x)
    {
        re[x]+=d;
        x-=lowbit(x);
    }
}
LL getsum(int x)
{
    LL s = 0;
    while(x<=N)
    {
        s+=re[x];
        x+=lowbit(x);
    }
    return s;
}
int main()
{
    int num;
    LL sum=0;
    double k;
    char s[20];
    while(scanf("%s",s)!=EOF)
    {
        if(s[0]=='Q')
        break;
        else if(s[0]=='B')
        {
            scanf("%lf",&k);
           int kk = floorl(k*100.0+0.5);
            add(kk,1);
        }
        else if(s[0]=='D')
        {
            scanf("%lf",&k);
            int kk = floorl(k*100.0+0.5);
            add(kk,-1);
        }
        else
        {
            scanf("%lf %d",&k,&num);
            int kk = floorl(k*100.0+0.5);
            LL ss = getsum(kk);
            if(ss>=num)
            sum+=num;
            else
            sum+=ss;
        }
    }
    printf("%.2lf\n",(double)sum/100.0+1e-9);
    return 0;
}