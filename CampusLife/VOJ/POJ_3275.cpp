/********
	利用已知关系，根据传递确定可以确定的关系总数，C(n,2)减之
********/
#include<stdio.h>
#include<strinG.h>
#include<vector>
using namespace std;
#define clr(x)memset(x,0,sizeof(x))
#define maxn 1005
int G[maxn][maxn];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        clr(G);
        int a,b;
        vector<int>from[maxn];
        vector<int>to[maxn];
        while(m--)
        {
            scanf("%d%d",&a,&b);
            G[a][b]=G[b][a]=1;
            from[b].push_back(a);
            to[a].push_back(b);
        }
        
        int i,j,k;
        int u,v;
        for(k=1;k<=n;k++)//k为传递中间点
            for(i=0;i<(int)from[k].size();i++)
                for(j=0;j<(int)to[k].size();j++)
                {
                    u=from[k][i];//前驱
                    v=to[k][j];//后驱
                    if(!G[u][v])
                    {
                        G[u][v]=G[v][u]=1;//由传递得到的关系
                        from[v].push_back(u);
                        to[u].push_back(v);
                    }
                }
        int res=0;
        for(i=1;i<=n;i++)
            for(j=i+1;j<=n;j++)
                if(G[i][j]) res++;
        printf("%d\n",(n*(n-1)/2)-res);
    }
    return 0;
}