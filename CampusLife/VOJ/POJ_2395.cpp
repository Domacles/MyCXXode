/**
	最小生成树最大边
**/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 2010
#define INF 0x3F3F3F3F

int n , m;
int vis[MAXN];
int lowcost[MAXN];
int G[MAXN][MAXN];

void init(){
    for(int i = 1 ; i <= n ; i++){
       for(int j = 1 ; j <= n ; j++)
           G[i][j] = INF;
    }
}

void prime(){
     memset(vis , 0 , sizeof(vis));
     int pos , ans;
     ans = 0;
     vis[1] = 1;
     for(int i = 1 ; i <= n ; i++)
        lowcost[i] = G[1][i];
     for(int i = 1 ; i <= n ; i++){
        pos = -1;
        for(int j = 1 ; j <= n ; j++){
           if(!vis[j] && (pos == -1 || lowcost[j] < lowcost[pos]))
              pos = j;
        }
        if(pos == -1)
            break;
        vis[pos] = 1;
        if(ans < lowcost[pos])
          ans = lowcost[pos];
        for(int j = 1 ; j <= n ; j++){
           if(!vis[j] && lowcost[j] > G[j][pos])
             lowcost[j] = G[j][pos];
        }
     }
     printf("%d\n" , ans);
}

int main(){
    int a , b , v;
    scanf("%d%d" , &n , &m);
    init();
    for(int i = 0 ; i < m ; i++){
        scanf("%d%d%d" , &a , &b , &v);
        if(G[a][b] > v)
          G[a][b] = G[b][a] = v;
    }
    prime();
    return 0;
}