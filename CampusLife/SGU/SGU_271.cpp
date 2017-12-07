/***************
    双端队列模拟
***************/
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int,int> PII;
typedef long long ll;

#define foreach(it,V) for(vector<int>::iterator it=V.begin(); it!=V.end(); ++it)

#define INF 0x7ffffff
const int maxn = 1e4+1e3;
const double eps = 1e-5;
const int mod = 1e9+7;

deque<string> S;
deque<string> dq;
int N,M,K;

int main()
{
    freopen("1.in","r",stdin);
    scanf("%d%d%d",&N,&M,&K);
    for(int i=1; i<=N; i++) {
        char str[11];
        scanf("%s",str);
        if(i>K)
            S.push_back(string(str));
        else
            dq.push_back(string(str));
    }

    int flag=0;
    for(int i=0; i<M; i++) {
        char str[31];
        scanf("%s",str);
        if(str[0]=='A') {
            string now;
            int x=4;
            while(str[x]!=')')
                now+=str[x], x++;

            if(!flag) {
                dq.push_front(now);
                while((int)dq.size()>K) {
                    now=dq.back();
                    dq.pop_back();
                    S.push_front(now);
                }
            } else {
                dq.push_back(now);
                while((int)dq.size()>K) {
                    now=dq.front();
                    dq.pop_front();
                    S.push_front(now);
                }
            }
        } else
            flag^=1;
    }
    if(!flag) {
        while((int)dq.size()>0) {
            string now=dq.back();
            dq.pop_back();
            S.push_front(now);
        }
    } else {
        while((int)dq.size()>0) {
            string now=dq.front();
            dq.pop_front();
            S.push_front(now);
        }
    }
    while(!S.empty()) {
        string now=S.front();
        char *p=new char[now.length()+1];
        strcpy(p,now.c_str());
        printf("%s\n",p);
        S.pop_front();
    }
    return 0;
}




