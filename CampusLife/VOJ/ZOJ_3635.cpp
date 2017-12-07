#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
#define lson  l,m,rt<<1
#define rson  m+1,r,rt<<1|1
const int maxn =  55000;
int sum[maxn<<2] , ans[maxn] , q[maxn];

void PushUp(int rt){sum[rt]=sum[rt<<1]+sum[rt<<1|1];}

void Build(int l,int r,int rt){
	if(l==r){
		sum[rt]=1;return;
	}
	int m=(l+r)>>1;
	Build(lson);	Build(rson);	PushUp(rt);
}

int Update(int x,int l,int r,int rt){
	if(l==r){
		sum[rt]=0;
		return l;
	}
	int ans , m=(l+r)>>1;
	if(x<=sum[rt<<1]) ans=Update(x,lson);
	else ans=Update(x-sum[rt<<1],rson);
	PushUp(rt);
	return ans;
}

int main()
{
	int n,m;
	while(~scanf("%d",&n)){
		memset(sum,0,sizeof(sum));
		Build(1,n,1);
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			ans[i]=Update(x,1,n,1);
		}
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
			scanf("%d",&q[i]);
		for(int i=1;i<=m;i++)
			printf("%d%c",ans[q[i]],(i==m?'\n':' '));
	}
	return 0;
}