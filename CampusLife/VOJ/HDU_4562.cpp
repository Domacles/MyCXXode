/*****
    每个圆根据其是否包含雅典娜或者怪物可以分成四种，//!!!!! 分类
    但既不包含雅典娜又不包含怪物或者既包含雅典娜又包含怪物的圆都是不必要添加的，由题意可知。

    因此，剩下的圆可分为两类，
        1：只包含雅典娜
        2：只包含怪物

        将每种的圆都按照R排序，进行dp统计，如果j<i，
        且C[j]与C[i]不相交，则i与j之前的也不会相交(一定是包含关系，因为他们都包含同一个节点)，
        则dp[i]可以表示枚举到i时最多套了多少个圆，dp[i]=max(1,dp[j]+1),j<i 且 C[j]与C[i]不相交;

        如此计算出dp1和dp2,//汇总
        则ans=max(max(dp1),max(dp2),max(dp1[i]+dp2[j])) C1[i]与C2[j]不相交。

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
const double eps = 1e-7;

struct  Node{
    int x,y,r;
    Node(){}
    Node(int xx,int yy,int rr):x(xx),y(yy),r(rr){}
    bool operator<(const Node &A) const{
        return r<A.r;
    }
};
vector<Node> V1,V2;
int X,Y,N;
int dp1[1111],dp2[1111];


double Dis(double x1,double y1,double x2,double y2){
    return sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) );
}

bool check(Node A,Node B)//判断两个圆相离
{
    double x1=A.x, y1=A.y, r1=A.r;
    double x2=B.x, y2=B.y, r2=B.r;
    double d=Dis(x1,y1,x2,y2);
    return d<r1-r2 || d>r1+r2;
}

void gao(vector<Node> &V,int dp[])
{
    for(int i=0;i<(int)V.size();i++){
        dp[i]=1;
        for(int j=0;j<i;j++)
            if(check(V[i],V[j]))
                dp[i]=max(dp[i],dp[j]+1);
    }
}

void solve(int dp1[],int dp2[])
{
    int ans=0;
    for(int i=0;i<(int)V1.size();i++) ans=max(dp1[i],ans);
    for(int i=0;i<(int)V2.size();i++) ans=max(dp2[i],ans);
    for(int i=0;i<(int)V1.size();i++){
        for(int j=0;j<(int)V2.size();j++)
            if(check(V1[i],V2[j]))
                ans=max(ans,dp1[i]+dp2[j]);
    }
    printf("%d\n",ans);
}

int main()
{
    //freopen("r.txt","r",stdin);
    int T; scanf("%d",&T);
    for(int t=1;t<=T;t++){
        V1.clear();
        V2.clear();
        scanf("%d%d%d",&N,&X,&Y);
        for(int i=0;i<N;i++){
            int x,y,r; scanf("%d%d%d",&x,&y,&r);
            double xx=x, yy=y, rr=r;
            double d1=Dis(xx,yy,0,0);
            double d2=Dis(xx,yy,X,Y);
            if(abs(d1-rr)<eps || abs(d2-rr)<eps) continue;
            if(d1<rr && d2>rr) V1.push_back(Node(x,y,r));
            if(d1>rr && d2<rr) V2.push_back(Node(x,y,r));
        }
        sort(V1.begin(),V1.end());
        sort(V2.begin(),V2.end());
        memset(dp1,0,sizeof(dp1));
        gao(V1,dp1);
        memset(dp2,0,sizeof(dp2));
        gao(V2,dp2);
        printf("Case %d: ",t);
        solve(dp1,dp2);
    }
    return 0;
}
