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
typedef long long ll;

const int maxn = 1e4+11;

int   P[maxn],Size;
bool is[maxn];

void init()
{
    memset(is,0,sizeof(is));
    for(int i=2;i<maxn;i++){
        if(is[i]) continue;
        for(int j=i+i;j<maxn;j+=i)
            is[j]=1;
        P[Size++]=i;
    }
}

int S[maxn],X;

int main()
{
    freopen("r.txt","r",stdin);
    init();
    while(~scanf("%d",&X)){
        int ans=0, num=0;
        ll res=1;
        memset(S,0,sizeof(S));

        for(int i=0;i<Size;i++){
            if(X%P[i]!=0) continue;
            if(X<P[i])    break;
            while(X%P[i]==0)
                S[num]++, X/=P[i];
            ans+=S[num];
            num++;
        }
        if(X!=1) S[num++]=1, ans++;
        for(int i=1;i<=ans;i++) res*=i;
        for(int i=0;i<num;i++)
            for(int j=1;j<=S[i];j++)
                res/=j;
        printf("%d %I64d\n",ans,res);
    }
    return 0;
}
