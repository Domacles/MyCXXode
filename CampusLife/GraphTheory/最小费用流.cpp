#define INF 0x7ffffff
const int maxn = 5555;

typedef pair<int,int> P;
struct edge{int to,cap,cost,rev;
	edge(){}
	edge(int a1,int a2,int a3,int a4){
		to=a1;cap=a2;cost=a3;rev=a4;}
};
int V;//�ڵ���
vector<edge>G[maxn];//ͼ���ڽӱ�
int h[maxn];//�������
int vis[maxn];//�Ƿ���SPFA�Ķ�����
int dist[maxn];//��̾���
int prevv[maxn],preve[maxn];//���·�е�ǰ���ڵ�Ͷ�Ӧ�ı�

void add_edge(int from,int to,int cap,int cost)
{
	G[from].push_back(edge(to,cap,cost,G[to].size()));
	G[to].push_back(edge(from,0,-cost,G[from].size()-1));
}

int min_cost_flow(int s,int t,int f)
{
	int res=0;
	while(f>0){
		queue<int> que;
		while(!que.empty()) que.pop();
		fill(dist,dist+V,INF);
		fill(vis,vis+maxn,0);
		dist[s]=0;
		que.push(s);vis[s]=1;
		while(!que.empty()){
			int v=que.front();que.pop();vis[v]=0;
			for(int i=0;i<(int)G[v].size();i++){
				edge &e=G[v][i];
				if(e.cap >0 && dist[e.to] > dist[v] + e.cost){
					dist[e.to] = dist[v] + e.cost;
					prevv[e.to]=v, preve[e.to]=i;
					if(!vis[e.to])
						vis[e.to]=1, que.push(e.to);
				}
			}
		}

		if(dist[t]==INF) return res;

		int d=f;
		for(int v=t;v!=s;v=prevv[v])
			d=min(d,G[prevv[v]][preve[v]].cap);

		f-=d;
		res+=dist[t]*d;

		for(int v=t;v!=s;v=prevv[v]){
			edge &e=G[prevv[v]][preve[v]];
			e.cap-=d;
			G[v][e.rev].cap+=d;
		}
	}
	return res;
}



int min_cost_flow(int s,int t,int f){
	int res=0;
	fill(h,h+V,0);
	while(f>0){
		//puts("DEBUG");
		priority_queue< P, vector<P>, greater<P> >que;
		fill(dist,dist+V,INF);
		dist[s]=0;
		que.push(P(0,s));
		while(!que.empty()){
			P p=que.top();que.pop();
			int v=p.second;		//��dist[v]������vΪ���ı�
			if(dist[v]<p.first) continue;//��dist[v]������vΪ���ıߣ����if��������ǰ״̬�Ѿ�������̣�������״̬��������һ��״̬
			//puts("DEBUG");
			for(int i=0;i<(int)G[v].size();i++){
				edge &e=G[v][i];
				if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
					dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
					prevv[e.to]=v;
					preve[e.to]=i;
					que.push(P(dist[e.to],e.to));
				}
			}
		}
		
		if(dist[t]==INF) return -1;
		
		for(int v=0;v<V;v++) h[v]+=dist[v];
		
		int d=f;
		for(int v=t;v!=s;v=prevv[v])
			d=min(d,G[prevv[v]][preve[v]].cap);
		f-=d;
		res+=d*h[t];
		
		for(int v=t;v!=s;v=prevv[v]){
			edge &e=G[prevv[v]][preve[v]];
			e.cap-=d;
			G[v][e.rev].cap+=d;
		}
	}
	return res;
}