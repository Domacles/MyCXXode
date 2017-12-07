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

typedef pair<int,int> PII;
typedef long long ll;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define All 1,N,1

const ll  INFll = 0x3f3f3f3f3f3f3f3fLL;
const int INF= 0x7fffffff;
const int maxn = 1e4+100;
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

struct Edge{
    int u,v;
    int val;
    Edge(){}
    Edge(int from,int to,int w):u(from),v(to),val(w){}
};

class Segment{
public:
    int Max[(maxn<<2)+100];
    //int flag[maxn<<2];
    /** Function **/
    void init(){
        memset(Max,0,sizeof(Max));
        //memset(flag,0,sizeof(flag));
    }
    void PushUp(int rt){
        Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);
    }
    void Update(int x,int val,int l,int r,int rt){
        if(l==r){
            Max[rt]=val;
            return;
        }
        int m=(l+r)>>1;
        if(x<=m) Update(x,val,lson);
        else Update(x,val,rson);
        PushUp(rt);
    }
    void Update(int L,int R,int v,int l,int r,int rt){
        if(l==r){
            Max[rt]*=-1;
            return;
        }
        int m=(l+r)>>1;
        if(L<=m) Update(L,R,-1,lson);
        if(R>m)  Update(L,R,-1,rson);
        PushUp(rt);
    }
    int Query(int L,int R,int l,int r,int rt){
         if(L<=l && r<=R){
            return Max[rt];
         }
        int m=(l+r)>>1, res=-INF;
        if(L<=m) res=max(Query(L,R,lson),res);
        if(R>m)  res=max(Query(L,R,rson),res);
        return res;
    }
}Seg;
///other datastruct

///

vector<Edge> edge_v; //Set_edge
vector<int>  G[maxn];//graph_tree

/** other infomation **/

int top[maxn],ine[maxn],son_id[maxn],num;
/// link_top  in_edge_node  height_nextnode count
int fa[maxn],s[maxn],dep[maxn];
/// father   size    dep


int N;

void add_edge(int u,int v,int w){
    edge_v.push_back(Edge(u,v,w));
    G[u].push_back(v);
    G[v].push_back(u);
}

void DFS(int u,int f){
    int maxs=-INF;
    s[u]=1, dep[u]=dep[f]+1, son_id[u]=0, fa[u]=f;
    for(int i=0;i<(int)G[u].size();i++){
        int v=G[u][i];
        if(v==f) continue;
        DFS(v,u), s[u]+=s[v];
        if(maxs<s[v]) maxs=s[v], son_id[u]=v;
    }
}

void DFS(int u,int f,int tp){
    ine[u]=++num; top[u]=tp;
    if(son_id[u]) DFS(son_id[u],u,tp);///height at first
    for(int i=0;i<(int)G[u].size();i++){
        int v=G[u][i];
        if(v!=f && v!=son_id[u]) DFS(v,u,v);
    }
}

void Update(int u,int v)
{
    int f1=top[u], f2=top[v];
    while(f1!=f2){
        if(dep[f1]<dep[f2])
            swap(f1,f2), swap(u,v);
        Seg.Update(ine[f1],ine[u],-1,1,N,1); //!!!!
        u=fa[f1], f1=top[u]; //!!!
    }
    if(u==v) return ;
    if(dep[u]>dep[v]) swap(u,v);
    Seg.Update(ine[son_id[u]],ine[v],-1,1,N,1);
}

int Query(int u,int v)
{
    int f1=top[u], f2=top[v], res=-INF;
    while(f1!=f2){
        if(dep[f1]<dep[f2])
            swap(f1,f2), swap(u,v);
        res=max(res,Seg.Query(ine[f1],ine[u],1,N,1));//!!!!
        u=fa[f1], f1=top[u];//!!!
    }
    if(u==v) return res;
    if(dep[u]>dep[v]) swap(u,v);
    return max(res,Seg.Query(ine[son_id[u]],ine[v],1,N,1));
}

void init(){
    num=0;
    memset(top,0,sizeof(top));
    memset(ine,0,sizeof(ine));
    edge_v.clear();
    for(int i=0;i<maxn;i++) G[i].clear();
}

void solve(){
    scanf("%d",&N);
    for(int i=1;i<N;i++){
        int u,v,w; scanf("%d%d%d",&u,&v,&w);
        add_edge(u,v,w);
    }
    DFS(1,0), DFS(1,0,1);
    Seg.init();
    for(int i=0;i<(int)edge_v.size();i++){
        int u=edge_v[i].u, v=edge_v[i].v;
        if(dep[u]>dep[v])
            swap(u,v), swap(edge_v[i].u,edge_v[i].v);
        Seg.Update(ine[v],edge_v[i].val,1,N,1);
    }

    while(1){
        char op[11]; scanf("%s",op);
        if(op[0]=='C'){
            int x,val; scanf("%d%d",&x,&val);
            int v=edge_v[x-1].v;
            Seg.Update(ine[v],val,1,N,1);
        }else if(op[0]=='Q'){
            int u,v; scanf("%d%d",&u,&v);
            printf("%d\n",Query(u,v));
        }else if(op[0]=='N'){
            int u,v; scanf("%d%d",&u,&v);
            Update(u,v);
        }
        else if(op[0]=='D')
            return;
    }
}

int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    int T=0; scanf("%d",&T);
    //int cas=0;
    while(T--){
    //while(~scanf("d",&M,&N)){
        init();
        //if(cas) puts("");
        //printf("Case #%d:\n",++cas);
        solve();
    }
    return 0;
}
