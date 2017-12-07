#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;
#define maxn 333
typedef long long ll;
struct Node{
	int h,x,y;
	Node(){}
	Node(int hh,int xx,int yy){h=hh;x=xx;y=yy;}
	bool operator<(const Node &A) const{
		return h>A.h;
	}
};
int R,C;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int vis[maxn][maxn];
int Map[maxn][maxn];

void init()
{}

ll solve()//从外围BFS，用heap选出最小者，最小者可决定周围四格的储存量
{
	ll val=0;
	priority_queue<Node>q;
	for(int i=0;i<C;i++){
		vis[R-1][i]=vis[0][i]=1;
		q.push(Node(Map[0][i],0,i));
		q.push(Node(Map[R-1][i],R-1,i));
	}
	for(int i=1;i<R-1;i++){
		vis[i][0]=vis[i][C-1]=1;
		q.push(Node(Map[i][0],i,0));
		q.push(Node(Map[i][C-1],i,C-1));
	}
	while(!q.empty()){
		Node u=q.top(); q.pop();
		int x=u.x , y=u.y;
		for(int i=0;i<4;i++){
			int xx=x+dx[i],yy=y+dy[i];
			if(xx<0||xx>=R) continue;
			if(yy<0||yy>=C) continue;
			if(vis[xx][yy]) continue;
			vis[xx][yy]=1;
			if(Map[xx][yy]<u.h)//周围有可以储存的，填充后，成为新的高度
				val+=u.h-Map[xx][yy] , q.push(Node(u.h,xx,yy));
			else q.push(Node(Map[xx][yy],xx,yy));
		}
	}
	return val;
}

int main()
{
	scanf("%d%d",&C,&R);
	for(int i=0;i<R;i++) for(int j=0;j<C;j++)
		scanf("%d",&Map[i][j]);
	ll ans=solve();
	printf("%lld\n",ans);
	return 0;
}