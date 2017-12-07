/****
	string hash
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
typedef unsigned long long ull;

const int maxn =1e5+1111;
const int seed =33;

int M,L;
string S;

ull s[maxn],base[maxn];

void init()
{
    base[0]=1;
    for(int i=1;i<maxn;i++) base[i]=base[i-1]*seed;
}

void deal()
{
    memset(s,0,sizeof(s));
    for(int i=(int)S.length()-1;i>=0;i--)
        s[i]=s[i+1]*seed+S[i]-'a';
}

map<ull,int>mp;

void work()
{
    int ans=0;
    for(int i=0;i<L && i+M*L<=(int)S.length();i++){
        mp.clear();
        ull temp=0;
        for(int j=i;j<i+M*L;j+=L){
            temp=s[j]-s[j+L]*base[L];
            mp[temp]++;
        }
        if(mp.size()==M) ans++;
        for(int j=i+M*L;j+L<=(int)S.length();j+=L){
            temp=s[j-M*L]-s[j-M*L+L]*base[L];
            mp[temp]--;
            if(mp[temp]==0) mp.erase(temp);
            temp=s[j]-s[j+L]*base[L];
            mp[temp]++;
            if(mp.size()==M) ans++;
        }
    }
    printf("%d\n",ans);
}

char str[maxn];
int main()
{
    //freopen("r.txt","r",stdin);
    init();
    while(~scanf("%d%d%s",&M,&L,str)){
        S=string(str);
        deal();
        work();
    }
    return 0;
}
