#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;
#define maxn 1100
typedef long long ll;
struct Node{
	int st,ed,w;
	Node(){}
	Node(int s,int e,int ww){st=s;ed=e;w=ww;}
};
bool operator < (Node a,Node b){
		if(a.st==a.st) return a.ed<b.ed;
		else return a.st<b.st;
}
vector<Node>A;
int dp[maxn];
int N,M,R;

int main()
{
	scanf("%d%d%d",&N,&M,&R);
	for(int i=0;i<M;i++){
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		A.push_back(Node(x,y,w));
	}
	memset(dp,0,sizeof(dp));
	sort(A.begin(),A.end());
	
	//for(int i=0;i<M;i++) cout<<A[i].st<<" "<<A[i].ed<<" "<<A[i].w<<endl;
	
	int maxs=0;
	for(int i=0;i<M;i++) dp[i]=A[i].w;
	for(int i=0;i<M;i++){
		for(int j=0;j<i;j++)
			if(A[j].ed+R<=A[i].st)
				dp[i]=max(dp[j]+A[i].w,dp[i]);
		maxs=max(maxs,dp[i]);
	}	
	printf("%d\n",maxs);
	return 0;
}