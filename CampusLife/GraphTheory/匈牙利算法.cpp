int N,used[maxn*2],mat[maxn*2];
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

int H_K()//¶þ·ÖÆ¥Åä
{
	int val=0;
	memset(mat,-1,sizeof(mat));
	for(int i=1;i<=N;i++){
		memset(used,0,sizeof(used));
		if(dfs(i)) val++;
	}
	return val;
}