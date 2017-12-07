/********
    ˼·��
        ���������뵽��Ӧ����
            D Ϊһ��A��B������������� + len(C) + A,B����һ�������������
        ��ˣ������������C��ΪA��B����������ռ�õ�A��B�Σ�Ȼ�������֮ǰ������������У�
        �����֮����A��B����������������С�

        �ĸ�dpά����
        dp[i][j]����Ϊstr1 �� str2 �������������
        dp0[i][j]�� Ϊstr1 �� str2 �ķ���������������У���str1��str2�Ӻ�ǰ�������������
        dp1[i][j]   Ϊstr1ǰi��ƥ����str3ǰj��ʱ��str3��str1����ʼλ�ã����������ƥ�䣬��Ϊ-1
        dp2[i][j]   Ϊstr2ǰi��ƥ����str3ǰj��ʱ��str3��str2����ʼλ�ã����������ƥ�䣬��Ϊ-1
*********/
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

int len1, len2, len3;
char str1[1111], str2[1111], str3[1111];
int  dp[1111][1111], dp0[1111][1111], dp1[1111][1111], dp2[1111][1111];

void init()
{
    memset(dp, 0,sizeof(dp));
    memset(dp0, 0,sizeof(dp));
    memset(dp1,0,sizeof(dp1));
    memset(dp2,0,sizeof(dp2));
}

void gao1(){
    for(int i=1;i<=len1;i++)
    for(int j=1;j<=len2;j++){
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        if(str1[i]==str2[j]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
    }
}

void gao2(){
    reverse(str1+1,str1+len1+1);
    reverse(str2+1,str2+len2+1);
    for(int i=1;i<=len1;i++)
    for(int j=1;j<=len2;j++){
        dp0[i][j]=max(dp0[i-1][j],dp0[i][j-1]);
        if(str1[i]==str2[j]) dp0[i][j]=max(dp0[i][j],dp0[i-1][j-1]+1);
    }
}

void gao3(int dp[][1111],char *str,int xlen,int clen){
    for(int i=0;i<=clen;i++) dp[0][i]=-1;
    for(int i=0;i<=xlen;i++) dp[i][0]= i;
    for(int i=1;i<=xlen;i++)
        for(int j=1;j<=clen;j++)
            if(str[i]==str3[j]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=dp[i-1][j];
}

void solve()
{
    int ans=0;
    for(int i=0;i<=len1;i++)
    for(int j=0;j<=len2;j++){
        int st1=dp1[len1-i][len3];//0~i Ϊ������str3��ǰһ�� i+1~len1 Ϊ��һ��
        int st2=dp2[len2-j][len3];//0~j Ϊ������str3��ǰһ�� j+1~len2 Ϊ��һ��
        if(st1==-1 || st2==-1) continue;
        ans=max(ans,dp[st1][st2]+dp0[i][j]);
    }
    printf("%d\n",ans+len3);
}

int main()
{
    //freopen("r.txt","r",stdin);
    int T; scanf("%d",&T);
    for(int t=1;t<=T;t++){
        init();
        scanf("%s%s%s",str1+1,str2+1,str3+1);
        len1=strlen(str1+1), len2=strlen(str2+1), len3=strlen(str3+1);
        gao3(dp1,str1,len1,len3), gao3(dp2,str2,len2,len3);
        gao1(), gao2();
        printf("Case #%d: ",t);
        solve();
    }
    return 0;
}
