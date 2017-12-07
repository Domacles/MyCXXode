/****
    ¶þ·ÖÅÐ¶¨
****/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;
const int maxn=111;
int n,C,P,T;
int a[maxn];
int b[maxn];
bool Can(int ans){
    LL cur=0,toPick;
    int p=0;
    for (int i=1;i<=n;i++){
        cur+=a[i];
        if (cur>=ans){
            p=i;
            toPick=ans-(cur-a[i]);
            break;
        }
    }
    LL ret=((toPick-1)/C+1)*p*2;
    int capa=C-(toPick-1)%C-1;
    for (int i=p-1;i>=1;i--){
        if (a[i]<=capa){
            capa-=a[i];
        }
        else{
            toPick=a[i]-capa;
            ret+=((toPick-1)/C+1)*i*2;
            capa=C-(toPick-1)%C-1;
        }
    }
    return ret*P<=T;
}

int main()
{
    while (~scanf("%d%d%d%d",&n,&C,&P,&T)){
        LL l=0,r=0;
        for (int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            r+=a[i];
        }
        LL ans=0;
        while (l<=r){
            LL mid=(l+r)>>1;
            if (Can(mid)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
