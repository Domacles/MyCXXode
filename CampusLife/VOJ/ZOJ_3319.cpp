/***
    题目大意：
        N个点的图，边为有向边，现在需要给他们添加边，使得他们每个点仅属于一个环(可能没有办法做到)，问有多少中方法可以做到。

    思路：
        图中的结构可以分成两种： 链和点，链是可以自己加一条边构成环，而点是不允许加一条边构成自环。
        所以，
            我们需要选出几条链和所有的独立点去组合成环，因为选出的链必须要和独立点或者其他被选出的链组成环，所以，
            它的作用与独立点无异，可以看做独立点。并且，这些独立点(包括被选出的链)的重要性质就是，不能自己连自己构成环，
            而可以连其他的独立点，这就是错排方法。

            因此，枚举，ans = sum（要选出的链数*构成新的独立点集的点数）

        思考： 假如允许自环的出现，那本题可以用枚举第一类斯特灵数来解答。

***/
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

char Map[maxn][maxn];
int N, A, B, in[maxn], out[maxn];
int C[maxn][maxn], d[maxn];//组合  错排

void init()
{
    memset(C,0,sizeof(C));
    for(int i=0;i<maxn;i++){
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
    d[0]=1; d[1]=0; d[2]=1;
    for(int i=2;i<maxn;i++)//错排
        d[i]=((d[i-1]+d[i-2])%mod)*(i-1)%mod;
}

bool check()
{
    A=0, B=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(Map[i][j]=='Y')
                out[i]++, in[j]++;
    for(int i=0;i<N;i++){
        if(in[i]>1 || out[i]>1) return 0;
        if(in[i]==0 && out[i]==1) A++;//链数
        if(in[i]==0 && out[i]==0) B++;//独立点数
    }
    return 1;
}

void solve()
{
    ll ans=0;
    for(int i=0;i<=A;i++)
        ans=(ans+(1LL*C[A][i]*d[B+i])%mod)%mod;
    printf("%lld\n",ans);
}

int main()
{
    //freopen("1.in","r",stdin);
    init();
    while(~scanf("%d",&N) && N){
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        for(int i=0;i<N;i++)
            scanf("%s",Map[i]);
        if(check())
            solve();
        else
            puts("0");
    }
    return 0;
}

