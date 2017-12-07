#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;
int N,mins,ansk=1,a[5555];

int sum[5555];
int lowbit(int x){return (-x)&x;}
int query(int x){
	int val=0;
	while(x>0){
		val+=sum[x];
		x-=lowbit(x);
	}
	return val;
}
void update(int x,int k){
	while(x<=N){
		sum[x]+=k;
		x+=lowbit(x);
	}
}

int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		char s[3];scanf("%s",s);
		if(s[0]=='B') a[i]=1,mins++;
	}
	for(int len=2;len<=N;len++){
		int temp=0;
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=N-len+1;i++)//N-len+1为最后一段的起点
			if((a[i]+query(i))&1){//此处需要反转
				temp++;
				update(i,1);
				update(i+len,-1);
			}
		for(int i=N-len+2;i<=N;i++)
			if((a[i]+query(i))&1){
				temp=0x7fffffff;
				break;
			}
		if(mins>temp)
			ansk=len,mins=temp;
	}
	printf("%d %d\n",ansk,mins);
	return 0;
}