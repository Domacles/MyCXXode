/****
���ǲ�����x>=y,��x=n+1,n+2,����,n+n.
��y = 1 / (1/n �C 1/x) = nx / (x �C n).
��k = x �C n, �� 1 <= k <= n.��y = n(n+k) / k.
��Ϊn*k = 0(mod k),y=n*n/k,��Ӧ����������n*n%k==0,���Դ�,��y�ĸ����͵���n*n��С�ڵ���n��Լ������.
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
