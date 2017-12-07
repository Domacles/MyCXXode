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
bool Map[222][222];
int N,M;

int main()
{
    //freopen("r.txt","r",stdin);
    //freopen("w.txt","w",stdout);
    while(~scanf("%d%d",&N,&M)){
        memset(Map,0,sizeof(Map));
        int flag=0,v[3]={0};
        for(int i=0;i<N;i++)//将原来的区域分成三部分
            for(int j=0;j<M;j++)
                v[(i+j)%3]++;

        for(int i=0;i<3;i++)//选取数量最少的一部分涂蓝色,一开始没注意= =!
            if(v[i]<v[flag]) flag=i;

        for(int i=0;i<N;i++){//涂色
            for(int j=0;j<M;j++)
                if((i+j)%3==flag) Map[i][j]=1;
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++)
                printf("%c",Map[i][j]==1?'#':'0');
            puts("");
        }
    }
    return 0;
}
