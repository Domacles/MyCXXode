#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
#define maxn 1111
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
struct Node {
	int x,y,dis;
	Node(){}
	Node(int xx,int yy,int d=0){x=xx;y=yy;dis=d;}
};
int X,Y,N,vis[maxn][maxn],f[maxn][maxn];

bool BFS()
{
	queue<Node>q;
	q.push(Node(500,500,0));
	vis[500][500]=1;
	while(!q.empty()){
		Node now=q.front();q.pop();
		if(now.x==X&&now.y==Y){
			printf("%d\n",now.dis);
			return 1;
		}
		for(int i=0;i<4;i++){
			int x=now.x+dx[i],y=now.y+dy[i];
			if(x>1000||x<0 ||y>1000||y<0) continue;
			if(vis[x][y]||f[x][y]) continue;
			vis[x][y]=1;
			q.push(Node(x,y,now.dis+1));
		}
	}
	return 0;
}

int main()
{
	scanf("%d%d%d",&X,&Y,&N);
	X+=500;Y+=500;
	for(int i=0;i<N;i++){
		int x,y;scanf("%d%d",&x,&y);
		x+=500;y+=500;
		f[x][y]=1;
	}
	BFS();
	return 0;
}