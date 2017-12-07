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
#define rson m+1,r,rt<<1|1

const ll  INFll = 0x3f3f3f3f3f3f3f3fLL;
const int INF= 0x7ffffff;
const int maxn = 1e5+100;
const int mod = 1000000007;

const double pi = acos(-1);
const double eps = 1e-5;

typedef complex<double> Point;
typedef complex<double> Vector;
#define X real()
#define Y imag()
Vector rotate(Vector v, double a) {return v*polar(1.0, a);}

#define intV vector<int>
#define intD vector<double>

//for_each()
struct Solve1{
    bool operator()(intV &a){//Class
        return 0;
    }
};
/***
    题目大意:
        某种操作[l,r] : 可以将a[l] ~~ a[r]这一段所有的数值全部加1
        使用这种操作将数列A所有数字变成h,但要求每个数字至多做为两次l,r

    思路:
        先求出每个元素需要多少次才能够到达h~~~
        然后求出前后差值,进行l,r匹配统计~~

        如果b[i]==1,则可作为l, cnt++
        如果b[i]==-1,则可作为r, ans*=cnt , cnt--,
        如果b[i]==0,则即可作为l,又可作为r,ans+=ans*cnt
        如果b[i]==other, ans=0
***/

vector<int> A,B;
int N,H;

int main()
{
    //freopen("1.in","r",stdin);
    while(~scanf("%d%d",&N,&H)){
        //init();
        for(int i=0;i<N;i++){
            int x; scanf("%d",&x);
            A.push_back(H-x);
        }
        for(int i=0;i<N;i++){
            if(i==0) B.push_back(A[i]);
            else
                B.push_back(A[i]-A[i-1]);
        }
        B.push_back(0-A[N-1]);
        ll cnt=0,ans=1;
        for(int i=0;i<=N;i++){
            if(B[i]==1) cnt++;
            else if(B[i]==-1){
                ans=ans*cnt%mod;
                cnt--;
            }else if(B[i]==0)
                ans=ans*(cnt+1)%mod;
            else {ans=0;break;}
        }
        printf("%I64d\n",ans%mod);
    }
    return 0;
}




