#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

void BFS(int n)
{
	queue<long long>q;
	while(!q.empty()) q.pop();
	q.push(1);
	while(!q.empty()){
		long long now=q.front();q.pop();
		if(now%n==0){printf("%lld\n",now);return;}
		q.push(now*10);
		q.push(now*10+1);
	}
}

int main()
{
	int x;
	while(~scanf("%d",&x)&&x) BFS(x);
	return 0;
}