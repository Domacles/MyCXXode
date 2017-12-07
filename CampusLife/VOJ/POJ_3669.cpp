#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;
#define INF 0x3fffffff
const int maxn = 55555;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

struct Node{
	int x,y,t;
	Node(){}
	Node(int xx,int yy,int tt){x=xx;y=yy;t=tt;}
};

int M,vis[333][333],time[333][333];

bool BFS()
{
	vis[0][0]=1;
	queue<Node>q;
	q.push(Node(0,0,0));
	while(!q.empty()){
		Node now=q.front();q.pop();
		int x=now.x, y=now.y, t=now.t; 
		if(time[x][y]==INF){
			printf("%d\n",t); return 1;
		}
		if(time[x][y]<=t) return 0;
		for(int i=0;i<4;i++){
			int xx=x+dx[i], yy=y+dy[i];
			if(xx<0||yy<0)  continue;
			if(vis[xx][yy]) continue;
			if(t+1<time[xx][yy])
				vis[xx][yy]=1,
				q.push(Node(xx,yy,t+1));
		}
	}
	return 0;
}

int main()
{
	scanf("%d",&M);
	for(int i=0;i<333;i++) for(int j=0;j<333;j++)
		time[i][j]=INF;
	
	for(int i=0;i<M;i++){
		int x,y,t;
		scanf("%d%d%d",&x,&y,&t);
		time[x][y]=min(time[x][y],t);
		for(int j=0;j<4;j++){
			int xx=dx[j]+x,yy=dy[j]+y;
			if(xx<0||yy<0) continue;
			else time[xx][yy]=min(time[xx][yy],t);
		}
	}
	if(!BFS()) puts("-1");
	return 0;
}