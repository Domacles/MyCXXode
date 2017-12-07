/*
区间翻转，注意标记的下传
*/
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define L ch[x][0]
#define R ch[x][1]
#define KT (ch[ ch[rt][1] ][0])
const int maxn = 100010;
int cmp(pair<int,int> a,pair<int,int> b){
        if(a.first!=b.first) return a.first<b.first;
        return a.second < b.second;
}
struct SplayTree {
    int sz[maxn];
    int ch[maxn][2];
    int pre[maxn];
    int mp[maxn];
    int flip[maxn];
    int val[maxn];
    int rt,top;
    inline void down(int x){
        if(flip[x]) {
            flip[ L ] ^= 1;
            flip[ R ] ^= 1;
            swap(L,R);
            flip[x]=0;
        }
    }
    inline void up(int x){
        sz[x]=1+sz[ L ] + sz[ R ];
    }
    inline void Rotate(int x,int f){
        int y=pre[x];
        down(y);
        down(x);
        ch[y][!f] = ch[x][f];
        pre[ ch[x][f] ] = y;
        pre[x] = pre[y];
        if(pre[x]) ch[ pre[y] ][ ch[pre[y]][1] == y ] =x;
        ch[x][f] = y;
        pre[y] = x;
        up(y);
    }
    inline void Splay(int x,int goal){//将x旋转到goal的下面
        down(x);//防止pre[x]就是目标点，下面的循环就进不去了，x的信息就传不下去了
        while(pre[x] != goal){
            down(pre[pre[x]]); down(pre[x]);down(x);//在旋转之前需要先下传标记，因为节点的位置可能会发生改变
            if(pre[pre[x]] == goal) Rotate(x , ch[pre[x]][0] == x);
            else   {
                int y=pre[x],z=pre[y];
                int f = (ch[z][0]==y);
                if(ch[y][f] == x) Rotate(x,!f),Rotate(x,f);
                else Rotate(y,f),Rotate(x,f);
            }
        }
        up(x);
        if(goal==0) rt=x;
    }
    inline void RTO(int k,int goal){//将第k位数旋转到goal的下面
        int x=rt;
        down(x);
        while(sz[ L ]+1 != k) {
            if(k < sz[ L ] + 1 ) x=L;
            else {
                k-=(sz[ L ]+1);
                x = R;
            }
            down(x);
        }
        Splay(x,goal);
    }
    void vist(int x){
        if(x){
            printf("结点%2d : 左儿子  %2d   右儿子  %2d   %2d  flip:%d\n",x,L,R,val[x],flip[x]);
            vist(L);
            vist(R);
        }
    }
    void Newnode(int &x,int c,int f){
        x=++top;flip[x]=0;
        L = R = 0;  pre[x] = f;
        sz[x]=1; val[x]=c;
    }
    inline void build(int &x,int l,int r,int f){
        if(l>r) return ;
        int m=(l+r)>>1;
        Newnode(x,num[id[m]].first,f);//!!!!!!!!特定问题，特殊赋值!!!!!!!!!!
        mp[id[m]]=x;
        build(L , l , m-1 , x);
        build(R , m+1 , r , x);
        pre[x]=f;
        up(x);
    }

    inline void Insert(int w){//插入
        int x=rt;
        down(x);
        while(ch[x][val[x]<w]){
            x=ch[x][val[x]<w];
            down(x);
        }
        Newnode(ch[x][val[x]<w],w,x);
        Splay(ch[x][val[x]<w],0);
    }

    void Del(){
         int t=rt;
         if(ch[rt][1]) {
             rt=ch[rt][1];
             RTO(1,0);
             ch[rt][0]=ch[t][0];
             if(ch[rt][0]) pre[ch[rt][0]]=rt;
         }
         else rt=ch[rt][0];
         pre[rt]=0;
         up(rt);
    }


        /****特定问题****/
    inline void init(int n){
        ch[0][0]=ch[0][1]=pre[0]=sz[0]=0;
        rt=top=0; flip[0]=0; val[0]=0;
        for(int i=1;i<=n;i++)   {
            scanf("%d",&num[i].first);
            num[i].second=i;
        }
        sort(num+1,num+n+1,cmp);
        for(int i=1;i<=n;i++)    id[num[i].second] = i;
        build(rt,1,n,0);
    }

    void solve(int n){
        for(int i=1;i<=n;i++) {
            Splay(mp[i],0);
            printf("%d",i+sz[ ch[rt][0] ]);
            flip[ch[rt][0]]^=1;
            Del();
            printf(i==n ? "\n": " ");
        }
    }
    pair<int,int> num[maxn];
    int id[maxn];
}spt;
int main()
{
    int n;
    while(~scanf("%d",&n)&&n){
        spt.init(n);
        spt.solve(n);
    }
    return 0;
}
