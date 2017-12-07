/***
����һ��n���㣬m������ߵ�ͼ����Ҫ��������Ҫ��
1.����һ�Ե��֮�������һ������ߣ���û���Ի���
2.��֤ͼ��ͨ��m���ߵı�Ȩ�ϸ�����[1, m]�һ�����ͬ��
��������������������·����ص���ʼ�㣬�����ı�Ȩ�ܺ���3�ı�����

���췽����
Ҫͬʱ����1.2��Ҫ�󣬶����������� m >= n + 3����ôҲ����˵��
�������������ɵ��ȹ���һ��n����n������ߵĻ�������ǰn-1���ߵı�Ȩ��1...2..3...n-1��
�������һ���ߣ�����ȡn, n+1�� n+2����֮ʹ�����������Ȩֵtot%3==0�����ˡ�

�����Ļ������Ǿ�����˳�����ͼ���Ѿ�������һ��n����n���������������ͼ�ˣ�
��ô����ʣ�µ�m-n������ô�죿���������Ҫ��ԭ�еĻ������һ����ȨΪw�ıߣ�
���һ�Ҫά��ͼ��1.2���ʣ���Ȼ������ֻ��Ҫ�ҵ�����һ�����<u, v>,
���������ǹ���ĳ�ʼ���ϣ�u - > v �ľ���Ϊg[u][v]��
��ôֻ��Ҫg[u][v] % 3 == w % 3�����Ǿ��ܱ�֤ͼ�����ʲ����ˣ�

˼·��
    �ȼ��滻
***/
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
const int inf = 1e7;

int  dis[88][88];
int   dp[88][88];
int vis[88*88/7];
stack<PII>v[88*88/7];
int N,M;

void init()//ע���ʼ������
{
    memset(vis,0,sizeof(vis));//!!!
    for(int i=0;i<=N;i++){
        dis[i][i]=dp[i][i]=0;
        for(int j=0;j<=N;j++){
            if(i==j) continue;
            dis[i][j]=dp[i][j]=inf;
        }
    }
    for(int i=0;i<=M;i++){
        while(!v[i].empty()) v[i].pop();
    }
}

void Floyd()
{
    for(int l=1;l<=N;l++)
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                if(dp[i][j]>dp[i][l]+dp[l][j])
                   dp[i][j]=dp[i][l]+dp[l][j];
}

void create()
{
    init();
    int s=0;
    for(int i=1;i<N;i++){
            dis[i][i+1]=i,s+=i,vis[i]=1;dp[i][i+1]=i;
    }
    for(int i=N;i<N+3;i++)
        if((s+i)%3==0){
            dis[N][1]=i;vis[i]=1;dp[N][1]=i;break;
        }
    Floyd();

    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++){
            if(dis[i][j]<=M || dis[j][i]<=M) continue;
            v[dp[i][j]%3].push(PII(i,j));
        }
}

bool check(int x)
{
    while(!v[x%3].empty()){
        PII now=v[x%3].top();
        if(dis[now.first][now.second]>=inf && dis[now.second][now.first]>=inf){
            dis[now.first][now.second]=x , v[x%3].pop();
            return 1;
        }else v[x%3].pop();
    }
    return 0;
}

bool solve()
{
    for(int i=1;i<=M;i++)
    if(!vis[i]){
        if(!check(i)) return 0;
    }
    return 1;
}

int main()
{
    //freopen("r.txt","r",stdin);
    int T; scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d%d",&N,&M);
        create();
        printf("Case #%d:\n",t);
        if(solve()){
            for(int i=1;i<=N;i++)
                for(int j=1;j<=N;j++)
                    if(i!=j && dis[i][j]<=M)
                        printf("%d %d %d\n",i,j,dis[i][j]);
        }else puts("-1");
    }
    return 0;
}
