#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long a[100],b[100],ge;

void init(int kk)
{
    int k=kk;
    ge=0;
    int i,j;
    for (i=2;i<=kk;i++)
    if (k%i==0 && k>0)
    {
		a[++ge]=i;
        j=0;
        while (k%i==0 && k>0) j++,k/=i;
        b[ge]=j;
    }
}

int main()
{
    char s[1000];
    long long k,i,a1,len,n;

    while(scanf("%s %lld\n",s,&k)!=EOF)
    {
        len=strlen(s);
        init(k);

        a1=1;
        n=0;
        for(i=len-1;i>=0;i--)
        {
            if(('0'<=s[i])&&(s[i]<='9'))n+=(s[i]-'0')*a1;
            if(('A'<=s[i])&&(s[i]<='Z'))n+=(s[i]-'A'+10)*a1;
            if(('a'<=s[i])&&(s[i]<='z'))n+=(s[i]-'a'+36)*a1;
            a1*=k;
        }

        long long min=-1,m,sum;
        for (i=1;i<=ge;i++)
        {
            sum=0;
            m=n;

            while (m>=a[i])
            {
                sum+=m/a[i];
                m/=a[i];//而不是用个变量不停乘a[i]因为可能溢出
            }

            if (min==-1) min=(sum/b[i]);//初始赋-1然后判断的方法比较好，maxint可能不够
            else if ((sum/b[i])<min) min=(sum/b[i]);
        }

        printf("%lld\n",min);
    }

    return 0;
}