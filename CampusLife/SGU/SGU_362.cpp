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
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

const int maxn =1e6;
int N,M,st,ed;
bool vis[12][12];
char  ac[]={'D','L','U','R'};

bool OK(int i,int j){
    if(i>=1 && i<=N && j>=1 && j<=M && !vis[i][j])
        return 1;
    return 0;
}

void DFS(int x,int y)
{
    vis[x][y]=1;
    for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(OK(xx,yy)){
            cout<<ac[i];
            DFS(xx,yy);
            break;
        }
    }
}

int main()
{
    //freopen("r.txt","r",stdin);
    cin>>N>>M>>st>>ed;
    DFS(st,ed);
    return 0;
}
