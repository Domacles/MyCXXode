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

int ans=0,state0,N,K;

void dfs(int row,int ld,int rd,int cnt,int now)
{
    if(now>N) return;
    if(cnt<K){
        int nows=state0 & ( ~(row|ld|rd) );
        while(nows!=0){
            int x=nows&(-nows);//补码性质,x为当前行状态
            nows-=x;
            dfs(row+x,(ld+x)<<1,(rd+x)>>1,cnt+1,now+1);
        }
        dfs(row,ld<<1,rd>>1,cnt,now+1);
    }
    else ans++;
}


int main()
{
    //freopen("D://r1.txt","r",stdin);
    while(cin>>N>>K)
    {
        state0=(1<<N)-1;ans=0;
        int row=0,ld=0,rd=0,cnt=0,now=0;
        dfs(row,ld,rd,cnt,now);
        cout<<ans<<endl;
    }
    return 0;
}
