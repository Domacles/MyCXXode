/***
	并查集
***/
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
#define maxn 11111
int dx[]={-1,-1,0, 1};
int dy[]={0,-1,-1,-1};
int f[maxn],Map[111][111],num,N,M;

void init()
{
	for(int i=0;i<maxn;i++) f[i]=i;
}

int Find(int x){
	if(f[x]!=x) f[x]=Find(f[x]);
	return f[x];
}

void Union(int x,int y){
	int X=Find(x);
	int Y=Find(y);
	if(X==Y) return;
	f[X]=f[Y]=min(X,Y);
	num--;
}

int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++){
		char s[111]; scanf("%s",s);
		for(int j=0;j<M;j++){
			if(s[j]=='W') Map[i][j]=1,num++;
		}
	}
	init();
	for(int i=0;i<N;i++) for(int j=0;j<M;j++){
		if(!Map[i][j]) continue;
		for(int k=0;k<4;k++){
			int x=i+dx[k] , y=j+dy[k];
			if(x<0 || y<0 || x>=N || y>=M) continue;
			if(Map[x][y]) Union(i*M+j,x*M+y);
		}
	}
	printf("%d\n",num);
	return 0;
}