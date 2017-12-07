//双向图的欧拉回路
#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;
#define maxn 11000
vector<int>G[maxn];
int N,M;

void dfs(int u){
	for(int i=0;i<(int)G[u].size();i++){
		int v=G[u][i];
		if(v==0) continue;
		G[u][i]=0;
		dfs(v);
	}
	printf("%d\n",u);
}

int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1);
	return 0;
}