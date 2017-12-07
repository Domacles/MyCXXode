#include<iostream>
#include<algorithm>
#include<cstdio> 
#include<queue>
#include<cstring>
 
using namespace std;
int N,K,ans;
int step[111111];

int BFS()
{
	int Max=K-N;
	memset(step,1,sizeof(step));
	queue<int>q;
	step[N]=0;
	q.push(N);
	while(!q.empty()){
		int now=q.front();q.pop();
		int s=step[now],next;
		if(s>Max) continue;
		next=now+1;
		if(next>=0&&step[next]>s+1)
			q.push(next),step[next]=s+1;
		next=now-1;
		if(next>=0&&step[next]>s+1)
			q.push(next),step[next]=s+1;
		next=now*2;
		if(next<111111&&step[next]>s+1)
			q.push(next),step[next]=s+1;
	}
	return step[K];
}

int main()  
{
	scanf("%d%d",&N,&K);
	if(N>=K)
		ans=N-K;
	else
		ans=BFS();
	printf("%d\n",ans);
	return 0;  
}