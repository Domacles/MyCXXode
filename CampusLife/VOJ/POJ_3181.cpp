/**********
	a[i][j]：用1~j来拼接i(完全背包)
	a[i][j]=a[i][j-1]+a[i-j][j] //a[i][j-1]->不使用j，a[i-j][j]->使用了j
*********
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long a[1100][110],b[1100][110],inf;

int main(){
    int n,k,i,j;
    for(inf=1,i=0;i<18;i++) inf*=10;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    scanf("%d%d",&n,&k);
    for(i=0;i<=k;i++) a[0][i]=1;
    for(i=1;i<=k;i++){
        for(j=1;j<=n;j++){
            if(j-i<0){
                b[j][i]=b[j][i-1];
                a[j][i]=a[j][i-1];
                continue;
            }
            b[j][i]=b[j][i-1]+b[j-i][i]+(a[j][i-1]+a[j-i][i])/inf;
            a[j][i]=(a[j][i-1]+a[j-i][i])%inf;
        }
    }
    if(b[n][k]) printf("%I64d",b[n][k]);
    printf("%I64d\n",a[n][k]);
    return 0;
}
**********/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long a[1100],b[1100],inf;

int main()
{
    int n,k,i,j;
    for(inf=1,i=0;i<18;i++) inf*=10;
    scanf("%d%d",&n,&k);
    a[0]=1;
    for(i=1;i<=k;i++){
        for(j=1;j<=n;j++){//完全背包，正着装
            if(j-i<0) continue;
            b[j]=b[j]+b[j-i]+(a[j]+a[j-i])/inf;
            a[j]=(a[j]+a[j-i])%inf;
        }
    }
    if(b[n]) printf("%I64d",b[n]);
    printf("%I64d\n",a[n]);
    return 0;
}