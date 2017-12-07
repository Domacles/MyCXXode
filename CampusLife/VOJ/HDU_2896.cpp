/***
	Ö¸ÕëºÄÄÚ´æ¶à
***/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn=100010;
vector<int> v5;
int idx(char c){return (int)c;}
int chd[maxn][128],sz,val[maxn],f[maxn],last[maxn];
int hash[maxn];
void init()
{
    sz=1;
    memset(chd[0],0,sizeof(chd[0]));
    memset(val,0,sizeof(val));
    memset(f,0,sizeof(f));
    memset(last,0,sizeof(last));
}
void insert(char *p,int i)
{
    int u=0;
    for(;*p;p++)
    {
        if(chd[u][idx(*p)]==0)
        {
            memset(chd[sz],0,sizeof(chd[sz]));
            chd[u][idx(*p)]=sz++;
        }
        u=chd[u][idx(*p)];
    }
    val[u]++;
    hash[u]=i;
}
int getFail()
{
    queue<int> q;
    f[0]=0;
    for(int c=0;c<128;c++)
    {
        int u=chd[0][c];
        if(u)
        {
            f[u]=0;q.push(u);last[u]=0;
        }
    }
    while(!q.empty())
    {
        int r=q.front(); q.pop();
        for(int c=0;c<128;c++)
        {
            int u=chd[r][c];
            if(!u)
            {
                chd[r][c]=chd[f[r]][c];
                continue;
            }
            q.push(u);
            int v=f[r];
            while(v&&!chd[v][c]) v=f[v];
            f[u]=chd[v][c];
            last[u]=(val[f[u]])?f[u]:last[f[u]];
        }
    }
}
void solve(int x)
{
    if(!x) return ;
    int u=hash[x];
    v5.push_back(u);
    solve(last[x]);
}
int find(char* T)
{
    int n=strlen(T);
    int j=0;
    for(int i=0;i<n;i++)
    {
        int c=idx(T[i]);
        j=chd[j][c];
        if(val[j]) solve(j);
        else if(last[j]) solve(last[j]);
    }
}
int main()
{
    int n,m;
    char dic[300],T[11000];
    while(scanf("%d",&n)!=EOF)
    {
        int cnt=0;
        init();
        for(int i=1;i<=n;i++)
        {
            scanf("%s",dic);
            insert(dic,i);
        }
        getFail();
        scanf("%d",&m);
        int cc=0;
        for(int i=1;i<=m;i++)
        {
            v5.clear();
            scanf("%s",T);
            find(T);
            if(v5.size())
            {   cc++;
                printf("web %d:",i);
                sort(v5.begin(),v5.end());
                for(int i=0;i<v5.size();i++)
                {
                    printf(" %d",v5[i]);
                }
                putchar(10);
            }
        }
        printf("total: %d\n",cc);
    }
    return 0;
}