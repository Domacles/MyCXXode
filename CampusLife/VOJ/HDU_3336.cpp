#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 220000;
const int mod =  10007;
char P[maxn];
int next[maxn],N,plen;
int dp[maxn];

void GetNext(){
	int i=0,j=-1;
	next[0]=-1;
	while(i<=plen){
		if(j==-1 || P[i]==P[j])
			++i, ++j, next[i]=j;
		else 
			j=next[j];
	}
}

int main()
{
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&plen);
		scanf("%s",P);
		GetNext();
		memset(dp,0,sizeof(dp));
		int ans=0;
		for(int i=1;i<=plen;i++){
			dp[i]=(dp[next[i]]+1)%mod;
			ans=(ans+dp[i])%mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}