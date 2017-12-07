//1.如果有乘客要上车，那么就让他上，收钱！
//2.如果超载了，把距目的地最远的几个乘客踢下去，退钱。
//3.行驶到下一站
#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;

struct node{
    int y,v;
    bool operator <(const node &b)const{
        return y<b.y;
    }
}stem;
int K,N,C;
vector<node> dd[10005],sd[10005];
int a[2][10005];

int f(vector<node> tt[],int flag){
    priority_queue<node> q;
    int k=0,ans=0;
    for(int i=1;i<=N;i++){
        ans+=a[flag][i];
        k-=a[flag][i];//當前數量
        for(int j=0;j<(int)tt[i].size();j++){
            k+=tt[i][j].v;
            stem=tt[i][j];
            q.push(stem);
        }
        while(k>C){
            node top=q.top();
            q.pop();
            if(k-C>=top.v){
                k-=top.v;
                a[flag][top.y]-=top.v;
            }
            else{
                a[flag][top.y]-=(k-C);
                top.v-=k-C;
                q.push(top);
                k=C;
            }
       }
        
    }
    return ans;
}
    
int main()
{
    scanf("%d%d%d",&K,&N,&C);
    int u,v,w;
    for(int i=1;i<=K;i++){
        scanf("%d%d%d",&u,&v,&w);
        stem.v=w;
        if(v>u){
            stem.y=v;
            dd[u].push_back(stem);
            a[0][v]+=w;
       }
        else {
            u=N-u+1; v=N-v+1;
            stem.y=v;
            sd[u].push_back(stem);
            a[1][v]+=w;
        }
    }
    int ans=0;
    ans+=f(dd,0);
    ans+=f(sd,1);
    printf("%d\n",ans);
    return 0;
}
