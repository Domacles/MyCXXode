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
        for(int i=0;i<N;i++)//��ԭ��������ֳ�������
            for(int j=0;j<M;j++)
                v[(i+j)%3]++;

        for(int i=0;i<3;i++)//ѡȡ�������ٵ�һ����Ϳ��ɫ,һ��ʼûע��= =!
            if(v[i]<v[flag]) flag=i;

        for(int i=0;i<N;i++){//Ϳɫ
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
