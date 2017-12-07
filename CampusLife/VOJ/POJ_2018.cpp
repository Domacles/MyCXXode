/***
	二分average，然后用每个a[i]减去二分值，然后求最大连续子段和，再求长度大于等于f的最大子段和    
***/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;

#define inf 99999999
#define maxn 100050
#define eps 1e-6

double sum[maxn],a[maxn],b[maxn],dp[maxn],maxx[maxn];
int main()
{
    int n,m,i,j,f,ant;
    double l,r,mid,ans;
    while(scanf("%d%d",&n,&f)!=EOF)
    {
        l=2000.0;r=1.0;
        for(i=1;i<=n;i++){
            scanf("%lf",&a[i]);
            l=min(l,a[i]);
            r=max(r,a[i]);
        }
        while(r-l>eps){
            mid=(l+r)/2.0;
            sum[0]=0;maxx[0]=0;
            for(i=1;i<=n;i++){
                b[i]=a[i]-mid;
                sum[i]=sum[i-1]+b[i];
                maxx[i]=max(b[i],maxx[i-1]+b[i]);
            }
            ans=sum[f];
            for(i=f+1;i<=n;i++){
                dp[i]=maxx[i-f+1]+sum[i]-sum[i-f+1];
                if(ans<dp[i])ans=dp[i];
            }
            if(ans>=0)l=mid;
            else r=mid;
        }
        ant=1000*r;
        printf("%d\n",ant);
    }
    return 0;
}
