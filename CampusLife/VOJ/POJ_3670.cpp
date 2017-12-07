/***********
	最长非降子序列算法(LIS) ： O(nlogn)
***********/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
int N,a[33333],b[33333],st[33333];

int LIS(int x[])
{
	memset(st,0,sizeof(st));
	int len=1 ;
	st[1]=x[1];
	for(int i=2;i<=N;i++){
		int l=1,r=len;
		while(l<=r){
			int m=(l+r)>>1;
			if(x[i]>=st[m]) l=m+1;
			else r=m-1;
		}
		st[l]=x[i];
		if(l>len) len++;
	}
	return len;
}

int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++) 
		scanf("%d",&a[i]),b[N+1-i]=a[i];
	int ans1=N-LIS(a);
	int ans2=N-LIS(b);
	printf("%d\n",min(ans1,ans2));
	return 0;
}