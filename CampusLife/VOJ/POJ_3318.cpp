/**解题思路
由于两矩阵相乘的运算量很大，为0(n^3)所以直接运算必定超时，这是需要将运算简化，
数学中有这样一个定理，如果X*A*B=X*C那么基本就可以认为A*B=C，定理数学上严格证明是错误的(x为当前意义下的0)。
不过有很大几率正确。我们可以用这个公式简化运算的过程，用一个行矩阵X左乘等式两端，
那么算法即可转化成O(n^2)，现在问题就是怎么取这个X，只要取值均匀，随机化一次！！，一次即可，所以第二次是用1到n的n个数字。
**/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
ll a[510][510],b[510][510],c[510][510];
ll d[510],e[510],f[510],x[510];
int main()
{
         ll n,i,j,randNum;
         while(scanf("%lld",&n)!=EOF)
         {
                   randNum=10;
                   for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%lld",&a[i][j]);
                   for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%lld",&b[i][j]);
                   for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%lld",&c[i][j]);
                   for(i=0;i<n;i++) x[i]=i;
                   for(i=0;i<n;i++) f[i]=d[i]=e[i]=0;
                   for(i=0;i<n;i++) for(j=0;j<n;j++)
                   {
                        e[i]+=b[i][j]*x[j];//矩阵E
                        f[i]+=c[i][j]*x[j];//矩阵F
                   }
                   for(i=0;i<n;i++) for(j=0;j<n;j++)
                        d[i]+=a[i][j]*e[j];//矩阵D
                   for(i=0;i<n;i++) if(d[i]!=f[i]) break;
                   if(i<n) printf("NO\n");
                   else printf("YES\n");
         }
         return 0;
}