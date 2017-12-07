#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;
#define maxn 105

int N;
int Sum[maxn][maxn];

int lowbit(int x){return (-x)&x;}
void add(int x,int y)
{
	for(int i=x;i<N;i+=lowbit(i))
		for(int j=y;j<N;j+=lowbit(j))
			Sum[i][j]+=1;
}
int query(int x,int y)
{
	int s=0;
	for(int i=x;i>0;i-=lowbit(i))
		for(int j=y;j>0;j-=lowbit(j))
			s+=Sum[i][j];
	return s;
}

void init()
{
	memset(Sum,0,sizeof(Sum));
}

int n,r,l,fx,fy;

int main()
{
	while(~scanf("%d",&n)&&n)
	{
		init();
		scanf("%d%d",&r,&l);
		N=maxn;
		for(int i=0;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
		}
		scanf("%d%d",&fx,&fy);
		int ans=0;
		for(int i=fx;i<=r;i++)	
			for(int j=fy;j<=l;j++){
			int x1=i,
				y1=j;
			int x2=x1-fx,
				y2=y1-fy;
			int temp=query(x1,y1)
					+query(x2,y2)
					-query(x1,y2)
					-query(x2,y1);
			ans=max(ans,temp);
		}
		printf("%d\n",ans);
	}
	return 0;
}