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

int ans=0;
void phi(int l,int n,int p)
{
    if(n==1) {
        ans=l;
        return ;
    }
    int k=n/2;
    if(p<=k) phi(n-k+l,k,k-p+1);
    else phi(l,n-k,n-p+1);
}

int main()
{
    //freopen("D://r1.txt","r",stdin);
    int N,Q;
    while(cin>>N>>Q){
        phi(1,N,Q);
        cout<<ans<<endl;
    }
	return 0;
}







