#include <cstdio>
#include <queue>
#include <vector>
#include <stack>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
#define maxn 1005
struct Node{
	int x,l,f,c;
	Node(){}
	Node(int xx,int ll,int ff,int cc){
		x=xx;l=ll;f=ff;c=cc;
	}
};
bool operator <(Node a,Node b){return a.x<b.x;}
vector<Node>a;
int L,N,B,dp[1111][1111];//dp : [0,i]花费为j的最大f

int main()
{
	scanf("%d%d%d",&L,&N,&B);
	for(int i=0;i<N;i++){
		int a1,a2,a3,a4;
		scanf("%d%d%d%d",&a1,&a2,&a3,&a4);
		a.push_back(Node(a1,a2,a3,a4));
	}
	sort(a.begin(),a.end());
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<=B;i++) dp[0][i]=0;
	for(int i=0;i<N;i++){
		if(a[i].x+a[i].l>L) continue;
		for(int j=0;j<=B;j++){
			if(dp[a[i].x][j]==-1) continue;
			if(j+a[i].c>B) continue;
			if( dp[a[i].x+a[i].l][j+a[i].c]<dp[a[i].x][j]+a[i].f )
				dp[a[i].x+a[i].l][j+a[i].c]=dp[a[i].x][j]+a[i].f;
		}
	}
	printf("%d\n",dp[L][B]);
	return 0;
}