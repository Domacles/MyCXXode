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
const int maxn = 111;
const double eps= 1e-5;
const int mod = 10000007;

double A[555],B[555];
int N,k1,k2,k3,a,b,c;

void init()
{
    A[N]=1.0/(k1*k2*k3), B[N]=1.0;
    if(N-1>=0) A[N-1]=1.0/(k1*k2*k3), B[N-1]=1.0;
    if(N-2>=0) A[N-2]=1.0/(k1*k2*k3), B[N-2]=1.0;
}

int main()
{
    //freopen("1.in","r",stdin);
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d%d%d%d",&N,&k1,&k2,&k3,&a,&b,&c);
        init();
        for(int x=N-3;x>=0;x--){
            A[x]=1, B[x]=1;
            for(int i=1;i<=k1;i++)
            for(int j=1;j<=k2;j++)
            for(int k=1;k<=k3;k++){
                if(i==a && j==b &&k==c) continue;
                int temp=x+i+j+k;
                if(temp>N) continue;
                A[x]+=A[temp], B[x]+=B[temp]/(k1*k2*k3);
            }
            A[x]/=k1*k2*k3;//!!!
        }
        double ans=B[0]/(1.0-A[0]);
        printf("%.10f\n",ans);
    }
    return 0;
}

