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
const int maxn = 111;
const double eps= 1e-5;
const int mod = 10000007;

int n, m;
int v[20], fa[20];
void make_set()
{
    for(int i = 1; i <= n; i++)
        fa[i] = i;
}
int find(int x)
{
    if(fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}
void Union(int x, int y)
{
    int a = find(x);
    int b = find(y);
    if(a != b)
        fa[b] = a;
}
int main()
{
    int i, a, b;
    while(scanf("%d %d",&n,&m) != -1) {
        memset(v,0,sizeof(v));
        make_set();
        for(i = 1; i <= m; i++) {
            scanf("%d %d",&a,&b);
            v[a]++;
            v[b]++;
            Union(a,b);//并查集判断连通性
        }
        if(n != m || n < 3) {
            printf("NO\n");
            continue;
        }
        for(i = 1; i <= n; i++)
            if(v[i] != 2 || fa[i] != fa[1])
                break;
        if(i <= n)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}

