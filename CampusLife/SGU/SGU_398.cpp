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

const int maxn = 55;
bool isf[maxn];
vector<int>V[maxn];
vector<int>ans;
int N,X;

int main()
{
    //freopen("r.txt","r",stdin);
    scanf("%d%d",&N,&X);
    for(int i=1;i<=N;i++){
        int s; scanf("%d",&s);
        for(int j=0;j<s;j++){
            int x; scanf("%d",&x);
            V[i].push_back(x);
            if(i==X) isf[x]=1;
        }
    }
    isf[X]=1;
    for(int i=0;i<(int)V[X].size();i++){
        int now=V[X][i];
        for(int j=0;j<(int)V[now].size();j++){
            if(!isf[V[now][j]])
                ans.push_back(V[now][j]),isf[V[now][j]]=1;
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(int i=0;i<(int)ans.size();i++){
        cout<<ans[i];
        if(i<(int)ans.size()-1) cout<<" ";
        else cout<<endl;
    }
    return 0;
}
