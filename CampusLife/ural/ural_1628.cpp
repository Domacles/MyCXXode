#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <string>

#define LL long long
#define DB double
#define SI(a) scanf("%d",&a)
#define SD(a) scanf("%lf",&a)
#define SS(a) scanf("%s",a)
#define SF scanf
#define PF printf
#define MM(a,v) memset(a,v,sizeof(a))
#define REP(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define REPD(i,a,b) for(int (i)=(a);(i)>(b);(i)--)
#define N 60009
#define INF 0x3f3f3f3f
#define EPS 1e-8
#define bug puts("bug")
using namespace std;
vector<int> Lx[N],Ly[N];
int n,m,k;
int fin(int x,int y)
{
    int l=0,r=Lx[x].size()-1,mid,ans=0;
    while(l<=r)
    {
        mid = (l+r)>>1;
        if(Lx[x][mid]<=y)
        {
            ans = mid;
            l = mid+1;
        }else
        {
            r = mid-1;
        }
    }
    if(Lx[x][ans]==y&&Lx[x][ans+1]==y+2) return 1;
    return 0;
}
int solve()
{
    int ret = 0;
    REP(i,1,n)
    {
        REP(j,1,(int)Lx[i].size())
        {
            if(Lx[i][j]-Lx[i][j-1]>2)
            ret++;
        }
    }
    REP(i,1,m)
    {
        REP(j,1,(int)Ly[i].size())
        {
            if(Ly[i][j]-Ly[i][j-1]>2)
            ret++;
            if(Ly[i][j]-Ly[i][j-1]==2)
            {
                if(fin(Ly[i][j]-1,i-1))
                ret++;
            }
        }
    }
    return ret;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    SI(n);SI(m);SI(k);
    int a,b;
    REP(i,0,k)
    {
        SI(a);SI(b);
        Lx[a].push_back(b);
        Ly[b].push_back(a);
    }
    n++,m++;
    REP(i,1,n) Lx[i].push_back(0),Lx[i].push_back(m);
    REP(i,1,m) Ly[i].push_back(0),Ly[i].push_back(n);
    REP(i,1,n) sort(Lx[i].begin(),Lx[i].end());
    REP(i,1,m) sort(Ly[i].begin(),Ly[i].end());
    PF("%d\n",solve());
    return 0;
}
