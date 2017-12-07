#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;
#define mod 100000000
typedef long long LL;
#define maxn 1<<12

vector<int>s;
int dp[15][maxn],Map[15],N,M;

void GetState()
{
	for(int i=0;i<(1<<M);i++){
		if(i&(i<<1)) continue;
		if(i&(i>>1)) continue;
		s.push_back(i);
	}
}

int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++) for(int j=0;j<M;j++){
		int x;scanf("%d",&x);
		Map[i]<<=1;
		if(x) Map[i]++;
	}
	
	GetState();
	for(int i=0;i<(int)s.size();i++)
		if((s[i]|Map[0])==Map[0]) dp[0][i]=1;
	for(int i=1;i<N;i++){
		for(int j=0;j<(int)s.size();j++){
			if((s[j]|Map[i])!=Map[i]) continue;
			for(int k=0;k<(int)s.size();k++){
				if((s[k]|Map[i-1])!=Map[i-1]) continue;
				if(s[j]&s[k]) continue;
				dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
			}
		}
	}
	int ans=0;
	for(int i=0;i<(int)s.size();i++)
		ans=(ans+dp[N-1][i])%mod;
	printf("%d\n",ans);
	return 0;
}