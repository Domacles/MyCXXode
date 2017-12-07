#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;
const int maxn =110000;
int N,M,maxa,sum,a[maxn];

int deal(int mid)
{
	int val=1,total=0;
	for(int i=1;i<=N;i++){
		if(total+a[i]>mid){
			total=a[i],val++;
		}
		else total+=a[i];
	}
	return val;
}

int main()
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
		scanf("%d",&a[i]),
		maxa=max(a[i],maxa),
		sum+=a[i];
	
	int l=maxa,r=sum;
	while(l<r){
		int m=(l+r)>>1;
		if(deal(m)<=M) r=m;
		else l=m+1;
	}
	printf("%d\n",r);
	return 0;
}