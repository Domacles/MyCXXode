#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<math.h>

using namespace std;
#define maxm 1100*1100
#define maxn 1100
#define eps 0.000001
#define zero(x) ((fabs(x)<eps?0:x))
#define INF 99999999
struct point
{
    int x;
    int y;
    int h;
}p[maxn];
double dist(int x,int y)
{
    double xx=0;
    xx=(p[x].x-p[y].x)*(p[x].x-p[y].x);
    xx+=(p[x].y-p[y].y)*(p[x].y-p[y].y);
    xx=xx*1.0;
    return sqrt(xx);
}
struct list
{
    double h;
    double l;
    double s;
    friend bool operator < (const list &a,const list &b)
    {
        return a.s<b.s;
    }
}maps[maxn][maxn];
int m,n;
double prime(double mid)//mid 假设的每单位距离的消耗
{//prime
    double dis[maxn];
    int vis[maxn];
    int i,j;
    for(i=0;i<=n;i++)
    {
        dis[i]=INF;
        vis[i]=0;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            maps[i][j].s=maps[i][j].h-maps[i][j].l*mid;
        }
    }
    dis[1]=0;
    double ans;
    ans=0;
    while(1)
    {
        double minn=INF;
        int ip;
        for(i=1;i<=n;i++)
        {
            if(vis[i])continue;
            if(dis[i]<minn)
            {
                minn=dis[i];
                ip=i;
            }
        }
        if(zero(minn-INF)==0)break;
        vis[ip]=1;
        ans+=minn;
        for(i=1;i<=n;i++)
        {
            if(vis[i])continue;
            dis[i]=min(dis[i],maps[ip][i].s);
        }
    }
    return ans;
}
int main()
{
    freopen("r1.txt","r",stdin);
    //int i,j;
    while(~scanf("%d",&n)&&n)
    {
        m=0;
        for(i=1;i<=n;i++)scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].h);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                maps[i][j].h=fabs(p[i].h-p[j].h);
                maps[i][j].l=dist(i,j);
            }
        }
        double l,r,mid;
        l=0;
        r=100;
        mid=(l+r)/2;
        while(zero(r-l)>0)//分数规划
        {
            mid=(l+r)/2;
            if(prime(mid)>0)l=mid;
            else r=mid;
        }
        printf("%.3f\n",mid);
    }
    return 0;
}
