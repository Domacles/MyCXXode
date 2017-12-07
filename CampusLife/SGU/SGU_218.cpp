/****************
    二分判定_+ 二分匹配

    由于是每一行每一列取一个,二分图匹配,如果能够有满足条件的解,那必然有二分图的完全匹配
*****************/
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int,int> PII;
typedef long long ll;

#define foreach(it,V) for(vector<int>::iterator it=V.begin(); it!=V.end(); ++it)

#define INF 0x7ffffff
const int maxn = 1e4+1e3;
const double eps = 1e-5;
const int mod = 1e9+7;

int N,used[maxn*2], mat[maxn*2];
vector<PII>G[maxn*2];
int Index;

bool dfs(int x){
	for(int i=0;i<(int)G[x].size();i++){
		PII p=G[x][i];
		int y=p.first;
		if(p.second>Index) continue;
		if(!used[y]){
			used[y]=1;
			if(mat[y]==-1 || dfs(mat[y])){
				mat[y]=x;
				return 1;
			}
		}
	}
	return 0;
}

int H_K()//二分匹配
{
	int val=0;
	memset(mat,-1,sizeof(mat));
	for(int i=1;i<=N;i++){
		memset(used,0,sizeof(used));
		if(dfs(i)) val++;
	}
	return val;
}

bool check(int m)
{
    Index=m;
    if(H_K()<N) return 0;
    return 1;
}

void solve(int m)
{
    for(int i=N+1;i<=2*N;i++)
        printf("%d %d\n",mat[i],i-N);
}

int main()
{
    //freopen("1.in","r",stdin);
    scanf("%d",&N);
    int l=INF,r=-1e7;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            int x; scanf("%d",&x);
            l=min(l,x), r=max(r,x);
            G[i].push_back(PII(N+j,x));
        }
    }
    while(l<r){
        int m=(l+r)>>1;
        if(check(m)) r=m;
        else l=m+1;
    }
    printf("%d\n",r);
    check(r);
    solve(r);
    return 0;
}




