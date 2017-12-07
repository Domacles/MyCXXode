/**********
//RMQ
#include <cstdio>
#include <iostream>

using namespace std;
#define maxn 55000
#define All  1,N,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int Max[maxn<<2],Min[maxn<<2];
int N,M,height[maxn];


void PushUp(int rt){Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);
					Min[rt]=min(Min[rt<<1],Min[rt<<1|1]);
}

void Build(int l,int r,int rt)
{
	if(l==r){
		Max[rt]=Min[rt]=height[l];
		return ;
	}
	int m=(l+r)>>1;
	Build(lson);
	Build(rson);
	PushUp(rt);
}

int Query_Min(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R)
		return Min[rt];
	int m=(l+r)>>1;
	int val=0x3fffffff;
	if(L<=m) val=min(val,Query_Min(L,R,lson));
	if(R>m)  val=min(val,Query_Min(L,R,rson));
	return val;
}

int Query_Max(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R)
		return Max[rt];
	int m=(l+r)>>1;
	int val=0;
	if(L<=m) val=max(val,Query_Max(L,R,lson));
	if(R>m)  val=max(val,Query_Max(L,R,rson));
	return val;
}

int main()
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++) scanf("%d",&height[i]);
	Build(All);
	for(int i=1;i<=M;i++){
		int L,R; scanf("%d%d",&L,&R);
		if(L>R) swap(L,R);
		printf("%d\n",Query_Max(L,R,All)-Query_Min(L,R,All));
	}
	return 0;
}
***************/

#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

const int M = 50005;
const int N = 20;
int H,dx[M][N],dy[M][N],n;

void Init()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&H);
        dx[i][0]=dy[i][0]=H;
    }
    for(j=1;(1<<j)<=n;j++)
        for(i=1; i+(1<<j)-1<=n;i++)
        {
            dx[i][j] = min(dx[i][j-1],dx[i+(1<<(j-1))][j-1]);
            dy[i][j] = max(dy[i][j-1],dy[i+(1<<(j-1))][j-1]);
        }

}
int RMQ(int L ,int R)
{
    int k = 0;
    k=log(R-L+1)/log(2);
	
    return max(dy[L][k],dy[R-(1<<k)+1][k]) 
	      -min(dx[L][k],dx[R-(1<<k)+1][k]);
}
int main()
{
    int m,a,b;
    while (~scanf("%d%d",&n,&m))
    {
        Init();
        while(m--)
        {
            scanf("%d%d",&a,&b);
            printf("%d\n",RMQ(a,b));
        }
    }
    return 0;
}