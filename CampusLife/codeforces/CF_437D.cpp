/****

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

const int maxn =1e6;
struct Edge{
    int u,v,c;
    Edge(int u,int v,int c):u(u),v(v),c(c){}
    bool operator <(const Edge &e)const{
        return c>e.c;
    }
};
vector<Edge>G;
int val[maxn],N,M;

int f[maxn*2];
ll Size[maxn];
int Find(int x){
    if(x!=f[x]) return f[x]=Find(f[x]);
    return x;
}
void Union(int x,int y){
    int a=Find(x);
    int b=Find(y);
    Size[a]+=Size[b];
    f[b]=a;
}

int main()
{
    //freopen("r.txt","r",stdin);
    while(cin>>N>>M){
        for(int i=1;i<=N;i++) scanf("%d",&val[i]);

        G.clear();
        for(int i=1;i<=N;i++) f[i]=i,Size[i]=1;

        for(int i=1;i<=M;i++){
            int u,v; scanf("%d%d",&u,&v);
            G.push_back(Edge(u,v,min(val[u],val[v])));
        }
        sort(G.begin(),G.end());//排序
//由于按照边权值从大到小排序，因此，遍历时找到开始集合的大小和结束集合的大小相乘便是以该边为最小时的组合种数
        double ans=0;
        for(int i=0;i<M;i++){
            int st=Find(G[i].u);//并查集
            int ed=Find(G[i].v);
            if(st==ed) continue;
            ans+=Size[st]*Size[ed]*G[i].c;
            Union(st,ed);
        }
        printf("%.6f\n",ans*2.0/((ll)N*(ll)(N-1)));
    }
    return 0;
}
