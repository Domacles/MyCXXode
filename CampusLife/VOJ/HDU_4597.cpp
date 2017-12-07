/********
    ����������ص㣬ÿ���˿���ʹ��ͬһ������״̬

    ��dp[l1][r1][l2][r2]Ϊĳ���ڵ�һ��ʣ��l1~r1,�ڶ���ʣ��l2~r2���������ȡ�õ����ֵ��

    �������ΪA���֣�������ѡһ����ʹ�Լ��õ����������Ʋ����ȶԷ�ѡ����С�������ƣ�
    ʣ�µ��Ʒ����ܺ�Ϊsum,ʹ�Է���һ���õ����٣����Լ��ܻ�õľ�Խ����ˣ�
    ���ֳ��֣���Ȼʹ��l1,r1,l2,r2����һ״̬��dp��С��
    ��ʹ��B����
        l1+1,r1,l2,r2;
        l1,r1-1,l2,r2;
        l1,r1,l2+1,r2;
        l1,r1,l2,r2-1;
        ������С��dp����A��õķ���Ϊsum-min_dp;
        ȱ�ٵ�����A��ȡ�����š�
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

const int maxn =1e6;
int N;
int s1[22],s2[22];
int sum1[22], sum2[22];
int dp[22][22][22][22];

int solve(int l1,int r1,int l2,int r2)
{
    if(dp[l1][r1][l2][r2]!=-1)
        return dp[l1][r1][l2][r2];
    if(l1>r1 && l2>r2)
        return dp[l1][r1][l2][r2]=0;
    int res=0, sum=0;
    if(l1<=r1) sum+=sum1[r1]-sum1[l1-1];
    if(l2<=r2) sum+=sum2[r2]-sum2[l2-1];
    if(l1<=r1){
        res=max(res,sum-solve(l1+1,r1,l2,r2));
        res=max(res,sum-solve(l1,r1-1,l2,r2));
    }
    if(l2<=r2){
        res=max(res,sum-solve(l1,r1,l2+1,r2));
        res=max(res,sum-solve(l1,r1,l2,r2-1));
    }
    return dp[l1][r1][l2][r2]=res;
}

int main()
{
    //freopen("r.txt","r",stdin);
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        memset(dp,-1,sizeof(dp));
        memset(sum1,0,sizeof(sum1));
        memset(sum2,0,sizeof(sum2));
        for(int i=1;i<=N;i++){
            scanf("%d",&s1[i]);
            sum1[i]=sum1[i-1]+s1[i];
        }
        for(int i=1;i<=N;i++){
            scanf("%d",&s2[i]);
            sum2[i]=sum2[i-1]+s2[i];
        }
        int ans=solve(1,N,1,N);
        printf("%d\n",ans);
    }
    return 0;
}
