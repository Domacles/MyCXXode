最小度限制生成树是指某一个节点的度限制为k的最小生成树。具体的做法去看论文或者黑书吧，这里不详细讲了。

理解最小度限制生成树的解法，最主要的就是看懂如何由m度生成树求m+1度生成树，另外要理解无解的情况。

今天终于把模板整理出来了，prim那里用了优先队列优化，添加删除边破环那里用的是动态规划。试了试PKU1639这道题，结果正确，但是由于数据水，不知道效率如何。

#define maxn 505
struct str
{
    int v,c,n;
}edge[maxn<<1];//邻接表
int head[maxn],cnt;
void init()
{
    memset(head,-1,sizeof(head));
    cnt=0;
}
void addEdge(int u,int v,int c)
{
    edge[cnt].v=v;
    edge[cnt].c=c;
    edge[cnt].n=head[u];
    head[u]=cnt++;
    edge[cnt].v=u;
    edge[cnt].c=c;
    edge[cnt].n=head[v];
    head[v]=cnt++;
}
int dis[maxn],best[maxn],index[maxn];
//dis是prim里到某节点的最短距离，best具体含义看论文，index是best对应的边号
int incom[maxn],com;//记录节点在哪个联通分量里
bool vis[maxn],intree[maxn<<1];
struct node
{
    int u,c,e;//u是邻接表里对应的那个v,c是边权，e是边号
    node(){}
    node(int _u,int _c,int _e):u(_u),c(_c),e(_e){}
    bool operator <(const node a)const{return a.c<c;}
};//优先队列数据结构
priority_queue<node>q;
int prim(int n,int s)
{
    for(int i=0;i<=n;i++)dis[i]=inf;
    memset(vis,0,sizeof(vis));vis[s]=true;
    memset(intree,0,sizeof(intree));//判断边是否在生成树中
    int val=0;com=0;
    for(int i=1;i<=n;i++)if(!vis[i])//求各个连通分量的最小生成树
    {
        dis[i]=0;++com;q.push(node(i,0,-1));
        while(!q.empty())
        {
            int u=q.top().u,e=q.top().e,c=q.top().c;q.pop();
            if(vis[u])continue;
            val+=c;incom[u]=com;
            vis[u]=intree[e]=intree[e^1]=true;
            for(int j=head[u];j!=-1;j=edge[j].n)
            {
                int v=edge[j].v,c=edge[j].c;
                if(vis[v])continue;
                if(dis[v]>c)dis[v]=c,q.push(node(v,c,j));
            }
        }
    }
    memset(vis,0,sizeof(vis));//vis数组复用，判断某节点所在的连通分量是否已经连接
    for(int i=head[s];i!=-1;i=edge[i].n)
    {
        int v=edge[i].v,c=edge[i].c;
        q.push(node(v,c,i));
    }
    while(!q.empty())//把各个分量连起来，这样就求出m度最小生成树
    {
        int v=q.top().u,c=q.top().c,e=q.top().e;
        q.pop();
        if(!vis[incom[v]])
            val+=c,intree[e]=intree[e^1]=vis[incom[v]]=true;
    }
    return val;
}
void dfs(int u,int fa,int n,int s)//更新best
{
    for(int i=head[u];i!=-1;i=edge[i].n)if(intree[i])
    {
        int v=edge[i].v,c=edge[i].c;
        if(v==fa)continue;
        if(u==s)best[v]=-inf,index[v]=i;
        else
        {
            if(best[u]>c)best[v]=best[u],index[v]=index[u];
            else best[v]=c,index[v]=i;
        }
        dfs(v,u,n,s);
    }
}
//int mval;
int klimit(int n,int s,int k)//求k度最小生成树,n是节点个数，s是度被限制的节点，k为限制的度数
{
    int val=prim(n,s);
    //mval=val;
    if(k<com)return inf;//如果k小于连通分量个数，则无解
    best[s]=-inf;dfs(s,-1,n,s);
    for(int i=com+1;i<=k;i++)
    {
        int mn=inf,ed=-1;
        for(int j=head[s];j!=-1;j=edge[j].n)if(!intree[j])
        {
            int v=edge[j].v,c=edge[j].c;
            if(mn>c-best[v])mn=c-best[v],ed=j;
        }
        if(ed==-1)return inf;//无法再使度扩大则也是无解的
        int v=edge[ed].v,dx=index[v];
        val+=mn;
        //mval=min(val,mval);
        intree[ed]=intree[ed^1]=true;
        intree[dx]=intree[dx^1]=false;
        best[v]=-inf,dfs(v,s,n,s);
    }
    return val;
}

如果是求某节点正好为k度则就是上面的模板，如果节点的度不大于k则将上面mval的三条注释取消掉，最后结果就是mval。