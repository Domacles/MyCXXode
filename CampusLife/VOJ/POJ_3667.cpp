#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define All 1,N,1
const int maxn = 55555;

int col[maxn<<2];
int lsum[maxn<<2],rsum[maxn<<2],sum[maxn<<2];
//分别表示左边最大房间数，右边最大房间数，整体最大房间数

void PushDown(int rt,int len){
	if(col[rt]==-1) return;
	col[rt<<1]=col[rt<<1|1]=col[rt];
	if(col[rt]==0){
		sum[rt<<1]=lsum[rt<<1]=rsum[rt<<1]=lsum[rt]=len-(len>>1);
		sum[rt<<1|1]=lsum[rt<<1|1]=rsum[rt<<1|1]=rsum[rt]=len>>1;
	}
	else{
		sum[rt<<1]=lsum[rt<<1]=rsum[rt<<1]=0;
		sum[rt<<1|1]=lsum[rt<<1|1]=rsum[rt<<1|1]=0;
	}
	col[rt]=-1;
}
void PushUp(int rt,int len){
	lsum[rt]=lsum[rt<<1];
	      if(lsum[rt<<1]==len-(len>>1)) lsum[rt]+=lsum[rt<<1|1];
	rsum[rt]=rsum[rt<<1|1];
	      if(rsum[rt<<1|1]==len>>1)     rsum[rt]+=rsum[rt<<1];
	sum[rt]=max(lsum[rt<<1|1]+rsum[rt<<1],
			max(sum[rt<<1],sum[rt<<1|1])
			);
}

void Build(int l,int r,int rt)
{
	col[rt]=-1;
	lsum[rt]=rsum[rt]=sum[rt]=r-l+1;
	if(l==r) return;
	int m=(l+r)>>1;
	Build(lson);
	Build(rson);
}

void Update(int L,int R,int key,int l,int r,int rt)
{
	if(L<=l&&r<=R){
		sum[rt]=lsum[rt]=rsum[rt]=key ? 0:r-l+1;
		col[rt]=key;return;
	}
	PushDown(rt,r-l+1);
	int m=(l+r)>>1;
	if(L<=m) Update(L,R,key,lson);
	if(R>m)  Update(L,R,key,rson);
	PushUp(rt,r-l+1);
}

int query(int len,int l,int r,int rt)
{
	if(l==r) return l;
	PushDown(rt,r-l+1);
	int m=(l+r)>>1;
	if(sum[rt<<1]>=len) 
		 return query(len,lson);
	else if(rsum[rt<<1]+lsum[rt<<1|1]>=len)
		 return m-rsum[rt<<1]+1;
	else return query(len,rson);
}

int N,M;
int main()
{
	scanf("%d%d",&N,&M);
	Build(All);
	for(int i=0;i<M;i++){
		int flag; scanf("%d",&flag);
		if(flag==1){
			int len; scanf("%d",&len);
			if(sum[1]<len) puts("0");
			else {
				int x=query(len,All);
				printf("%d\n",x);
				Update(x,x+len-1,1,All);
			}
		}
		else{
			int x,len;
			scanf("%d%d",&x,&len);
			Update(x,x+len-1,0,All);
		}
	}
	return 0;
}