//对于每个点从该点出发的速度是恒定的，例如从a->b->c;
//则c出发的速度就是V*2^(A-B）*2^(B-C)=V*2^(A-C)    [!!!!!]
//SPFA(using heap)
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#include <stack>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;
#define maxn 105
struct Node{int r,c;
	double dis;
	Node(){}
	Node(int rr,int cc,double d){r=rr;c=cc;dis=d;}
	bool operator<(const Node &a)const{
        return dis>a.dis;
    }
};
int vis[maxn][maxn],V,R,C;
double edge[maxn][maxn];//SPD的倒數
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

bool InMap(int x,int y){
	if(x>=1 && x<=R && y>=1 && y<=C)
		return 1;
	return 0;
}

double SPFA_Heap(){
	priority_queue<Node>q;
	q.push(Node(1,1,0));
	while(!q.empty()){
		Node u=q.top(); q.pop();
		if(vis[u.r][u.c]) continue;
		vis[u.r][u.c]=1;
		if(u.r==R&&u.c==C) return u.dis;
		for(int i=0;i<4;i++){
			int x=u.r+dx[i];
			int y=u.c+dy[i];
			if(InMap(x,y)&&!vis[x][y])
				q.push(Node(x,y,u.dis+edge[u.r][u.c]));//[!!!!!!!]
		}
	}
	return 0;
}

int main()
{
	scanf("%d%d%d",&V,&R,&C);
	for(int i=1;i<=R;i++) for(int j=1;j<=C;j++){
		scanf("%lf",&edge[i][j]);
		if(i==1&&j==1) continue;
		double SPD=V*pow(2,edge[1][1]-edge[i][j]);
		edge[i][j]=1.0/SPD;
	}
	edge[1][1]=1.0/V;
	printf("%.2f\n",SPFA_Heap());
	return 0;
}