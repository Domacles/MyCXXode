#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;
ll ans=0,Cube[11111];
char Ans[11111];
char Ans0[22][22]={
"",
"+",
"-+",
"-++",
"-+++",
"-++++",
"-+++-+",
"+---+++",
"+--+--++",
"+--+-+--+",
"-+-+++++++",
"-++-+--++++",
"+--++---+-++",
"--+++++-+++++",
"-++-+--++--+-+"
};

ll ABS(ll x)
{
	if(x<0) return -x;
	else return x;
}

bool DFS(ll sum,ll n)
{
	for(ll i=n;i>0;i--)
		if(sum>=Cube[i])
		{
			if(sum-Cube[i]==0||DFS(sum-Cube[i],i-1))
			{
				Ans[i-1]='+';
				return true;
			}
		}
	return false;
}

int main()
{
	for(ll i=1;i<=10000;i++) Cube[i]=i*i*i;
	ll n;
	while(~scanf("%lld",&n))
	{
		ans=0x7fffffffffffffff;
		memset(Ans,'-',sizeof(Ans));
		if(n<15) puts(Ans0[n]);
		else
		{
			ll sum=n*n*(n+1)*(n+1)/8;
			DFS(sum,n);
			for(int i=n-1;i>=0;i--) printf("%c",Ans[i]);
			printf("\n");
		}
	}
	return 0;
}