#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
#define maxn 4400
struct Node{int a,h,s;};
vector<Node>bu;
int N,dp[maxn*10];

bool operator<(Node A,Node B){
	return A.a<B.a;
}

void DP()
{
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	for(int i=0;i<(int)bu.size();i++){
		for(int s=bu[i].s;s>0;s--)
		for(int j=bu[i].a;j>=bu[i].h;j--){
			if(dp[j-bu[i].h]!=-1)
				dp[j]=max(dp[j],dp[j-bu[i].h]+bu[i].h);
		}
	}
	int ans=0;
	for(int i=1;i<maxn*10;i++) 
		if(dp[i]!=-1) ans=max(ans,dp[i]); 
	printf("%d\n",ans);
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		Node x;
		scanf("%d%d%d",&x.h,&x.a,&x.s);
		bu.push_back(x);
	}
	sort(bu.begin(),bu.end());
	DP();
	return 0;
}