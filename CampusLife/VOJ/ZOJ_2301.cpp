#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
#define maxn 8444
#define lson rt<<1
#define rson rt<<1|1

struct TNode
{
    int l,r,col;
}
Node[maxn<<4];
struct Point
{
    int l,r,lx,rx,c;
}
point[maxn];
int N,num,x[maxn],col[maxn];

void init()
{
    num=0;
    memset(Node,0,sizeof(Node));
    memset(x,0,sizeof(x));
}

int find(int X)
{
    int l=0,r=num;
    while(l<r)
    {
        int m=(l+r)>>1;
        if(x[m]>=X) r=m;
        else l=m+1;
    }
    return r;
}

void Build(int rt,int l,int r)
{
    if(l>=r) return ;
    Node[rt].l=l , Node[rt].r=r;
    if(l==r-1) return;
    int m=(l+r)>>1;
    Build(lson,l,m);
    Build(rson,m,r);
}

void PushDown(int rt,int col)
{
    if(Node[rt].col>=0)
    {
        Node[lson].col=Node[rson].col=Node[rt].col;
        Node[rt].col=-1;
    }
}

void Update(int rt,int L,int R,int col)
{
    if(L>=R) return ;
    int l=Node[rt].l , r=Node[rt].r;
    //cout<<L<<"  "<<R<<","<<l<<"  "<<r<<endl;
    if(L==l&&r==R)
    {
        Node[rt].col=col;
        return;
    }
    PushDown(rt,col);
    int m=(l+r)>>1;
    if(R<=m) Update(lson,L,R,col);
    else
    if(L>m)  Update(rson,L,R,col);
    else{
        Update(lson,L,m,col);
        Update(rson,m,R,col);
    }
}

void Query(int rt)
{
    int l=Node[rt].l , r=Node[rt].r;
    if(l>=r) return;
    if(Node[rt].col>=0){
        for(int i=l; i<r; i++)
        col[i]=Node[rt].col;
        return ;
    }
    Query(lson);
    Query(rson);
}

int main()
{
    while(~scanf("%d",&N))
    {
        init();
        for(int i=0; i<N; i++)
        {
            char s[2];
            scanf("%d%d%s",&point[i].l,&point[i].r,s);
            point[i].r++;
            if(s[0]=='w') point[i].c=1;
            else point[i].c=0;
            x[num++]=point[i].l,x[num++]=point[i].r;
        }

        sort(x,x+num);
        int k=0;
        for(int i=1; i<num; i++)
            if(x[i]!=x[k]) x[++k]=x[i];
        num=k+1;
        //for(int i=0;i<num;i++) cout<<x[i]<<" ";cout<<endl;
        for(int i=0; i<N; i++)
        {
            int l=find(point[i].l);
            int r=find(point[i].r);
            point[i].lx=l,point[i].rx=r;
            //cout<<l<<","<<r<<" "<<point[i].c<<endl;
        }
        Build(1,0,num);
        for(int i=0; i<N; i++)
            Update(1,point[i].lx,point[i].rx,point[i].c);
        Query(1);

        int st=-1,ed=-1;
        int newst=-1,newed=-1;
        x[num]=x[num-1]+1;
        for(int i=0; i<num; i++)
        {
            if(col[i]!=1) continue;
            newst=x[i];
            while(col[i]==1) i++;
            if(i>num) break;
            newed=x[i];
            if(newed-newst>ed-st) ed=newed,st=newst;
        }
        if(ed==st)
            printf("Oh, my god\n");
        else
            printf("%d %d\n",st,ed-1);
    }
    return 0;
}
