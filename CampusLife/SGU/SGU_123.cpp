#include<iostream>
#include<cstdio>

using namespace std;
typedef long long ll;
ll sum[44],f[44];

void init(){
	f[1]=1,f[2]=1;
	for(int i=3;i<=41;i++)
		f[i]=f[i-1]+f[i-2];
	for(int i=1;i<=41;i++)
		sum[i]=sum[i-1]+f[i];
}


int main()
{
	int n;
	init();
	while(~scanf("%d",&n)){
		printf("%lld\n",sum[n]);
	}
	return 0;
}