/***
	差分约束  (求最长路)
***/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <map>
using namespace std;
#define INF 10000000
struct node
{
    int u,v,next,w;
} edge[1000100];
int first[3001],d[3001];
int n;
int t;
void CL()
{
    t = 1;
    int i;
    for(i = 1; i <= n; i ++)
        first[i] = -1;
    for(i = 1;i <= n;i ++)
    d[i] = 0;
}
void add(int u,int v,int w)
{
    edge[t].u = u;
    edge[t].v = v;
    edge[t].w = w;
    edge[t].next = first[u];
    first[u] = t;
    t ++;
}
int main()
{
    int i,m,j,u,v,flag,sv,ev,w;
    char ch;
    while(scanf("%d%d%*c",&n,&m)!=EOF)
    {
        CL();
        for(i = 1; i <= m; i ++)
        {
            scanf("%c",&ch);
            if(ch == 'V')
            {
                scanf("%d%d%*c",&sv,&ev);
                add(ev,sv,1);
            }
            else
            {
                scanf("%d%d%d%*c",&sv,&ev,&w);
                add(ev,sv,w);
                add(sv,ev,-w);
            }
        }
        for(i = 1; i <= n+1; i ++)
        {
            flag = 0;
            for(j = 1;j < t;j ++)
            {
                u = edge[j].u;
                v = edge[j].v;
                if(d[v] < d[u] + edge[j].w)
                {
                    d[v] = d[u] + edge[j].w;
                    flag = 1;
                }
            }
            if(!flag)
            break;
        }
        if(!flag)
            printf("Reliable\n");
        else
            printf("Unreliable\n");
    }
    return 0;
}