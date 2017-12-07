/***
	拓扑序最后一个缩点的其中一个牛，检查所有点都能够到达（使用边反向）
***/
#include <cstdio>
#include <queue>
#include <vector>
#include <stack>
#include <cstring>
#include <utility>
#include <iostream>

using namespace std;
#define maxn 11111
int V;
vector<int>  G[maxn];//图的邻接表
vector<int> rG[maxn];//图的边反向
vector<int> vs; //后序遍历的顶点列表
bool used[maxn];  //访问标记
int cmp[maxn];//所属强连通分量的拓扑序

void add_edge(int from,int to)
{
	G[from].push_back(to);
	rG[to].push_back(from);
}

void dfs(int v)
{
	used[v]=true;
	for(int i=0;i<(int)G[v].size();i++){
		if(!used[G[v][i]]) dfs(G[v][i]);
	}
	vs.push_back(v);
}

void rdfs(int v,int k)
{
	used[v]=true;
	cmp[v]=k;
	for(int i=0;i<(int)rG[v].size();i++){
		if(!used[rG[v][i]]) rdfs(rG[v][i],k);
	}
}

int scc()//点为 0 ~ V-1
{
	memset(used,0,sizeof(used));
	vs.clear();
	
	for(int v=0;v<V;v++)
		if(!used[v]) dfs(v);
		
	memset(used,0,sizeof(used));
	int k=0;
	for(int i=(int)vs.size()-1;i>=0;i--)
		if(!used[vs[i]]) rdfs(vs[i],k++);
		
	return k;
}

int N,M;

void solve()
{
	V=N;
	for(int i=0;i<maxn;i++) 
		G[i].clear(),rG[i].clear();
		
	for(int i=0;i<M;i++) {
		int A,B;
		scanf("%d%d",&A,&B);
		add_edge(A-1,B-1);
	}
	int n=scc();
	
	int u=0,num=0;//拓扑序
	for(int v=0;v<V;v++)
		if(cmp[v]==n-1)
			u=v,num++;
	
	memset(used,0,sizeof(used));
	rdfs(u,0);//边反向不改变连通性，故此可重用
	
	for(int v=0;v<V;v++)
		if(!used[v]){
			num=0;
			break;
		}
	printf("%d\n",num);
}

int main()
{
	while(~scanf("%d%d",&N,&M))
		solve();
	return 0;
}
