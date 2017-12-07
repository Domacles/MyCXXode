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

const int maxn =1e4;
const int INF =1e9;
struct Edge{
    int u,v,w;
    Edge(){}
    Edge(int uu,int vv,int ww):u(uu),v(vv),w(ww){}
    bool operator<(const Edge &E)const{
        return w<E.w;
    }
};
vector<Edge> E;
int N,M,fa[maxn];

int find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}

int main()
{
    //freopen("r.txt","r",stdin);
    while(~scanf("%d%d",&N,&M)){
        for(int i=1;i<=N;i++) fa[i]=i;
        E.clear();
        for(int i=0;i<M;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            E.push_back(Edge(u,v,w));
        }

        sort(E.begin(),E.end());
        int ans=0;
        for(int i=0;i<(int)E.size();i++){
            Edge e=E[i];
            int a=find(e.u);
            int b=find(e.v);
            if(a!=b){
                fa[b]=a, ans=e.w;
            }
            if(find(N)==find(1)) break;
        }
        if(find(N)==find(1))
            printf("%d\n",ans*(ans+1)/2);
        else puts("-1");
    }
    return 0;
}
