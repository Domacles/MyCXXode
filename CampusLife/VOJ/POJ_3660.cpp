#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <algorithm>

using namespace std;
typedef pair<int, int> PII;
set<PII> lines;

int G[111][111],N,M;
void Floyd()
{
	for(int k=1;k<=N;k++)
		for(int i=1;i<=N;i++){
			if(i==k) continue;
			for(int j=1;j<=N;j++){
				if(i==j||k==j)  continue;
				if(G[i][j]!=-1) continue;
				if(G[i][k]==1&&G[k][j]==1)
					G[i][j]=1,G[j][i]=0;
				if(G[i][k]==0&&G[k][j]==0)
					G[i][j]=0,G[j][i]=1;
			}
		}
}

void deal()
{
	int val=0;
	for(int i=1;i<=N;i++){
		int flag=1;
		for(int j=1;j<=N;j++)
			if(i!=j&&G[i][j]==-1)
				{flag=0;break;}
		if(flag) val++;
	}
	printf("%d\n",val);
}

int main() 
{
	memset(G,-1,sizeof(G));
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		G[x][y]=1; G[y][x]=0;
	}
	Floyd();
	deal();
	return 0;
}
