#define INF 1e8
#define maxn 555
struct edge{
	int to,rev;
	int cap;
	edge(){}
	edge(int a1,int a2,int a3){to=a1;cap=a2;rev=a3;}
};

vector<edge>G[maxn];
int level[maxn];
int iter[maxn];

void add_edge(int from,int to,int cap){
	G[from].push_back(edge(to,cap,G[to].size()));
	G[to].push_back(edge(from,0,G[from].size()-1));

}

void bfs(int s){
	memset(level,-1,sizeof(level));
	queue<int> que;
	level[s]=0;
	que.push(s);
	while(!que.empty()){
		int v=que.front();que.pop();
		for(int i=0;i<(int)G[v].size();i++){
			edge &e=G[v][i];
			if(e.cap > 0 && level[e.to] <0){
				level[e.to]=level[v]+1;
				que.push(e.to);
			}
		}
	}
}

int dfs(int v,int t,int f){
	if(v==t) return f;
	for(int &i=iter[v];i<(int)G[v].size();i++){
		edge &e=G[v][i];
		if(e.cap > 0 && level[v] < level[e.to]){
			int d=dfs(e.to,t,min(f,e.cap));

			if(d>0){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s,int t){
	int flow=0;
	while(1){
		bfs(s);
		if(level[t]<0) return flow;
		memset(iter,0,sizeof(iter));
		int f;
		while((f=dfs(s,t,INF))>0){
			flow+=f;
		}
	}
}

void Print()
{
    for(int i=S;i<=T;i++){
        printf("...... %d .....\n",i);
        for(int j=0;j<(int)G[i].size();j++){
            edge &e=G[i][j];
            printf("%d %d\n",e.to,e.cap);
        }
    }
}
