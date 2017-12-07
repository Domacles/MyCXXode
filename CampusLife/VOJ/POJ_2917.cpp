/****
我们不妨设x>=y,则x=n+1,n+2,……,n+n.
而y = 1 / (1/n – 1/x) = nx / (x – n).
令k = x – n, 则 1 <= k <= n.则y = n(n+k) / k.
因为n*k = 0(mod k),y=n*n/k,而应是整数，则n*n%k==0,所以答案,即y的个数就等于n*n的小于等于n的约数个数.
****/
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
vector<pair<int,int> > prime;
int solve(int n)
{
    for (int i = 2; i * i <= n; i ++)
    {
        int num = 0;
        while(n % i == 0)
        {
            num ++;
            n /= i;
        }
        prime.push_back(make_pair(i, num));
        if (n == 1)
            break;
    }
    if (n > 1)
        prime.push_back(make_pair(n, 1));
    long long ans = 1;
    for (int i = 0; i <(int)prime.size(); i ++)
        ans *= (2 * prime[i].second + 1);
    return (ans + 1)/2;
}
int main()
{
    int t, caseo = 1;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        prime.clear();
        scanf("%d",&n);
        printf("Scenario #%d:\n", caseo ++);
        printf("%d\n\n", solve(n));
    }
    return 0;
}
