#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

#define L(rt) (rt<<1)
#define R(rt) (rt<<1|1)

const int N=40010;

struct node{
    int l,r,h;
}tree[N<<3];

int seg[N<<1],hei[N],lp[N],rp[N];

void build(int l,int r,int rt){
    tree[rt].l=l;
    tree[rt].r=r;
    tree[rt].h=0;
    if(l+1==r)
        return ;
    int mid=(l+r)>>1;
    build(l,mid,L(rt));
    build(mid,r,R(rt));
}

void update(int id,int l,int r,int rt){
    if(seg[tree[rt].l]==l && seg[tree[rt].r]==r){   //找到与原来长度相等的
        if(tree[rt].h<hei[id])  //比已存在的高 就把它覆盖
            tree[rt].h=hei[id];
        return ;
    }
    int mid=seg[(tree[rt].l+tree[rt].r)>>1];
    if(r<=mid)
        update(id,l,r,L(rt));
    else if(l>=mid)
        update(id,l,r,R(rt));
    else{
        update(id,l,mid,L(rt));
        update(id,mid,r,R(rt));
    }
}

long long Solve(int h,int rt){  //算每个子结点的面积并
    if(tree[rt].h<h)     //延迟覆盖 父结比子结点高的话
        tree[rt].h=h;
    if(tree[rt].l+1==tree[rt].r)
        return (long long)(seg[tree[rt].r]-seg[tree[rt].l])*tree[rt].h;
    long long a=Solve(tree[rt].h,L(rt));
    long long b=Solve(tree[rt].h,R(rt));
    return a+b;
}

int main(){

    //freopen("input.txt","r",stdin);

    int n;
    while(~scanf("%d",&n)){
        int cnt=0;
        for(int i=1;i<=n;i++){  //离散化操作
            scanf("%d%d%d",&lp[i],&rp[i],&hei[i]);
            seg[++cnt]=lp[i];
            seg[++cnt]=rp[i];
        }
        sort(seg+1,seg+cnt+1);
        int len=unique(seg+1,seg+cnt+1)-(seg+1);
        build(1,len,1);
        for(int i=1;i<=n;i++)
            update(i,lp[i],rp[i],1);
        long long ans=Solve(0,1);
        printf("%I64d\n",ans);
    }
    return 0;
}