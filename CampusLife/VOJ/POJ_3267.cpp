#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;
string s[666],p;
int N,L,dp[666];//dp[i]表示从头到i位（i位包含）最少需要除去多少个字符，S是原串
int len[666];

int main()
{
	scanf("%d%d",&N,&L);
	cin>>p;
	for(int i=0;i<N;i++) cin>>s[i],len[i]=s[i].length();
	
	for(int i=0;i<L;i++){
		if(i==0) dp[i]=1;
		else dp[i]=dp[i-1]+1;
		
		for(int k=0;k<N;k++){
			int now=len[k]-1,j=i;
			int remove=L;          /*******优化（下）********/
			while(now>=0 && j>=0 && i-j+1-len[k]<dp[i])//S[k..i]包含str
			{
				if(s[k][now]==p[j]) now--;
				j--;
			}
			if(now<0) remove=i-j-len[k];
			dp[i]=min(dp[j]+remove,dp[i]);
		}
	}
	printf("%d\n",dp[L-1]);
	return 0;
}