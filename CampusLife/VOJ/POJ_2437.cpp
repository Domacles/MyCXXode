#include<iostream>
#include<cmath>
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<ctime>
#include<bitset>
#define eps 1e-6
#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define M 1000000007

using namespace std;
typedef long long ll;
#define Maxn 110000

struct Inte
{
    ll s,e;
}inte[Maxn];
int n,l;

bool cmp(struct Inte a,struct Inte b)
{
    return a.s<b.s;
}

int main()
{
    ll la;

    while(~scanf("%lld%lld",&n,&l))
    {
        for(int i=1;i<=n;i++)
            scanf("%lld%lld",&inte[i].s,&inte[i].e);

        sort(inte+1,inte+n+1,cmp); //将区间从小到大排序
        la=-1;
        ll ans=0,len,num;

        for(int i=1;i<=n;i++)
        {
            if(inte[i].e<=la) //如果上一个棒将这个区间完全覆盖了，则不需要继续添加棒了
                continue;

            if(inte[i].s<la) //如果占据了该区间一部分
            {
                len=inte[i].e-la; //剩下的长度
                num=(len+(l-1))/l; //所需要的棒的个数，注意向上取整
                ans+=num; //
                la+=num*l; //新的棒的覆盖位置
            }
            else
            {
                len=inte[i].e-inte[i].s; //上一个棒 没有延伸到该区间
                num=(len+(l-1))/l; //棒的个数
                ans+=num;
                la=inte[i].s+num*l; //新的棒的覆盖位置
            }
        }
        printf("%lld\n",ans);
    }
   return 0;
}
