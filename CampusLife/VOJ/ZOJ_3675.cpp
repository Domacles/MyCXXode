#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int maxn = (1<<20)+10;
int dp[maxn],q[maxn],vis[maxn];
char str[22];
int len,slen,s0,s1,s2,front,real;

void init()
{
	s0=0,s1=0,s2=0,front=0,real=-1;
	memset(dp,0,sizeof(dp)) , memset(vis,0,sizeof(vis));
}

int main()
{
	while(~scanf("%d%s%d",&len,str,&slen)){
		init();
		dp[s0]=0,q[++real]=s0,vis[s0]=1;
		for(int i=0;i<len;i++) if(str[i]=='*'){
			s1|=1<<i;
            s2|=1<<(len-i-1); 
		}
		if(s1==0){puts("-1");continue;}
		
		while(real-front>=0){
			int now=q[front++],step=dp[now];
			if((now&((1<<slen)-1))==(1<<slen)-1){
				printf("%d\n",step);break;
			}
			for(int i=0;i<slen;i++){
				int S1=(s1<<i)&((1<<slen)-1);
				int S2=(s2<<i)&((1<<slen)-1);
				if(!vis[now|S1]) vis[now|S1]=1,q[++real]=now|S1,dp[now|S1]=step+1;
				if(!vis[now|S2]) vis[now|S2]=1,q[++real]=now|S2,dp[now|S2]=step+1;
				if(!vis[now|(s1>>i)])
					vis[now|(s1>>i)]=1,q[++real]=now|(s1>>i),dp[now|(s1>>i)]=step+1;
				if(!vis[now|(s2>>i)])
					vis[now|(s2>>i)]=1,q[++real]=now|(s2>>i),dp[now|(s2>>i)]=step+1;
			}
		} 
	}
	return 0;
}