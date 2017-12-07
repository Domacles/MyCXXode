/****
���⣺����һ���ַ�����ÿ�ο��Խ������ڵ�������ĸ��
��������Ҫ���ٴο���ʹ�ô���Ϊ���Ĵ���

˼·����������ɨ�衣����ÿһ���ַ����ҵ����Ӧ����ĸ�������Ƶ��Ҳ���Ӧ��λ�á�
���ʱ����Ϊlen(ÿ���ƶ���󳤶Ȼ��ȥ2)��ǰ���Ѿ��ƶ���num������ǰҪ�ƶ���λ��Ϊk��
[num+1,k-1]�������Ѿ��ƶ��ߵ�λx����
�򱾴���Ҫ�ƶ�len-(k-num-x)����ônum�ǿ���ֱ�Ӽ�¼�ģ�x����Ҫ����ġ�����״���顣
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
