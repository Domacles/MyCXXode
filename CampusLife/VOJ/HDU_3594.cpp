#include <cstdio>
#include <cstring>
#include <stack>
#define M 20007
using namespace std;
int head[M],low[M],dfn[M],vis[M],id[M];
stack<int>s;
int n,cnt,num,count,ok;
struct Edg
{
    int to,next;
}edg[M*5];

void init()
{
    cnt=num=count=ok=0;
    memset(vis,0,sizeof(vis));
    memset(dfn,0,sizeof(id));
    memset(head,-1,sizeof(head));
}

void addedge(int a,int b)
{
    edg[cnt].to=b;
    edg[cnt].next=head[a];
    head[a]=cnt++;
}

void tarjan(int u)
{
    int v;
    low[u]=dfn[u]=++num;
    vis[u]=1;
    s.push(u);
    for(int i=head[u];i!=-1;i=edg[i].next)
    {
        v=edg[i].to;
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[v],low[u]);
        }
        else if(vis[v])
        {
            low[u]=min(dfn[v],low[u]);
            if(dfn[v]!=low[v])//说明一条边在两个环上
                ok=1;
        }
        if(ok) return;
    }
    if(dfn[u]==low[u])
    {
        count++;
        if(count>1)//如果count大于1就说明存在多个连通分量
            ok=1;
        do
        {
            v=s.top();
            s.pop();
            vis[v]=0;
        }while(s.top()!=u);
    }
}

int main()
{
	//freopen("in.txt","r",stdin);
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d",&n);
        init();
        int a,b;
        while(scanf("%d%d",&a,&b),a|b)
        {
            a++;b++;
            addedge(a,b);
        }
        for(int i=1;i<=n;i++)
            if(!dfn[i])
                tarjan(i);
        if(ok||count!=1)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
