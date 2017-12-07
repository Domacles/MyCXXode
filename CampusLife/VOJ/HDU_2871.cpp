/****
RE?
****/
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;
#define maxn 55000

struct  Node
{
	int l,r;
	int f;
	int ls,rs,cs;
}tree[maxn<<2];

void PushUp(int rt)
{
	if(tree[rt<<1].f == tree[rt<<1|1].f) tree[rt].f = tree[rt<<1].f;
	else tree[rt].f = -1;
	//ls
	tree[rt].ls=tree[rt<<1].ls;
	//rs
	tree[rt].rs=tree[rt<<1|1].rs;
	//cs
	int ret=0;
	ret=max(ret,tree[rt<<1].cs);
	ret=max(ret,tree[rt<<1].rs+tree[rt<<1|1].ls);
	ret=max(ret,tree[rt<<1|1].cs);
	tree[rt].cs=ret;
}

void PushDown(int rt)
{
	if(tree[rt].f!=-1){
		tree[rt<<1].f = tree[rt<<1|1].f = tree[rt].f;
		tree[rt].f=-1;
	}
}

void Build(int l,int r,int rt)
{
	tree[rt].l=l , tree[rt].r=r;
	tree[rt].ls=tree[rt].rs=tree[rt].cs=r-l+1;
	if(l==r) return ;
	int m=(l+r)>>1;
	Build(l,m,rt<<1);
	Build(m+1,r,rt<<1|1);
}

int Query(int rt,int len)
{
	//int l=tree[rt].l , r=tree[rt].r;
	PushDown(rt);
	if(tree[rt].ls>=len)
		return tree[rt].l;
	else
	if(tree[rt].cs>=len){
		if(tree[rt<<1].cs>=len)
			return Query(rt<<1,len);
		else if(tree[rt<<1].rs && tree[rt<<1].rs+tree[rt<<1|1].ls>=len)
			return Query(rt<<1,len-tree[rt<<1].rs);
		else if(tree[rt<<1|1].ls>=len)
			return tree[rt<<1|1].l;
		else if(tree[rt<<1|1].cs>=len)
			return Query(rt<<1|1,len);
	}
	else
	if(tree[rt].rs>=len)
		return Query(rt<<1|1,len);
	return -1;
}

void Updata(int L,int R,int x,int rt)
{
	int l=tree[rt].l , r=tree[rt].r;
	PushDown(rt);
	if(L<=l && r<=R){
		tree[rt].f=x;
		if(x) tree[rt].ls=tree[rt].rs=tree[rt].cs=0 ;
		else  tree[rt].ls=tree[rt].rs=tree[rt].cs=r-l+1 ;
		return ;
	}
	int m=(l+r)>>1;
	if(L<=m) Updata(L,R,x,rt<<1);
	if(R>m) Updata(L,R,x,rt<<1|1);
	PushUp(rt);
}

typedef pair<int,int> pii;
int N,M;
vector< pii > B;

int Find(int x)
{
	int l=0,r=B.size()-1;
	for(int i=l;i<r;i++){
        if(B[i].first<=x && x<=B[i].second)
            return i;
	}
	return 0;
}

int main()
{
	//freopen("D:\\r1.txt","r",stdin);
	while(~scanf("%d%d",&N,&M)){
		Build(1,N,1);
		B.clear();
		for(int i=0;i<M;i++){
			char s[10];
			scanf("%s",s);
			if(s[0]=='R') tree[1].f=0 , B.clear() ,puts("Reset Now");
			else
			if(s[0]=='N'){
				int len; scanf("%d",&len);
				int x=Query(1,len);
				if(x==-1) puts("Reject New");
				else{
					printf("New at %d\n",x);
					Updata(x,x+len-1,1,1);
					B.push_back( pii(x,x+len-1) );
				}
			}
			else
			if(s[0]=='F'){
				int pos; scanf("%d",&pos);
				int index=Find(pos);
				if(B.size()==0 || B[index].second<pos || B[index].first>pos){
					puts("Reject Free");
					continue;
				}
				printf("Free from %d to %d\n", B[index].first, B[index].second);
				Updata(B[index].first, B[index].second, 0, 1);
				B.erase(B.begin()+index, B.begin()+index+1);
			}
			else
			if(s[0]=='G'){
				int pos; scanf("%d",&pos);
				if(pos>B.size()){
					puts("Reject Get");
					continue;
				}
				printf("Get at %d\n",B[pos-1].first);
			}
		}
	}
	return 0;
}
