int g[1010][1010];
int n,m,x;
const int INF=1000000000;
int v[1010];
int dist[1010][20];
int main()
{
    while (scanf("%d%d%d",&n,&m,&x)!=EOF)
    {
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                g[i][j]=INF;
        for (int i=0; i<m; i++)
        {
            int p,q,r;
            scanf("%d%d%d",&p,&q,&r);
            if (r<g[p][q]) g[p][q]=r;
        }
        for (int i=1; i<=n; i++)
        {
            v[i]=0;
            for (int j=0; j<=x; j++)
                dist[i][j]=INF;
        }
        dist[1][0]=0;
        dist[0][0]=INF;
        while (1)
        {
            int k=0;
            for (int i=1; i<=n; i++)
                if (v[i]<x && dist[i][v[i]]<dist[k][0])
                    k=i;
            if (k==0) break;
            if (k==n && v[n]==x-1) break;
            for (int i=1; i<=n; i++)
            {
                if (v[i]<x &&
                        dist[k][v[k]]+g[k][i]<dist[i][x])
                {
                    dist[i][x]=dist[k][v[k]]+g[k][i];
                    for (int j=x; j>0; j--)
                        if (dist[i][j]<dist[i][j-1])
                            swap(dist[i][j],dist[i][j-1]);
                }
            }
            v[k]++;
        }
        if (dist[n][x-1]<INF) printf("%d\n",dist[n][x-1]);
        else printf("-1\n");
    }
    return 0;
}
