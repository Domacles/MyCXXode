/****
    用链表维护，每次只取前100个输出；
    注意，不要只存100个，而把剩下的都丢掉了，因为这样，在100个中被tag了好几次之后，还需要100个之后的名字补足100
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
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int,int> PII;
typedef long long ll;

#define foreach(it,V) for(vector<int>::iterator it=V.begin(); it!=V.end();++it)

#define INF 0x7ffffff
const int maxn = 555;
const double eps= 1e-5;

char op[8],name[60];
list<string> lst;
set<string> st;
void insert(const string &s)
{
    lst.push_front(s);
    st.insert(s);
}
void del(const string &s)
{
    st.erase(s);
}
void search()
{
    int c = 0;
    set<string> tmp;
    for(list<string>::iterator it = lst.begin(); it != lst.end() && c < 100; ) {
        if(st.find(*it) != st.end()) {
            if(tmp.find(*it) == tmp.end()) {
                tmp.insert(*it);
                printf("%s\n", (*it).c_str());
                c++, it++;
            } else it = lst.erase(it);
        } else it = lst.erase(it);
    }
    printf("###\n");
}
int main()
{
    int n;
    while(scanf("%d", &n) != EOF) {
        for(int i = 0; i < n; i++) {
            scanf("%s", op);
            switch(op[0]) {
            case 'r':
            case 'n':
                scanf("%s", name);
                insert(name);
                break;
            case 't':
                scanf("%s", name);
                del(name);
                break;
            case 's':
                search();
                break;
            default:
                break;
            }
        }
        printf("\n");
        lst.clear();
        st.clear();
    }
    return 0;
}

