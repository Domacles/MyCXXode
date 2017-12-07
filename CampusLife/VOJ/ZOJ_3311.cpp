/*********
	easy
*********/
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

#define foreach(it,V) for(vector<int>::iterator it=V.begin(); it!=V.end();++it)

#define INF 0x7ffffff
const int maxn = 1e6+1e3;
const double eps= 1e-5;

char str[1111];

int main()
{
    //freopen("1.in","r",stdin);
    while(~scanf("%s",str)){
        int len=strlen(str), flag1=0, flag2=0;
        for(int i=0;i<len;i++){
            if(str[i]=='Z') flag1++;
            if(str[i]=='J') flag2++;
            if(flag2>flag1) break;
        }
        if(flag1!=1 || flag2!=1){
            puts("Wrong Answer"); continue;
        }

        int idx=0,f=0;
        for(int i=0;i<len;i++)
            if(str[i]=='Z'){idx=i+1; break;}
            else f++;

        int s=0;
        for(int i=idx;i<len;i++)
            if(str[i]=='J') {idx=i+1;break;}
            else s++;
        if(s<1) {
            puts("Wrong Answer"); continue;
        }

        int d=0;
        for(int i=idx;i<len;i++)
            d++;
        if(d!=s+f){
            puts("Wrong Answer"); continue;
        }
        puts("Accepted");
    }
    return 0;
}

