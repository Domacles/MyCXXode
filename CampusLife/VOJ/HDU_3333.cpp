#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
using namespace std;
#define LL long long
const int maxn = 100100;
struct point{
    LL x,y;
    LL num;
    long long ans;
}po[maxn];
LL rec[maxn];
LL tree[maxn];
int n,m;
map<int,LL> ma;
bool cmp(const point &a,const point &b){
    return a.y < b.y;
}
bool cmp1(const point &a,const point &b){
    return a.num < b.num;
}
int lowbit(int x){
    return (-x)&x;
}
int update(int pos,LL num){
    while(pos<=n){
        tree[pos]+=num;
        pos+=lowbit(pos);
    }
    return 0;
}
LL sum(int pos){
    LL ans=0;
    while(pos>0){
        ans+=tree[pos];
        pos-=lowbit(pos);
    }
    return ans;
}
int main(){
    int i,j,k,t;
    scanf("%d",&t);
    while(t--){
        memset(tree,0,sizeof(tree));
        ma.clear();
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        scanf("%lld",&rec[i]);
        scanf("%d",&m);
        for(i=1;i<=m;i++){
            scanf("%I64d%I64d",&po[i].x,&po[i].y);
            if(po[i].x>po[i].y){
                swap(po[i].x,po[i].y);
            }
            po[i].num=i;
        }
        sort(po+1,po+m+1,cmp);
        k=1;
        for(i=1;i<=m;i++){
            while(k<=po[i].y){
                if(ma[rec[k]]==0){
                    update(k,rec[k]);
                }
                else{
                    update(ma[rec[k]],-rec[k]);
                    update(k,rec[k]);
                }
                ma[rec[k]]=k;
                k++;
            }
            po[i].ans=sum(po[i].y)-sum(po[i].x-1);
        }
        sort(po+1,po+1+m,cmp1);
        for(i=1;i<=m;i++){
            printf("%I64d\n",po[i].ans);
        }
    }
    return 0;
}
