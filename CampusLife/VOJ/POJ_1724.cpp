#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
const int maxn = 10005;
int money,n,m;
int head[maxn],next[maxn];
int u[maxn],v[maxn],l[maxn],c[maxn];

struct Node
{
	int v,len,cost;
	friend bool operator < (const Node &a,const Node &b)//这里要注意。。，堆顶为 > 关系最大者
	{
		if(a.len==b.len) return a.cost>b.cost;//长度相同按照cost从小到大排列
		else return a.len>b.len;//按长度从小到大排列
	}//< 成立，不交换位置~~ 大根堆
	Node(){}
	Node(int vv,int ll,int cc){v=vv,len=ll,cost=cc;}
};

int BFS()
{
	 priority_queue<Node>q;
	 q.push(Node(1,0,0));
	 while(!q.empty()){
		Node u=q.top();	q.pop();
		
		if(u.v==n) return u.len;
		
		for(int i=head[u.v];i>=0;i=next[i])
			if(u.cost+c[i]<=money)
				q.push(Node(v[i],u.len+l[i],u.cost+c[i]));
	 }
	 return -1;
}

int main()
{
	while(~scanf("%d%d%d",&money,&n,&m))
	{
		memset(head,-1,sizeof(head));
		for(int i=0;i<m;i++){
			scanf("%d%d%d%d",&u[i],&v[i],&l[i],&c[i]);
			next[i]=head[u[i]];
			head[u[i]]=i;
		}
		printf("%d\n",BFS());
	}
	return 0;
}