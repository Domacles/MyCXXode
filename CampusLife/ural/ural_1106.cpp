/***
	分组问题
	team1中能有朋友在team2
	每次只需要当前将不属于任何两组人放到t2，他的朋友放到t1即可
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
int t1[111],t2[111];
vector<int>G[111];

void init()
{
    memset(t1,0,sizeof(t1));
    memset(t2,0,sizeof(t2));
    for(int i=0;i<111;i++) G[i].clear();
}

int N;

int main()
{
    //freopen("r.txt","r",stdin);
    while(~scanf("%d",&N)){
        init();
        for(int i=1;i<=N;i++){
            int x;
            while(~scanf("%d",&x) && x){
                G[i].push_back(x);
                G[x].push_back(i);
            }
        }
        for(int i=1;i<=N;i++){
            if(!t1[i] && !t2[i]){
                for(int j=0;j<(int)G[i].size();j++)
                    if(!t1[G[i][j]] && !t2[G[i][j]]) t1[G[i][j]]=1;
                t2[i]=1;
            }
        }
        int ans=0,flag=1;
        for(int i=1;i<=N;i++) if(t1[i]) ans++;
        printf("%d",ans);
        for(int i=1;i<=N;i++) if(t1[i]){
            if(flag) printf("\n%d",i),flag=0;
            else printf(" %d",i);
        }
        printf("\n");
    }
    return 0;
}
