/***
    删除竖着的第一列，横着的最后一列，
    剩下的任务就是找count((x,y)) && gcd(x,y)==1 ,1<=x<=N-1,1<=y<=M-1
****/
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

const int MAXN = 1e6+100;

bool v[MAXN]={0};
int n,m;
vector <int> pri;
vector <int> fac;
vector <int> P[MAXN];
long long tmp;

void prework(){
    for (int i=2;i<MAXN;++i)
        if (!v[i]){
            for (int j=i+i;j<MAXN;j+=i){
                v[j]=1;
                P[j].push_back(i);
            }
            P[i].push_back(i);
        }
}

void dfs(int m,int dep,int mul,int tot,int MD,int i){
    if (dep>MD){
        if (tot%2==0) tmp+=m/mul;
        else tmp-=m/mul;
        return;
    }
    dfs(m,dep+1,mul,tot,MD,i);
    dfs(m,dep+1,mul*P[i][dep-1],tot+1,MD,i);
}

void work(){
    if (n==1 && m==1){
        cout<<0<<endl; return;
    }
    if (n==1 || m==1){
        cout<<1<<endl; return ;
    }
    long long Ans=2;
    for (int i=1;i<m;++i){
            tmp=0;
            dfs(n-1,1,1,0,P[i].size(),i);
            Ans+=tmp;
    }
    cout<<Ans<<endl;
}

int main(){
    //freopen("r.txt","r",stdin);
    prework();
    scanf("%d%d",&n,&m);
    work();
    return 0;
}


/***
    删除竖着的第一列，横着的最后一列，
    剩下的任务就是找count((x,y)) && gcd(x,y)==1 ,1<=x<=N-1,1<=y<=M-1

    容斥原理,求互质对数
****/

using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn = 1001000;
bool v[maxn]={0};
int  P[maxn];
ll   n,m;
void work(){
    if (n==1 && m==1){cout<<0<<endl; return;}
    if (n==1 || m==1){cout<<1<<endl; return;}
    n--,m--;
    memset(P,0,sizeof(P));
    for(int i=2;i<=min(n,m);++i)
        if(!v[i]){
            for (int j=i+i;j<=min(n,m);j+=i){ v[j]=1;
                if(P[j]!=-1) P[j]++;
                if(1LL*i*i<=min(n,m) && j%(i*i)==0) P[j]=-1;
            } P[i]++;
    }
    ll ans=2;
    for(int i=1;i<=min(n,m);i++){
        if(P[i]==-1) continue;//容斥原理,求互质对数
        if(P[i]&1) ans-=(n/i)*(m/i);
        else ans+=(n/i)*(m/i);
    }
    cout<<ans<<endl;
}
int main(){
    //freopen("r.txt","r",stdin);
    scanf("%I64d%I64d",&n,&m); work();
    return 0;
}
