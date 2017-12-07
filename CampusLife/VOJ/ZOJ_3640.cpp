/******
���⣺
һֻ��Ѫ����n��·�����ߣ�ÿ���������һ��·��
ÿ��·�и����ƣ������ʱ�����Ѫ��Ĺ���������
����ĳ��ֵ����ô�ͻỨ��t���ӳ�ȥ�����򣬻���1��
��ʱ�䣬���ҹ��������ӣ������ӳ�ȥ������
************/
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

double dp[maxn];
int N,F,a[maxn];
double solve(int x)
{
    if(dp[x]>0) return dp[x];
    dp[x]=0;
    for(int i=1;i<=N;i++){
        if(x>a[i]){
            int temp=(1.0+sqrt(5.0))/2.0*a[i]*a[i];
            dp[x]+=(double)temp/N;
        }else
            dp[x]+=(1+solve(x+a[i]))/N;
    }
    return dp[x];
}

int main()
{
    freopen("r.txt","r",stdin);
    while(~scanf("%d%d",&N,&F)){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=N;i++)
            scanf("%d",&a[i]);
        printf("%.3lf\n",solve(F));
    }
    return 0;
}
