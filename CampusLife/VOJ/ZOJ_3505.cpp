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
    for(int i=1;i<maxn;i++)//���ַ�������Ϊiʱ�ж����ִ�
        dp[i]=3*dp[i-1];//�����߲���ͬ
    for(int i=1;i<maxn;i++)//���ַ�������at mostΪiʱ�ж����ִ�
        dp[i]+= dp[i-1];//�����ǰ�������
}

int GetNum(int len,char lastc,char* s)
{
    if(*s==0) return 0;
    else{
        ll m=1;//��������Լ�
        for(char i='0';i<*s;i++)
            if(i==lastc) continue;
            else m+=dp[len-1];//�ӱȵ�ǰλС������
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
                num-=dp[len-1];//��ǡ�ñȵ�ǰnumС������
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
