#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,f[1010];
struct node
{
    int x,y,s;
}e[20010];
bool cmp(node s, node v)
{
    return s.s>v.s;
}
int find(int x)
{
    if (x==f[x]) return x;
    f[x]=find(f[x]);
    return f[x];
}
void krusical()
{
    int i,t=0,ans=0;
    for (i=0; i<m; i++)
    {
        int x=find(e[i].x);
        int y=find(e[i].y);
        if (x!=y)
        {
            ans+=e[i].s;
            f[y]=f[x];
            t++;
        }
        if (t==n-1) break;
    }
    if (t==n-1) cout<<ans<<endl;
    else cout<<"-1"<<endl;
}
int main ()
{
    cin>>n>>m;
    int i,j;
    for (i=1; i<=n; i++)
        f[i]=i;
    for (i=0; i<m; i++)
        scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].s);
    sort(e,e+m,cmp);
    krusical();
    return 0;
}
