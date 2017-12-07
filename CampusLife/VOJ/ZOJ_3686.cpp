#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;
#define maxn 110000
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

vector<int>son[maxn];
struct Node
{
	int low,high;
}node[maxn];
int num,n;
int sum[maxn<<3],col[maxn<<3];

void init()
{
	for(int i=1;i<=n;i++) son[i].clear();
	memset(node,0,sizeof(node));
	memset(sum,0,sizeof(sum));
	memset(col,0,sizeof(col));
	num=0;
}

void DFS(int v)
{
	node[v].low=++num;
	for(int i=0;i<(int)son[v].size();i++) DFS(son[v][i]);
	node[v].high=num;
}

void PushUp(int rt) {sum[rt]=sum[rt<<1]+sum[rt<<1|1];}

void PushDown(int rt,int len)
{
	if(col[rt])
	{
		col[rt<<1|1]^=1,col[rt<<1]^=1;
		sum[rt<<1]=(len-(len>>1))-sum[rt<<1];
		sum[rt<<1|1]=(len>>1)-sum[rt<<1|1];
		col[rt]=0;
	}
}

void Update(int L,int R,int l,int r,int rt)
{
	int len=r-l+1;
	if(L<=l&&r<=R)
	{
		col[rt]^=1;
		sum[rt]=len-sum[rt];
		return;
	}
	PushDown(rt,len);
	int m=(l+r)>>1;
	if(L<=m) Update(L,R,lson);
	if(R>m)  Update(L,R,rson);
	PushUp(rt);
}

int Query(int L,int R,int l,int r,int rt)
{
	int len=r-l+1;
	if(L<=l&&r<=R)
		return sum[rt];
		
	PushDown(rt,len);
	int ret=0,m=(l+r)>>1;
	if(L<=m) ret+=Query(L,R,lson);
	if(R>m)  ret+=Query(L,R,rson);
	PushUp(rt);
	return ret;
}

int main()
{
	int m;
	while(~scanf("%d%d",&n,&m))
	{
		init();
		for(int i=2;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			son[x].push_back(i);
		}
		DFS(1);
		//for(int i=1;i<=n;i++) cout<<"node "<<i<<" Low="<<node[i].low<<",High="<<node[i].high<<endl;
		int N=num;
		for(int i=1;i<=m;i++)
		{
			int x;
			char s[5];
			scanf("%s%d",s,&x);
			if(s[0]=='o') Update(node[x].low,node[x].high,1,N,1);
			else printf("%d\n",Query(node[x].low,node[x].high,1,N,1));
		}
		printf("\n");
	}
	return 0;
}