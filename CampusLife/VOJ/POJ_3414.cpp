#include <cstdio>
#include <string>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;
const int maxn = 101;
string step[6]={"FILL(1)", "FILL(2)", "DROP(1)", "DROP(2)", "POUR(1,2)", "POUR(2,1)"};

bool vis[maxn][maxn];
struct Node
{
	int a,b,step_num,op,pre;
	Node(){}
	Node(int A,int B,int Step,int Op,int Pre)
	{a=A,b=B,step_num=Step,op=Op,pre=Pre;}
}q[maxn*111];

void print(int x)
{
	if(q[x].op>=0) print(q[x].pre);
	if(q[x].op>=0) cout<<step[q[x].op]<<endl;
}

void BFS(int A,int B,int C)
{
	memset(q,0,sizeof(q));
	memset(vis,0,sizeof(vis));
	int front=0,real=-1;
	q[++real]=Node(0,0,0,-1,-1);
	
	while(real-front>=0){
		Node now=q[front];
		int a=now.a , b=now.b;
		int pre=front++ , stepN=now.step_num;
		if(a==C||b==C)
		{
			cout<<stepN<<endl,print(pre);
			return;
		}
		else
		{
			int w1=min(a,B-b),w2=min(A-a,b);
			if(!vis[A][b]) q[++real]=Node(A,b,stepN+1,0,pre),vis[A][b]=1;
			if(!vis[a][B]) q[++real]=Node(a,B,stepN+1,1,pre),vis[a][B]=1;
			if(!vis[0][b]) q[++real]=Node(0,b,stepN+1,2,pre),vis[0][b]=1;
			if(!vis[a][0]) q[++real]=Node(a,0,stepN+1,3,pre),vis[a][0]=1;
			if(!vis[a-w1][b+w1]) q[++real]=Node(a-w1,b+w1,stepN+1,4,pre),vis[a-w1][b+w1]=1;
			if(!vis[a+w2][b-w2]) q[++real]=Node(a+w2,b-w2,stepN+1,5,pre),vis[a+w2][b-w2]=1;
		}
	}
	cout<<"impossible"<<endl;
}

int main()
{
	int a,b,c;
	while(cin>>a>>b>>c)
		BFS(a,b,c);
	return 0;
}