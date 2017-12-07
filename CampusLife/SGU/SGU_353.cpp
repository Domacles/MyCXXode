#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int,int> PII;
typedef long long ll;

const int maxn =1e6;

int main()
{
    //freopen("r.txt","r",stdin);
    ll n,k1,k2,p1,p2,p3;
    scanf("%I64d %I64d %I64d %I64d %I64d %I64d",&n,&k1,&k2,&p1,&p2,&p3);
    ll ans=0;
    if(n<=p1)
    {
        printf("%I64d\n",n==p1?k1:0);
        return 0;
    }
    else{
        n-=p1;
        ans+=k1;
    }

    if(n<=k2*p2) {
        ans+=(n+p2-1)/p2;
        printf("%I64d\n",ans);
        return 0;
    }
    else {
        n-=k2*p2;
        ans+=k2;
    }

    ans+=(n+p3-1)/p3;
    printf("%I64d\n",ans);
    return 0;
    return 0;
}
