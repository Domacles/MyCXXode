/*********
	F[i]表示取[M,i]这个区间的代价
	显然F[M-1]=0,答案就是F[E]
	则方程为F[a[i].T2]=min(F[j])+a[i].S (T1-1<=J<=T2-1)
	a[i]按T2从小到大排列；
	那么显然a[i]取时，[M,T1-1]已经被前面的给取了，
	因为如果被后面的[t1,t2] 取了,那么必有t1<T1 T2<t2， 就没必要取[T1,T2]了。
*********/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<iostream>
#include<functional>
#include<algorithm>
using namespace std;
#define MAXN (10000+10)
#define MAXE (86399)
#define MAXS (500000+10)
#define INF (9187201950435737471)
int n,s,e;
struct SegMent
{
	int l,r;
	long long S;
	SegMent(){}
	SegMent(int _l,int _r,long long _S):l(_l),r(_r),S(_S){}
	friend bool operator<(const SegMent a,const SegMent b){return a.r<b.r;}
}a[MAXN];
struct SegMentTree //min()
{
	int n,M;
	long long t[MAXE*10];
	void fillchar(int _n)
	{
		n=_n+2;
		M=1;while (M-2<n) M<<=1;
		memset(t,127,sizeof(t));
	}
	void update(int x)
	{
		for (x>>=1;x;x>>=1) t[x]=min(t[x<<1],t[(x<<1)^1]);
	}
	void insert(int x,long long c)
	{
		x=x+2;
		x+=M;
		if (t[x]>c) {t[x]=c; update(x);	}
	}
	long long find(int l,int r)
	{
		l=l+2;r=r+2;
				
		l=l-1+M;r=r+1+M;
		long long ans=INF;
		while (l^r^1)
		{
			if (~l&1) ans=min(ans,t[l+1]);
			if (r&1) ans=min(ans,t[r-1]);
			l>>=1;r>>=1;
		}
		return ans;
	}
}t;
int main()
{
//	freopen("poj3171.in","r",stdin);
	scanf("%d%d%d",&n,&s,&e);
	for (int i=1;i<=n;i++) scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].S);
	sort(a+1,a+1+n);
	t.fillchar(e);
	t.insert(s-1,0);
	for (int i=1;i<=n;i++)
	{
		if (a[i].r<s) continue;
		t.insert(a[i].r,t.find(max(s-1,a[i].l-1),a[i].r-1)+a[i].S);
	}	
/*	for (int i=t.M;i<=t.M*2;i++) cout<<t.t[i]<<' ';
	cout<<endl;
*/	if (t.t[e+2+t.M]==INF) cout<<"-1\n";
	else cout<<t.t[e+2+t.M]<<endl;	
	
	
	return 0;
}