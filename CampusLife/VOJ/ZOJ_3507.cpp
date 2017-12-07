#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <complex>
#include <cassert>
#include <utility>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;
///#pragma comment(linker, "/STACK:102400000,102400000")
typedef pair<int,int> PII;
typedef long long ll;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<11
#define All 1,N,1

const ll  INFll = 0x3f3f3f3f3f3f3f3fLL;
const int INF= 0x7ffffff;
const int maxn = 1e5+100;
const int mod = 1000000007;

const double pi = acos(-1);
const double eps = 1e-10;

typedef complex<double> Point;
typedef complex<double> Vector;
typedef vector<int> intV;
typedef vector<double> intD;
#define X real()
#define Y imag()
Vector rotate(Vector v, double a) {return v*polar(1.0, a);}
int dx[]={0 ,-1,  0,1};
int dy[]={-1, 0,  1,0};

int M,N,K;
char Map[15][15];

void init(){
    getchar();
    for(int i=0;i<M;i++)
        gets(Map[i]);
    scanf("%d",&K);
}

char getv(int r,int c,int d)
{
    if(d==1)
        return Map[r][c];
    char x=getv(r/M,c/N,d-1);
    if(x==' ') return x;
    else return Map[r%M][c%N];
}

void solve()
{
    int r=1,c=1;
    for(int i=1;i<=K;i++)
        r*=M, c*=N;
    for(int i=0;i<r;i++){
        int space=-1;
        for(int j=c-1;j>=0;j--)
            if(getv(i,j,K)!=' '){
                space=j; break;
            }
        for(int j=0;j<=space;j++)
            printf("%c",getv(i,j,K));
        puts("");
    }
}

int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    //int T=0; scanf("%d",&T);
    int cas=0;
    //while(T--){
    while(~scanf("%d%d",&M,&N)){
        init();
        if(cas) puts("");
        printf("Fractal #%d:\n",++cas);
        solve();
    }
    return 0;
}

