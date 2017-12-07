#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
#define maxn 11111
int N,K;

int main()
{
	scanf("%d%d",&N,&K);
	for(int i=1;i<=K;i++){
		int S,T,R;
		int re,ans;
		scanf("%d%d%d",&S,&T,&R);
		re=N%(S*T);
		if(!re) ans=(N/(S*T))*(T+R)-R;
		else{
			ans=(N/(S*T))*(T+R);
			if(re%S) ans+=re/S+1;
			else ans+=re/S;
		}
		printf("%d\n",ans);
	}
	return 0;
}