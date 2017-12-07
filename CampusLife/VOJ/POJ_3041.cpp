#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
const int nMax = 505;
const int eMax = 10005;
 
struct Edge{int v,next;}edge[eMax];
int n, m, k = 1;
int edgeHead[nMax], link[nMax];
bool vis[nMax];
 
bool dfs(int u){
    for(int i = edgeHead[u]; i != 0; i = edge[i].next){
        int v = edge[i].v;
        if(!vis[v]){
            vis[v] = true;
            if(link[v] == -1 || dfs(link[v])){
                link[v] = u;
                return true;
            }
        }
    }
    return false;
}
 
int main(){
    int i, u, v;
    scanf("%d%d", &n, &m);
    while(m --){
        scanf("%d%d", &u, &v);
        edge[k].v = v;
        edge[k].next = edgeHead[u];
        edgeHead[u] = k ++;
    }
    int ans = 0;
    memset(link, -1, sizeof(link));
    for(i = 1; i <= n; i ++){
        memset(vis, 0, sizeof(vis));
        if(dfs(i)) ans ++;
    }
    printf("%d\n", ans);
    return 0;
}