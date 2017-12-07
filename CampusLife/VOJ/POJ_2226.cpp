#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;
#define maxn 1005
typedef pair<int,int> PII;

int R,C,Map[maxn][maxn];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

int N,nr,nc,used[maxn*2],mat[maxn*2];
vector<int>G[maxn*2];

bool dfs(int x){
	for(int i=0;i<(int)G[x].size();i++){
		int y=G[x][i];
		if(!used[y]){
			used[y]=1;
			if(mat[y]==-1 || dfs(mat[y])){
				mat[y]=x;
				return 1;
			}
		}
	}
	return 0;
}

int H_K()//二分匹配
{
	int val=0;
	memset(mat,-1,sizeof(mat));
	for(int i=1;i<=N;i++){
		if(dfs(i)) val++;
		memset(used,0,sizeof(used));
	}
	return val;
}

int main()
{
	scanf("%d%d",&R,&C);
	//映射构图，同一行不属于同一块的点赋予不同行标，同块则同行标
	for(int i=0;i<R;i++){
		char s[maxn];scanf("%s",s);
		int pre=0;
		for(int j=0;j<C;j++){
			if(s[j]=='*') {	
				if(pre) Map[i][j]=nr;
				else{
					Map[i][j]=++nr;  pre=1;
				}
			}
			else pre=0;
		}
	}
	//同一列同上
	for(int i=0;i<C;i++){
		int pre=0;
		for(int j=0;j<R;j++){
			if(Map[j][i]) {	
				if(!pre) nc++,pre=1;
				G[Map[j][i]].push_back(nc);
			}
			else pre=0;
		}
	}
	
	N=nr;
	int ans=H_K();
	printf("%d\n",ans);
	return 0;
}