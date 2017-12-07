/*******
		K短路
*******/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <queue>
using namespace std;

struct Edge
{
    int to;
    int value;
    int next;
    bool operator < (const Edge &t) const
    {
        return t.value < value;
    }
};
struct Edge1
{
    int to;
    int value;
    int next;
};
struct Node
{
    int to;
    int f, g;
    bool operator < (const Node &t) const
    {
        if(t.f==f)
            return t.g < g;
        return t.f < f;
    }
};
Edge edge[100010];  //存储边与原图反向的图
Edge1 edge1[100010];    //存储原图
int adj[1010], adj1[1010], visited[1010], dis[1010], edgeNum, edgeNum1;
int N, M;

void Dijkstra(int start)
{
    int k;
    Edge t, cur;
    priority_queue<Edge> PQ;
    for(k=0; k<N; k++)
    {
        visited[k] = 0;
        dis[k] = INT_MAX;
    }
    t.to = start;   //起始顶点
    t.next = -1;
    t.value = 0;
    dis[start] = 0; //自己到自己路径为0
    PQ.push(t);
    visited[start] = 1; //标记以入队
    while(!PQ.empty())
    {
        cur = PQ.top();  //出队
        PQ.pop();
        visited[cur.to] = 0;    //标记出队
        for(int tmp = adj[cur.to]; tmp != -1; tmp = edge[tmp].next)
        {
            if(dis[edge[tmp].to] > dis[cur.to] + edge[tmp].value)
            {
                dis[edge[tmp].to] = dis[cur.to] + edge[tmp].value;
                if(visited[edge[tmp].to] == 0)
                {
                    PQ.push(edge[tmp]);
                    visited[edge[tmp].to] = 1;
                }
            }
        }
    }
}

int A_star(int start, int end, int k)
{
    Node e, ne;
    int cnt = 0;
    priority_queue<Node> PQ;
    if(start==end)
        k++;
    if(dis[start]==INT_MAX)     //无法到达终点
        return -1;
    e.to = start;
    e.g = 0;
    e.f = e.g + dis[e.to];
    PQ.push(e);
    while(!PQ.empty())
    {
        e = PQ.top();
        PQ.pop();
        if(e.to==end)
            cnt++;  //第cnt短路
        if(cnt==k)
            return e.g;
        for(int i=adj1[e.to]; i!=-1; i=edge1[i].next)
        {
            ne.to = edge1[i].to;
            ne.g = e.g + edge1[i].value;
            ne.f = ne.g + dis[ne.to];
            PQ.push(ne);
        }
    }
    return -1;
}

void addEdge(int a, int b, int len) //反向图添加边
{
    edge[edgeNum].to = b;
    edge[edgeNum].next = adj[a];
    edge[edgeNum].value = len;
    adj[a] = edgeNum++;
}

void addEdge1(int a, int b, int len)    //原图添加边
{
    edge1[edgeNum1].to = b;
    edge1[edgeNum1].next = adj1[a];
    edge1[edgeNum1].value = len;
    adj1[a] = edgeNum1++;
}

int main()
{
//    freopen("test.txt", "r", stdin);
    int a, b, len, i, s, t, k;
    while(scanf("%d %d", &N, &M)!=EOF)
    {
        for(i=0; i<N; i++)
        {
            adj[i] = -1;
            adj1[i] = -1;
        }
        for(edgeNum=i=0; i<M; i++)
        {
            scanf("%d %d %d", &a, &b, &len);
            addEdge1(a-1, b-1, len);    //构造原图
            addEdge(b-1, a-1, len); //构造反向图
        }
        scanf("%d %d %d", &s, &t, &k);
        Dijkstra(t-1);  //求原图中各点到终点的最短路
        int ans = A_star(s-1, t-1, k);  //求第k短路
        printf("%d\n", ans);
    }
    return 0;
}