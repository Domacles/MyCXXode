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

template <class T>
inline bool scan_d(T &ret) {
   char c; int sgn;
   if(c=getchar(),c==EOF) return 0; //EOF
   while(c!='-'&&(c<'0'|c>'9')) c=getchar();
   sgn=(c=='-')?-1:1;
   ret=(c=='-')?0:(c-'0');
   while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
   ret*=sgn;
   return 1;
}

inline void out(long long x) {
   if(x>9) out(x/10);
   putchar(x%10+'0');
}

typedef complex<double> Point;
typedef complex<double> Vector;
typedef vector<int> intV;
typedef vector<double> intD;
#define X real()
#define Y imag()
Vector rotate(Vector v, double a) {return v*polar(1.0, a);}
int dx[]={0 ,-1,  0,1};
int dy[]={-1, 0,  1,0};

int n, k, rank[maxn], tmp[maxn];
bool cmp(int i,int j){
    if(rank[i]!=rank[j]) return rank[i]<rank[j];
    else{
        int ri=i+k<=n?rank[i+k]:-1;
        int rj=j+k<=n?rank[j+k]:-1;
        return ri<rj;
    }
}
void SA(string S,int *sa){
    n=S.length();
    //init rank
    for(int i=0;i<=n;i++){
        sa[i]=i;
        rank[i]=i<n?S[i]:-1;
    }

    for(k=1;k<=n;k*=2){
        sort(sa,sa+n+1,cmp);

        tmp[sa[0]]=0;//tmp save rank
        for(int i=1;i<=n;i++)
            tmp[sa[i]]=tmp[sa[i-1]]+(cmp(sa[i-1],sa[i])?1:0);

        for(int i=0;i<=n;i++) rank[i]=tmp[i];
    }
}
void LCP(string S,int *sa,int *lcp){
    n=S.length();
    for(int i=0;i<=n;i++) rank[sa[i]]=i;
    int h=0;
    lcp[0]=0;
    for(int i=0;i<n;i++){
        int j=sa[rank[i]-1];
        if(h>0) h--;
        for(;j+h<n && i+h<n;h++)
            if(S[j+h]!=S[i+h]) break;
        lcp[rank[i]-1]=h;
    }
}

string S;
int N,sa[maxn],lcp[maxn];

bool check(int m){
    for(int i=n-1;i>=0;i--){
        if(lcp[i]<m) continue;
        for(int j=i+1;j<n;j++){
            if(abs(sa[i]-sa[j])>=m) return 1;
            if(lcp[j]<m) break;
        }
    }
    return 0;
}

void init(){
    S.clear();
    memset(sa,0,sizeof(sa));
    memset(lcp,0,sizeof(lcp));
}

void solve(){
    int last=0;
    for(int i=0;i<N;i++){
        int x;scanf("%d",&x);
        if(i) S.push_back(x-last+'0');
        last=x;
    }

    SA(S,sa);
    LCP(S,sa,lcp);

    int l=3,r=n,ans=1;
    for(int i=0;l<r;i++){
        int m=(l+r)>>1;
        if(check(m)){
            l=m+1, ans=m;
        }else r=m;
    }
    if(ans>=4) printf("%d\n",ans+1);
    else puts("0");
}

int main()
{
    //freopen("1.in","r",stdin);
    while(~scanf("%d",&N) && N){
        init();
        solve();
    }
    return 0;
}

