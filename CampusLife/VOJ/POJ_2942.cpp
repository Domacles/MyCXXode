/***
	双连通分量性质：
	若某块(双连通分量)不可染色为二分图，则该块存在奇圈；若某块存在奇圈，那么该块中的所有点都存在与奇圈；
***/
#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#define PII make_pair
using namespace std;

const int maxn=1000+10,maxm=1000000+10;

bool ok[maxn];
bool G[maxn][maxn];
int n,m,DFN[maxn],Low[maxn],belong[maxn],Index,cnt;
//cnt 双连通分量的个数; belong 属于哪个双连通分量;

vector<int> BCC[maxn];
stack< pair<int,int> > s;

void Tarjan(int u,int fa)//用于求双连通分量的个数(双连通分量)
{
    DFN[u]=Low[u]=++Index;
    for(int i=1;i<=n;i++)
        if(i!=fa && G[u][i] && i!=u){
            if(!DFN[i]){
                s.push(PII(u,i));
                Tarjan(i,u);
                Low[u]=min(Low[i],Low[u]);
                if(DFN[u]<=Low[i]){
                    BCC[++cnt].clear();
                    pair<int,int> e;
                    do{
                        e=s.top();s.pop();
                        if(belong[e.first ]!=cnt){belong[e.first ]=cnt;BCC[cnt].push_back(e.first );}
                        if(belong[e.second]!=cnt){belong[e.second]=cnt;BCC[cnt].push_back(e.second);}
                    }while((e.first!=u)||(e.second!=i));
                }
            }
            else Low[u]=min(DFN[i],Low[u]);
        }
}
bool color(int u)
{
        for(int i=1;i<=n;i++){
            if((!G[u][i])||(belong[u]!=belong[i])||(i==u))continue;
            if(DFN[i]==DFN[u])return 0;
            if(!DFN[i]){
                DFN[i]=3-DFN[u];
                if(!color(i)) return 0;
            }
        }
        return 1;
}
int main()
{
    ios::sync_with_stdio(0);
    while(cin>>n>>m){
        if(n==0 && m==0)break;
        memset(G,1,sizeof(G));
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            G[x][y]=G[y][x]=0;
        }
        memset(ok,0,sizeof(ok));
        memset(DFN,0,sizeof(DFN));
        memset(Low,0,sizeof(Low));
        memset(belong,0,sizeof(belong));
        Index=0;cnt=0;
        for(int i=1;i<=n;i++)
            if(!DFN[i])
                Tarjan(i,0);//可能存在孤点

        for(int i=1;i<=cnt;i++){
            memset(DFN,0,sizeof(DFN));
            for(int j=0;j<BCC[i].size();j++)
                belong[BCC[i][j]]=i;
            DFN[BCC[i][0]]=1;

            if(!color(BCC[i][0]))
                for(int j=0;j<BCC[i].size();j++)
					ok[BCC[i][j]]=1;
        }

        int ans=0;
        for(int i=1;i<=n;i++)ans+=ok[i];
        cout<<n-ans<<endl;
    }
    return 0;
}
