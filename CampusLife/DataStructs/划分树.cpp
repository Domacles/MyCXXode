/***
	无修改的区间第k小问题
****/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = (int)3e6+10;
const int maxn = (int)1e5;
int lson[N],rson[N],sum[N];
int Time[N];
int total;
int s[N],X[N];
void pushup(int root){
    sum[root] = sum[lson[root]] + sum[rson[root]];
}
int build(int L,int R){
    int now = ++total;
    if(L==R){
        lson[now] = rson[now] = 0;
        sum[now] = 0;
        return now;
    }
    int m=(L+R)>>1;
    lson[now] = build(L,m);
    rson[now] = build(m+1,R);
    pushup(now);
    return now;
}
int update(int root,int pos,int L,int R){
    int now = ++total;
    if(L==R){
        sum[now] = sum[root] + 1;
        lson[now] = rson[now] = 0;
        return now;
    }
    int m=(L+R)>>1;
    if(pos<=m){
        lson[now] = update(lson[root],pos,L,m);
        rson[now] = rson[root];
    }else{
        lson[now] = lson[root];
        rson[now] = update(rson[root],pos,m+1,R);
    }
    pushup(now);
    return now;
}
int ask(int root1,int root2,int k,int L,int R){
    if(L==R){
        return X[L];
    }
    int number = sum[lson[root2]] - sum[lson[root1]];
    int m=(L+R)>>1;
    if(number >= k)
        return ask(lson[root1],lson[root2],k,L,m);
    else
        return ask(rson[root1],rson[root2],k-number,m+1,R);
}
int main(){
    int T;scanf("%d",&T);
    int n,m;
    while(T--){
        scanf("%d%d",&n,&m);
        int cnt = 0;
        for(int i=1;i<=n;i++){
            scanf("%d",&s[i]);
            X[++cnt] = s[i];
        }
        sort(X+1,X+1+cnt);//离散化
        int all = 1;
        for(int i=2;i<=cnt;i++)//离散化
            if(X[i]!=X[i-1])X[++all] = X[i];
        total = 0;
        Time[0] = build(1,all);
        for(int i=1;i<=n;i++){
            int pos = lower_bound(X+1,X+1+all,s[i])-X;
            Time[i] = update(Time[i-1],pos,1,all);
        }
        while(m--){
            int L,R,k;
            scanf("%d%d%d",&L,&R,&k);
            printf("%d\n",ask(Time[L-1],Time[R],k,1,all));
        }
    }
    return 0;
}
