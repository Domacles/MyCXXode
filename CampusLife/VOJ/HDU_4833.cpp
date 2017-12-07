/************
    �����i�����ܹ�ʹ�õı���(ǰ��ı����Ѿ�Ͷ��)�����������ں���������ʹ�ã���ˣ�
    dp[i]��ʾ��i��Ͷ�뱾��󣬵�����ܹ���õ���������ʣ�
    ��dp[i]=max(dp[i+1], dp[i.st->ed]+i.st->rate); ��
        1, i�㲻�������;
        2, i�㹺�� MAX(��i���������Ӧ��ed�����ܻ�õ������� + ��ǰ��ε��������);

	�ص㣺1�Ӻ���ǰת�� 2���i�㱾��ʹ��ǰ��ı����ж��ٲ��ؿ��ǣ�ֻ��Ҫ�����ⲿ�ֱ����ʹ�����
************/
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

const int maxn =1e5+1000;

struct ResM{
    int d,val;
    ResM(){}
    ResM(int dd,int vv):d(dd),val(vv){}
};
struct Pro{
    int st,ed,rate;
    Pro(){}
    Pro(int ss,int ee,int rr):st(ss),ed(ee),rate(rr){}
};

map<int,int> Day;
vector<ResM> A;
vector<Pro> B;

int N,M;
ll f[maxn], s[maxn];
vector<int> day, st_ed[maxn], st_m[maxn];

void init()
{
    memset(f,0,sizeof(f));
    memset(s,0,sizeof(s));
    A.clear(); B.clear(); day.clear(); Day.clear();
}

void deal()
{
    for(int i=1;i<maxn;i++) f[i]+=f[i-1];//�ӵ�0�쵽��i���ۼƵı���

    sort(day.begin(),day.end());//��ɢ��
    vector<int>::iterator it=unique(day.begin(),day.end());
    day.erase(it,day.end());//ȥ��

    for(int i=0;i<(int)day.size();i++) Day[day[i]]=i;//map

    s[0]=f[day[0]];
    for(int i=1;i<(int)day.size();i++){
        int a=day[i];
        int b=day[i-1];
        s[i]=f[a]-f[b];
//�����i��ʱ��������ǰһ��ʱ���������룬�������Ŀ����ʽ�(ǰ��Ķ��Ѿ�Ͷ��)
    }

    for(int i=0;i<=(int)day.size()+10;i++) st_ed[i].clear();//��i��st����Ӧ��ed
    for(int i=0;i<=(int)day.size()+10;i++) st_m[i].clear();//��i��st����Ӧ������m
    for(int i=0;i<M;i++){
        Pro &p=B[i];
        int st=Day[p.st], ed=Day[p.ed];
        st_ed[st].push_back(ed);
        st_m[st].push_back(p.rate);
    }
}

int dp[maxn];

void solve()
{
    memset(dp,0,sizeof(dp));
    for(int i=day.size()-1;i>=0;i--){
        dp[i]=dp[i+1];//dp[i] ��ʾ�����ʱ�������ܹ���õ����������
        for(int j=0;j<(int)st_ed[i].size();j++)
            dp[i]=max(dp[i],dp[st_ed[i][j]]+st_m[i][j]);
    }
    ll ans=0;
    for(int i=0;i<(int)day.size();i++){
        ans+=(ll)dp[i]*s[i];
    }
    printf("%.2lf\n",ans/100.0);
}

int main()
{
    freopen("r.txt","r",stdin);
    int T; scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d%d",&N,&M);
        init();

        for(int i=0;i<N;i++){
            int x,y; scanf("%d%d",&x,&y);
            A.push_back(ResM(x,y));
            day.push_back(x);
            f[x]+=y;//!!һ���ڶ�����
        }

        for(int i=0;i<M;i++){
            int x,y,z; scanf("%d%d%d",&x,&y,&z);
            B.push_back(Pro(x,y,z));
            day.push_back(x);
            day.push_back(y);
        }
        printf("Case #%d:\n",t);
        deal();
        solve();
    }
    return 0;
}
