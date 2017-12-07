/****
	线段树用于统计序列和，max，min
求出所有的mex(1, i)；接着删去第1个结点，就是所有的mex(2, i)；接着再删去第1个结点，就是所有的mex(3, i)；……最后就是mex(n, n)，求和即是答案。

而维护删除结点后的信息，正是线段树的拿手好戏。

对于每个线段树结点(o, L, R)，设mexv[o]表示mex(left, R)，这里的left表示第一个数的下标，初始1，随着删除的进行，left递增。

设sumv[o]表示区间[L, R]上的所有mexv的和。

当删除了一个结点a[i]时，如果a[i] < mexv[1]，说明a[i]被删后一定会使某个区间的mex变成a[i]，这个区间就是第一个mexv比a[i]大的i到下个a[i]出现的前一位。
****/
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int,int> PII;
typedef long long ll;

const int maxn = 200200;

int N,a[maxn],mex1[maxn],vis[maxn],next[maxn];
ll sum[maxn<<2],maxs[maxn<<2], flag[maxn<<2];
#define all 1,N,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

void pushup(int rt) {
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
    maxs[rt]=max(maxs[rt<<1],maxs[rt<<1|1]);
}

void pushdown(int l,int r,int rt)
{
    int len=r-l+1;
    if(flag[rt]!=-1){
        flag[rt<<1]=flag[rt<<1|1]=flag[rt];
        maxs[rt<<1]=maxs[rt<<1|1]=flag[rt];
        sum[rt<<1] =(len-(len>>1))*flag[rt];
        sum[rt<<1|1]=(len>>1)*flag[rt];
        flag[rt]=-1;
    }
}

void Build(int l,int r,int rt)
{
    flag[rt]=-1;
    if(l==r){
        maxs[rt]=sum[rt]=mex1[l];
        return ;
    }
    int m=(l+r)>>1;
    Build(lson);
    Build(rson);
    pushup(rt);
}

int QueryMax(int val,int l,int r,int rt)//first val's address > val
{
    if(l==r) return l;
    pushdown(l,r,rt);
    int m=(l+r)>>1;
    if(maxs[rt<<1]>val) return QueryMax(val,lson);
    else return QueryMax(val,rson);
}

void Update(int L,int R,int val,int l,int r,int rt)
{
    if(L<=l && r<=R){
        flag[rt]=maxs[rt]=val;
        sum[rt]=(r-l+1)*val;
        return ;
    }
    pushdown(l,r,rt);
    int m=(l+r)>>1;
    if(L<=m) Update(L,R,val,lson);
    if(R>m)  Update(L,R,val,rson);
    pushup(rt);
}

void init()
{
    memset(mex1,0,sizeof(mex1));
    memset(vis,0,sizeof(vis));
    memset(sum,0,sizeof(sum));
    memset(flag,0,sizeof(flag));
}

void solve()
{
    ll ret=0;
    Build(all);
    for(int i=1;i<=N;i++){
        ret+=sum[1];
        if(a[i]<maxs[1]){
            int L=QueryMax(a[i],all),R=next[i]-1;
            if(L<=R) Update(L,R,a[i],all);//!!!!!!!!!!!!!
        }
        Update(i,i,0,all);
        if(maxs[1]==0) break;
    }
    printf("%I64d\n",ret);
}

int main()
{
    //freopen("r.txt","r",stdin);
    while(~scanf("%d",&N) && N){
        init();
        for(int i=1;i<=N;i++) scanf("%d",&a[i]),a[i]=(a[i]>=N)?N:a[i];
        int mex=0;
        //Max1[i]
        for(int i=1;i<=N;i++){
            vis[a[i]]=1;
            while(vis[mex]) mex++;
            mex1[i]=mex;
        }
        //getNext
        for(int i=0;i<=N;i++) vis[i]=N+1;
        for(int i=N;i>=1;i--){
            next[i]=vis[a[i]];
            vis[a[i]]=i;
        }
        solve();
    }
    return 0;
}

