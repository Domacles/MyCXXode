/****
    暴力 = =!
		不过，可能有使用线段树的做法，放~
****/
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
#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int,int> PII;
typedef long long ll;

const int maxn =505000;

list <PII> p;

int main()
{
    //freopen("r.txt","r",stdin);
    for(char t; scanf("%c",&t)!=EOF;)
    {
        int a,b;
        scanf("%d%d\n",&a,&b);
        if(t=='+')
        {
            int r=0;
            for(list<PII>::iterator ite=p.begin(); ite!=p.end(); ++ite)
                if(ite->first>=a && ite->second<=b)
                    ++r;
            printf("%d\n",r);
            p.push_front(PII(a,b));
        }
        else
        {
            for(list<PII>::iterator ite=p.begin(); ite!=p.end(); ++ite)
                if(ite->first==a && ite->second==b)
                {
                    p.erase(ite);
                    break;
                }
        }
    }
    return 0;
}
