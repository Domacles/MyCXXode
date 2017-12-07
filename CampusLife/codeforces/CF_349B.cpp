#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;
const int maxn =1e6;

int sum,cost[11];
int ans[maxn+10];
int main()
{
	int min_cost=maxn+10;
	scanf("%d",&sum);
	for(int i=1;i<=9;i++) {	
		scanf("%d",&cost[i]);
		min_cost=min(cost[i],min_cost);
	}
	if(sum<min_cost) puts("-1");
	else{
		int N=sum/min_cost;
		for(int j=0;j<N;j++)
			for(int i=9;i>=1;i--)
				if((sum-cost[i]+min_cost)/min_cost + j==N)
				{
					sum-=cost[i];ans[j]=i;break;
				}
		for(int i=0;i<N;i++) printf("%d",ans[i]);
		puts("");
	}
	return 0;
}