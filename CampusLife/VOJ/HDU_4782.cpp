/***
    Ä£Äâ
***/
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

vector<string>v;
void read()
{
    v.clear();
    char c=getchar();
    while(1){
        string str="";
        while(c==' ' || c=='\t' || c=='\n') c=getchar();
        if(c=='<'){
            str+=c;
            while(c!='>') {
                c=getchar(); str+=c;
            }
            v.push_back(str);
            if(str=="</html>") return;
            c=getchar();
        }else{
            while(c!='<'){
                    int flag=1;
                    while(c==' ' || c=='\t' || c=='\n') c=getchar(),flag=0;
                    if(c=='<') break;//!!!!!!!!!!!
                    if(!flag) str+=' ';
                    str+=c;
                    c=getchar();
            }
            v.push_back(str);
        }
    }
}

void deal()
{
    int cnt=0;
    for(int i=0;i<(int)v.size();i++){
        if(v[i][0]=='<'){
            if(v[i][1]!='/'){
                for(int j=0;j<cnt;j++) printf(" ");
                cout<<v[i]<<endl;
                if(v[i][v[i].length()-2]!='/') cnt++;
                else continue;
            }else{
                cnt--;
                for(int j=0;j<cnt;j++) printf(" ");
                cout<<v[i]<<endl;
            }
        }else{
            for(int j=0;j<cnt;j++) printf(" ");
            cout<<v[i]<<endl;
        }
    }
}

int main()
{
    freopen("r.txt","r",stdin);
    freopen("w.txt","w",stdout);
    int T; scanf("%d",&T); getchar();
    for(int t=1;t<=T;t++){
        read();
        printf("Case #%d:\n",t);
        deal();
    }
    return 0;
}
