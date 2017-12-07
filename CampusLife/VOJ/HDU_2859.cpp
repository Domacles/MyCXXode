/*********
    ��ĿҪ��һ�������Ĵ����µ����ϵ����ľ���
    ��ˣ���״̬dp[i][j]Ϊ��(i,j)Ϊ���½ǵ�������Ҫ��ľ����ģ��
    ��
        ������������dp[i+1][j-1]ʱ��
            ���ͨ����ƥ�䷢��(i+1,j-1)���Ϻ����ҵ�ƥ�䳤�ȴ���dp[i][j]+1��
            �����ǿ��Եõ���(i+1,j-1)Ϊ���½ǵ��¾��󣬵��ܵ���(i,j)Ϊ���½ǵ�������Ҫ��ľ������ޣ�
            ��ģֻ��dp[i][j]+1�ģ�
            ��(i+1,j-1)���Ϻ����ҵ�ƥ�䳤��С��dp[i][j]+1������(i+1,j-1)Ϊ���½ǵ��¾���Ĺ�ģ
            ֻ�������Ϻ����ҵ�ƥ�䳤�ȡ�
        ת�Ʒ��̼ȵá�

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

int N, dp[1111][1111];
char s[1111][1111];

int main()
{
    freopen("r.txt","r",stdin);
    while(~scanf("%d",&N) && N){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=N;i++) scanf("%s",s[i]+1);

        int ans=0;
        for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++){
            int up=i, right=j, t=0;
            while(up>=1 && right<=N && s[up][j]==s[i][right])
                t++, up--, right++;
            if(t>=dp[i-1][j+1]+1) dp[i][j]=dp[i-1][j+1]+1;
            else dp[i][j]=t;
            ans=max(ans,dp[i][j]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
