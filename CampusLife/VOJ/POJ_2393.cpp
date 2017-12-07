#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
#define maxn 11111
int N,K,Min,p,s;

int main()
{
	scanf("%d%d",&N,&K);
	scanf("%d%d",&p,&s);
	Min=p;
	long long ans=Min*s;
	for(int i=1;i<N;i++){
		scanf("%d%d",&p,&s);
		Min=min(Min+K,p);
		ans+=Min*s;
	}
	printf("%lld\n",ans);
	return 0;
}