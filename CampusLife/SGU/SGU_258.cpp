#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <complex>
#include <cassert>
#include <utility>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;
///#pragma comment(linker, "/STACK:102400000,102400000")
typedef pair<int,int> PII;
typedef long long ll;

int size01(int x){return __builtin_popcount(x);}
#define lson l,m,rt<<1
#define rson m+1,r,rt<<11
#define All 1,N,1

const ll  INFll = 0x3f3f3f3f3f3f3f3fLL;
const int INF= 0x7ffffff;
const int maxn = 1e5+3e4+100;
const int mod = 1000000007;

const double pi = acos(-1);
const double eps = 1e-10;

typedef complex<double> Point;
typedef complex<double> Vector;
typedef vector<int> intV;
typedef vector<double> intD;
#define X real()
#define Y imag()
Vector rotate(Vector v, double a) {return v*polar(1.0, a);}
int dx[]={0 ,-1,  0,1};
int dy[]={-1, 0,  1,0};


const int Val=50;
int  N,M;
int  dp[11][11][111][11][11], bit[11], len;
/**
int  Sum[5][10][40];//n digits, first digit, sum val
int  SumUp[5][10][10][40],SumDown1[5][10][10][40],SumDown2[5][10][10][40];
//n  digits, first digit, UpOrDown maxval, isornot first, sum val
**/

void init(){
    memset(dp,-1,sizeof(dp));
}
/*******
    *�����sum������λ�ĺͣ�����ǰN/2λ���N/2λ�Ĳ�+����ֵ��������Ϊ������±꣬��õĺͲ���С��0��
    ����Ŀ���������������10^9�����ǰN/2λ���N/2λ�Ĳ����ֵ��󲻻ᳬ��36,��˻���ֵֻҪ��36�󼴿ɡ�
    *dfs(��ǰλ��[0~n-1]���ܹ�λ��n��ǰN/2λ���N/2λ�Ĳ�+����ֵ��������ֵ�����½�ֵ���Ƿ���ȡ�߽�)
    *�����ж�����ֵ������ʱ������ö�����߲���һ������~~~
*******/
int dfs(int p,int n,int sum,int up,int down,int flag){//ö��+����
    if(p==-1) return sum!=Val && sum+up>=Val && sum-down<=Val;
    if(!flag && dp[p][n][sum][up][down]>=0) return dp[p][n][sum][up][down];
    int res=0;
    int ed=flag?bit[p]:9;
    for(int i=(p==n-1?1:0);i<=ed;i++){
        int nextSum, nextUp, nextDown;
        if(p>=n/2)
            nextSum=sum+i, nextUp=max(up,9-i), nextDown=max(down,p==n-1?i-1:i);
        else
            nextSum=sum-i, nextUp=max(up,i), nextDown=max(down,9-i);
            //�����nextUp��Ӧ�����nextDown����Ϊ����n/2λ�ڣ���Ҫ����ǰֵ
        res+=dfs(p-1,n,nextSum,nextUp,nextDown,flag && i==ed);
    }
    if(!flag) dp[p][n][sum][up][down]=res;
    return res;
}

int ans(int x){
    len=0;
    memset(bit,0,sizeof(bit));
    while(x){
        bit[len++]=x%10, x/=10;
    }
    int res=0;
    for(int i=2;i<=len;i+=2){
        res+=dfs(i-1,i,Val,0,0,i==len);
    }
    return res;
}

void solve(){
    scanf("%d%d",&N,&M);
    printf("%d\n",ans(M)-ans(N-1));
}

int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    init();
    solve();
    return 0;
}


