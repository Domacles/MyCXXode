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

int size01(int x){return __builtin_popcount(x);}
#define lson l,m,rt<<1
#define rson m+1,r,rt<<11
#define All 1,N,1

const ll  INFll = 0x3f3f3f3f3f3f3f3fLL;
const int INF= 0x7ffffff;
const int maxn = 1e5+3e4+100;
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
/**********
首先，
    证明结论：对于k个满足相加和为0的集合，使用倒试剂的操作（简称操作），最多需要k-1次操作即可使每一个变成0.
    假设每一个多的都要向少的倒，那至多会有k-1次，如果超过k-1次，那必然有操作可以合并为1次操作。
然后，
    题目要求最少多少次操作。
    假设一个集合A元素个数为N，满足相加和为0(2).那这个集合就可以划分成多个(也可能只有一个)和为0的不相交不可再分的子集，设子集的个数位k。
    不可再分的子集是需要k-1次操作才能使得每一项都为0.因此，
    A的操作数Ans=(k1-1)+(k2-1)+(k3-1)+...+(kc-1)=(k1+k2+k3+..+kc)-c=N-c
    因此，Ans最小，则c应最大。
    即，须将集合划分成多个和为0的集合，且集合个数最多。
最后，
    假设F(S)为S状态下，至多有一个集合和不为0，最多能划分出的集合个数。(1)
    条件(1) & 条件(2) = 条件(1),因此，Ans=N-F(S)，S=(1<<N)-1
**********/

int N,s,a[22],b[2097152],sum[2097152],f[2097152];

void init(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    for(int i=0;i<N;i++){
        int x; scanf("%d",&x);
        s+=(a[i]-=x);
    }
}

void solve(){
    if(s!=0) {
        puts("-1");
        return;
    }
    int S=1<<N;
    for(int i=0;i<N;i++) b[1<<i]=a[i];//1<<i状态下的值
    for(int i=1;i<S;i++){//好思路!!!!!
        int j=i&(-i);
        sum[i]=sum[i^j]+b[j];//!!
    }
    for(int i=1;i<S;i++){
        int k;
        for(int j=i;j;j^=k){
            k=j&(-j);//枚举i状态集合中的每一项
            f[i]=max(f[i],f[i^k]+(sum[i]==b[k]));
            //F(S)是S状态下至多一个和不为0的子集，因此，假设b[k]就是那个子集，那组数就是在i^k(这说明在这种状态下,所有子集和为0)的基础上再+1
            //假设i^k状态下已经有一个和不为0的子集，那b[k]就会被划分到那个子集中，不会sum[i]==b[k]成立
        }
    }
    printf("%d\n",N-f[S-1]);
}

int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    init();
    solve();
    return 0;
}

