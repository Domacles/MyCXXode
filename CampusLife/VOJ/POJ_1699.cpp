/*****
	DFSö���ַ���˳�򣬱Ƚ���ֵ
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
string str[111];
int N,dp[111][111];
int ans=0;

int Addlen(int m,int n){//�˴���Ϊ��yΪx�е�һ���֣���yֻ����x���棬Ҳ����˵����ʱ����lenx+leny
    int l,i,j,k;
    k=0;
    for(l=1; l<=(int)str[m].length() && l<=(int)str[n].length(); l++){   // lΪ�����ϲ��ĳ��ȡ�
        bool sign=true;
        for(i=0,j=(int)str[m].length()-l; i<l; i++,j++)
            if(str[m][j]!=str[n][i]){
                sign=false;
                break;
            }
        if(sign) k=l;
    }
    return  (int)str[n].length()-k;
}
/*
int Addlen(int x,int y)
{//�˴�����yΪx�е�һ���֣���ʱ��xһ������y�غϣ����Ȳ���
    if(x==y) return 0;
    for(int i=0;i<(int)str[x].length();i++)
        for(int j=0;j<(int)str[y].length();j++){
            if(str[x][i]!=str[y][j]) break;
            int xx=i,yy=j;
            while(str[x][xx]==str[y][yy]){
                xx++,yy++;
                if(xx==(int)str[x].length()) return str[y].length()-yy;
                if(yy==(int)str[y].length()) return 0;
            }
        }
    return str[y].length();
}
*/

int vis[111]={0};

void deal()
{
    memset(dp,0,sizeof(dp));
    memset(vis,0,sizeof(vis));
    ans=22222;
    for(int i=1;i<=N;i++){
        dp[0][i]=str[i].length();
        for(int j=1;j<=N;j++)
            dp[i][j]=Addlen(i,j);
    }
}

void DFS(int pre,int num,int nowlen)
{
    if(nowlen>=ans) return;
    if(num==N){
        if(ans>nowlen) ans=nowlen;
        return;
    }
    for(int i=1;i<=N;i++){
        if(!vis[i]){
            vis[i]=1;
            DFS(i,num+1,nowlen+dp[pre][i]);
            vis[i]=0;
        }
    }
}

int main()
{
    freopen("r.txt","r",stdin);
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=1;i<=N;i++) cin>>str[i];
        deal();
        DFS(0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}
