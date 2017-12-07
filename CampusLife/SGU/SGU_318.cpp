/****
    ºØ∫œ≈–÷ÿ
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

vector<int>v[111];
int N,M,f[111];
int is[111];

void init()
{
    for(int i=0;i<=N;i++) f[i]=i;
    for(int i=0;i<=N;i++) v[i].clear();
}

int Find(int x){
    if(x!=f[x]) return f[x]=Find(f[x]);
    return x;
}
void Union(int x,int y)
{
    int a=Find(x);
    int b=Find(y);
    f[b]=a;
}

int main()
{
    //freopen("r.txt","r",stdin);
    while(cin>>N>>M){
        init();
        for(int i=1;i<=M;i++){
            int x; scanf("%d",&x);
            for(int j=0;j<x;j++){
                int xx; scanf("%d",&xx);
                v[xx].push_back(i);
            }
        }
        for(int i=1;i<=N;i++)
        for(int j=i+1;j<=N;j++){
            if(v[i].size()!=v[j].size()) continue;
            int flag=1;
            for(int k=0;k<(int)v[i].size();k++)
                if(v[i][k]!=v[j][k]){flag=0;break;
                }
            if(flag) Union(i,j);
        }
        int ans=0;
        memset(is,0,sizeof(is));
        for(int i=1;i<=N;i++){
            is[Find(i)]=1;
            if(v[i].size()==0) is[Find(i)]=0;
        }
        for(int i=1;i<=N;i++) ans+=is[i];
        printf("%d\n",ans);
    }
    return 0;
}
