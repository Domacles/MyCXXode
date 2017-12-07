/****
	³ßÈ¡·¨
***/
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

const int maxn = 1e6;

int N,K,a[maxn];
vector<int> A,B[maxn];

int solve(int x)
{
    int res=0,temp=0;
    deque<int> q;
    vector<int> &now=B[x];
    for(int i=0;i<(int)now.size();i++){
        if(q.empty()) q.push_front(now[i]);
        else{
                int head=q.front(), last=q.back();
                if(temp+now[i]-head-1>K){
                    do{
                        q.pop_back();
                        if(!q.empty()) temp-=(q.back()-last-1), last=q.back();
                        else temp=0;
                    }while(!q.empty() && temp+(now[i]-head-1)>K);
                }
                if(!q.empty()) temp+=now[i]-head-1;
                q.push_front(now[i]);
        }
        res=max(res,(int)q.size());
    }
    return res;
}

int main()
{
    //freopen("r.txt","r",stdin);
    while(~scanf("%d%d",&N,&K)){
        A.clear();
        for(int i=0;i<N;i++){
            scanf("%d",&a[i]);
            A.push_back(a[i]); B[i].clear();
        }
        sort(A.begin(),A.end());
        vector<int>::iterator it=unique(A.begin(),A.end());
        A.erase(it,A.end());
        for(int i=0;i<N;i++){
            int id=lower_bound(A.begin(),A.end(),a[i])-A.begin();
            B[id].push_back(i);
        }
        int ans=0;
        for(int i=0;i<(int)A.size();i++){
            ans=max(ans,solve(i));
        }
        printf("%d\n",ans);
    }
    return 0;
}
