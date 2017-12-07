/***
找到草地的最左上的点，连一条垂线到地图上边界，
然后BFS，要求必须从右边穿过这条垂线一次且仅一次，
这样就能保证一定绕过了草地，而BFS保证这是最短路径。
***/
#include <stdio.h>
#include <queue>
#define N (100)
#define D (8)
using std::queue;
struct STATUS
{
	int r,c,t;
	STATUS(int r,int c,int t)
	{
		this->r=r;
		this->c=c;
		this->t=t;
	}
	bool operator == (STATUS s)
	{
		return (r==s.r&&c==s.c&&t==s.t);
	}
};
const int dx[D]={0,-1,-1,-1,0,1,1,1};
const int dy[D]={1,1,0,-1,-1,-1,0,1};
int n,m,maze[N][N],sr,sc,vis[N][N][2];
queue<STATUS> q;
queue<int> qs;
int bfs();
int main()
{
	scanf("%d%d\n",&n,&m);
	for (int i=1;i<=n;++i,getchar())
		for (int j=1;j<=m;++j)
		{
			char t=getchar();
			if (t=='X')
				maze[i][j]=0;
			else
			{
				maze[i][j]=1;
				if (t=='*')
				{
					sr=i;
					sc=j;
				}
			}
		}
	int r,c=-1;
	for (int i=1;c<0&&i<=n;++i)
		for (int j=1;c<0&&j<=m;++j)
			if (!maze[i][j])
			{
				r=i;
				c=j;
			}
	for (int i=1;i<r;++i)
		maze[i][c]=2;
	printf("%d\n",bfs());
	return 0;
}
int bfs()
{
	vis[sr][sc][0]=1;
	q.push(STATUS(sr,sc,0));
	qs.push(0);
	while (!q.empty())
	{
		STATUS cur=q.front();
		int step=qs.front();
		q.pop();
		qs.pop();
		if (cur==STATUS(sr,sc,1))
			return step;
		for (int i=0;i<D;++i)
		{
			int x=cur.r+dx[i],y=cur.c+dy[i];
			if (!maze[x][y])
				continue;
			if (maze[cur.r][cur.c]==2&&y>cur.c)
				continue;
			if (2==maze[x][y]&&cur.c<y)
				continue;
			if (2==maze[cur.r][cur.c])
			{
				if (!vis[x][y][1])
				{
					vis[x][y][1]=1;
					q.push(STATUS(x,y,1));
					qs.push(step+1);
				}
			}
			else
			{
				if (!vis[x][y][cur.t])
				{
					vis[x][y][cur.t]=1;
					q.push(STATUS(x,y,cur.t));
					qs.push(step+1);
				}
			}
		}
	}
}