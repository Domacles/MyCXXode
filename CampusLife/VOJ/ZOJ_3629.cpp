/***
	[n/1] + [n/2] + ... + [n/k] + ...  k->inf 取整计算~~
	[0,1) [4,9) [16,25) [36,49) ... force_algorithm：all are real.....
***/
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;

ll deal(ll n)
{
    if (n==-1) return 0;
    ll r=(ll)sqrt((double)n+1);//[l,r) left r limited's sqrt 
    if (r&1)//odd
        return r*((r+1)>>1);
    else//even
        return n-r*r+(r>>1)*(r-1)+1;
}
int main()
{
    ll n,m;
    while(~scanf("%lld%lld", &n, &m))
        printf("%lld\n",deal(m)-deal(n-1));
    return 0;
}