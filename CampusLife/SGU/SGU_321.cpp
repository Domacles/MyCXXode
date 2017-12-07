/****
        基于树结构的贪心，越靠近root的边变成1效果越好
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

const int maxn =200022;
struct Edge{
    int v,num,f;
    Edge(){}
    Edge(int v,int num,int f):v(v),num(num),f(f){}
};
vector<Edge>G[maxn];
int   N, need[maxn];

void init(){
    memset(need,0,sizeof(need));
    for(int i=0;i<maxn;i++)
        G[i].clear();
}

void addedge(int u,int v,int num,int f){
    G[v].push_back(Edge(u,num,f));
}

void DFS(int x,int dep,int has)
{
    need[x]=(dep+1)/2-has;
    for(int i=0;i<(int)G[x].size();i++){
        Edge e=G[x][i];
        DFS(e.v,dep+1,has+e.f);
        need[x]=max(need[x],need[e.v]);
    }
}

vector<int>ans;
void dfs(int x,int has){
    for(int i=0;i<(int)G[x].size();i++){
        Edge e=G[x][i];
        if(has<need[e.v]){
            if(e.f==0){
                ans.push_back(e.num);
                dfs(e.v,has+1);
            }else dfs(e.v,has);
        }
    }
}

int main()
{
    //freopen("r.txt","r",stdin);
    cin>>N;
    init();
    for(int i=1;i<N;i++){
        int u,v; char str[11];
        scanf("%d%d%s",&u,&v,str);
        if(str[0]=='a')
             addedge(u,v,i,0), scanf("%s",str);
        else addedge(u,v,i,1);
    }

    DFS(1,0,0);dfs(1,0);

    printf("%d\n",(int)ans.size());
    sort(ans.begin(),ans.end());
    for(int i=0;i<(int)ans.size();i++){
        printf("%d",ans[i]);
        if(i==(int)ans.size()-1) puts("");
        else printf(" ");
    }
    return 0;
}
