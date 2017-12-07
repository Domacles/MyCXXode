/***
构造一个n个点，m条有向边的图，需要满足两个要求：
1.任意一对点对之间最多有一条有向边，且没有自环。
2.保证图联通，m条边的边权严格属于[1, m]且互不相同，
从任意点出发，经过任意路径后回到起始点，经过的边权总和是3的倍数。

构造方法：
要同时满足1.2的要求，而且输入数据 m >= n + 3，那么也就是说，
我们总是能轻松的先构造一个n个点n条有向边的环，其中前n-1条边的边权是1...2..3...n-1，
对于最后一条边，可以取n, n+1或 n+2，总之使得这个环的总权值tot%3==0就行了。

这样的话，我们就完成了初步建图：已经构造了一个n个点n条边且满足题意的图了，
那么对于剩下的m-n条边怎么办？如果我们需要在原有的环上添加一条边权为w的边，
并且还要维护图的1.2性质，显然，我们只需要找到这样一个点对<u, v>,
其中在我们构造的初始环上，u - > v 的距离为g[u][v]，
那么只需要g[u][v] % 3 == w % 3，我们就能保证图的性质不变了！

思路：
    等价替换
***/
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

const int maxn =1e6;
const int inf = 1e7;

int  dis[88][88];
int   dp[88][88];
int vis[88*88/7];
stack<PII>v[88*88/7];
int N,M;

void init()//注意初始化！！
{
    memset(vis,0,sizeof(vis));//!!!
    for(int i=0;i<=N;i++){
        dis[i][i]=dp[i][i]=0;
        for(int j=0;j<=N;j++){
            if(i==j) continue;
            dis[i][j]=dp[i][j]=inf;
        }
    }
    for(int i=0;i<=M;i++){
        while(!v[i].empty()) v[i].pop();
    }
}

void Floyd()
{
    for(int l=1;l<=N;l++)
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                if(dp[i][j]>dp[i][l]+dp[l][j])
                   dp[i][j]=dp[i][l]+dp[l][j];
}

void create()
{
    init();
    int s=0;
    for(int i=1;i<N;i++){
            dis[i][i+1]=i,s+=i,vis[i]=1;dp[i][i+1]=i;
    }
    for(int i=N;i<N+3;i++)
        if((s+i)%3==0){
            dis[N][1]=i;vis[i]=1;dp[N][1]=i;break;
        }
    Floyd();

    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++){
            if(dis[i][j]<=M || dis[j][i]<=M) continue;
            v[dp[i][j]%3].push(PII(i,j));
        }
}

bool check(int x)
{
    while(!v[x%3].empty()){
        PII now=v[x%3].top();
        if(dis[now.first][now.second]>=inf && dis[now.second][now.first]>=inf){
            dis[now.first][now.second]=x , v[x%3].pop();
            return 1;
        }else v[x%3].pop();
    }
    return 0;
}

bool solve()
{
    for(int i=1;i<=M;i++)
    if(!vis[i]){
        if(!check(i)) return 0;
    }
    return 1;
}

int main()
{
    //freopen("r.txt","r",stdin);
    int T; scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d%d",&N,&M);
        create();
        printf("Case #%d:\n",t);
        if(solve()){
            for(int i=1;i<=N;i++)
                for(int j=1;j<=N;j++)
                    if(i!=j && dis[i][j]<=M)
                        printf("%d %d %d\n",i,j,dis[i][j]);
        }else puts("-1");
    }
    return 0;
}
