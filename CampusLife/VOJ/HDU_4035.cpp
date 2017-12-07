/**
http://www.cnblogs.com/kuangbin/archive/2012/10/03/2711108.html
**/
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

const int maxn =1e5+111;
const double eps= 1e-9;

vector<int> G[maxn];
int N;
double dp[maxn];
double K[maxn], E[maxn], A[maxn], B[maxn], C[maxn];

void init()
{
    for(int i=0;i<=N;i++) G[i].clear();
    memset(A,0,sizeof(A));
    memset(B,0,sizeof(B));
    memset(C,0,sizeof(C));
    memset(dp,0,sizeof(dp));
}

bool DFS(int u,int f)
{
    int m=G[u].size();
    A[u]=K[u], B[u]=(1-K[u]-E[u])/m;
    C[u]=1-K[u]-E[u];

    double temp=0;
    for(int i=0;i<(int)G[u].size();i++){
        int v=G[u][i];
        if(v==f) continue;
        if(!DFS(v,u)) return 0;
        A[u]+=(1-K[u]-E[u])/m*A[v];
        C[u]+=(1-K[u]-E[u])/m*C[v];
        temp+=(1-K[u]-E[u])/m*B[v];
    }
    if(fabs(1-temp)<eps) return 0;
    temp=1-temp;
    A[u]/=temp; B[u]/=temp; C[u]/=temp;
    return 1;
}

int main()
{
    freopen("r.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&N);
        init();
        for(int i=1;i<N;i++){
            int u,v; scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int i=1;i<=N;i++){
            int k,e;
            scanf("%d%d",&k,&e);
            K[i]=k/100.0, E[i]=e/100.0;
        }
        printf("Case %d: ",t);
        if(DFS(1,-1) && fabs(1-A[1])>eps)
            printf("%.6lf\n",C[1]/(1-A[1]));
        else
            puts("impossible");
    }
    return 0;
}
