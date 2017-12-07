#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
#define maxn 333
typedef long long ll;
ll dp[maxn],p[maxn],sum[maxn],n,S;
ll Max,flag;
bool cmp(ll a,ll b){return a>b;}

void DFS(int k,ll s)
{
	if(s==S) {Max=S,flag=1;return;}
	if(k==n+1){Max=max(Max,s);}
	else{
		if(s+sum[n]-sum[k-1]<Max) return;
		if(s+p[k]<=S) DFS(k+1,s+p[k]);
		DFS(k+1,s);
	}
}

int main()
{
	while(~scanf("%lld%lld",&n,&S))
	{
		for(int i=1;i<=n;i++) scanf("%lld",&p[i]);
		sort(p+1,p+1+n,cmp);
		for(int i=1;i<=n;i++) sum[i]=sum[i-1]+p[i];
		Max=flag=0;
		DFS(1,0);
		printf("%lld\n",Max);
	}
	return 0;
}