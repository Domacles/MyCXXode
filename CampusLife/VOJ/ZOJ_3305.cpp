/********
    x = (x - 1) & st 实现了子集遍历：for(int i=S;i;i=(i-1)&S)
    比如 st=1110
    1101 & 1110 = 1100
    1011 & 1110 = 1010
    1001 & 1110 = 1000
    0111 & 1110 = 0110
    0101 & 1110 = 0100
    0011 & 1110 = 0010
    0001 & 1110 = 0000

    因此，不必要每次枚举物品的状态进行匹配了
********/
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

#define foreach(it,V) for(vector<int>::iterator it=V.begin(); it!=V.end();++it)

const int maxn =1e5+111;
const double eps= 1e-9;

int has[1<<17];
int dp[1<<17],N,M;

int solve(int S)
{
    if(dp[S]!=-1) return dp[S];
    dp[S]=0;
    for(int i=S;i;i=(i-1)&S){
        if(!has[i]) continue;
        dp[S]=max(dp[S],solve(S-i)+1);
    }
    return dp[S];
}
int main()
{
    //freopen("1.in","r",stdin);
    while(~scanf("%d%d",&N,&M)){
        memset(dp,-1,sizeof(dp));
        memset(has,0,sizeof(has));
        for(int i=0;i<M;i++){
            int x,s=0;
            scanf("%d",&x);
            for(int j=0;j<x;j++){
                int y; scanf("%d",&y);
                s+=1<<(y-1);
            }
            has[s]=1;
        }
        printf("%d\n",solve((1<<N)-1));
    }
    return 0;
}



