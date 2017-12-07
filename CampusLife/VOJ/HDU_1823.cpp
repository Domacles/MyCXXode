#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>

using namespace std;

const int N=2050;

struct sub_node
{
    int la,ra;
    int max;
};

struct node
{
    int l,r;
    sub_node T[N];
};

node TT[N];

void sub_build(int rt,int sub_rt,int la,int ra)
{
    TT[rt].T[sub_rt].la=la;
    TT[rt].T[sub_rt].ra=ra;
    TT[rt].T[sub_rt].max=-1;
    if(la==ra) return;
    int mid=(la+ra)>>1;
    sub_build(rt,sub_rt<<1,la,mid);
    sub_build(rt,sub_rt<<1|1,mid+1,ra);
}

void build(int rt,int l,int r,int la,int ra)
{
    TT[rt].l=l;
    TT[rt].r=r;
    sub_build(rt,1,la,ra);
    if(l==r) return;
    int mid=(l+r)>>1;
    build(rt<<1,l,mid,la,ra);
    build(rt<<1|1,mid+1,r,la,ra);
}

void sub_update(int rt,int sub_rt,int active,int love)
{
    if(TT[rt].T[sub_rt].la==TT[rt].T[sub_rt].ra)
    {
        TT[rt].T[sub_rt].max=max(TT[rt].T[sub_rt].max,love);
        return;
    }
    int mid=(TT[rt].T[sub_rt].la+TT[rt].T[sub_rt].ra)>>1;
    if(active<=mid)
         sub_update(rt,sub_rt<<1,active,love);
    else
         sub_update(rt,sub_rt<<1|1,active,love);
    TT[rt].T[sub_rt].max=max(TT[rt].T[sub_rt].max,love);
}

void update(int rt,int height,int active,int love)
{
    sub_update(rt,1,active,love);
    if(TT[rt].l==TT[rt].r) return;
    int mid=(TT[rt].l+TT[rt].r)>>1;
    if(height<=mid)
        update(rt<<1,height,active,love);
    else
        update(rt<<1|1,height,active,love);
}

int sub_query(int rt,int sub_rt,int a1,int a2)
{
    if(TT[rt].T[sub_rt].la==a1&&TT[rt].T[sub_rt].ra==a2)
        return TT[rt].T[sub_rt].max;
    int mid=(TT[rt].T[sub_rt].la+TT[rt].T[sub_rt].ra)>>1;
    if(a2<=mid)
        return sub_query(rt,sub_rt<<1,a1,a2);
    else if(a1>mid)
        return sub_query(rt,sub_rt<<1|1,a1,a2);
    else
        return max(sub_query(rt,sub_rt<<1,a1,mid),sub_query(rt,sub_rt<<1|1,mid+1,a2));
}

int query(int rt,int h1,int h2,int a1,int a2)
{
    if(TT[rt].l==h1&&TT[rt].r==h2)
        return sub_query(rt,1,a1,a2);
    int mid=(TT[rt].l+TT[rt].r)>>1;
    if(h2<=mid)
        return query(rt<<1,h1,h2,a1,a2);
    else if(h1>mid)
        return query(rt<<1|1,h1,h2,a1,a2);
    else
        return max(query(rt<<1,h1,mid,a1,a2),query(rt<<1|1,mid+1,h2,a1,a2));
}

int main()
{
    int n,i;
    int active,love;
    char str[5];
    while(~scanf("%d",&n))
    {
        if(n==0) break;
        build(1,100,200,0,1000);
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            if(str[0]=='I')
            {
                int h;
                double a,l;
                scanf("%d%lf%lf",&h,&a,&l);
                active=(int)10*a;
                love=(int)10*l;
                update(1,h,active,love);
            }
            else
            {
                int h1,h2;
                double a1,a2;
                scanf("%d%d%lf%lf",&h1,&h2,&a1,&a2);
                int aa1=(int)10*a1;
                int aa2=(int)10*a2;
                if(h1>h2) swap(h1,h2);
                if(aa1>aa2) swap(aa1,aa2);
                double ans=query(1,h1,h2,aa1,aa2);
                if(ans<0) puts("-1");
                else      printf("%.1lf\n",ans/10);
            }
        }
    }
    return 0;
}
