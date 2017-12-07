// tree + dp
/***
	dp[node][0] :  node  have is 1 , otherside is 0
	dp[node][0]+=dp[all_chil][1]
	dp[node][1]+=min(dp[one_chil][0] , dp[one_chil][1])
***/
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn =1555;
int  N, dp[maxn][2], d[maxn];
vector<int> G[maxn];

void init()
{
	memset(d,0,sizeof(d));
	memset(dp,0,sizeof(dp));
	for(int i=0;i<N;i++) G[i].clear();
}

int Treedp(int u)
{
	dp[u][0]=0,dp[u][1]=1;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		Treedp(v);
		dp[u][0]+=dp[v][1];//!!
		dp[u][1]+=min(dp[v][0],dp[v][1]);//!!
	}
	return min(dp[u][0],dp[u][1]);
}

int main()
{
	//freopen("r1.txt","r",stdin);
	while(~scanf("%d",&N)){
		init();
		int node, s;
		for(int j=0;j<N;j++){
			scanf("%d:(%d)",&node,&s);
			for(int i=0;i<s;i++){
				int x; scanf("%d",&x);
				G[node].push_back(x);
				d[x]++;
			}
		}
		int root=0;
		for(int i=0;i<N;i++)
			if(!d[i]) root=i;
		printf("%d\n",Treedp(root));
	}
	return 0;
}

/***
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define maxn 2000
using namespace std;
vector<int>node[maxn];
int mm[maxn];
int visit[maxn];
int n;
int dfs(int fa)
{
    for(int i=0;i<node[fa].size();i++)
    {
        int v=node[fa][i];
        if(!visit[v])
        {
            visit[v]=1;
            if(mm[v]==-1||dfs(mm[v]))
            {
                mm[v]=fa;
                return 1;
            }
        }
    }
    return 0;
}

void solve()
{
     int cnt=0;
     memset(mm,-1,sizeof(mm));
     for(int i=0;i<n;i++)
     {
         memset(visit,0,sizeof(visit));
         if(dfs(i)) cnt++;
     }
     cout<<cnt/2<<endl;
//因为连的是双向边，所以求的的匹配数是所需答案的2倍
}
int main()
{

    int u,num;
    int v;
    while(cin>>n)
    {
        for(int i=0;i<=n;i++)
            node[i].clear();
        for(int i=0;i<n;i++)
        {
            scanf("%d:(%d)",&u,&num);//这个读入要注意
            while(num--)
            {
                cin>>v;
                node[u].push_back(v);//要连双向边
                node[v].push_back(u);
            }
        }
        solve();
    }
    return 0;
}
**/