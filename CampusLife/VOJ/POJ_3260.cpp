/***
	背包
***/
#include<stdio.h>
#include<string.h>
const int T = 14400+1;
const int T2 = T+14400+2;
const int N = 101;
int change[T];//change[i]表示商店找钱i所需的硬币数
int dp[T2];//dp[i]表示用户付钱i所需硬币数
int c[N];
int v[N];
long long upper;
inline int min(int a,int b)
{
    if(a==-1)return b;
    return a<b?a:b;
}
void init(int n)
{
   memset(change,-1,sizeof(change));
   int i,j;
   upper = 0;
   change[0]=0;
   for(i=0;i<n;i++)
   {
       for(j=v[i];j<T;j++)
       {
           if(change[j-v[i]]!=-1)
           change[j]=min(change[j],change[j-v[i]]+1);
       }
   }
}
 
void zeroOnePack(int v,int c)
{
    long long i;
    for(i=upper;i>=v;i--)
    {
        if(dp[i-v]!=-1)
        dp[i]=min(dp[i],dp[i-v]+c);
    }
}
int main()
{
    int n,t;
    while(scanf("%d%d",&n,&t)!=EOF)
    {
        int i;
        for(i=0;i<n;i++)
            scanf("%d",&v[i]);
        for(i=0;i<n;i++)
            scanf("%d",&c[i]);
 
        if(t==0)
        {
            printf("0\n");
            continue;
        }
        init(n);
 
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        upper = 0;
        for(i=0;i<n;i++)
        {
              upper=upper+c[i]*v[i];
              if(upper>=T2)upper = T2-1;
              int count = 1;
              while(count<c[i])
              {
                  zeroOnePack(v[i]*count,count);
                   c[i]-=count; 
                   count<<=1;
                 
              }
              zeroOnePack(v[i]*c[i],c[i]);
        } 
 
 
        int ans = -1;
         
        for(i=t;i<=upper;i++)
            if(dp[i]!=-1&&(i-t)<T&&change[i-t]!=-1)
            ans=min(ans,dp[i]+change[i-t]);
 
            printf("%d\n",ans);
    }
    return 0;
}