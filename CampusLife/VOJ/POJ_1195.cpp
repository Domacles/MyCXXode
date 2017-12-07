/****
		二维树状数组
****/
#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;
typedef long long ll;
#define maxn 1035

int sum[maxn][maxn],N;
int lowbit(int x) {return x&(-x);}

int Query(int X,int Y)
{
	int s=0;
	for(int i=X; i>0; i-=lowbit(i))
		for(int j=Y; j>0; j-=lowbit(j))
			s+=sum[i][j];
	return s;
}

void Add(int X,int Y,int k)
{
	for(int i=X; i<=N; i+=lowbit(i))
		for(int j=Y; j<=N; j+=lowbit(j))
			sum[i][j]+=k;
}

void init()
{
	memset(sum,0,sizeof(sum));
}

int main()
{
	int x;
	while(~scanf("%d",&x)&&x!=3){
		if(x==0){
			init();
			scanf("%d",&N);
		}
		else if(x==1){
			int X,Y,K;
			scanf("%d%d%d",&X,&Y,&K);
			Add(X+1,Y+1,K);
		}
		else if(x==2){
			int L,B,R,T;
			scanf("%d%d%d%d",&L,&B,&R,&T);
			int ans=0;
			ans= Query(R+1,T+1)+Query(L,B)
				-Query(L,T+1)
				-Query(R+1,B);
			printf("%d\n",ans);
		}
	}
	return 0;
}