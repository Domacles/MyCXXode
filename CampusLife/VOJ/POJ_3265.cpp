#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=3e2+9;
int a[maxn],b[maxn];
int suma[maxn],sumb[maxn];
int dp[maxn][maxn];//第dp[i][len]月解决从i-len+1到第i个问题 
int main()
{
    int m,p;
    while(scanf("%d %d",&m,&p)!=EOF)
    {
        suma[0]=sumb[0]=0;
        for(int i=1;i<=p;i++)
        {
            scanf("%d %d",&a[i],&b[i]);
            suma[i]=suma[i-1]+a[i];
            sumb[i]=sumb[i-1]+b[i];
        }
        memset(dp,50,sizeof(dp));
        dp[0][0]=0;
        for(int i=0;i<=p;i++) for(int len=i;len>=0;len--){//本月解决从i-len+1到i的问题
			for(int mid=i;mid<=p;mid++){
				if(suma[mid]-suma[i]//下一个月需要解决从i+1到mid的问题
				  +sumb[i]-sumb[i-len]>m) break;
				if(suma[mid]-suma[i]>m)   break;//下下月要支付的after
				dp[mid][mid-i]=min(dp[mid][mid-i],dp[i][len]+1);
			}
		}
		printf("%d\n",dp[p][0]+1);
    }
    return 0;
}