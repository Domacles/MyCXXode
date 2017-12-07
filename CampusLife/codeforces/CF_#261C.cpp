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

#define foreach(it,V) for(vector<int>::iterator it=V.begin(); it!=V.end();++it)

const int maxn =1e5+111;
const double eps= 1e-9;
int N,K,D;
int bit[1111][1111];
//N ->K 进制
/*
    由于0～N-1都是不相同的数字，所以当他们变成一个D位K进制数字后也是不会出想两者相同的情况。

    所以，我们给这些人标记上0～N-1，然后把每个人的编号化成一个D位K进制的数字，然后将每一位
    按照人的次序依次输出即可实现题目要求。

    一旦出现有人的编号超出了D位K进制的所能表示的范围，则说明必然会有两人无法满足要求。
*/
int main()
{
    freopen("1.in","r",stdin);
    cin>>N>>K>>D;
    for(int i=0; i<N; i++) {
        int t=i;
        for(int j=0; j<D; j++) {
            bit[i][j]=t%K;
            t/=K;
        }
        if(t) {
            puts("-1");
            return 0;
        }
    }
    for(int i=0; i<D; i++) {
        for(int j=0; j<N; j++)
            cout<<bit[j][i]+1<<" ";
        cout<<endl;
    }
    return 0;
}


