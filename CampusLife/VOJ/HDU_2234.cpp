#include<cstdio>
#include<iostream>

using namespace std;
int a[5][5],dept;

void Add_c(int k){//列 上加
	int temp=a[0][k];
	for(int i=0;i<3;i++) a[i][k]=a[i+1][k];
	a[3][k]=temp;
}
void Sub_c(int k){//列 下减
	int temp=a[3][k];
	for(int i=3;i>0;i--) a[i][k]=a[i-1][k];
	a[0][k]=temp;
}
void Add_r(int k){//行 上加
	int temp=a[k][0];
	for(int i=0;i<3;i++) a[k][i]=a[k][i+1];
	a[k][3]=temp;
}
void Sub_r(int k){//行 下减
	int temp=a[k][3];
	for(int i=3;i>0;i--) a[k][i]=a[k][i-1];
	a[k][0]=temp;
}

bool OK_c(){//列相同
	for(int i=0;i<4;i++){
		int count=4,h[5]={0};
		for(int j=0;j<4;j++){
			if(h[a[i][j]]) count--;
			h[a[i][j]]++;
		}
		if(count!=1) return 0;
	}
	return 1;
}

bool OK_r(){//行相同
	for(int i=0;i<4;i++){
		int count=4,h[5]={0};
		for(int j=0;j<4;j++){
			if(h[a[j][i]]) count--;
			h[a[j][i]]++;
		}
		if(count!=1) return 0;
	}
	return 1;
}

int h(){
	int r=0,c=0;
	for(int i=0;i<4;i++){
		int count=4,h[5]={0};
		for(int j=0;j<4;j++){
			if(h[a[i][j]]) count--;
			h[a[i][j]]++;
		}
		r=max(count-1,r);
	}
	for(int i=0;i<4;i++){
		int count=4,h[5]={0};
		for(int j=0;j<4;j++){
			if(h[a[j][i]]) count--;
			h[a[j][i]]++;
		}
		c=max(count-1,c);
	}
	return min(r,c);
}

bool DFS(int now)
{
	if(now+h()>dept) return 0;
	if(OK_r()||OK_c()) return 1;
	for(int i=0;i<4;i++){
		Add_c(i);if(DFS(now+1)) return 1;Sub_c(i);
		Sub_c(i);if(DFS(now+1)) return 1;Add_c(i);
	}
	for(int i=0;i<4;i++){
		Add_r(i);if(DFS(now+1)) return 1;Sub_r(i);
		Sub_r(i);if(DFS(now+1)) return 1;Add_r(i);
	}
	return 0;
}

int main()
{
	int T;scanf("%d",&T);
	while(T--){
		for(int i=0;i<4;i++) for(int j=0;j<4;j++)
			scanf("%d",&a[i][j]);
		for(dept=0;dept<=5;dept++)
			if(DFS(0)) break;
		printf("%d\n",dept==6?-1:dept);
	}
	return 0;
}