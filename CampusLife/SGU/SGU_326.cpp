/*****
        ��Ŀ����:
        ��֪С���ڸ���ӵ�Ŀǰ�÷֣�С�����ӽ�Ҫ�����ĳ���(�Ȱ���С���ڵģ�������С�����)��
        ��֪С����i��j��Ҫ�����ĳ�����
        ��:1�Ŷ����ܷ�ȡ�õ�һ���߲��е�һ��

        ˼·�� ���������
        ��Ҫʹ1����ӻ�ʤ���Σ�Ȼ��ʹ��������ӻ�ʤ�����������С��
        ��������ȽϵĲ��ԣ���1������������Ŀǰ�÷ֵĲ���Ϊ��������÷ֵ��Ͻ�upi��
        ��ͼ��
        Դ����Ϊ1�Ŷ��飬Ȼ����N-1������Ϊ�������飬��Դ�㵽����������һ������λupi�ı�;
        Ȼ�󣬶���ÿһ���б�����i��j���飬��һ������Ϊ����i,j���������ĵ㣬
        i��j���õ���һ������Ϊs[i][j]�ıߣ�Ȼ��õ㵽�����һ������Ϊs[i][j]�ıߣ�������

        ����������˵�����еı������ɷ���Ӷ��ﵽĿ�꣬�������NO��
*****/
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

const int maxn =222;

int N;
int score[maxn],r[maxn],a[maxn][maxn];

#define INF 1e8
struct edge{int to,rev;
			int cap;
	edge(){}
	edge(int a1,int a2,int a3){to=a1;cap=a2;rev=a3;}
};

vector<edge>G[maxn];//ͼ���ڽӱ�
int level[maxn];//���㵽Դ��ľ�����
int iter[maxn];//��ǰ��������֮ǰ�ı��Ѿ�û����

void add_edge(int from,int to,int cap){
	G[from].push_back(edge(to,cap,G[to].size()));
	G[to].push_back(edge(from,0,G[from].size()-1));
	//����ͼ�з����Ϊ0������ͼ�з����Ϊcap
}

//ͨ��bfs��Դ������ľ�����
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

//ͨ��DFSѰ������·
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

//��s��t�������
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

void init()
{
	for(int i=0;i<maxn;i++)
		G[i].clear();
}

int s[maxn];
bool solve(int st,int ed)
{
    int sum=0;
    for(int i=1;i<N;i++){
        s[i]=score[0]-score[i];
        if(s[i]<0) return 0;
    }
    init();

    for(int i=1;i<N;i++) add_edge(0,i,s[i]);
    int V=N;
    for(int i=1;i<N;i++) for(int j=i+1;j<N;j++){
        s[V]=a[i][j];
        sum+=s[V];
        add_edge(i,V,a[i][j]);
        add_edge(j,V,a[i][j]);
        V++;
    }
    for(int i=N;i<V;i++) add_edge(i,V,s[i]);
    int ret=max_flow(0,V);
    return ret==sum;
}

int main()
{
    //freopen("r.txt","r",stdin);
    while(~scanf("%d",&N)){
        for(int i=0;i<N;i++) scanf("%d",&score[i]);
        for(int i=0;i<N;i++) scanf("%d",&r[i]);
        score[0]+=r[0];
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                scanf("%d",&a[i][j]);
        if(solve(1,N-1)) puts("YES");
        else puts("NO");
    }
    return 0;
}
