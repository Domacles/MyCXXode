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
typedef pair<int,int> PII;
struct Node{
	int d,p;
	Node(){}
	Node(int dd,int pp){d=dd;p=pp;}
};
vector<Node>a;
int N,L,P;

bool operator<(Node a,Node b){return a.d>b.d;}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int x,y; scanf("%d%d",&x,&y);
		a.push_back(Node(x,y));
	}
	scanf("%d%d",&L,&P);
	sort(a.begin(),a.end());
	
	priority_queue<PII>q;
	int i=0,ans=0;
	if(P>=L) { printf("%d\n",ans); return 0; }//开始就能直接到达
	for(i=i;i<N;i++){
			if(P>=L-a[i].d) q.push(PII(a[i].p,L-a[i].d));
			else break;
	}
	while(!q.empty()){
		PII now=q.top(); q.pop();
		P+=now.first;
		ans++;
		if(P>=L) { printf("%d\n",ans); return 0; }
		for(i=i;i<N;i++){
			if(P>=L-a[i].d) q.push(PII(a[i].p,L-a[i].d));
			else break;
		}
	}
	if(P<L) printf("-1\n");
	return 0;
}