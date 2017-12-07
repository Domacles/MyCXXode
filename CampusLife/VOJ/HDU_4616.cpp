/*****
题解：
树形DP。用dp[u][j]表示以u为根的子树上，从某点走到u且走过j个陷阱能得到的最大值;
考虑如果最优解走过了k个陷阱，如果k!=C，那么其起点和终点都可以为没有陷阱的点，如果k=C，那么起点或者终点至少有一点为有陷阱的点，所以dp数组还需要增加一维：dp[u][i][flag]，若flag=1，表示以u为根的子树上，从一个有陷阱的点走到u走过j个陷阱能得到的最大值，若flag=0，表示起点没有陷阱。
状态转移：
1) 当u点本身就有陷阱时，dp[u][j+1][flag]=max{dp[v][j][flag]+val[u]}，0<=j<C，v是u的儿子;
2) 当u点没有陷阱时，dp[u][j][flag]=max{dp[v][j][flag]+val[u]}，0<=j<C，特殊的，当j=C时，因为路上走过了C个陷阱，所以起点和终点不能同时为没有陷阱的点，所以只有flag=1，能用上式转移，也就是说dp[u][C][0]是不可能的情况。
这两种情况可以合成一种写。
更新ans：最优解可以看成两条链拼在一起，枚举两条链上陷阱的个数然后再拼起来。
注意答案为long long和dp数组的初始化。
*****/
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

const int maxn =50005;
vector<int>G[maxn];
int N,C,trap[maxn],val[maxn];
ll ans,dp[maxn][4][2];

void DFS(int u,int f)
{
    dp[u][trap[u]][trap[u]]=val[u];//有陷阱时，此时视自己为起点
    ans=max(ans,dp[u][trap[u]][trap[u]]);
    for(int i=0;i<(int)G[u].size();i++){
        int v=G[u][i];
        if(v==f) continue;
        DFS(v,u);
        for(int j=0;j<=C;j++)
        for(int k=0;j+k<=C;k++){//当经过的陷阱个数为C时，起点和终点必然有一个点是trap
            ans=max(ans,dp[u][j][1]+dp[v][k][1]);//以u点为中介点
            if(j+k<C)ans=max(ans,dp[u][j][0]+dp[v][k][0]);
            if(j!=C) ans=max(ans,dp[u][j][0]+dp[v][k][1]);
            if(k!=C) ans=max(ans,dp[u][j][1]+dp[v][k][0]);
        }
        for(int j=0;j<C;j++){//更新dp[u][j]
            dp[u][j+trap[u]][0]=max(dp[u][j+trap[u]][0],dp[v][j][0]+val[u]);
            dp[u][j+trap[u]][1]=max(dp[u][j+trap[u]][1],dp[v][j][1]+val[u]);
        }
        if(!trap[u]) dp[u][C][1]=max(dp[u][C][1],dp[v][C][1]+val[u]);
    }
}

int main()
{
    //freopen("r.txt","r",stdin);
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&C);
        for(int i=0;i<N;i++)
            scanf("%d%d",&val[i],&trap[i]);
        for(int i=0;i<N;i++) G[i].clear();
        for(int i=1;i<N;i++){
            int u,v; scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int i=0;i<=N;i++)
            for(int j=0;j<=C;j++)
                for(int k=0;k<2;k++)
                    dp[i][j][k]=-(1LL<<61);
        ans=0;
        DFS(0,-1);
        printf("%I64d\n",ans);
    }
    return 0;
}
