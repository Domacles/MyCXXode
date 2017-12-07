#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;
int a[50005];
int L,N,M;

int main()
{
	scanf("%d%d%d",&L,&N,&M);
	for(int i=1;i<=N;i++)
		scanf("%d",&a[i]);
	a[N+1]=L;
	sort(a,a+N+1);
	int l=L,r=L;
	for(int i=1;i<=N;i++)
		if(l>a[i]-a[i-1]) l=a[i]-a[i-1];
	while(l<=r){
		int m=(l+r)>>1;
		int del=0,sumlen=0;
		for(int i=1;i<=N;i++){
			sumlen+=a[i]-a[i-1];
			if(sumlen<m) del++;
			else sumlen=0;
		}
		if(del<=M) l=m+1;
		else r=m-1;
	}
	printf("%d\n",r);
	return 0;
}
