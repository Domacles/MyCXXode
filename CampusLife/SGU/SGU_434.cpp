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
/**********
���ȣ�
    ֤�����ۣ�����k��������Ӻ�Ϊ0�ļ��ϣ�ʹ�õ��Լ��Ĳ�������Ʋ������������Ҫk-1�β�������ʹÿһ�����0.
    ����ÿһ����Ķ�Ҫ���ٵĵ������������k-1�Σ��������k-1�Σ��Ǳ�Ȼ�в������Ժϲ�Ϊ1�β�����
Ȼ��
    ��ĿҪ�����ٶ��ٴβ�����
    ����һ������AԪ�ظ���ΪN��������Ӻ�Ϊ0(2).��������ϾͿ��Ի��ֳɶ��(Ҳ����ֻ��һ��)��Ϊ0�Ĳ��ཻ�����ٷֵ��Ӽ������Ӽ��ĸ���λk��
    �����ٷֵ��Ӽ�����Ҫk-1�β�������ʹ��ÿһ�Ϊ0.��ˣ�
    A�Ĳ�����Ans=(k1-1)+(k2-1)+(k3-1)+...+(kc-1)=(k1+k2+k3+..+kc)-c=N-c
    ��ˣ�Ans��С����cӦ���
    �����뽫���ϻ��ֳɶ����Ϊ0�ļ��ϣ��Ҽ��ϸ�����ࡣ
���
    ����F(S)ΪS״̬�£�������һ�����ϺͲ�Ϊ0������ܻ��ֳ��ļ��ϸ�����(1)
    ����(1) & ����(2) = ����(1),��ˣ�Ans=N-F(S)��S=(1<<N)-1
**********/

int N,s,a[22],b[2097152],sum[2097152],f[2097152];

void init(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    for(int i=0;i<N;i++){
        int x; scanf("%d",&x);
        s+=(a[i]-=x);
    }
}

void solve(){
    if(s!=0) {
        puts("-1");
        return;
    }
    int S=1<<N;
    for(int i=0;i<N;i++) b[1<<i]=a[i];//1<<i״̬�µ�ֵ
    for(int i=1;i<S;i++){//��˼·!!!!!
        int j=i&(-i);
        sum[i]=sum[i^j]+b[j];//!!
    }
    for(int i=1;i<S;i++){
        int k;
        for(int j=i;j;j^=k){
            k=j&(-j);//ö��i״̬�����е�ÿһ��
            f[i]=max(f[i],f[i^k]+(sum[i]==b[k]));
            //F(S)��S״̬������һ���Ͳ�Ϊ0���Ӽ�����ˣ�����b[k]�����Ǹ��Ӽ���������������i^k(��˵��������״̬��,�����Ӽ���Ϊ0)�Ļ�������+1
            //����i^k״̬���Ѿ���һ���Ͳ�Ϊ0���Ӽ�����b[k]�ͻᱻ���ֵ��Ǹ��Ӽ��У�����sum[i]==b[k]����
        }
    }
    printf("%d\n",N-f[S-1]);
}

int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    init();
    solve();
    return 0;
}

