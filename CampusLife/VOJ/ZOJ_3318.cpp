/*************
    题目大意：
有m个地图。你要在每个地图上找一条s到t的路。总的费用是每条路的长度的和，
对于每两个相邻的地图，若你选的路不完全相同，则额外需要1的费用。问总的最小费用。
（一开始没看懂= =！）

    思路： dp
    dp[i] 表示前i个地图的最小费用。

    dp[i]=max(cost(1,i)*i, max(dp[j-1]+cost(j,i)*(i-j+1)+1)) , 1<j<=i

    cost(1,i)表示从1～i地图的相对最短路的距离，直接用SPFA计算即可。
    表示：dp[i]从
        1，所有图都用同一条相对的最短路，这样，就不会有额外费用了，只需要算出cost(1,i)的i倍；
        2，从j～i用同一种最短路，则花费为dp[j-1]+cost(j,i)*(i-j+1)+1，因为j的路径不同于j-1，所以才有+1，然后枚举j即可。

*************/
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int,int> PII;
typedef long long ll;

#define foreach(it,V) for(vector<int>::iterator it=V.begin(); it!=V.end();++it)

#define INF 0x7ffffff
const int maxn = 55;
const double eps= 1e-5;

bool Map1[33][maxn][maxn], vis[maxn];
ll dp[maxn], dis[maxn];
queue<int> q;
int N,M,S,T;

ll cost_ST(int st,int ed)
{
    bool Map[maxn][maxn];
    memset(Map,1,sizeof(Map));
    for(int i=st;i<=ed;i++){
        for(int j=1;j<=N;j++)
        for(int k=1;k<=N;k++)
            Map[j][k]&=Map1[i][j][k];
    }
    while(!q.empty())
        q.pop();
    fill(dis,dis+maxn-1,INF);
    fill(vis,vis+maxn-1,0);
    dis[S]=0, q.push(S), vis[S]=1;

    while(!q.empty()){
        int u=q.front(); q.pop();
        vis[S]=0;
        for(int v=1;v<=N;v++)
            if(Map[u][v] && dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                if(!vis[v])
                    q.push(v), vis[v]=1;
            }
    }
    return dis[T];
}

int main()
{
    //freopen("1.in","r",stdin);
    int icas; scanf("%d",&icas);
    while(icas--){
        scanf("%d%d%d%d",&N,&M,&S,&T);
        memset(Map1,0,sizeof(Map1));
        for(int i=1;i<=M;i++){
            int r; scanf("%d",&r);
            for(int j=0;j<r;j++){
                int x,y; scanf("%d%d",&x,&y);
                Map1[i][x][y]=Map1[i][y][x]=1;
            }
        }

        dp[1]=cost_ST(1,1);
        for(int i=2;i<=M;i++){
            dp[i]=cost_ST(1,i)*i;
            for(int j=2;j<=i;j++)
                dp[i]=min(dp[i],dp[j-1]+cost_ST(j,i)*(i-j+1)+1);
        }
        printf("%lld\n",dp[M]);
    }
    return 0;
}

