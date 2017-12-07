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

ll GetSum(ll x){
    ll ret=0;
    while(x){
        ret+=x/5;
        x/=5;
    }
    return ret;
}

int main()
{
    //freopen("D://r1.txt","r",stdin);
    ll N;
    while(cin>>N){
        if(N==0) {
            cout<<1<<endl;
            continue;
        }
        else{
            ll l=0,r=1e16;
            while(l<r){
                ll m=(l+r)/2;
                if(GetSum(m)<N) l=m+1;
                else r=m;
            }
            if(GetSum(r)==N) cout<<r<<endl;
            else cout<<"No solution"<<endl;
        }
    }
	return 0;
}
