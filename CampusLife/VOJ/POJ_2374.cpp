/**
	线段树+dp
	用dp[i].A表示到达挡板i往左走到端点的最小距离和，dp[i].B表示到达挡板i往右走的最小距离和。
**/
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

#define maxn 220000
#define maxr 100001
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

struct Node{int l,r,x;} Tree[maxn<<2];
struct FFFF{int l,r;} F[maxn];
int dp[maxn][2];
int N,S;

void Build(int l,int r,int rt)
{
	Tree[rt].l=l,Tree[rt].r=r;
	Tree[rt].x=0;
	if(l==r) return;
	int m=(l+r)>>1;
	Build(lson);
	Build(rson);
}

void Updata(int L,int R,int key,int rt)
{
	int l=Tree[rt].l , r=Tree[rt].r;
	if(L<=l && r<=R){
		Tree[rt].x=key;
		return ;
	}
	int m=(l+r)>>1;
	if(L<=m)Updata(L,R,key,rt<<1);
	if(R>m)	Updata(L,R,key,rt<<1|1);
}

int Query(int pos,int rt)
{
	int l=Tree[rt].l,r=Tree[rt].r;
	if(l==r) return Tree[rt].x;
	int m=(l+r)>>1;
	int ret=0;
	if(pos<=m) ret=Query(pos,rt<<1);
	else ret=Query(pos,rt<<1|1);
	return max(ret,Tree[rt].x);//不必垂直落下，可以沿着fence走~~
}

int Answer(int x,int pos)
{
	if(!x) return abs((double)(pos-maxr));
	else
		return min( F[x].r-pos + dp[x][1] , pos-F[x].l + dp[x][0] );
}

int main()
{
	//freopen("D://r1.txt","r",stdin);
	scanf("%d%d",&N,&S);
	S+=maxr;
	Build(1,maxr*2,1);
	for(int i=1;i<=N;i++){
		scanf("%d%d",&F[i].l,&F[i].r);
		F[i].l+=maxr;
		F[i].r+=maxr;
		dp[i][0]=Answer(Query(F[i].l,1),F[i].l);
		dp[i][1]=Answer(Query(F[i].r,1),F[i].r);
		Updata(F[i].l,F[i].r,i,1);
	}
	 printf("%d\n",min(S-F[N].l+dp[N][0],F[N].r-S+dp[N][1]));
	return 0;
}
