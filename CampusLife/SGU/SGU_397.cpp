/****
    使用链表模拟文本编辑器
*****/
#include <list>
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

char org[maxn];

int main()
{
    list<char> word;
    scanf("%s",org);
    int len=strlen(org);
    list<char>::iterator it=word.begin();
    for(int i=0;i<len;i++){
        if(org[i]=='L'){
            if(it!=word.begin()) --it;
        }
        else if(org[i]=='R'){
            if(it!= word.end())  ++it;
        }
        else
            word.insert(it, org[i]);
    }
    for(it=word.begin();it!=word.end();++it)
        printf("%c",*it);
    printf("\n");
    return 0;
}
