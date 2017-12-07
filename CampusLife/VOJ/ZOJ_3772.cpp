#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;
#define maxn  110000
#define mod 1000000007

typedef long long ll;

struct Ma{int val[2][2];} M1;
Ma operator*(Ma A,Ma B){
	Ma C;
	C.val[0][0]=C.val[0][1]=C.val[1][0]=C.val[1][1]=0;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				for(int k=0;k<2;k++)
					C.val[i][j] = (C.val[i][j] + ((ll)A.val[i][k]*(ll)B.val[k][j])%mod ) %mod;
	return C;
}

struct  Node{ int l,r;
	Ma X;
}Tree[maxn<<2];

int N,M,A[maxn];

void init()
{
	M1.val[0][0]=1,M1.val[1][1]=1;
	memset(Tree,0,sizeof(Tree));
}

void Build(int l,int r,int rt){
	Tree[rt].l=l , Tree[rt].r=r;
	if(l==r){
		Tree[rt].X.val[0][0]=0 , Tree[rt].X.val[0][1]=A[l];
		Tree[rt].X.val[1][0]=1 , Tree[rt].X.val[1][1]=1;
		return ;
	}
	int m=(l+r)>>1;
	Build(l,m,rt<<1);
	Build(m+1,r,rt<<1|1);
	Tree[rt].X = Tree[rt<<1].X * Tree[rt<<1|1].X;
}

Ma Query(int L,int R,int rt){
	int l=Tree[rt].l , r=Tree[rt].r;
	if(L<=l && r<=R)
		return Tree[rt].X;
	int m=(l+r)>>1;
	Ma ret=M1;
	if(L<=m) ret=ret*Query(L,R,rt<<1);
	if(R>m)  ret=ret*Query(L,R,rt<<1|1);
	return ret;
}

int main()
{
	//freopen("D://r1.txt","r",stdin);
	int T; scanf("%d",&T);
	while(T--){
		init();
		scanf("%d%d",&N,&M);
		for(int i=1;i<=N;i++) scanf("%d",&A[i]);
		Build(1,N,1);
		for(int i=1;i<=M;i++){
			int L,R; scanf("%d%d",&L,&R);
			if(R>=L+2){
				Ma NowM=Query(L+2,R,1);
				int ans=(((ll)NowM.val[0][1]*(ll)A[L])%mod +
				    	 ((ll)NowM.val[1][1]*(ll)A[L+1])%mod)%mod;
				printf("%d\n",ans);
			}
			else{
				if(R==L+1) printf("%d\n",A[L+1]);
				else
				if(R==L) printf("%d\n",A[L]);
			}
		}
	}
	return 0;
}
