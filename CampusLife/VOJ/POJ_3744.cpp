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

struct Matrix
{
    double val[2][2];
    Matrix operator*(const Matrix &M) const{
        Matrix res;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++){
                double &p=res.val[i][j];
                p=0;
                for(int k=0;k<2;k++) p+=val[i][k]*M.val[k][j];
            }
        return res;
    }
}M;

Matrix Pow(Matrix X,int n)
{
    Matrix res;
    res.val[0][0]=res.val[1][1]=1;
    res.val[1][0]=res.val[0][1]=0;
    while(n){
        if(n&1) res=res*X;
        X=X*X, n>>=1;
    }
    return res;
}

int N,ED;
double p;
vector<int>a;

void init()
{
    ED=0;
    a.clear();
    M.val[0][0]=p, M.val[0][1]=1, M.val[1][0]=1-p, M.val[1][1]=0;
}

double solve()
{
    int ed1=ED;
    double x=1,y=1;
    for(int i=(int)a.size()-1;i>=0;i--){
        int n=ed1-a[i];
        if(i>0 && a[i-1]==a[i]-1) return 0;
        Matrix temp=Pow(M,n);
        ed1=a[i];
        double xx=x, yy=y;
        x=xx*temp.val[0][0]+yy*temp.val[1][0];
        y=xx*temp.val[0][1]+yy*temp.val[1][1];
        x=0;
    }
    int n=ed1-1;
    Matrix temp=Pow(M,n);
    double xx=x, yy=y;
    x=xx*temp.val[0][0]+yy*temp.val[1][0];
    y=xx*temp.val[0][1]+yy*temp.val[1][1];
    return x;
}

int main()
{
    //freopen("r.txt","r",stdin);
    while(~scanf("%d%lf",&N,&p)){
        init();
        for(int i=0;i<N;i++){
            int x; scanf("%d",&x);
            a.push_back(x);
            ED=max(ED,x);
        }
        ED++;
        sort(a.begin(),a.end());
        printf("%.7f\n",solve());
    }
    return 0;
}
