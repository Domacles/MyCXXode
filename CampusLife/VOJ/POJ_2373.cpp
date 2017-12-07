//单调队列 + dp
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
#define maxn 1100000
#define INF  2147480000 
int  dp[maxn],que[maxn],N,L,A,B;
bool OK[maxn],flag;

void solve()
{
	for(int i=1;i<=L;i++) dp[i]=INF;
	
	int head=0,tail=-1;
	for(int i=2*A;i<=L;i++){//单调队列：dp[x] && x 递增(x in que) 
		int last=i-2*A;
		
		while(head<=tail && dp[ que[tail] ]>=dp[last]) --tail;
		if(!OK[last]) que[++tail]=last;
		
		if(i&1 || OK[i]) continue;
		
		while(head<=tail && que[head]<i-2*B) ++head;
		if(head<=tail) dp[i]=dp[ que[head] ]+1;
	}
}

int main()
{
	scanf("%d%d%d%d",&N,&L,&A,&B);
	for(int i=0;i<N;i++){
		int l,r; scanf("%d%d",&l,&r);
		for(int j=l+1;j<=r-1;j++) OK[j]=1;
		if(r-l>2*B) flag=1;
	}
	if(flag) puts("-1");
	else {
		solve();
		if(dp[L]>=INF) puts("-1");
		else printf("%d\n",dp[L]);
	}
	return 0;
}	