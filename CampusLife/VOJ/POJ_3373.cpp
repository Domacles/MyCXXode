/****
				??????????????
****/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn=105;
int dp[maxn][maxn*maxn];//dp[i][j] 第 i 个字母 % k = j 至少需要改变多少次
int path[maxn][maxn*maxn][2];// 0 保存上一个字母的位置，1 保存当前选择的字母
char s[maxn];
int k,len;
int mod[maxn][10];//大整数求模，必须通过递推式算出保存在数组里
void print(int cur,int left)//因为顺序是反的，用个递归函数输出
{
    if(cur>len) return ;
    printf("%d",path[cur][left][1]);
    print(cur+1,path[cur][left][0]);
}
void init()
{
    len=strlen(s+1);
    for(int i=0;i<=9;i++) mod[len][i]=i%k;//求 mod k 的值，与数位对应的
    for(int i=len-1;i>=1;i--)
        for(int j=0;j<=9;j++)
            mod[i][j]=mod[i+1][j]*10%k;
}
void DP()
{
    memset(dp,-1,sizeof(dp));
    dp[len+1][0]=0;
    for(int i=len;i>=1;i--)//递推方式写的。每个状态根据当前字母取值不同推出10种状态
        for(int p=(i==1?1:0);p<=9;p++)
            for(int j=0;j<k;j++)
                if(dp[i+1][j]!=-1)                                //排除不存在的状态
                {
                    int left=(j+mod[i][p])%k;                       //推出的状态。注意有个模，所以都能推出10种状态
                    if(dp[i][left]==-1||dp[i+1][j]+(p!=s[i]-'0')<dp[i][left])
                    {      //第一次或更优
                        dp[i][left]=dp[i+1][j]+(p!=s[i]-'0');
                        path[i][left][0]=j;                                //上一个的位置
                        path[i][left][1]=p;                                //当前取的字母
                    }
                }
}
int main()
{
    while(cin>>s+1>>k)
    {
        init();
        DP();
        print(1,0);
        printf("\n");
    }
    return 0;
}