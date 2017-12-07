#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;
typedef long long ll;
#define maxn 11000
#define lson l,  m,rt<<1
#define rson m+1,r,rt<<1|1
vector<int>w[maxn];
ll ans;
int n,a[maxn*11];
int Min[(maxn<<2)*111];

void build(int l,int r,int rt)
{
	int m=(l+r)>>1;
	if(l==r)
	{
		Min[rt]=a[l];return ;
	}
	build(lson);
	build(rson);
	Min[rt]=min(Min[rt<<1],Min[rt<<1|1]);
}

int query(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R)
		return Min[rt];
	int m=(l+r)>>1;
	int ret=0x7fffffff;
	if(L<=m)
		ret=min(ret,query(L,R,lson));
	if(R>m)
		ret=min(ret,query(L,R,rson));
	return ret;
}

void Find(int l,int r,int now)
{
	int minx=query(l,r,1,n,1);
	ans+=minx-now;
	int Size=w[minx].size();
	int last=l;
	for(int i=0;i<Size;i++)
	{
		if(w[minx][i]<l) continue;
		if(w[minx][i]>r) break;
		if(w[minx][i]==last)
		{
			last++;continue;
		}
		if(last<w[minx][i])
			Find(last,w[minx][i]-1,minx);
		last=w[minx][i]+1;
	}
	if(last<=r)
		Find(last,r,minx);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		w[a[i]].push_back(i);
	}
	build(1,n,1);
	Find(1,n,0);
	printf("%lld\n",ans);
	return 0;
}
/***标准答案
#include <cstdio>
#define MAXN 100010
int h[MAXN],ans=0,n;
int main() 
{
    h[0]=0;
    scanf("%d",&n);
    for (int i=0;i<n;i++) 
	{
        scanf("%d",&h[i]);
        if (h[i]>h[i-1]) ans+=h[i]-h[i-1];
    }
    printf("%d\n",ans);
    return 0;
}
***/