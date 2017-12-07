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

int N,M,K,S;
double P[22],Q[22];

struct Mx{
    double v[22][22];
    Mx(){
        memset(v,0,sizeof(v));
    }
    Mx operator*(const Mx &M1) const{
        Mx M0;
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                for(int k=1;k<=N;k++)
                    M0.v[i][j]+=v[i][k]*M1.v[k][j];
        return M0;
    }
}Ma;

void init()
{
    memset(Q,0,sizeof(Q));
    memset(P,0,sizeof(P));
    memset(Ma.v,0,sizeof(Ma.v));
    for(int i=1;i<=N;i++){
        int x=i, y=i;
        if(x+1<=N) Ma.v[x+1][y]=0.5;
        if(y+1<=N) Ma.v[x][y+1]=0.5;
    }
    Ma.v[2][1]=1, Ma.v[N-1][N]=1;
    P[S]=1;
}

Mx Pow(Mx M0,int n)
{
    Mx res;
    for(int i=1;i<=N;i++)
        res.v[i][i]=1;
    while(n){
        if(n&1) res=res*M0;
        n>>=1, M0=M0*M0;
    }
    return res;
}

int main()
{
    //freopen("r.txt","r",stdin);
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&N,&M,&K,&S);
        init();
        if(N==1) {puts("1.0000"); continue;}
        Mx ret=Pow(Ma,M*K);
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                Q[i]+=ret.v[i][j]*P[j];
        for(int i=1;i<N;i++)
            printf("%.4lf ",Q[i]);
            printf("%.4lf\n",Q[N]);
    }
    return 0;
}
