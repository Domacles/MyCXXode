/***
    ��λͳ��
        ����һ�����䣬����������ڵ�����ת����B���ƺ󣬸պ���B��1�ĵ����ж��ٸ���
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

void init()//�������
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
    while(x){//��ΪB����
        bit[len++]=x%B;
        x/=B;
    }
    int ret=0;
    for(int i=len-1;i>=0;i--){
        if(bit[i]>1){//��λ+�����λ��ö��K-num��1�ĸ���
            ret+=dp[i+1][K-num];
            break;
        }
        else if(bit[i]==1){
            if(i>=K-num) ret+=dp[i][K-num];//��λ��Ϊ0��ö�ٺ���
            num++;//Ŀǰ�Ѿ������˶��ٸ�1
            if(num>K) break;//����K���������
        }
        if(!i && num==K) ret++;//xҲ�Ǹ�����Ҫ�������
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
