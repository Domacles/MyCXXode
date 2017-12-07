/************
    求出第i个点能够使用的本金(前面的本金都已经投入)，这个本金会在后来被反复使用，因此，
    dp[i]表示在i点投入本金后，到最后能够获得的最大利润率，
    则dp[i]=max(dp[i+1], dp[i.st->ed]+i.st->rate); 即
        1, i点不购买基金;
        2, i点购买 MAX(从i点出发到对应的ed点所能获得的利润率 + 当前这段点的利润率);

	特点：1从后往前转移 2求第i点本金，使得前面的本金有多少不必考虑，只需要考虑这部分本金的使用情况
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
    for(int i=1;i<maxn;i++) f[i]+=f[i-1];//从第0天到第i天累计的本金

    sort(day.begin(),day.end());//离散化
    vector<int>::iterator it=unique(day.begin(),day.end());
    day.erase(it,day.end());//去重

    for(int i=0;i<(int)day.size();i++) Day[day[i]]=i;//map

    s[0]=f[day[0]];
    for(int i=1;i<(int)day.size();i++){
        int a=day[i];
        int b=day[i-1];
        s[i]=f[a]-f[b];
//代表第i个时间点相对于前一个时间点的新收入，即这个点的可用资金(前面的都已经投入)
    }

    for(int i=0;i<=(int)day.size()+10;i++) st_ed[i].clear();//第i个st，对应的ed
    for(int i=0;i<=(int)day.size()+10;i++) st_m[i].clear();//第i个st，对应的收入m
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
        dp[i]=dp[i+1];//dp[i] 表示从这个时间点出发能够获得的最大利润率
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
            f[x]+=y;//!!一天内多收入
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
