/****
    A->B
    对A,B分奇数偶数讨论~~~
    目标，把A,B变成偶数，然后，A->B一定会存在。
****/
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ull;

bool key = 1;
ull A, B ;
ull tA, tB;
ull tot = 0;
ull ans [1000];

ull Check(ull x)
{
    int t = ((int) sqrt(x)) + 1;
    for(int i = 2; i <= t; ++ i)
        if (x % i == 0) return i;
    cout << "Impossible" << endl;
    exit(0);
}

void Init()
{
    cin >> A >> B;
    if (A == 2) {
        cout << "Impossible" << endl;
        exit(0);
    }

    if (A & 1) {
        tA = Check(A);
        ans[++ tot] = A;
        A += tA;
    }

    if (B & 1) {
        tB = Check(B);
        key = 0;
        ans[0] = B;
        B -= tB;
    }

    if (A > B) {
        cout << "Impossible" << endl;
        exit(0);
    }
}

void Solve()
{
    ans[++ tot] = A;
    while (A != B) {
        ull tmp = A, inc = 1;
        while (inc * 2 < A && inc * 2 <= B - A && tmp % 2 == 0) {
            inc *= 2;
            tmp /= 2;
        }
        A += inc;
        ans[++ tot] = A;
    }
    for(int i = 1; i <= tot; ++ i)
        cout << ans[i] << endl;
    if (! key) cout << ans[0] << endl;
}

int main()
{
    Init();
    Solve();
    return 0;
}


