#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=20;
long long f[25],stir[25][25];
int solve(){
    int i,j;
    f[0]=1;
    for(i=1;i<=maxn;i++)
        f[i]=i*f[i-1];
            //因为N有N！种排列顺序，这作为总数
        //计算概率
    for(i=1;i<=maxn;i++)
        stir[i][0]=0;
    stir[1][1]=1;
    for(i=1;i<=maxn;i++)
        for(j=1;j<=i;j++){
            if(i==j)
                stir[i][j]=1;
            else
                stir[i][j]=stir[i-1][j-1]+(i-1)*stir[i-1][j];
        }
    for(i=1;i<=maxn;i++)
        for(j=1;j<=maxn;j++)
            if(stir[i][j]<0)
                stir[i][j]=-stir[i][j];
    return 0;
}
int main(){
    int cas,n,i,k;
    long long sum;
    solve();
    scanf("%d",&cas);
    while(cas--){
        scanf("%d %d",&n,&k);
        sum=0;
        for(i=1;i<=k;i++)
            sum+=stir[n][i]-stir[n-1][i-1];
        printf("%.4lf\n",1.0*sum/f[n]);
    }
    return 0;
}