/**********
二分答案，枚举区间，BFS判可否
**********/
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

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int h[111][111],vis[111][111],N;

bool check(int i,int j){
    if(i<1 || i>N) return 0;
    if(j<1 || j>N) return 0;
    return 1;
}

bool BFS(int minh,int maxh)
{
    queue<PII>q;
    memset(vis,0,sizeof(vis));
    q.push(PII(1,1)), vis[1][1]=1;
    if(h[1][1]<minh || h[1][1]>maxh) return 0;

    while(!q.empty()){
        PII a=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x=a.first+dx[i], y=a.second+dy[i];
            if(check(x,y)==0) continue;
            if(vis[x][y]) continue;
            if(h[x][y]<minh || h[x][y]>maxh) continue;
            q.push(PII(x,y)); vis[x][y]=1;
        }
    }

    if(vis[N][N]) return 1;
    return 0;
}

int main()
{
    //freopen("r.txt","r",stdin);
    int T; scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&N);
        int L=222,R=0,minh=222,maxh=0;
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                scanf("%d",&h[i][j]),L=min(L,h[i][j]),R=max(R,h[i][j]);
        minh=L, maxh=R;
        R=R-L, L=0;
        printf("Scenario #%d:\n",t);
        while(L<R){
            int m=(L+R)>>1;
            int flag=0;
            for(int i=minh;i+m<=maxh;i++)
                if(BFS(i,i+m)) {flag=1;break;}
            if(flag) R=m;
            else L=m+1;
        }
        printf("%d\n\n",R);
    }
    return 0;
}
