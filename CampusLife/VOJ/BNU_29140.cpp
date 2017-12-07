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
#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int,int> PII;
typedef long long ll;

const int maxn =1e6;

//f[i]=sum(p^k)(1<=k<=i)，那么ans[i]=ans[i-1]+f[i]，
//进而得到：ans[n]=sum((n+1-i)*p^i)(1<=i<=n)
int main()
{
    //freopen("r.txt","r",stdin);
    int T; scanf("%d",&T);
    while(T--){
        int N; scanf("%d",&N);
        double p;scanf("%lf",&p);
        double ans=0,temp;
        if(p==1)
            ans=1.0*(N+1)*N/2;
        else{
            temp=1;
            for(int i=1;i<=N;i++){
                temp*=p;
                ans+=(N+1-i)*temp;
            }
        }
        printf("%.6lf\n",ans);
    }
    return 0;
}
