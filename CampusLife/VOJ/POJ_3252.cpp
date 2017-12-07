#include <cstdio>
#include <iostream>

using namespace std;
typedef long long ll;
ll C[35][35];

void init()
{
	for(int i=0;i<33;i++) C[i][0]=C[i][i]=1;
	for(int i=0;i<33;i++)
		for(int j=1;j<i;j++)
			C[i][j]=C[i-1][j-1]+C[i-1][j];
}

ll deal(int n)
{
	ll sum=0;
	int len=0,bit[35]={0};
	while(n){
		bit[++len]=n%2; n/=2;
	}
	
	for(int i=1;i<len;i++)//长度小于len
        for(int j=(i+1)/2;j<i;j++)  
            sum+=C[i-1][j];
	
	int sum1=1,sum0=0;
	for(int i=len-1;i>0;i--)
	{
		if(bit[i]){
			sum0++;
			for(int j=max(0,(len+1)/2-sum0);j<i;j++)
				sum+=C[i-1][j];
			sum0--;
			sum1++;
		}
		else	sum0++;
	}
	return sum;
}

int main()
{
	int l,r;
	init();
	while(~scanf("%d%d",&l,&r))
		printf("%lld\n",deal(r+1)-deal(l));
	return 0;
}