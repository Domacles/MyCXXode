#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX  110000
#define min(a,b) (a)<(b)?(a):(b)
#define max(a,b) (a)>(b)?(a):(b)


struct node {

	int v;
	node *next;
}*head[MAX],tree[MAX];
int n,ptr,dp[MAX];
int ans,res[MAX],tot;

void Initial(){
	//初始化
	ptr = 1,ans = 2147483647;
	memset(dp,0,sizeof(dp));
	memset(head,NULL,sizeof(head));
}
void AddEdge(int x,int y) {
	//插入一条边
	tree[ptr].v = y;
	tree[ptr].next = head[x],head[x] = &tree[ptr++];
	tree[ptr].v = x;
	tree[ptr].next = head[y],head[y] = &tree[ptr++];
}

void Dfs(int son,int pa) {
	//第一次深搜，记录每个节点的子节点数
	node *p = head[son];
	dp[son] = 1;
	while (p != NULL) {

		if (p->v != pa) 
			Dfs(p->v,son),dp[son] += dp[p->v];
		p = p->next;
	}
}
void Tree_DP(int son,int pa) {

	int mmax = 0,sum = 0,sumpa = 0;
	node *p = head[son];

	//算向上和向下的节点数
	while (p != NULL) {
	
		if (p->v != pa) {
			
			Tree_DP(p->v,son);
			mmax = max(mmax,dp[p->v]);
		}
		p = p->next;
	}
	//更新答案
	mmax = max(n-dp[son],mmax);
	if (mmax < ans) {

		tot = 1,ans = mmax;
		res[tot] = son;
	}
	else if (mmax == ans) {

		tot++;
		res[tot] = son;
	}
}


int main()
{
	int i,j,k,a,b;


	while (scanf("%d",&n) != EOF) {
		
		Initial();
		for (i = 1; i < n; ++i)
			scanf("%d%d",&a,&b),AddEdge(a,b);


		Dfs(1,0);
		Tree_DP(1,0);
		sort(res+1,res+tot+1);
		for (i = 1; i <= tot; ++i)
			printf("%d%c",res[i],i==tot?'\n':' ');
	}
}