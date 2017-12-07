/*********
	最小支配集问题
	支配集：图集合中，若对于某子集的补集中任意点，
	该子集中存在一点与之存在边，这样的子集称为支配集。
*********/
#include <cstdio>
#include <vector>

using namespace std;
#define maxn 11111
vector<int>G[maxn];
int N,ans,vis[maxn],col[maxn];

void add_edge(int from,int to)
{
	G[from].push_back(to);
	G[to].push_back(from);
}

//当图为无向无环图时，可使用贪心DFS得到最小支配集
void DFS(int f,int u)//后序遍历
{
	bool flag=0;//孩子中是否有col标记
	vis[u]=1;
	for(int i=0;i<(int)G[u].size();i++){
		int v=G[u][i];
		if(vis[v]) continue;
		DFS(u,v); flag=flag||col[v];//如果孩子v标记了,则u不用标记
	}
	if(!f) 
		ans+=!(col[u]||flag),col[u]=1;//根节点特判
	else if(!flag && !col[u] &&!col[f])
		ans++,col[f]=1;//如果f没有标记，u自己也没标记，则标记f
}

int main()
{
	scanf("%d",&N);
	for(int i=1;i<N;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add_edge(x,y);
	}
	DFS(0,1);
	printf("%d\n",ans);
	return 0;
}