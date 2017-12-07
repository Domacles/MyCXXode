/***
����Ҫ��������һ���������ġ�

����һ��N������������������������ġ����ĵĶ������£�

ɾ��ĳ���i����ʣ��k����ͨ��������ô����d(i)Ϊ��Щ��ͨ�����н���������ֵ��

��ν���ģ�����ʹ��d(i)��С�Ľ��i��
***/
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

vector<int>G[maxn];
int N,s[maxn],dp[maxn];

void DFS(int u,int f)
{
    s[u]=1;dp[u]=0;
    for(int i=0;i<(int)G[u].size();i++){
        int v=G[u][i];
        if(v==f) continue;
        DFS(v,u), s[u]+=s[v];
    }
}

void dfs(int u,int f)
{
    dp[u]=s[1]-s[u];
    for(int i=0;i<(int)G[u].size();i++){
        int v=G[u][i];
        if(v==f) continue;
        dp[u]=max(dp[u],s[v]);
        dfs(v,u);
    }
}

int main()
{
    freopen("r.txt","r",stdin);
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=0;i<=N;i++) G[i].clear();
        for(int i=1;i<N;i++){
            int u,v; scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        memset(s,0,sizeof(s));
        DFS(1,0), dfs(1,0);
        int mins=1;
        for(int i=1;i<=N;i++)
            if(dp[i]<dp[mins]) mins=i;
        printf("%d %d\n",mins,dp[mins]);
    }
    return 0;
}
