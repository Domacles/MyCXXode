/*
HDU 3586
树形DP+二分答案
*/
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1010;
const int INF=1000010;//这里一定要设得合适，不能太大，不能太小

struct Node
{
    int to;
    int next;
    int w;
}edge[MAXN*2];
int head[MAXN];
int tol;
int dp[MAXN];
void add(int a,int b,int w)
{
    edge[tol].to=a;
    edge[tol].next=head[b];
    edge[tol].w=w;
    head[b]=tol++;
    edge[tol].to=b;
    edge[tol].next=head[a];
    edge[tol].w=w;
    head[a]=tol++;
}

void init()
{
    tol=0;
    memset(head,-1,sizeof(head));
}

void dfs(int u,int pre,int limit)
{
    int flag=false;//标记是不是叶子结点
    dp[u]=0;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==pre)continue;
        flag=true;
        dfs(v,u,limit);
        if(edge[i].w<=limit)dp[u]+=min(dp[v],edge[i].w);
        else dp[u]+=dp[v];
    }
    if(!flag)dp[u]=INF;//叶子结点无穷大
}
int main()
{
    int n,m;
    int a,b,w;
    int l,r,mid;
    while(scanf("%d%d",&n,&m)==2)
    {
        if(n==0&&m==0)break;
        init();
        r=0;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d%d",&a,&b,&w);
            add(a,b,w);
            if(w>r)r=w;
        }
        l=1;
        int ans=-1;
        while(l<=r)
        {
            mid=(l+r)/2;
            dfs(1,-1,mid);
            if(dp[1]<=m)
            {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}