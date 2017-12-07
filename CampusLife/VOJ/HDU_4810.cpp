#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int,int> PII;
typedef unsigned long long ull;

const int maxs = 65 ;
const int maxn = 1e6;
const int mod= 1e6+3;
int s[maxs];
ull b[maxs],C[1111][1111];

void init()
{
    b[0]=1;
    for(int i=1;i<maxs;i++) b[i]=b[i-1]*2%mod;
    memset(C,0,sizeof(C));
    C[0][0]=1;//!!!!!!!!!!!
    for(int i=1;i<1111;i++){
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
}

int main()
{
    freopen("r.txt","r",stdin);
    int N;
    init();
    while(~scanf("%d",&N)){
            memset(s,0,sizeof(s));
        for(int i=0;i<N;i++){
            int x; scanf("%d",&x);
            int cnt=0;
            while(x){
                s[cnt]+=x&1; x>>=1; cnt++;
            }
        }

        for(int i=1;i<=N;i++){
            ull ans=0;
            for(int j=0;j<maxs/2;j++){
                for(int k=1;k<=s[j] && k<=i;k+=2){
                    ull temp=0;
                    if(N-s[j]<i-k) continue;
                    temp=((ull)C[s[j]][k]*C[N-s[j]][i-k])%mod;
                    temp=(temp*b[j])%mod;
                    ans=(ans+temp)%mod;
                }
            }
            if(i>1) printf(" ");
            printf("%I64d",ans);
        } printf("\n");
    }
    return 0;
}
