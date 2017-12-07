#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;
#define N 12

typedef long long LL;
typedef pair<int,int> P;
const int INF = 0x3fffffff;
vector<int>a;
int dp[N],n,sum;

int main()
{
	scanf("%d%d",&n,&sum);
	for(int i=0;i<n;i++) a.push_back(i+1);
	do{
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++) dp[i]=a[i];
		for(int k=1;k<n;k++)
			for(int i=0;i+k<n;i++)
				dp[i]=dp[i]+dp[i+1];
			if(dp[0]==sum){
				for(int i=0;i<n;i++) 
					printf("%d ",a[i]);
			break;
			}
	}while(next_permutation(a.begin(),a.end()));
	puts("");
	return 0;
}