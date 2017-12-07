/****
    排序模拟
****/
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
const int maxn = 1e6+1e3;
const double eps= 1e-5;

#define N 101
#define M 101
struct node {
    int in, leave;
    int num, room;
} s[N];
int cmp(struct node a, struct node b)
{
    if(a.in != b.in)
        return a.in < b.in;
    else
        return a.leave < b.leave;
}
int cmp2(struct node a, struct node b)
{
    return a.num < b.num;
}
int main(void)
{
    int room[M],  in, leave, m, n, i, j;
    while(scanf("%d%d",&n, &m), n) {
        memset(room, 0, sizeof(room));
        for(i=1; i<=n; i++) {
            scanf("%d%d",&s[i].in, &s[i].leave);
            s[i].num = i;
        }
        sort(s+1, s+n+1, cmp);
        for(i=1; i<=n; i++) {
            for(j=1; j<=m; j++)
                if(s[i].in >= room[j]) {
                    s[i].room = j;
                    room[j] = s[i].leave;
                    goto X;
                }
            s[i].room = 0;
X:
            continue;
        }
        sort(s+1, s+n+1, cmp2);
        for(i=1; i<=n; i++)
            printf("%d\n", s[i].room);
    }
    return 0;
}

