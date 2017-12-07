/********
	贪心
********/
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
#define INF 1e8
#define maxn 1000005

struct Node{
	int l,r,num;
	Node(){}
	Node(int ll,int rr,int nn){l=ll;r=rr;num=nn;}
};
int N,L[maxn],R[maxn];
vector<Node>a;

bool operator <(Node x,Node y){
	if(x.l==y.l) return x.r<y.r;
	else return x.l<y.l;
}
struct Greater{
	bool operator()(const Node& x, const Node& y)const 
	{
		return x.r>y.r;
	}
};

void solve()
{
	int ans[50005]={0};
	for(int i=0;i<N;i++) a.push_back(Node(L[i],R[i],i));
	sort(a.begin(),a.end());
	priority_queue<Node,vector<Node>,Greater>que;
	que.push(a[0]); 	ans[a[0].num]=1;
	for(int i=1;i<N;i++){
		Node Top=que.top();
		if(a[i].l > Top.r){
			Top.r=a[i].r;
			ans[a[i].num]=ans[Top.num];
			que.pop();
			que.push(Top);
		}
		else{
			ans[a[i].num]=que.size()+1;
			que.push(a[i]);
		}
	}
	printf("%d\n",que.size());
	for(int i=0;i<N;i++) printf("%d\n",ans[i]);
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d%d",&L[i],&R[i]);
	solve();
	return 0;
}