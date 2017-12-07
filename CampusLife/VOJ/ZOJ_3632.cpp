#include <cstdio>
#include <cstring>

using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define maxn 55555
typedef long long ll;
ll inf=0;
ll n,p[maxn],v[maxn];
ll Min[maxn<<2];

ll min(ll a,ll b)
{
	if(a<b) 
		return a;
	else 
		return b;
}
void PushUp(int rt){Min[rt]=min(Min[rt<<1],Min[rt<<1|1]);}
void Build(int l,int r,int rt)
{
	Min[rt]=inf;
	if(l==r) return;
	int m=(l+r)>>1;
	Build(lson);Build(rson);
}
void Update(int p,ll x,int l,int r,int rt)
{
	if(l==r)
	{
		Min[rt]=x;
		return;
	}
	int m=(l+r)>>1;
	if(p<=m) Update(p,x,lson);
	else	 Update(p,x,rson);
	PushUp(rt);
}
ll Query(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R) return Min[rt];
	int m=(l+r)>>1;
	ll ret=inf;
	if(L<=m) ret=min(Query(L,R,lson),ret);
	if(R>m)  ret=min(Query(L,R,rson),ret);
	return ret;
}

int main()
{
	while(~scanf("%lld",&n))
	{
		ll ans=0;
		inf=0;
		for(int i=1;i<=n;i++) scanf("%lld",&p[i]),inf+=p[i];
		for(int i=1;i<=n;i++) scanf("%lld",&v[i]);
		Build(1,n,1);
		for(int i=n;i>=1;i--)
		{
			int l=i+1,r=i+v[i];
			if(r>n) ans=p[i];
			else ans=Query(l,r,1,n,1)+p[i];
			Update(i,ans,1,n,1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}