/***
    数位统计
        给出一个区间，问这个区间内的数，转换成B进制后，刚好有B个1的的数有多少个。
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

int dp[33][33];
int X,Y,K,B;

void init()//求组合数
{
    for(int i=0;i<32;i++)
        dp[i][0]=dp[i][i]=1;
    for(int i=1;i<32;i++)
        for(int j=1;j<i;j++)
            dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
}

int solve(int x)
{
    int bit[33]={0},len=0,num=0;
    while(x){//化为B进制
        bit[len++]=x%B;
        x/=B;
    }
    int ret=0;
    for(int i=len-1;i>=0;i--){
        if(bit[i]>1){//此位+后面的位，枚举K-num个1的个数
            ret+=dp[i+1][K-num];
            break;
        }
        else if(bit[i]==1){
            if(i>=K-num) ret+=dp[i][K-num];//此位变为0，枚举后面
            num++;//目前已经存在了多少个1
            if(num>K) break;//超出K，无需进行
        }
        if(!i && num==K) ret++;//x也是个满足要求的数字
    }
    return ret;
}

int main()
{
    //freopen("r.txt","r",stdin);
    init();
    while(cin>>X>>Y>>K>>B){
        cout<<solve(Y)-solve(X-1)<<endl;
    }
    return 0;
}
