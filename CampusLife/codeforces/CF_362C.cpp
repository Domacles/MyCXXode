#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

#define N 5005

int dp[N][N];
int num[N];

int main()
{
    freopen("r1.txt","r",stdin);
    int n,i,j;
    int r,t;
    int min,c;
    while(scanf("%d",&n)==1)
    {
        t=0;
        for(i=1; i<=n; i++) scanf("%d",&num[i]);
        for(i=1; i<=n; i++)
        {
            for(j=i+1; j<=n; j++) dp[i][j]=dp[i][j-1]+(num[j]<num[i]);//計算逆序數對
            for(j=i-1; j>=1; j--) dp[i][j]=dp[i][j+1]+(num[j]<num[i]);//為了之後交換(i,j)做準備
            t+=dp[i][n];//總逆序數對
        }
        min=n*n;
        for(i=1; i<=n; i++)
            for(j=i+1; j<=n; j++)
                if(num[i]>num[j])
                {
                    r=t-2*(dp[i][j-1]-dp[j][i+1])-1;//交換i,j之後的變化
                    if(r<min) min=r,c=0;
                    if(r==min) c++;//計算幾對(i,j)可以達到min
                }
        printf("%d %d\n",min,c);
        //printf("%d\n",t-min);
        /*
        for(i=0;i<n;i++)
        {
           for(j=0;j<n;j++) printf("%d ",dp[i][j]);
           printf("\n");
        }
        printf("t=%d\n",t);
        */
    }
    return 0;
}