��С��������������ָĳһ���ڵ�Ķ�����Ϊk����С�����������������ȥ�����Ļ��ߺ���ɣ����ﲻ��ϸ���ˡ�

�����С�������������Ľⷨ������Ҫ�ľ��ǿ��������m����������m+1��������������Ҫ����޽�������

�������ڰ�ģ����������ˣ�prim�����������ȶ����Ż������ɾ�����ƻ������õ��Ƕ�̬�滮��������PKU1639����⣬�����ȷ��������������ˮ����֪��Ч����Ρ�

#define maxn 505
struct str
{
    int v,c,n;
}edge[maxn<<1];//�ڽӱ�
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
//dis��prim�ﵽĳ�ڵ����̾��룬best���庬�忴���ģ�index��best��Ӧ�ıߺ�
int incom[maxn],com;//��¼�ڵ����ĸ���ͨ������
bool vis[maxn],intree[maxn<<1];
struct node
{
    int u,c,e;//u���ڽӱ����Ӧ���Ǹ�v,c�Ǳ�Ȩ��e�Ǳߺ�
    node(){}
    node(int _u,int _c,int _e):u(_u),c(_c),e(_e){}
    bool operator <(const node a)const{return a.c<c;}
};//���ȶ������ݽṹ
priority_queue<node>q;
int prim(int n,int s)
{
    for(int i=0;i<=n;i++)dis[i]=inf;
    memset(vis,0,sizeof(vis));vis[s]=true;
    memset(intree,0,sizeof(intree));//�жϱ��Ƿ�����������
    int val=0;com=0;
    for(int i=1;i<=n;i++)if(!vis[i])//�������ͨ��������С������
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
    memset(vis,0,sizeof(vis));//vis���鸴�ã��ж�ĳ�ڵ����ڵ���ͨ�����Ƿ��Ѿ�����
    for(int i=head[s];i!=-1;i=edge[i].n)
    {
        int v=edge[i].v,c=edge[i].c;
        q.push(node(v,c,i));
    }
    while(!q.empty())//�Ѹ������������������������m����С������
    {
        int v=q.top().u,c=q.top().c,e=q.top().e;
        q.pop();
        if(!vis[incom[v]])
            val+=c,intree[e]=intree[e^1]=vis[incom[v]]=true;
    }
    return val;
}
void dfs(int u,int fa,int n,int s)//����best
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
int klimit(int n,int s,int k)//��k����С������,n�ǽڵ������s�Ƕȱ����ƵĽڵ㣬kΪ���ƵĶ���
{
    int val=prim(n,s);
    //mval=val;
    if(k<com)return inf;//���kС����ͨ�������������޽�
    best[s]=-inf;dfs(s,-1,n,s);
    for(int i=com+1;i<=k;i++)
    {
        int mn=inf,ed=-1;
        for(int j=head[s];j!=-1;j=edge[j].n)if(!intree[j])
        {
            int v=edge[j].v,c=edge[j].c;
            if(mn>c-best[v])mn=c-best[v],ed=j;
        }
        if(ed==-1)return inf;//�޷���ʹ��������Ҳ���޽��
        int v=edge[ed].v,dx=index[v];
        val+=mn;
        //mval=min(val,mval);
        intree[ed]=intree[ed^1]=true;
        intree[dx]=intree[dx^1]=false;
        best[v]=-inf,dfs(v,s,n,s);
    }
    return val;
}

�������ĳ�ڵ�����Ϊk������������ģ�壬����ڵ�ĶȲ�����k������mval������ע��ȡ���������������mval��