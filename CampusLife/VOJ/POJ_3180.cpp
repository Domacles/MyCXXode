/****
	求强联通分量size>=2的个数
****/
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>
#include <iostream>

using namespace std;
#define maxn 10005

typedef long long LL;
typedef pair<int,int> P;
const int INF = 0x3fffffff;
int vis[maxn],N,M;
vector<int>G[maxn],rG[maxn],Stack1,Stack2;
int num1,num2;

void add_edge(int u,int v)
{
	G[u].push_back(v);
	rG[v].push_back(u);
}

void dfs(int u,int c){
	vis[u]=c;
	for(int i=0;i<(int)G[u].size();i++)
		if(!vis[G[u][i]]) dfs(G[u][i],c);
	Stack1.push_back(u);
}

void rdfs(int u,int c){
	vis[u]=c;
	for(int i=0;i<(int)rG[u].size();i++)
		if(!vis[rG[u][i]]) rdfs(rG[u][i],c);
	Stack2.push_back(u);
}

int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int x,y; scanf("%d%d",&x,&y);
		x--,y--,add_edge(x,y);
	}
	for(int i=0;i<N;i++)
		if(!vis[i]) dfs(i,++num1);
	memset(vis,0,sizeof(vis));
	int ans=0;
	for(int i=N-1;i>=0;i--){
		Stack2.clear();
		if(!vis[Stack1[i]]) rdfs(Stack1[i],++num2);
		if(Stack2.size()>=2) ans++;
	}
	printf("%d\n",ans);
	return 0;
}