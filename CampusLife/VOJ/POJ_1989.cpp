/***
如果存在其有包括全排序的一个最小组合，(1,2,...n),(次序不限，只要有1...n的数字就行了,也有可能有重复数字)
找到其所有这样组合。可合成()()()...()[],( 设有k个括号,[]里的元素可能为空)
则其最短的非子序长度为k+1;
原因：
长度为k的子序,都可由前k个括号里抽出一个数组成。
但对于k+1,就找不到一个组合,因为最后一个组合里少了需要的最后一个数。
***/
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
#define maxn 11111
int N,K,ans,f[maxn],num;
void init()
{
	memset(f,0,sizeof(f));
	num=0;
}
int main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++){
		int x;scanf("%d",&x);
		if(!f[x]) f[x]=1,num++;
		if(num==K) init(),ans++;
	}
	printf("%d\n",ans+1);
	return 0;
}