/****
    矩阵维护序列
*****/
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

int N,M,K;

struct Matirx{
    ll v[111][111];
    Matirx(){
        memset(v,0,sizeof(v));
    }
    void clear(){
        memset(v,0,sizeof(v));
    }
    Matirx operator *(const Matirx &M) const{
        Matirx res;
        for(int k=0;k<=N;k++)
        for(int i=0;i<=N;i++)
            if(v[i][k]){//!!!!这个地方太强了
                for(int j=0;j<=N;j++)
                    res.v[i][j]+=v[i][k]*M.v[k][j];
        }
        return res;
    }
}A0,ans;

void init()
{
    A0.clear();
    for(int i=0;i<=N;i++) A0.v[i][i]=1;
}

Matirx Pow(Matirx x,int m)
{
    Matirx res=A0;
    while(m){
        if(m&1) res=res*x;
        x=x*x, m>>=1;
    }
    return res;
}

int main()
{
    //freopen("r.txt","r",stdin);
    while(~scanf("%d%d%d",&N,&M,&K)){
        if(N==0 && M==0 && K==0) break;
        init();
        Matirx p=A0;
        for(int i=0;i<K;i++){
            char ac[3]; scanf("%s",ac);
            if(ac[0]=='g'){
                int x; scanf("%d",&x);
                p.v[0][x]++;
            }else if(ac[0]=='e'){
                int x; scanf("%d",&x);
                for(int i=0;i<=N;i++)
                    p.v[i][x]=0;
            }else{
                int x,y; scanf("%d%d",&x,&y);
                for(int i=0;i<=N;i++)
                    swap(p.v[i][x],p.v[i][y]);
            }
        }
        p=Pow(p,M);
        memset(ans.v,0,sizeof(ans.v));
        ans.v[0][0]=1;
        ans=ans*p;
        for(int i=1;i<=N;i++){
            printf("%I64d",ans.v[0][i]);
            if(i<N) printf(" ");
            else printf("\n");
        }

    }
    return 0;
}
