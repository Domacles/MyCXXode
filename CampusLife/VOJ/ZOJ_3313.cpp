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

#define foreach(it,V) for(vector<int>::iterator it=V.begin(); it!=V.end();++it)

#define INF 0x7ffffff
const int maxn = 1e6+1e3;
const double eps= 1e-5;

int main()
{
    //freopen("1.in","r",stdin);
    int T; scanf("%d",&T);
    while(T--){
        int x; scanf("%d",&x);
        double ans=x*2.0/360.0*86400.0;
        printf("%.2lf\n",ans);
    }
    return 0;
}

