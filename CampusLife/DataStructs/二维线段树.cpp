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

# define lson l,m,rt<<1
# define rson m+1,r,rt<<1|1
# define MAXN 805
int xL,xR,yL,yR,val;
int maxv,minv;
int Max[MAXN<<2][MAXN<<2],Min[MAXN<<2][MAXN<<2];
int N,mat[MAXN][MAXN];

void PushUp(int xrt,int rt)
{
    Max[xrt][rt]=max(Max[xrt][rt<<1],Max[xrt][rt<<1|1]);
    Min[xrt][rt]=min(Min[xrt][rt<<1],Min[xrt][rt<<1|1]);
}

void BuildY(int x,int flag,int l,int r,int rt,int xrt)
{
    if(l==r){
        if(!flag)
            Max[xrt][rt]=Min[xrt][rt]=mat[x][l];
        else{
            Max[xrt][rt]=max(Max[xrt<<1][rt],Max[xrt<<1|1][rt]);
            Min[xrt][rt]=min(Min[xrt<<1][rt],Min[xrt<<1|1][rt]);
        }
        return ;
    }
    int m=(l+r)>>1;
    BuildY(x,flag,lson,xrt);
    BuildY(x,flag,rson,xrt);
    PushUp(xrt,rt);
}

void BuildX(int l,int r,int rt)
{
    if(l==r) {
        BuildY(l,0,1,N,1,rt);
        return ;
    }
    int m=(l+r)>>1;
    BuildX(lson);
    BuildX(rson);
    BuildY(l,1,1,N,1,rt);
}

void UpdateY(int x,int flag,int l,int r,int rt,int xrt)//yL yR
{
    if(l==r){
        if(!flag) Max[xrt][rt]=Min[xrt][rt]=val;
        else{
            Max[xrt][rt]=max(Max[xrt<<1][rt],Max[xrt<<1|1][rt]);
            Min[xrt][rt]=min(Min[xrt<<1][rt],Min[xrt<<1|1][rt]);
        }
        return ;
    }
    int m=(l+r)>>1;
    if(yL<=m) UpdateY(x,flag,lson,xrt);
    else UpdateY(x,flag,rson,xrt);
    PushUp(xrt,rt);
}

void UpdateX(int l,int r,int rt)//xL xR
{
    if(l==r){
        UpdateY(l,0,1,N,1,rt);
        return ;
    }
    int m=(l+r)>>1;
    if(xL<=m) UpdateX(lson);
    else UpdateX(rson);
    UpdateY(l,1,1,N,1,rt);
}

void QueryY(int l,int r,int rt,int xrt)//yL yR
{
    if(yL<=l && r<=yR)
    {
        minv=min(minv,Min[xrt][rt]);
        maxv=max(maxv,Max[xrt][rt]);
        return ;
    }
    int m=(l+r)>>1;
    if(yL<=m) QueryY(lson,xrt);
    if(yR>m) QueryY(rson,xrt);
}

void QueryX(int l,int r,int rt)
{
    if(xL<=l && r<=xR)
    {
        QueryY(1,N,1,rt);
        return;
    }
    int m=(l+r)>>1;
    if(xL<=m) QueryX(lson);
    if(xR>m) QueryX(rson);
}

int main()
{
    freopen("r.txt","r",stdin);
    int T; scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&N);
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                scanf("%d",&mat[i][j]);
        BuildX(1,N,1);

        int M; scanf("%d",&M);
        printf("Case #%d:\n",t);
        for(int i=0;i<M;i++){
            int x,y,l; scanf("%d%d%d",&x,&y,&l);
            l=(l+1)/2;
            xL=max(1,x-l+1),xR=min(N,x+l-1);
            yL=max(1,y-l+1),yR=min(N,y+l-1);
            minv=1<<30, maxv=-(1<<30);
            QueryX(1,N,1);
            val=(minv+maxv)/2;
            xL=x, yL=y;
            printf("%d\n",val);
            UpdateX(1,N,1);
        }
    }
    return 0;
}
