#include <cstdio>
#include <queue>
#include <vector>
#include <stack>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
#define maxn 11000
vector<int>chil[maxn];
int size[maxn],vis[maxn],N;

void add_edge(int u,int v){
	chil[u].push_back(v);
	chil[v].push_back(u);
}
int dfs(int u){
	vis[u]=1;
	size[u]=1;
	for(int i=0;i<(int)chil[u].size();i++){
		int v=chil[u][i];
		if(vis[v]) continue;
		size[u]+=dfs(v);
	}
	return size[u];
}

bool check(int x){
	int up=N-size[x];
	if(up>N/2) return 0;
	for(int i=0;i<(int)chil[x].size();i++)
		if(size[chil[x][i]]<size[x] && size[chil[x][i]]>N/2) return 0;
	return 1;
}

int main()
{
	scanf("%d",&N);
	for(int i=1;i<N;i++){
		int u,v; scanf("%d%d",&u,&v);
		add_edge(u,v);
	}
	dfs(1);
	for(int i=1;i<=N;i++)
		if(check(i)) printf("%d\n",i);
	return 0;
}