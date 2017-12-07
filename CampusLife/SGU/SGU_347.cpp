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
int N;
vector<string>v;

bool cmp(string A,string B){return (A+B)<(B+A);}
//当出现某字符串是另外一字符串的前缀时

int main()
{
    //freopen("r.txt","r",stdin);
    while(cin>>N){
        string  str;
        for(int i=0;i<N;i++){
            cin>>str; v.push_back(str);
        }
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<N;i++)
            cout<<v[i];
        cout<<endl;
    }
    return 0;
}
