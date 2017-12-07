/************
	此类并查集维护相对关系，rank记录x到根的距离，如要维护单点关系，则可以添加虚拟节点0
	如要删除节点，则只需要改变原节点x的映射值f(x)即可~
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
        dis[b]=dis[x]+val-dis[y];//到根节点的距离
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
