#include <cstdio>
#include <queue>
#include <vector>
#include <stack>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int a[1111],N,D,K;
vector<int>s;

void GetS(){
	for(int i=0;i<(1<<D);i++){
		int x=i,sum=0;
		while(x){
			if(x&1) sum++;
			x>>=1;
		}
		if(sum<=K) s.push_back(i);
	}
}

int Max(){
	int val=0;
	for(int i=0;i<(int)s.size();i++){
		int temp=0;
		for(int j=0;j<N;j++)
			if((s[i]|a[j])==s[i]) temp++;
		val=max(val,temp);
	}
	return val;
}

int main()
{
	scanf("%d%d%d",&N,&D,&K);	
	for(int i=0;i<N;i++){
		int n; scanf("%d",&n);
		for(int j=0;j<n;j++){
			int x; scanf("%d",&x);
			a[i]|=(1<<(x-1));
		}
	}
	GetS();
	printf("%d\n",Max());
	return 0;
}