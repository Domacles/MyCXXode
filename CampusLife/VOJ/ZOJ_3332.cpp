/****
    在一个N个点的有向图中找一条经过每个点一次且仅一次的路径,有向图所对应的无向图是个完全图,有向图每两个点之间有且仅有一条有向边.

    枚举起点+DFS
****/
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
const int maxn = 311;
const double eps= 1e-5;
const int mod = 10000007;

bool vis[maxn],Map[maxn][maxn];
int N;
stack<int> Ans;

bool DFS(int u){
    Ans.push(u), vis[u]=1;
    if((int)Ans.size()==N) return 1;
    for(int i=1;i<=N;i++){
        if(Map[u][i] && !vis[i])
            if(DFS(i)) return 1;
    }
    Ans.pop(); vis[u]=0;
    return 0;
}

int main()
{
    freopen("1.in","r",stdin);
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        memset(Map,0,sizeof(Map));
        for(int i=1;i<=N*(N-1)/2;i++){
            int u,v; scanf("%d%d",&u,&v);
            Map[u][v]=1;
        }
        int flag=0;
        for(int i=1;i<=N;i++){
            memset(vis,0,sizeof(vis));//必要的初始化
            while(!Ans.empty())//必要的初始化
                Ans.pop();
            if( (flag=DFS(i)) )
                break;
        }
        if(!flag)
            puts("Impossible");
        else {
            vector<int> ans;
            while(!Ans.empty()){//存着的是倒序
                ans.push_back(Ans.top()), Ans.pop();
            }
            for(int i=(int)ans.size()-1;i>=0;i--){
                printf("%d",ans[i]);
                if(i==0) printf("\n");
                else printf(" ");
            }
        }
    }
    return 0;
}

