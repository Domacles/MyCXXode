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

const int maxn = 22;

ll dp[22],M;
int N;
char s[80];

void init()
{
    dp[0]=1;
    for(int i=1;i<maxn;i++)//当字符串长度为i时有多少种串
        dp[i]=3*dp[i-1];//相邻者不相同
    for(int i=1;i<maxn;i++)//当字符串长度at most为i时有多少种串
        dp[i]+= dp[i-1];//计算带前导零进入
}

int GetNum(int len,char lastc,char* s)
{
    if(*s==0) return 0;
    else{
        ll m=1;//最后算上自己
        for(char i='0';i<*s;i++)
            if(i==lastc) continue;
            else m+=dp[len-1];//加比当前位小的数量
        m+=GetNum(len-1,*s,s+1);
        return m;
    }
}

void solve(int len,int num,char lastc,char* s)
{
    if(num==0) *s='\0';
    else{
        num--;
        for(*s='0';;++*s){
            if(*s==lastc) continue;
            if(num<dp[len-1]){
                solve(len-1,num,*s,s+1); break;
            }else
                num-=dp[len-1];//减恰好比当前num小的数量
        }
    }
}

int main()
{
    //freopen("r.txt","r",stdin);
    init();
    while(~scanf("%d%I64d%s",&N,&M,s)){
        M=GetNum(N,'0',s)-M;
        solve(N,M,'0',s);
        puts(s);
    }
    return 0;
}
