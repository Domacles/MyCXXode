/*****
1：把沟通分成向左和向右，向左就是：v[右] > v[左]，它们之间取右边牛的声调。
2：先求向左的总能量：运用2个树状数组，都以牛的声调做下标，arNum[]用于求某个声调范围内牛的数量，arDis[]用于求某个声调范围内牛的总距离(与起点0的总距离)，这对于当前的牛(x,v)来说，用它的音调向左沟通消耗的总能量则为：v * 左边声调比它小的牛和它的距离差之和(sum(v-1, arNum)* sum(v-1, arDis)）。
3：相同的道理求出向右的总能量。
*****/
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
#define maxn 20005
#define lowbit(x) ((x)&(-x))

typedef long long ll;

struct Node{int w,x;
	Node(){}
	Node(int ww,int xx){w=ww;x=xx;}
};
vector<Node>cows;
bool operator<(Node a,Node b){return a.x<b.x;}

int sumNum[maxn],sumDis[maxn],N;

void init()
{
	memset(sumNum,0,sizeof(sumNum));
	memset(sumDis,0,sizeof(sumDis));
}
void add(int x,int val,int a[]){
	while(x<maxn){
		a[x]+=val;
		x+=lowbit(x);
	}
}
int query(int x,int a[]){
	int ans=0;
	while(x){
		ans+=a[x];
		x-=lowbit(x);
	}
	return ans;
}


int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int w,x; scanf("%d%d",&w,&x);
		cows.push_back(Node(w,x));
	}
	sort(cows.begin(),cows.end());
	ll ans=0;
	
	ll preNum=0,preDis=0;
	for(int i=0;i<N;i++){
		preNum=query(cows[i].w-1,sumNum);
		preDis=query(cows[i].w-1,sumDis);
		ans+=(ll)(preNum*cows[i].x-preDis)*cows[i].w;
		add(cows[i].w,1,sumNum);
		add(cows[i].w,cows[i].x,sumDis);
	}
	init();
	ll aftNum=0,aftDis=0;
	for(int i=N-1;i>=0;i--){
		aftNum=query(cows[i].w,sumNum);//考虑到相等的情况
		aftDis=query(cows[i].w,sumDis);
		ans+=(ll)(aftDis-aftNum*cows[i].x)*cows[i].w;
		add(cows[i].w,1,sumNum);
		add(cows[i].w,cows[i].x,sumDis);
	}
	printf("%I64d\n",ans);
	return 0;
}