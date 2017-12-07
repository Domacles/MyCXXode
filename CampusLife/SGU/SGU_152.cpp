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
    bool round[10000]={0};
    long per[10000]={0};
    long n,c(100),z(0);
    scanf("%ld",&n);
    for (int i(0);i<n;++i)
    {
        scanf("%ld",&per[i]);
        z+=per[i];
    }
    for (int i(0);i<n;++i)
    {
        round[i]=per[i]*100%z;
        per[i]=per[i]*100/z;
        c-=per[i];
    }
    for (int i(0);i<n;++i)
        if (round[i])
        {
            ++per[i]; --c;
            if (!c) break;
        }
    for (int i(0);i<n;++i)
        printf("%ld ",per[i]);
    return 0;
}







