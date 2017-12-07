#include <cstdio>
#include <cstring>
#include <stack>
#define M 100007
using namespace std;

int head[M],low[M],dfn[M],vis[M],id[M];
stack<int>s;
int n,m,cnt,num,count,belong[M];
struct Edg
{
    int to,next;
}edg[M*5];

void init()
{
    cnt=num=count=0;
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
            low[u]=min(dfn[v],low[u]);
    }
    if(dfn[u]==low[u])
    {
        count++;
       /* do
        {
            v=s.top();
            s.pop();
            vis[v]=0;
            belong[v]=count;
        }while(s.top()!=u); */
    }
}

int main()
{
	//freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0 && m==0) break;
        init();
        int a,b;
        for(int i=1;i<=m;i++) 
            scanf("%d%d",&a,&b) , addedge(a,b);
        for(int i=1;i<=n;i++)
            if(!dfn[i]) tarjan(i);
        if(count>1) printf("No\n");
        else  printf("Yes\n");
    }
    return 0;
}
