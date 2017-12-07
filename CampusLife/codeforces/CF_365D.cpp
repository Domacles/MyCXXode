#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int x, n, m, sum;
bool dp[520000];

int main()
{
    scanf("%d%d",&n,&m);
    dp[0]=true;
    for(int i=0;i<n;i++){
        scanf("%d",&x),sum+=x;
        for(int j=sum;j>=x;j--) dp[j]|=dp[j-x];//背包，表示可达的状态
    }
    int ans=0,tot=0;
    while(true){
        int pre_ans = ans;
        ans+=m;
        while(!dp[ans]) ans--;//在前一个价值基础上+m，在[ans，ans+m]之间寻找下一个ans
        if(ans==pre_ans) break;//无法再向上寻找更大的价值总和
        tot++;
    }
    printf("%d %d\n", ans, tot);
    return 0 ;
}