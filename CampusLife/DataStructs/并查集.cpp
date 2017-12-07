/************
	���ಢ�鼯ά����Թ�ϵ��rank��¼x�����ľ��룬��Ҫά�������ϵ��������������ڵ�0
	��Ҫɾ���ڵ㣬��ֻ��Ҫ�ı�ԭ�ڵ�x��ӳ��ֵf(x)����~
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

int dis[maxn],fa[maxn],N,M,ans;

void init()
{
    ans=0;
    memset(dis,0,sizeof(dis));
    for(int i=0;i<=N;i++) fa[i]=i;
}

int Find(int x)
{
    if(fa[x]!=x){
        int p=fa[x];
        fa[x]=Find(fa[x]);
        dis[x]+=dis[p];
        return fa[x];
    }else
        return fa[x];
}

void solve(int x,int y,int val)
{
    x--;
    int a=Find(x);
    int b=Find(y);
    if(a!=b){
        fa[b]=a;
        dis[b]=dis[x]+val-dis[y];//�����ڵ�ľ���
    }else{
        if(dis[y]-dis[x]!=val) ans++;
    }
}

int main()
{
    //freopen("r.txt","r",stdin);
    while(~scanf("%d%d",&N,&M)){
        init();
        for(int i=0;i<M;i++){
            int x,y,c; scanf("%d%d%d",&x,&y,&c);
            solve(x,y,c);
        }
        printf("%d\n",ans);
    }
    return 0;
}
