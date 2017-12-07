#include <math.h>
#include <stdio.h>
#include <string.h>

const int mod = 10000;
typedef int Int_Array[2];
int M[2][2],ans[2][2];

void init()
{
	memset(ans,0,sizeof(ans));
	M[0][0]=1,M[0][1]=1,M[1][0]=1,M[1][1]=0;
}

void equalM()
{
	for(int i=0;i<2;i++) for(int j=0;j<2;j++)
	ans[i][j]=M[i][j];
}

void Power(int k)
{
	if(k==-1) init();
	else if(k==0) equalM();
	else
		while(k){
			if(k&1){
				int ret[2][2]={0,0,0,0};
				for(int i=0;i<2;i++) for(int j=0;j<2;j++)
				for(int k=0;k<2;k++)
					ret[i][j]=(ret[i][j]+ans[i][k]*M[k][j])%mod;
				for(int i=0;i<2;i++) for(int j=0;j<2;j++)
					ans[i][j]=ret[i][j];
			};
			int ret[2][2]={0,0,0,0};
			for(int i=0;i<2;i++) for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				ret[i][j]=(ret[i][j]+M[i][k]*M[k][j])%mod;
			for(int i=0;i<2;i++) for(int j=0;j<2;j++)
				M[i][j]=ret[i][j];
			k>>=1;
		}
}

int main()
{
	int n;
	while(~scanf("%d",&n)){
		if(n==-1) break;
		init();
		equalM();
		Power(n-1);
		printf("%d\n",ans[1][0]);
	}
	return 0;
}