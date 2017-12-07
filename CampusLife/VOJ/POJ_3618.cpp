#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;
#define maxn 11111
typedef long long ll;
struct Node{
	int x,flag;
	Node(){}
	Node(int xx,int f){x=xx;flag=f;} 
};
bool operator <(Node a,Node b){return a.x<b.x;}
vector<Node>A;
ll  N;
int K; 

int main()
{
	scanf("%lld%d",&N,&K);
	for(int i=0;i<K;i++){
		int x;
		scanf("%d",&x);
		if(x<0) A.push_back(Node(-x,-1));
		else A.push_back(Node(x,1));
	}
	sort(A.begin(),A.end());
	ll T=0;
	int ans=0,now=0;
	for(int i=0;i<K;i++){
		int temp=abs(A[i].x*A[i].flag-now);
		if(T+temp>N) break;
		ans++;
		T+=temp;
		now=A[i].x*A[i].flag;
	}
	printf("%d\n",ans);
	return 0;
}