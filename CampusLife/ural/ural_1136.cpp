/***
	»Ö¸´¶þ²æ²éÕÒÊ÷
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

vector<int>G[3333];
int val[3333],N;

void DFS(int rt,int l,int r)
{
    if(l>r) return;
    int pos=0;
    for(int i=l;i<=r;i++){
        if(val[i]<val[rt]) pos=i;
        else break;
    }
    if(!pos){
        G[rt].push_back(r);
        DFS(r,l,r-1);
        return;
    }
    if(pos) G[rt].push_back(pos),DFS(pos,l,pos-1);
    if(pos && pos<r) G[rt].push_back(r),DFS(r,pos+1,r-1);
}

void Print(int x)
{
    for(int i=(int)G[x].size()-1;i>=0;i--)
        Print(G[x][i]);
    printf("%d",val[x]);
    if(x==N) puts("");
    else printf(" ");
}

void init()
{
    for(int i=0;i<=N;i++) G[i].clear();
}

int main()
{
    //freopen("r.txt","r",stdin);
    while(~scanf("%d",&N)){
        init();
        for(int i=1;i<=N;i++) scanf("%d",&val[i]);
        DFS(N,1,N-1);
        Print(N);
    }
    return 0;
}
