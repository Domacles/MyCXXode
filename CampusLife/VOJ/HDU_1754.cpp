/**
   线段树简单应用，单点更新，区间最值,按照NotOnlySuccess的博客刷,不能只看不刷呢~~
**/
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <vector>
#include <bitset>
#include <cstdio>
#include <string>
#include <numeric>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long  ll;
typedef unsigned long long ull;

int dx[4]= {-1,1,0,0};
int dy[4]= {0,0,-1,1}; //up down left right
bool inmap(int x,int y,int n,int m)
{
    if(x<1||x>n||y<1||y>m)return false;
    return true;
}
int hashmap(int x,int y,int m)
{
    return (x-1)*m+y;
}

#define eps 1e-8
#define inf 0x7fffffff
#define debug puts("BUG")
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define read freopen("in.txt","r",stdin)
#define write freopen("out.txt","w",stdout)
#define maxn 222222

int N;
int score[maxn<<2];

void update(int rt)
{
    score[rt]=max(score[rt<<1],score[rt<<1|1]);//更新区间最值
}

void build(int l,int r,int rt)
{
    if(l==r)
    {
        scanf("%d",&score[rt]);//初始化
        return ;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    update(rt);
}

void change(int p,int s,int l,int r,int rt)
{
    if(l==r)
    {
        score[rt]=s;
        return ;
    }
    int m=(l+r)>>1;
    if(p<=m)
        change(p,s,lson);
    else
        change(p,s,rson);
    update(rt);
}

int query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R)
        return score[rt];

    int m=(l+r)>>1;
    int ans=0;
    if(L<=m)
        ans=max(ans,query(L,R,lson));
    if(R>m)
        ans=max(ans,query(L,R,rson));
    return ans;
}

int main()
{
    int m;
    while(~scanf("%d%d",&N,&m))
    {
        build(1,N,1);
        while(m--)
        {
            char op[2];
            int a,b;
            scanf("%s%d%d",op,&a,&b);
            if (op[0] == 'Q')
                printf("%d\n",query(a,b,1,N,1));
            else
                change(a,b,1,N,1);
        }
    }
    return 0;
}
