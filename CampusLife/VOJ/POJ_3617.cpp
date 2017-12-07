#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;
#define maxn 11111
typedef long long ll;

int main()
{
	int N,l,r,s=0;
	string cow="";
	scanf("%d",&N);
	l=0,r=N-1;
	for(int i=0;i<N;i++){
		char c[2];
		scanf("%s",c);
		cow+=c[0];
	}
	while(l<=r){
		bool flag=0;
		for(int i=0;l+i<=r;i++)
			if(cow[l+i]<cow[r-i]){
				flag=1;break;
			}
			else if(cow[l+i]>cow[r-i]){
				flag=0;break;
			}
		s++;
		if(flag)
			printf("%c",cow[l++]);
		else 
			printf("%c",cow[r--]);
		if(s%80==0) printf("\n");
	}
	return 0;
}