#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int N = 300050;
int n,a[N],l[N],r[N],ans[N],len;
int main()
{
    while(scanf("%d",&n)!=-1)
    {
        for(int i=1;i<=n;++i)
        {
            scanf("%d",a+i);
            l[i]=r[i]=i;
            while(l[i]>1&&a[l[i]-1]%a[i]==0) l[i]=l[l[i]-1];//,cout<<i<<" "<<l[i]<<endl;
        }
        int mx=0;
        for(int i=n;i>=1;--i)
        {
            while(r[i]<n&&a[r[i]+1]%a[i]==0)
                r[i]=r[r[i]+1];

            if(r[i]-l[i]>mx) mx=r[i]-l[i];
        }
//        for(int i=1;i<=n;++i)
//            printf("%d %d %d\n",i,l[i],r[i]);
        len=0;
        for(int i=1;i<=n;++i)
            if(r[i]-l[i]==mx) ans[++len]=l[i];
        sort(ans+1,ans+1+len);
        len=unique(ans+1,ans+1+len)-ans-1;
        printf("%d %d\n",len,mx);
        for(int i=1;i<=len;++i)
            printf(i==len?"%d\n":"%d ",ans[i]);
    }
    return 0;
}
/**
Quite simple note: if the pair (l, r) satisfies the condition 1 from the statements, then min(l, r) = GCD(l, r), where min(l, r) is smallest number ai from the segment (l, r) and GCD(l, r) is a GCD of all numbers from the segment (l, r). Calculate some data structure that will allow us to respond quickly to requests GCD(l, r) and min(l, r). For example, you can use Sparce Table. Solutuions, that uses segment tree, is too slow. So I think, you should use Sparce Table. So, now our task quite simple. Let's use binary search to find greatest value of r - l:

lf = 0;  //left boundary of binary search
rg = n;  //right boundary of binary search
while (rg - lf > 1) {
  int mid = (lf + rg) / 2;
  if (ok(mid))   //ok(mid)
    lf = mid;
  else
    rg = mid;
}
ok(mid) is the function, that determines, is there some segment where min(l, r) = GCD(l, r) and mid = r - l (mid — is fixed value by binary search). If there is some good segment, you should update boundaries of binary search correctly. After that, it's very simple to restore answer.
**/
