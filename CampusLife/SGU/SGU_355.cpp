/*****
    数素数因子的个数
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
vector<int>Prim;
bool  isp[maxn];

void init(){
    memset(isp,1,sizeof(isp));
    isp[1]=0;
    isp[2]=1;
    for(int i=2;i<=1e4;i++){
        if(!isp[i]) continue;
        int next=i*i;
        for(int j=next;j<=1e4;j+=i)
            isp[j]=0;
        Prim.push_back(i);
    }
}

int num,col[maxn];

int main()
{
    //freopen("r.txt","r",stdin);
    init();
    int N;
    while(cin>>N){
        col[1]=1,num=1;
        for(int i=2;i<=N;i++){
            int x=i,c=0;
            for(int j=0;j<(int)Prim.size();j++){
                if(x==1) break;
                while(x%Prim[j]==0){
                    c++;
                    x/=Prim[j];
                }
            }
            if(x!=1) c++;
            num=max(num,c+1);
            col[i]=c+1;
        }
        printf("%d\n",num);
        for(int i=1;i<=N;i++){
            if(i!=1) printf(" ");
            printf("%d",col[i]);
        }
        puts("");
    }
    return 0;
}
