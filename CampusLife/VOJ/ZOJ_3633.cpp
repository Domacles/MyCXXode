#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>

using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn = 550000;

int Max[maxn<<2],before[maxn],a[maxn];

void PushUp(int rt){Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);}

void Build(int l,int r,int rt){
	if(l==r){
		Max[rt]=before[l];return;
	}
	int m=(l+r)>>1;
	Build(lson);	Build(rson);	PushUp(rt);
}

int Query(int L,int R,int l,int r,int rt){
	if(L<=l&&r<=R) return Max[rt];
	if(l==r) return 0;
	int m=(l+r)>>1;
	int ret1=0,ret2=0;
	if(L<=m) ret1=Query(L,R,lson);
	if(R>m)  ret2=Query(L,R,rson);
	if(ret1>=L)
    {
        if(ret2>=L) return max(ret1,ret2);
        return ret1;
    }
    if(ret2>=L) return ret2;
    return 0;
}

int main()
{
	int n,m;
	while(~scanf("%d",&n))
	{
		map<int,int>v;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			before[i]=v[a[i]];
			v[a[i]]=i;
		}
		Build(1,n,1);
		scanf("%d",&m);
		for(int i=1;i<=m;i++){
			int l,r;scanf("%d%d",&l,&r);
			int ret=Query(l,r,1,n,1);
			if(ret)	printf("%d\n",a[ret]);
			else puts("OK");
		}
		puts("");
	}
	return 0;
}