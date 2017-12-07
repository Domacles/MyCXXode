#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
#define lson rt<<1
#define rson rt<<1|1

const int maxn = 1000100;

struct  Node{
	int f,fx,s,l,r;
}tree[4][maxn*3];

bool A[4][maxn];
int N,M;

void init()
{
	memset(tree,0,sizeof(tree));
	memset(A,0,sizeof(A));
}

void PushUp(int rt,int k){tree[k][rt].s = tree[k][lson].s + tree[k][rson].s;}

void PushDown(int rt,int k)
{
	if(tree[k][rt].f!=-1){
        tree[k][lson].f=tree[k][rson].f=tree[k][rt].f;
        tree[k][lson].fx=tree[k][rson].fx=0;

		if(tree[k][rt].f==0)
            tree[k][lson].s=tree[k][rson].s=0;
		else{
            tree[k][lson].s=tree[k][lson].r-tree[k][lson].l+1;
            tree[k][rson].s=tree[k][rson].r-tree[k][rson].l+1;
		}
        tree[k][rt].f=-1;
	}
	if(tree[k][rt].fx){
        tree[k][lson].fx^=1;
        tree[k][rson].fx^=1;
        tree[k][rt].fx=0;

        tree[k][lson].s=tree[k][lson].r-tree[k][lson].l+1-tree[k][lson].s;
        tree[k][rson].s=tree[k][rson].r-tree[k][rson].l+1-tree[k][rson].s;
        //PushUp(rt,k);
	}
}



void Build(int l,int r,int rt,int k){
	tree[k][rt].l=l , tree[k][rt].r=r;
	tree[k][rt].f=-1;
	tree[k][rt].s=0;
	if(l==r){
		tree[k][rt].s=A[k][l];
		return ;
	}
	int m=(l+r)>>1;
	Build(l, m, lson,k);
	Build(m+1,r,rson,k);
	PushUp(rt,k);
}

void updata(int rt,int k,int key){
    int l=tree[k][rt].l , r=tree[k][rt].r;
    if(key==0)
        tree[k][rt].s=0 , tree[k][rt].f=key;
    else
    if(key==1)
        tree[k][rt].s=r-l+1 , tree[k][rt].f=key;
    else
    if(key==2){
        tree[k][rt].fx^=1;
        if(tree[k][rt].fx)
            tree[k][rt].s=(r-l+1)-tree[k][rt].s;
    }
}

void Updata(int L,int R,int rt,int k,int key)
{
	int l=tree[k][rt].l , r=tree[k][rt].r;
	PushDown(rt,k);
	if(L<=l && r<=R)
	{
		updata(rt,k,key);
		return ;
	}
	int m=(l+r)>>1;
	if(L<=m) Updata(L,R,lson,k,key);
	if(R>m)  Updata(L,R,rson,k,key);
	PushUp(rt,k);
}

int Query(int L,int R,int rt,int k)
{
	int l=tree[k][rt].l , r=tree[k][rt].r;
    PushDown(rt,k);
	if(L<=l && r<=R)
		return tree[k][rt].s;
	int m=(l+r)>>1,ret=0;
	if(L<=m) ret+=Query(L,R,lson,k);
	if(R>m)  ret+=Query(L,R,rson,k);
	PushUp(rt,k);
	return ret;
}

int pow(int k,int x)
{
    int ret=1;
    for(int i=0;i<x;i++)
        ret*=k;
    return ret;
}

int Sum(int l,int r)
{
	int ret=0;
	for(int i=0;i<4;i++)
		ret+=Query(l,r,1,i)*pow(2,i);
	return ret;
}

int main()
{
    freopen("D://r1.txt","r",stdin);
	int T; scanf("%d",&T);
	while(T--){
		init();
		scanf("%d%d",&N,&M);
		for(int i=0;i<N;i++){
			int x; scanf("%d",&x);
			for(int k=0;k<4;k++)
				if( (1<<k)&x ) A[k][i]++;
		}
		for(int i=0;i<4;i++)
            Build(0,N-1,1,i);
		for(int i=0;i<M;i++){
			char s[10]; scanf("%s",s);
			if(s[0]=='S'){
				int l,r;
				scanf("%d%d",&l,&r);//l++,r++;
				if(l>r) swap(l,r);
				printf("%d\n",Sum(l,r));
			}
			else if(s[0]=='A'){
				int x,l,r;
				scanf("%d%d%d",&x,&l,&r);//l++,r++;
				if(l>r) swap(l,r);
				for(int j=0;j<4;j++)
					if(!((1<<j)&x)) Updata(l,r,1,j,0);
			}
			else if(s[0]=='O'){
				int x,l,r;
				scanf("%d%d%d",&x,&l,&r);//l++,r++;
				if(l>r) swap(l,r);
				for(int j=0;j<4;j++)
					if((1<<j)&x)    Updata(l,r,1,j,1);
			}
			else{
				int x,l,r;
				scanf("%d%d%d",&x,&l,&r);//l++,r++;
				if(l>r) swap(l,r);
				for(int j=0;j<4;j++)
					if((1<<j)&x)    Updata(l,r,1,j,2);
			}
		}
	}
	return 0;
}
