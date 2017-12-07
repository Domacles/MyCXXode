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

const int maxn = 1e6;
int N;
int a[maxn];
ll sum[maxn];

bool check1(int k,int x,int y){
    if(k==1) return x>y;
    return x<y;
}
bool check2(int k,int x,int y){
    if(k==1) return x>=y;
    return x<=y;
}

ll solve(int n,int k)
{
    ll ret=0;
    memset(sum,0,sizeof(sum));
    stack<int>s;
    for(int i=0;i<n;i++){
        while(!s.empty() && check1(k,a[i],a[s.top()])) s.pop();
        if(s.empty()) sum[i]=i;
        else sum[i]=i-1-s.top();
        s.push(i);
    }
    while(!s.empty()) s.pop();
    for(int i=n-1;i>=0;i--){
        ll temp=0;
        while(!s.empty() && check2(k,a[i],a[s.top()])) s.pop();
        if(s.empty()) temp=n-i-1;
        else temp=s.top()-i-1;
        ret+=(temp+1)*(sum[i]+1)*a[i];
        s.push(i);
    }
    return ret;
}


int main()
{
    freopen("r.txt","r",stdin);
    scanf("%d",&N);
    int cas=0;
    while(N--){
        ll ans=0;
        int n;scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        ans+=solve(n,1);
        ans-=solve(n,0);
        ans+=1LL*n*(n+1)/2;
        printf("Case %d: %I64d\n",++cas,ans);
     }
    return 0;
}
