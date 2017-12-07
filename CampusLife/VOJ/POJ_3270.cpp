#include <cstdio>
#include <iostream>

using namespace std;
#define maxn 11000
#define Maxn 100001

int vis[maxn],cow[maxn],pos[Maxn],Min,Max,N;

void Sort()//计数排序
{
	Min=0x7fffffff,Max=0;
	for(int i=1;i<=N;i++){
		pos[cow[i]]=1;
		Min=min(Min,cow[i]);
		Max=max(Max,cow[i]);
	}
	for(int i=Min;i<=Max;i++) pos[i]+=pos[i-1];
}

int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",&cow[i]);
	Sort();
	
	/****
		在一循环节内，有两种置换方法：
		1，使用循环节内最小的cow作为媒介；
		2，使用所有cow的最小值作为媒介，先将循环节内的cow置换出去；
	****/
	int ans=0;
	for(int i=1;i<=N;i++){
		int len=0,mid=i,s=0,m=0x7fffffff;
		while(!vis[mid]){
			vis[mid]=1;
			len++;
			s+=cow[mid];
			m=min(m,cow[mid]);
			mid=pos[cow[mid]];
		}
		if(len==0) continue;
		int temp1=s+m*(len-2);//1
		int temp2=s+m+Min*(len+1);//2
		ans+=min(temp1,temp2);
	}
	printf("%d\n",ans);
	return 0;
}