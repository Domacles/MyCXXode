#include <cstdio>

using namespace std;

typedef long long ll;
const int maxn = 24;

ll tri[maxn];

void init()
{
	tri[0]=1;
	for(int i=1;i<maxn;i++) tri[i]=tri[i-1]*3;
}

ll gcd(ll a,ll b)
{
	while(b){
		ll t=b;
		b=a%b;
		a=t;
	}
	return a;
}

int main()
{
	int n;
	init();
	while(~scanf("%d",&n)&&n!=-1){
		ll ans=0;
		for(int i=0;i<n;i++) ans+=tri[gcd(n,i)];//polya , 旋转置换
		if(n%2){//对称置换
			ans+=(ll)n*tri[(n+1)/2];//对称轴有n条，任意对称轴过一点，此点是孤单的，所以，n个球会被分成(n+1)/2部分
		}
		else{
			ans+=(ll)n/2*(tri[n/2]+tri[n/2+1]);//对称轴有n/2条,对称轴分为两种：不过点和过点的~~
		}
		if(n) printf("%lld\n",ans/(ll)n/2);
		else
			puts("0");
	}
	return 0;
}