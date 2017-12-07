/**
线段树最后一层存的是每行的剩余量，然后父节点存当前子树中最大连续空余。
**/
#include <queue>
#include <stack>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <string>
#include <algorithm>
#define MID(x,y) ( ( x + y ) >> 1 )
#define L(x) ( x << 1 )
#define R(x) ( x << 1 | 1 )
#define BUG puts("here!!!")

using namespace std;

const int MAX = 200010;
struct Tnode{int l,r,val;};
Tnode node[MAX << 2];
int w;
void init()
{
	memset(node,0,sizeof(node));
}
void Build(int t,int l,int r)
{
	node[t].l = l; node[t].r = r;
	if( node[t].l == node[t].r - 1 )
	{
		node[t].val = w;
		return ;
	}
	int mid = MID(l,r);
	Build(L(t),l,mid);
	Build(R(t),mid,r);
	node[t].val = max(node[L(t)].val,node[R(t)].val);
}

int Updata(int t,int l,int r,int val)
{
	if( node[t].val < val )  return -1;
	if( node[t].l == node[t].r - 1 && node[t].val >= val )
	{
		node[t].val -= val;
		return node[t].r;
	}
	int mid = MID(node[t].l,node[t].r);
	int ans = -1;
	if( val <= node[L(t)].val )
		ans = Updata(L(t),l,r,val);
	else
		if( val <= node[R(t)].val )
			ans = Updata(R(t),l,r,val);
	node[t].val = max(node[L(t)].val,node[R(t)].val);	
	return ans;
}

int main()
{
	int h,n,d;

	while( ~scanf("%d%d%d",&h,&w,&n) )
	{
		Build(1,0,min(h,n));
		for(int i=0; i<n; i++)
		{
			scanf("%d",&d);
			int ans = Updata(1,0,n,d);
			printf("%d\n",ans);
		}
	}
return 0;
}
