/********
	哈夫曼编码
********/
#include <queue>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
typedef long long LL;

int main()
{
	priority_queue<LL,vector<LL>,greater<LL> > q;
	int N;scanf("%d",&N);
	for(int i=0;i<N;i++){
		int x;scanf("%d",&x);
		q.push(x);
	}
	LL ans=0;
	for(int i=0;i<N-1;i++){
		LL temp=0;
		temp+=q.top(); q.pop();
		temp+=q.top(); q.pop();
		ans+=temp;
		q.push(temp);
	}
	cout<<ans<<endl;
	return 0;
}