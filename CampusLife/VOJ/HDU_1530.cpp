/***
	最大团问题
		一个无向图 G=(V，E)，V 是点集，E 是边集。取 V 的一个子集 U，
		若对于 U 中任意两个点 u 和 v，有边 (u,v)∈E，那么称 U 是 G 的一个完全子图。 
		U 是一个团当且仅当 U 不被包含在一个更大的完全子图中。
		G的最大团指的是定点数最多的一个团。
	复习：
		1、最大团点的数量=补图中最大独立集点的数量
		2、二分图中，最大独立集点的数量+最小覆盖点的数量=整个图点的数量
		3、二分图中，最小覆盖点的数量=最大匹配的数量
		4、图的染色问题中，最少需要的颜色的数量=最大团点的数量
	
***/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

int Map[111][111],N;
int ret,stack[111],dp[111];
//stack:当前点的最大团集合   dp[i]:i~N-1中，最大团的大小
void dfs(int now,int num){//num for stack
	int flag;
	for(int i=now+1;i<N;i++){
		if(!Map[now][i]) continue;
		if(dp[i]+num<=ret) return;//剪枝2,显然
		
		flag=1;
		
		for(int j=0;j<num;j++)
			if(!Map[i][stack[j]]){
				flag=0;break;
			}
		if(flag){
			stack[num]=i;
			dfs(i,num+1);
		}
	}
	if(num>ret) ret=num;
}

int query()
{
	ret=0;
	for(int i=N-1;i>=0;i--){//剪枝1,从后到前，不断扩大问题规模
		stack[0]=i;
		dfs(i,1);
		dp[i]=ret;//剪枝2,dp[i]<=Count(i,N-1)
	}
	return ret;
}

int main()
{
	while(~scanf("%d",&N)&&N){
		for(int i=0;i<N;i++) for(int j=0;j<N;j++)
			scanf("%d",&Map[i][j]);
		printf("%d\n",query());
	}
	return 0;
}