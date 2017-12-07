/***
�����Զ���...ֻ��4��״̬���Զ���. 0��ʾû��666�ҵ�ǰû��6, 1��ʾû��666�ҵ�ǰ��һ��6, 2��ʾû��666�ҵ�ǰ������6, 3��ʾ��666,
 ���ǿ��������ת�Ʊ�trans. ����f[i][j]Ϊ��j״̬���ַ���������i���ַ��ܴﵽĿ��ķ�����. ��ʼ̬��f[0][3] = 1, ת�Ʒ���f[i][j] = sigma(f[i-1][trans[j][k]]),
 kΪ10��ת��. �����ʱ�����λ��dig, �ٴ�dig��λ����λһλһλȷ���ͺ���.
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
const int NUM = 10;
const int S = 4;

int trans[S][NUM]={
    {0,0,0,0,0,0,1,0,0,0},
    {0,0,0,0,0,0,2,0,0,0},
    {0,0,0,0,0,0,3,0,0,0},
    {3,3,3,3,3,3,3,3,3,3}
};

const int MAXL = 10;

ll dp[MAXL+1][S];

void init()
{
    dp[0][3]=1;
    for(int i=1;i<=MAXL;i++) for(int j=0;j<S;j++)
        for(int k=0;k<NUM;k++){
            dp[i][j]+=dp[i-1][trans[j][k]];
        }//����ԭ��(������Ϊi-1�Ĵ�)ǰ��+1��ɳ���Ϊi�Ĵ�
}

int main()
{
    //freopen("r.txt","r",stdin);
    init();
    int T; scanf("%d",&T);
    for(int t=1;t<=T;t++){
        int N; scanf("%d",&N);

        int len=0;
        for(int i=1;i<=MAXL;i++){
            if(dp[i][0]>=N){
                len=i;break;
            }
        }

        int now=0;
        for(int i=len;i>=1;i--){
            ll cnt=0;
            for(int j=0;j<NUM;j++){
                cnt+=dp[i-1][trans[now][j]];
                if(cnt>=N){
                    printf("%d",j);
                    cnt-=dp[i-1][trans[now][j]];
                    N-=cnt;
                    now=trans[now][j];
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
