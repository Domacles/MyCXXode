/****
题意：给出一个字符串。每次可以交换相邻的两个字母。
问最少需要多少次可以使得串变为回文串？

思路：从左向右扫描。对于每一个字符，找到其对应的字母，将其移到右侧相应的位置。
设此时长度为len(每次移动完后长度会减去2)，前面已经移动了num个，当前要移动的位置为k，
[num+1,k-1]区间内已经移动走的位x个，
则本次需要移动len-(k-num-x)。那么num是可以直接记录的，x是需要计算的。用树状数组。
****/
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

int s[maxn];
int last[maxn],f[maxn],a[maxn];
bool vis[maxn];

int lowbit(int x){return x&(-x);}

void Add(int x,int n,int val){
    while(x<=n){
        s[x]+=val;
        x+=lowbit(x);
    }
}
int Sum(int x){
    int ret=0;
    while(x>0){
        ret+=s[x];
        x-=lowbit(x);
    } return ret;
}

int solve(int index,int now)
{
    now-=now-Sum(now);
    return index-now;
}


void init()
{
    memset(s, 0,sizeof(s));
    memset(f, 0,sizeof(f));
    memset(a, 0,sizeof(a));
}

int main()
{
    //freopen("r.txt","r",stdin);
    string str;
    while(cin>>str){
        init();
        for(int i=1;i<=(int)str.length();i++){
            last[i]=f[str[i-1]];
            f[str[i-1]]=i;
            a[str[i-1]]++;
        }

        int flag=0;
        for(int i='A';i<='Z';i++) flag+=(a[i]&1);
        if(flag>(int)str.length()%2){puts("-1"); continue;}

        int pre=0,len=(int)str.length();
        ll ret=0;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=(int)str.length();i++){
            if(vis[i]) continue;
            int now=str[i-1];
            int t=f[now];
            if(i>=t) len--,ret+=len/2;
            else{
                ret+=len-(t-pre-Sum(t));
                vis[t]=1;
                Add(t,(int)str.length(),1);
                len-=2;
                f[now]=last[t];
            }
            pre++;
        }
        printf("%I64d\n",ret);
    }
    return 0;
}
