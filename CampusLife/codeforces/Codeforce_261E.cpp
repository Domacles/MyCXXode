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

struct Edge{
    int u,v,val;
    Edge(){}
    Edge(int uu,int vv,int w):u(uu),v(vv),val(w){}
    bool operator<(const Edge &e) const{
        return val<e.val;
    }
};
vector<Edge> G;
int dp[maxn],f[maxn],N,M;

int main()
{
    freopen("r.txt","r",stdin);

    memset(dp,0,sizeof(dp));
    memset(f,0,sizeof(f));

    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++){
        int u,v,w; scanf("%d%d%d",&u,&v,&w);
        G.push_back(Edge(u,v,w));
    }
    sort(G.begin(),G.end());//将边排序，则从前往后枚举可以保证升序
    for(int i=0;i<M;i++){
        int j=i;
        while(j<M && G[j].val==G[i].val) j++;//同时更新相同长度的边
        for(int x=i;x<j;x++)//使用中介数组f，保证严格升序，求得到G[x].v的最大距离；不使用f则保证为不降
            f[G[x].v]=max(f[G[x].v],dp[G[x].u]+1);
        for(int x=i;x<j;x++)//为dp赋值
            dp[G[x].v]=f[G[x].v];
        i=j-1;
    }
    int ans=0;
    for(int i=1;i<=N;i++)
        ans=max(ans,dp[i]);
    printf("%d\n",ans);
    return 0;
}
