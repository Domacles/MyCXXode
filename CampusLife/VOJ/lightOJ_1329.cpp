/****
题意：给出n张扑克牌，将其排成一排，要求相邻的扑克牌的数字不同。问有多少种排列方式？

思路：很显然，在DP的过程中我们需要记录还剩下 哪些扑克牌以及在已经排列好的扑克牌中最后一个的数字是多少。
对于剩下哪些的这个记录的方法，一个很显然的思路是用一个五进制记录，因为数字最大为4，有 五种情况，这样就是5^13。
这么大的数字从空间和时间上显然是行不通的。那么我们这样来考虑。所有的数字个数只能是0，1,2,3,4,我们就记录 1,2,3,4分别有多少个（0显然是没有必要记录的）。
比如3个8,3个9,2个10,2个11,2个12,2个13，1个A，我们就记录1有1个，2 有4个，3有2个，4有0个，那么可以用(1,4,2,0)来记录。
可知这个状态最多为13^4，在加上已经排列好的中最后一个的数字，有5种情况，那么 一个五元组就可以完美表示所有状态。
接下来是转移，我们枚举这一次放什么在后面，有4种情况，比如放3个的，那么设状态为(a,b,c,d,flag)，
若flag!=3,那么这次又3*c种情况可选，因为有c个3嘛（比如3个1,3个2，此时c=2）；
若flag=3,那么上一次最后放的必然是1或者 2，那么此时只有3*(c-1)种可选。对于子状态，我们选完3后，2必然增加一个，
即b+1,c-1，子状态为(a,b+1,c-1,d,3)。
*****/
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
const int maxn = 1311;
const double eps= 1e-5;
const unsigned ll mod = 1LL<<64;

int s[100],sum[5];
unsigned ll dp[14][14][14][14][14];

int f(char x)
{
    if(x>='0' && x<='9') return x-'0';
    if(x=='T') return 10;
    if(x=='J') return 11;
    if(x=='Q') return 12;
    if(x=='K') return 13;
    if(x=='A') return 1;
}

unsigned ll solve(int s1,int s2,int s3,int s4,int x)
{
    if(!s1 && !s2 && !s3 && !s4)
        return dp[s1][s2][s3][s4][x]=1;

    unsigned ll &ret=dp[s1][s2][s3][s4][x];
    if(vis[s1][s2][s3][s4][x]) return ret;
    else vis[s1][s2][s3][s4][x]=1;
    if(s1){
        if(x!=1) ret+=s1*DFS(s1-1,s2,s3,s4,0);
        else if(s1>1) ret+=(s1-1)*DFS(s1-1,s2,s3,s4,0);//last=0,原因是选的那张牌原属于s1而拿走了之后就输入s0了,下同
    }
    if(s2){
        if(x!=2) ret+=2*s2*DFS(s1-1,s2,s3,s4,0);
        else if(s2>1) ret+=2*(s2-1)*DFS(s1+1,s2-1,s3,s4,1);
    }
    if(s3){
        if(x!=3) ret+=3*s3*DFS(s1-1,s2,s3,s4,0);
        else if(s3>1) ret+=3*(s3-1)*DFS(s1,s2+1,s3-1,s4,2);
    }
    if(s4){
        if(x!=4) ret+=4*s4*DFS(s1-1,s2,s3,s4,0);
        else if(s4>1) ret+=4*(s4-1)*DFS(s1,s2,s3+1,s4-1,3);
    }
}

int main()
{
    freopen("1.in","r",stdin);
    int T; scanf("%d",&T);
    for(int t=1;t<=T;t++){
        memset(s,0,sizeof(s));
        memset(sum,0,sizeof(sum));
        sum[0]=13;
        int N; scanf("%d",&N);
        for(int i=0;i<N;i++){
            char str[5]; scanf("%s",str);
            char x=f(str[0]);
            sum[s[x]]--, s[x]++, sum[s[x]]++;
        }
        memset(dp,0,sizeof(dp));

        int s1=sum[1], s2=sum[2], s3=sum[3], s4=sum[4];
        unsigned ll ans=solve(s1,s2,s3,s4,0);
        printf("Case %d: %I64d\n",t,ans);
    }
    return 0;
}

