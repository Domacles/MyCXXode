/*
    MEMO:模拟
*/
#include<cstdio>
int a[10];
int main()
{
    int k,n,x;
    scanf("%d%d",&k,&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        a[x/1000]++;
    }
    int ans=0;
    for (int i=1;i<=9;i++)
        if (a[i]%k==0) ans+=a[i]/k;
        else ans+=a[i]/k+1;
    printf("%d",ans+2);
}