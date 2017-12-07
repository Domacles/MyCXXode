#include <map>
#include <set>
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

const int maxn =1e5+111;
const double eps= 1e-5;

double dp[322][322],A,B,C;
int a[322],N,K,x;
vector<int>b;

void init()
{
    fill(dp[0],dp[N+1],-1);
    b.clear();
}

double solve(int l,int r)
{
    if(l>r)
        return 0;
    else if(dp[l][r]>=0)
        return dp[l][r];
    else{
        int has=r-l+1;
        double &ret=dp[l][r];
        ret=0;
        for(int i=l;i<=r;i++)
            ret+=A*(a[i]==x?1.0:0)+B*solve(l,i-1)+C*solve(i+1,r);
        ret/=has;
        return ret;
    }
}

int main()
{
    freopen("1.in","r",stdin);
    while(~scanf("%d",&N) && N>=0){
        init();
        for(int i=1;i<=N;i++)
            scanf("%d",&a[i]), b.push_back(a[i]);
        scanf("%d%lf%lf",&K,&A,&B);
        C=1.0-A-B;
        sort(b.begin(),b.end());
        if(unique(b.begin(),b.end())-b.begin()<K){
            x=-1;
        }
        else x=b[K-1];
        printf("%.3lf\n",solve(1,N));
    }
    return 0;
}

