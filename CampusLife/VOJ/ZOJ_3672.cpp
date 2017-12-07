#include <iostream>
#include <algorithm>

using namespace std;

int N;

void solve(){
    bool ok = 1;
    long long A, B, sum = 0, Max = -1, dis;
    for(int i = 1; i <= N; i++){
        cin>>A>>B;
        dis = A-B;
        sum += dis;
        Max = max(Max, dis);
    }
    if(sum&1||2*Max>sum) ok = 0;
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main()
{
    while(cin >> N) solve();
    return 0;
}

