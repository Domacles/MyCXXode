#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define red(i, a, b) for (int i = (a); i >= (b); --i)
#define clr( x , y ) memset(x,y,sizeof(x))
#define sqr(x) ((x) * (x))
#define mp make_pair
#define pb push_back
typedef long long lint;
int n , m , t , people , x , y , c;
int a[2600] , d[2600] , pre[2600] , f[2600];
lint sum;
bool v[2600];
 
struct nodd
{
    int y , d , f , n;
} b[21000];
 
void add(int x,int y,int d,int f)
{
    b[++t].y = y; b[t].d = d;
    b[t].f = f; b[t].n = a[x]; a[x] = t;
}
 
void init()
{
    scanf("%d%d",&m,&people);
    t = 1;
    rep(i,0,n+1) a[i] = 0;
    add( 0 , 1 , people , 1 );
    add( 1 , 0 , 0 , -1 );
    rep(i,1,m) {
        scanf("%d%d%d",&x,&y,&c);
        x ++; y ++;
        add( x , y , c , 1 );
        add( y , x , 0 , -1 );
    }
}
 
bool spfa()
{
    queue < int > q;
    q.push( 0 );
    d[0] = -1;
    rep(i,1,n+1) d[i] = 100000000 , v[i] = 1;
    while ( !q.empty() ) {
        x = q.front(); q.pop();
        v[x] = 1;
        for ( int p = a[x]; p ; p = b[p].n ) if ( b[p].d && d[x] + b[p].f < d[ y = b[p].y ] ) {
            d[y] = b[p].f + d[x];
            pre[y] = p;
            f[y] = x;
            if ( v[y] ) v[y] = 0 , q.push( y );
        }
    }
    if ( d[n] == d[n+1] ) return 0;
    for ( x = n , y = 100; x ; x = f[x] ) y = min( y , b[pre[x]].d );
    for ( x = n; x; x = f[x] ) b[pre[x]].d -= y , b[pre[x]^1].d += y;
    return 1;
}
 
void work()
{
    int ans = people ? people + m + 1 : 0 , now = 0 , sum = 0 , s = people;
    while ( spfa() ) {
        s -= ( d[n] - now ) * sum + y;
        sum += y; now = d[n];
        lint k = now + ceil( 1.0 * ( s < 0 ? 0 : s ) / sum );
        if ( k < ans ) ans = k;
        if ( s < 1 ) break;
    }
    if ( ans > people + m ) puts("No solution"); else printf("%d\n",ans);
}
 
int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}