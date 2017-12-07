/*********
    本题:
    给定n个工作，m条通道。工作可以分成若干份,但每一时刻只能由一个医生来做.
    然后这m条通道要么全部一起完成工作，要么只有1条在完成工作，求把n个工作全部做完至少需要多长时间。

    思路:
        首先求出所有人同时工作的最大时间ans, 然后 s[1~N]-ans*(M-1)就是答案

    ans可以采用二分,判断条件: 1, ans*M>=s[1~N] 2,min(ans),第一个满足条件的ans,在满足精度要求下.

    实际上,就是把原来每个人的检查时间t,按照ans分块,使得那些没有达到ans的块的总和最小.

    ans实际上还满足:
        在t[i]降序的情况下,
            ans>=t[i+1]
            ans<=t[i]
            s[i+1~~N]+i*ans>=M*ans  ==>  ans<=s[i+1~~N]/(M-i)
    因此,可以循环一边进行判定.

*********/
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int,int> PII;
typedef long long ll;

#define foreach(it,V) for(vector<int>::iterator it=V.begin(); it!=V.end();++it)

#define INF 0x7ffffff
const int maxn = 1311;
const double eps= 1e-5;
const int mod = 10000007;

int N,M;
double a[maxn],s[maxn];

void solve()
{
    double ans=0;
    s[N+1]=a[N+1]=0;
    a[0]=1e20;
    for(int i=N;i>=1;i--) s[i]=s[i+1]+a[i];
    for(int i=0;i<=N;i++)
        if(i==M){
            ans=a[i]; break;
        }else if(i<M){
            double x=min(a[i],s[i+1]/(M-i));//当i等于0的时候,就意味着所有工作只由一个人做,则x=s[1],因此,a[0]必须是个很大的数字
            if(x>=a[i+1]){
                ans=x; break;
            }
        }
    printf("%.9lf\n",s[1]-ans*M+ans);
}

int main()
{
    freopen("1.in","r",stdin);
    while(~scanf("%d%d",&M,&N)){
        for(int i=1;i<=N;i++)
            scanf("%lf",&a[i]);
        sort(a+1,a+N+1,greater<double>());
        solve();
    }
    return 0;
}

