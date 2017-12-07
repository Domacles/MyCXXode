#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;
typedef double D;
ll gcd(ll a,ll b)
{
	while(b)
	{
		ll t=b;
		b=a%b;
		a=t;
	}
	return a;
}

int main()//polya计数   (旋转和对称)
{
	int k,n;
	while(~scanf("%d%d",&k,&n)&&k+n!=0){
		ll ans=0;
		for(int i=0;i<n;i++) ans+=(ll)pow((D)k,(D)gcd(n,i));
		if(n%2){
			ans+=(ll)n*(ll)pow((D)k,(D)(n+1)/2);
		}
		else{
			ans+=(ll)n/2*(pow((D)k,(D)n/2)+pow((D)k,(D)n/2+1));
		}
		if(n)	printf("%lld\n",ans/(n*2));
		else	puts("0");
	}
}