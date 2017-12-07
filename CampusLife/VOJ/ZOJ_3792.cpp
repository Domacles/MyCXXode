/************
����һ������ͼ�����е����� p,q ,ͼ�е�ÿ���߶���һ��Ȩֵ c ��
��Ҫ��ɾ��ĳЩ��ʹ�� p,q ֮�䲻�����κ�·��,
�ڱ��ƻ����ߵ���Ȩֵ��С�������,ʹ��ʣ���Ȩֵ���ܺ���ɾ������ cnt �ı�ֵ���.

��Ȩֵ��С->��С��

ɾ��������С--> ����:
    ÿ���ߵ�cֵС��1000,��ôp��q֮�����С��һ��С�� 1000M��1000000 ����ÿ���ߵ� c ���¶�Ϊ 1000000c+1 ��
    Ȼ����maxFlow����maxFlow/1000000Ϊ��С�maxFlow%1000000Ϊ���ٵĸ�������������ֵ���ɡ�
            <!!!>
************/
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int,int> PII;
typedef long long ll;

#define INF 1LL<<61
#define maxn 55
struct edge{
	int to,rev;
	ll cap;
	edge(){}
	edge(int a1,int a2,int a3){to=a1;cap=a2;rev=a3;}
};

vector<edge>G[maxn];
int level[maxn];
int iter[maxn];

void add_edge(int from,int to,ll cap){
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

ll dfs(int v,int t,ll f){
	if(v==t) return f;
	for(int &i=iter[v];i<(int)G[v].size();i++){
		edge &e=G[v][i];
		if(e.cap > 0 && level[v] < level[e.to]){
			ll d=dfs(e.to,t,min(f,e.cap));
			if(d>0){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}

ll max_flow(int s,int t){
	ll flow=0;
	while(1){
		bfs(s);
		if(level[t]<0) return flow;
		memset(iter,0,sizeof(iter));
		ll f;
		while((f=dfs(s,t,INF))>0){
			flow+=f;
		}
	}
}

int N,M,P,Q;

void init()
{
    for(int i=0;i<=N;i++) G[i].clear();
}

int main()
{
    //freopen("r.txt","r",stdin);
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&N,&M,&P,&Q);
        init();
        ll sum=0;
        for(int i=0;i<M;i++){
            int u,v,c; scanf("%d%d%d",&u,&v,&c);
            sum+=c;
            add_edge(u,v,1000000*c+1);
            add_edge(v,u,1000000*c+1);// undirected
        }
        ll ans=max_flow(P,Q);
        ll a=sum-ans/1000000;
        ll b=ans%1000000;
        if(b) printf("%.2lf\n",(double)a/(double)b);
        else puts("Inf");
    }
    return 0;
}
