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

#define foreach(it,V) for(vector<int>::iterator it=V.begin(); it!=V.end(); ++it)

#define INF 0x7ffffff
const int maxn = 1e4+1e3;
const double eps = 1e-5;
const int mod = 1e9+7;

vector<int>G[111];
int N,M,d[111],vis[111],ans[111];

bool bfs()//拓扑排序
{
    queue<int> q;
    for(int i=1;i<=N;i++)
        if(!d[i])
            q.push(i);
    int Index=0;
    while(!q.empty()){
        int u=q.front(); q.pop();
        ans[u]=++Index;
        for(int i=0;i<(int)G[u].size();i++){
            int v=G[u][i];
            d[v]--;
            if(!d[v]) q.push(v);
        }
    }
    for(int i=1;i<=N;i++)
        if(!ans[i]) return 0;
    return 1;
}

int main()
{
    //freopen("1.in","r",stdin);
    scanf("%d%d",&N,&M);
    memset(d,0,sizeof(d));
    for(int i=1;i<=M;i++){
        int x,y; scanf("%d%d",&x,&y);
        G[x].push_back(y);
        d[y]++;
    }
    if(bfs())
        for(int i=1;i<=N;i++){
            printf("%d",ans[i]);
            if(i<N) printf(" ");
            else printf("\n");
        }
    else puts("No solution");
    return 0;
}




