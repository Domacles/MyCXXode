/*****
��⣺
����DP����dp[u][j]��ʾ��uΪ���������ϣ���ĳ���ߵ�u���߹�j�������ܵõ������ֵ;
����������Ž��߹���k�����壬���k!=C����ô�������յ㶼����Ϊû������ĵ㣬���k=C����ô�������յ�������һ��Ϊ������ĵ㣬����dp���黹��Ҫ����һά��dp[u][i][flag]����flag=1����ʾ��uΪ���������ϣ���һ��������ĵ��ߵ�u�߹�j�������ܵõ������ֵ����flag=0����ʾ���û�����塣
״̬ת�ƣ�
1) ��u�㱾���������ʱ��dp[u][j+1][flag]=max{dp[v][j][flag]+val[u]}��0<=j<C��v��u�Ķ���;
2) ��u��û������ʱ��dp[u][j][flag]=max{dp[v][j][flag]+val[u]}��0<=j<C������ģ���j=Cʱ����Ϊ·���߹���C�����壬���������յ㲻��ͬʱΪû������ĵ㣬����ֻ��flag=1��������ʽת�ƣ�Ҳ����˵dp[u][C][0]�ǲ����ܵ������
������������Ժϳ�һ��д��
����ans�����Ž���Կ���������ƴ��һ��ö��������������ĸ���Ȼ����ƴ������
ע���Ϊlong long��dp����ĳ�ʼ����
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

const int maxn =50005;
vector<int>G[maxn];
int N,C,trap[maxn],val[maxn];
ll ans,dp[maxn][4][2];

void DFS(int u,int f)
{
    dp[u][trap[u]][trap[u]]=val[u];//������ʱ����ʱ���Լ�Ϊ���
    ans=max(ans,dp[u][trap[u]][trap[u]]);
    for(int i=0;i<(int)G[u].size();i++){
        int v=G[u][i];
        if(v==f) continue;
        DFS(v,u);
        for(int j=0;j<=C;j++)
        for(int k=0;j+k<=C;k++){//���������������ΪCʱ�������յ��Ȼ��һ������trap
            ans=max(ans,dp[u][j][1]+dp[v][k][1]);//��u��Ϊ�н��
            if(j+k<C)ans=max(ans,dp[u][j][0]+dp[v][k][0]);
            if(j!=C) ans=max(ans,dp[u][j][0]+dp[v][k][1]);
            if(k!=C) ans=max(ans,dp[u][j][1]+dp[v][k][0]);
        }
        for(int j=0;j<C;j++){//����dp[u][j]
            dp[u][j+trap[u]][0]=max(dp[u][j+trap[u]][0],dp[v][j][0]+val[u]);
            dp[u][j+trap[u]][1]=max(dp[u][j+trap[u]][1],dp[v][j][1]+val[u]);
        }
        if(!trap[u]) dp[u][C][1]=max(dp[u][C][1],dp[v][C][1]+val[u]);
    }
}

int main()
{
    //freopen("r.txt","r",stdin);
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&C);
        for(int i=0;i<N;i++)
            scanf("%d%d",&val[i],&trap[i]);
        for(int i=0;i<N;i++) G[i].clear();
        for(int i=1;i<N;i++){
            int u,v; scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int i=0;i<=N;i++)
            for(int j=0;j<=C;j++)
                for(int k=0;k<2;k++)
                    dp[i][j][k]=-(1LL<<61);
        ans=0;
        DFS(0,-1);
        printf("%I64d\n",ans);
    }
    return 0;
}
