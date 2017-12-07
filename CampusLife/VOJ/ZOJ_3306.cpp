/***********
    状态压缩，枚举要选择的列，然后排序选出最多的行
***********/
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

#define foreach(it,V) for(vector<int>::iterator it=V.begin(); it!=V.end();++it)

const int maxn =1e5+111;
const double eps= 1e-9;

int S[22],has[1<<20],N;

void init()
{
    for(int i=0;i<(1<<20);i++){
        int x=i,s=0;
        while(x){
            if(x&1) s++;
            x>>=1;
        }
        has[i]=s;
    }
}

int main()
{
    //freopen("1.in","r",stdin);
    init();
    while(~scanf("%d",&N) && N){
        memset(S,0,sizeof(S));
        for(int i=0;i<20;i++){
            char str[22]; scanf("%s",str);
            for(int j=0;j<20;j++)
                if(str[j]=='#') S[i]|=(1<<j);
        }
        int ans=0;
        for(int i=1;i<(1<<20);i++){
            int x=has[i];
            if(x>=N) continue;
            int cnt[22]={0};
            for(int j=0;j<20;j++)
                cnt[j]=has[S[j]&i];//这是一个优化
            sort(cnt,cnt+20,greater<int>());
            int s=0;
            for(int j=0;j<20 && j<N-x;j++)
                s+=cnt[j];
            ans=max(ans,s);
        }
        printf("%d\n",ans);
    }
    return 0;
}


