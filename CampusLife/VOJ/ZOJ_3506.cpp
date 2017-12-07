/*****
    树形DP
*****/
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <complex>
#include <cassert>
#include <utility>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;
///#pragma comment(linker, "/STACK:102400000,102400000")
typedef pair<int,int> PII;
typedef long long ll;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<11
#define All 1,N,1

const ll  INFll = 0x3f3f3f3f3f3f3f3fLL;
const int INF= 0x7ffffff;
const int maxn = 2e3+100;
const int mod = 1000000007;

const double pi = acos(-1);
const double eps = 1e-10;

typedef complex<double> Point;
typedef complex<double> Vector;
typedef vector<int> intV;
typedef vector<double> intD;
#define X real()
#define Y imag()
Vector rotate(Vector v, double a) {return v*polar(1.0, a);}
int dx[]={0 ,-1,  0,1};
int dy[]={-1, 0,  1,0};

int N,K,w[maxn],s[maxn],dp[maxn][22];
vector<int> G[maxn];

void init(){
    for(int i=0;i<=N;i++) G[i].clear();
    for(int i=1;i<=N;i++)
        scanf("%d",&w[i]);
    for(int i=1;i<N;i++){
        int u,v; scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

void DFS(int u,int f)
{
    s[u]=0;//以u节点为根的子树有多少条边
    dp[u][0]=w[u];
    fill(dp[u]+1,dp[u]+K+1,INF);
    for(int i=0;i<(int)G[u].size();i++){
        int v=G[u][i];
        if(v==f) continue;
        DFS(v,u);
        s[u]+=s[v]+1;
        for(int j=K;j>=0;j--){
            dp[u][j]+=dp[v][0];
            for(int k=j-1;k>=0;k--)//保留以v节点为根节点的子树
                dp[u][j]=min(dp[u][j],dp[u][k]+dp[v][j-k]);

            for(int k=1;k<=s[v]+1 && k<=j;k++)//舍弃以v节点为根节点的子树，并在上面砍上几道
                dp[u][j]=min(dp[u][j],dp[u][j-k]);
        }
    }
}

void solve(){
    int ans;
    DFS(1,0);
    ans=dp[1][K];
    for(int i=2;i<=N;i++)
        for(int j=1;j<=K && j<=N-1-s[i];j++)
            ans=min(ans,dp[i][K-j]);
    printf("%d ",ans);

    for(int i=1;i<=N;i++)
        w[i]=-w[i];//边变负，求得的最小值即为最大值
    DFS(1,0);
    ans=dp[1][K];
    for(int i=2;i<=N;i++)
        for(int j=1;j<=K && j<=N-1-s[i];j++)
            ans=min(ans,dp[i][K-j]);
    printf("%d\n",-ans);
}

int main()
{
    //freopen("1.in","r",stdin);
    //int T,cas=0; scanf("%d",&T);
    while(~scanf("%d%d",&N,&K)){
        init();
        //printf("Case #%d:\n",++cas);
        solve();
    }
    return 0;
}


