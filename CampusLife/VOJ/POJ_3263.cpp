#include <cstdio>
#include <utility>
#include <set>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
#define All 1,N,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define maxn 11111
typedef pair<int,int> PII;
typedef long long ll;
set<PII>S;
int height[maxn],N,I,H,M;
ll  sum[maxn<<2],col[maxn<<2];

void PushDown(int rt,int len){
	if(col[rt]){
		col[rt<<1]+=col[rt];
		col[rt<<1|1]+=col[rt];
		col[rt]=0;
	}
}

void Update(int L,int R,int l,int r,int rt)
{
	int len=r-l+1;
	if(L<=l&&r<=R){
		col[rt]++;
		return;
	}
	PushDown(rt,len);
	int m=(l+r)>>1;
	if(L<=m) Update(L,R,lson);
	if(R>m)  Update(L,R,rson);
}

void Query(int l,int r,int rt)
{
	int len=r-l+1;
	if(l==r){
		height[l]=H-col[rt];
		return;
	}
	PushDown(rt,len);
	int m=(l+r)>>1;
	Query(lson);
	Query(rson);
}


int main()
{
	scanf("%d%d%d%d",&N,&I,&H,&M);
	for(int i=0;i<M;i++){
		int l,r;scanf("%d%d",&l,&r);// h[r]>=h[l]
		int L=l,R=r;
		if(L>R) swap(L,R);
		L++,R--;
		if(!S.count(PII(L,R))) S.insert(PII(L,R));
		else continue;
		if(L<=R) Update(L,R,All);
	}
	Query(All);
	for(int i=1;i<=N;i++)
		printf("%d\n",height[i]);
	return 0;
}
/***********
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e4+9;
struct D
{
    int l,r;
    bool operator <(const struct D & xx) const
    {
        if(l==xx.l)
        return r<xx.r;
        return l<xx.l;
    }
}qry[maxn];
int dp[maxn];
int main()
{
    int n,m,h,r;
    scanf("%d %d %d %d",&n,&m,&h,&r);
    for(int i=1;i<=r;i++)
    {
        scanf("%d %d",&qry[i].l,&qry[i].r);
        if(qry[i].l>qry[i].r)
        swap(qry[i].l,qry[i].r);
    }
    sort(qry+1,qry+1+r);
    qry[0].l=0;
    for(int i=1;i<=r;i++)
    {
        if(qry[i].l==qry[i-1].l&&qry[i].r==qry[i-1].r)
        continue;
        dp[qry[i].l+1]--;
        dp[qry[i].r]++;
    }
    int ret=0;
    for(int i=1;i<=n;i++)
    {
        ret+=dp[i];
        printf("%d\n",ret+h);
    }
    return 0;
}

***********/