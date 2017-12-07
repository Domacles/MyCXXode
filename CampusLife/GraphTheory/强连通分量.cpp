const int maxn = 1e6;
int Stack[maxn],InStack[maxn],top;
int Belong[maxn],dfn[maxn],low[maxn],index;
vector<int>  G[maxn];
vector<int>SCC[maxn];
int scc,N,M;

void init()
{
    for(int i=0;i<=N;i++)
        G[i].clear(),SCC[i].clear();
    scc=0, top=0, index=0;
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(Belong,0,sizeof(Belong));
    memset(Stack,0,sizeof(Stack));
    memset(InStack,0,sizeof(InStack));
}

void DFS(int u,int f)
{
    dfn[u]=low[u]=++index;
    Stack[top++]=u, InStack[u]=1;
    for(int i=0;i<(int)G[u].size();i++){
        int v=G[u][i];
        if(!dfn[v]){
            DFS(v,u);
            low[u]=min(low[u],low[v]);
        }else if(InStack[v])
            low[u]=min(low[u],dfn[v]);
    }
    int j;
    if(dfn[u]==low[u]){
        scc++;
        while((j=Stack[--top])){//node >=1
            InStack[j]=0;
            Belong[j]=scc;
            SCC[scc].push_back(j);
            if(j==u) break;
        }
    }
}

int g[1100][1100],d[maxn];

void solve()
{
    memset(g,0,sizeof(g));
    memset(d,0,sizeof(d));
    for(int i=1;i<=N;i++)
        if(!dfn[i]) DFS(i,0);

    for(int u=1;u<=N;u++)
        for(int j=0;j<(int)G[u].size();j++){
            int v=G[u][j];
            if(Belong[v]!=Belong[u] && !g[Belong[u]][Belong[v]])
                g[Belong[u]][Belong[v]]=1,d[Belong[v]]++;
        }
}

vector<int> rG[maxn]; 
vector<int> vs;
bool used[maxn];
int  cmp[maxn];

void dfs(int v)
{
	used[v]=true;
	for(int i=0;i<(int)G[v].size();i++)
		if(!used[G[v][i]]) dfs(G[v][i]);
	vs.push_back(v);
}

void rdfs(int v,int k)
{
	used[v]=true;
	cmp[v]=k;
	for(int i=0;i<(int)rG[v].size();i++)
		if(!used[rG[v][i]]) rdfs(rG[v][i],k);
}

int solve()
{
	memset(used,0,sizeof(used));
	vs.clear();
	for(int v=1;v<=N;v++)
		if(!used[v]) dfs(v);
	memset(used,0,sizeof(used));
	int k=0;
	for(int i=vs.size()-1;i>=0;i--)
		if(!used[vs[i]]) rdfs(vs[i],k++);
	return k;
}

