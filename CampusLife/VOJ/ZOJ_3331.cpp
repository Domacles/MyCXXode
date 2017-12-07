/******
    多道批处理程序,不能打断~
    题意:有两个机器A，B。要处理n个部件，第i个部件在机器A上完成需要t1[i]，在B机器上需要提t2[i]，
    每个部件只能选择一个机器来完成,在任何时间,每台机器只能进行一个任务。
    且当地i个部件开始加工时前[1，i-1]部件必须已经完成或者正在被加工。求加工完所有n个部件的最小时间是多少。

    思路: 动态规划
        状态:dp[i][j]表示加工完第i个零件时,A上的总时间与B上的总时间差值为j+100时的最小时间.
    转移参照的条件:
        第N项工作加在较高的塔上，此时虽然高度差增加，但由于N+1项工作必须在第N项开始之后才能开始，因此在另一塔的高度也增加了空闲值。
        第N项工作加在较低的塔上，使高度差减小，但原先的高塔仍然较高
        第N项工作加在较低的塔上，使低塔高度超过高塔
******/
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

int N,t1[maxn],t2[maxn];
int dp[maxn][maxn];

int solve()
{
    const int d=100;
    for(int i=0;i<=N;i++)
        for(int j=0;j<maxn;j++)
            dp[i][j]=INF;
    dp[0][0+d]=0;

    for(int i=1;i<=N;i++){
        int A=0, B=0;
        for(int j=0;j<=200;j++){
            if(dp[i-1][j]==INF) continue;
            if(j<d) {
                A=dp[i-1][j]-(d-j), B=dp[i-1][j];//A小,B大
                dp[i][A+t1[i]-B+d]=min(dp[i][A+t1[i]-B+d],max(A+t1[i],B));
//将i任务放在总时间小的机器上(A),这样会出现两种情况:A+t1仍然没有超过最长的总时间(B)或者已经超过B,如此,这时的总时间取的为A+t1与B的最大
                dp[i][d-t2[i]]=min(dp[i][d-t2[i]], B+t2[i]);
//将i任务放在总时间大的机器上(B),而题目要求i+1任务必须在之前的任务完成或者正在做的时候才能进行,即只有在i开始做或者i做完时才可以进行,
//因此, 用B+t2去更新dp[i][d-t2](代表A上的下一个任务至少是从i任务开始时才开始的)
            }
            else {
                A=dp[i-1][j], B=dp[i-1][j]-(j-d);//A大,B小
                dp[i][A-(B+t2[i])+d]=min(dp[i][A-(B+t2[i])+d],max(B+t2[i],A));
                dp[i][d+t1[i]]=min(dp[i][d+t1[i]],A+t1[i]);
//同上,只是AB互换
            }
        }
    }
    int res=INF;
    for(int i=0;i<=200;i++){
        res=min(res,dp[N][i]);
    }
    return res;
}

int main()
{
    //freopen("1.in","r",stdin);
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=1;i<=N;i++)
            scanf("%d%d",&t1[i],&t2[i]);
        printf("%d\n",solve());
    }
    return 0;
}

