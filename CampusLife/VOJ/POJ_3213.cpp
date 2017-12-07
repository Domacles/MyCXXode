/*求从S到E恰好经过N条边(可重复走)的最短路。*/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define MAXN 210
#define INF 1000000000
int v[1005];
int map[MAXN][MAXN];
int ans[MAXN][MAXN];
int temp[MAXN][MAXN];
int cnt;
int N,T,S,E;
void Init()
{
    int val,s,e,i,j;
    for(i=0;i<205;i++)
    {
        for(j=0;j<205;j++)
            map[i][j]=ans[i][j]=temp[i][j]=INF;
        ans[i][i]=0;
    }
    cnt=0;
    memset(v,0,sizeof(v));
    for(i=1;i<=T;i++)
    {
        scanf("%d%d%d",&val,&s,&e);
        if(v[s]==0)
        {
            cnt++;
            v[s]=cnt;
        }
        if(v[e]==0)
        {
            cnt++;
            v[e]=cnt;
        }
        if(map[v[s]][v[e]]>val)
            map[v[s]][v[e]]=map[v[e]][v[s]]=val;
    }
}
void floyd(int a[MAXN][MAXN],int b[MAXN][MAXN],int c[MAXN][MAXN])
{
    int i,j,k;
    for(k=1;k<=cnt;k++)
        for(i=1;i<=cnt;i++)
            for(j=1;j<=cnt;j++)
                if(a[i][j]>b[i][k]+c[k][j])
                    a[i][j]=b[i][k]+c[k][j];
}
void copy(int a[MAXN][MAXN],int b[MAXN][MAXN])
{
    int i,j;
    for(i=1;i<=cnt;i++)
        for(j=1;j<=cnt;j++)
        {
            a[i][j]=b[i][j];
            b[i][j]=INF;
        }
}
void work(int n)//N次Floyd
{
    while(n)
    {
        if(n&1)
        {
            floyd(temp,ans,map);
            copy(ans,temp);
        }
        floyd(temp,map,map);
        copy(map,temp);
        n>>=1;
    } 
}
int main()
{
    while(scanf("%d%d%d%d",&N,&T,&S,&E)!=EOF)
    {
        Init();
        work(N);
        printf("%d\n",ans[v[S]][v[E]]);
    }
    return 0;
}