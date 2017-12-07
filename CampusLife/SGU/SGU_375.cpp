/***
    BFS
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

const int maxn =1e6;

int main()
{
    //freopen("r.txt","r",stdin);
    int N;
    while(cin>>N){
        if(N&1){
            cout<<(int)(log(N)/log(2))<<endl;
            vector<int>ans;
            while(N!=1){
                if(((N+1)/2)&1)
                    ans.push_back(1),N=(N+1)/2;
                else
                if(((N-1)/2)&1)
                    ans.push_back(2),N=(N-1)/2;
            }
            for(int i=ans.size()-1;i>=0;i--){
                if(i==0) cout<<ans[i]<<endl;
                else cout<<ans[i]<<" ";
            }
        }else cout<<"No solution"<<endl;
    }
    return 0;
}
