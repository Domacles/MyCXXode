/***
	求出每一块板下降到的板并记录，然后按照这个路径进行动态规划，求MaxW;
	线段树段更新求路径+dp
***/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct TREE{int l, r, id;} tree[500000];
//id=-1   不完全覆盖
int n;
struct LINE {int h, l, r, w;} line[100000];

int cmp(LINE a,LINE b){return a.h<b.h;}

struct PATH
{
    int l;
    int r;
} path[100001];

void build(int i,int l,int r)
{
    tree[i].l=l;
    tree[i].r=r;
    tree[i].id=0;
    if(l==r)
        return;
    int mid=(l+r)/2;
    build(2*i,l,mid);
    build(2*i+1,mid+1,r);
}

void updata(int i,int l,int r,int id)//更新覆盖当前段的id
{
    if(tree[i].l>r || tree[i].r<l) return;
    if(tree[i].l>=l && tree[i].r<=r){
        tree[i].id=id;
        return;
    }
    if(tree[i].id!=-1){
        tree[2*i].id=tree[2*i+1].id=tree[i].id;
        tree[i].id=-1;
    }
    updata(2*i,l,r,id);
    updata(2*i+1,l,r,id);
}

int query(int i,int w)//查询该点下的点的id
{
    if(tree[i].id!=-1 && tree[i].l<=w && tree[i].r>=w)
        return tree[i].id;
    else
    {
        int mid=(tree[i].l+tree[i].r)/2;
        if(w<=mid)
            return query(2*i,w);
        else
            return query(2*i+1,w);
    }
}

int dp[110000];

int main()
{
    int i,k;
    while(scanf("%d",&n)!=EOF)
    {
        k=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d%d%d%d",&line[i].h,&line[i].l,&line[i].r,&line[i].w);
            if(line[i].l>k)
                k=line[i].l;
            if(line[i].r>k)
                k=line[i].r;
        }
        sort(line+1,line+n+1,cmp);//按照高度从小到大排序
        build(1,1,k);
        for(i=1;i<=n;i++)
        {//求得路径
            path[i].l=query(1,line[i].l); 
            path[i].r=query(1,line[i].r);
            updata(1,line[i].l,line[i].r,i);  
        }
        memset(dp,0,sizeof(dp));
        dp[n]=100+line[n].w;
        for(i=n;i>=1;i--){
            if(dp[i]){
                dp[path[i].l]=max(dp[path[i].l],dp[i]+line[path[i].l].w);
                dp[path[i].r]=max(dp[path[i].r],dp[i]+line[path[i].r].w);
            }
        }
        if(dp[0]>0) printf("%d\n",dp[0]);
        else printf("-1\n");
    }
    return 0;
}