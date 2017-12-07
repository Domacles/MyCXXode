/**
    成段更新，区间求和
    成段更新用到了Lazy思想,用到了延迟标记,每一次更新时,将这次的值和前面遗留的延迟标记综合,
    然后,找到对应区间,将标记记录在该区间上,当下一次更新时或者查询时才可能会有变动.

    延迟标记可以是某一段区间要加上的值,也可能是某一种乘法标记.碰到之后要总结~~
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
#define Mem(a,x) memset((a),(x),sizeof(a))
#define maxn 111111

int col[maxn<<2];//节点对应的延迟标记
int sum[maxn<<2];//区间之和

void init()//多样例.需要每次进行初始化
{
    Mem(col,0);
    Mem(sum,0);
}

void PushUp(int rt)//更新区间之和
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void PushDown(int rt,int len)
{
    if(col[rt])//如果标记存在的话,需要往下传递,然后删除该点的标记
    {
        col[rt<<1]=col[rt<<1|1]=col[rt];//传递
        sum[rt<<1]=(len-(len>>1))*col[rt];//如果区间长度为奇数时，左子树的区间长度要比右子树多1，因此这样计算sum的值
        sum[rt<<1|1]=(len>>1)*col[rt];//右子树的标记传递
        col[rt]=0;//删除标记
    }
}

void build(int l,int r,int rt)
{
    if(l==r)//建树
    {
        sum[rt]=1;
        col[rt]=0;
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    PushUp(rt);//更新
}

void update(int L,int R,int key,int l,int r,int rt)//成段更新
{
    int len=r-l+1;
    if(L<=l&&r<=R)
    {
        col[rt]=key;
        sum[rt]=len*key;
        return ;
    }
    PushDown(rt,len);//传递延迟标记,len是当前区间长度,用于求和
    int m=(l+r)>>1;
    if(L<=m)
        update(L,R,key,lson);
    if(R>m)
        update(L,R,key,rson);
    PushUp(rt);//更新sum
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1; t<=T; t++)
    {
        init();
        int n,m;
        scanf("%d%d",&n,&m);
        build(1,n,1);
        for(int i=0; i<m; i++)
        {
            int l,r,key;
            scanf("%d%d%d",&l,&r,&key);
            update(l,r,key,1,n,1);//成段更新
        }
        printf("Case %d: The total value of the hook is %d.\n",t,sum[1]);
    }
    return 0;
}
