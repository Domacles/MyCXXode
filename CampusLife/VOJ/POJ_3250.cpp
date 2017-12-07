/***
	转化为每头牛被多少头牛看到的数量和
***/
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
typedef long long ll;
stack<ll>s;

int main()
{
	int n; scanf("%d",&n);
	ll x;  scanf("%lld",&x);
	s.push(x);
	ll ans=0;
	for(int i=1;i<n;i++){
		scanf("%lld",&x);/**单调栈**/
		while(!s.empty() && s.top()<=x) s.pop();
		ans+=s.size();//当前这头牛能够被前面多少头牛看到
		s.push(x);
	}
	printf("%lld\n",ans);
	return 0;
}