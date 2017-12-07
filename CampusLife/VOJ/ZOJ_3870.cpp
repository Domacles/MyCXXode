/********
	进栈模拟
********/
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<vector>
#include<queue>
#include<set>
using namespace std;
#define N 1005
vector<int>ans;
char mp[N][N];
int n, h[N], l[N];
int yes[N];
int Stack[N], Top;

void init(){
	ans.clear();
	memset(yes, 0, sizeof yes);
	memset(h, 0, sizeof h);
	memset(l, 0, sizeof l);
	Top = 0;
}
bool cmp(int a,int b){return a>b;}
//0-n-1 表示列 n-2n-1 表示行
void work(){
	sort(Stack, Stack+Top, cmp);
	queue<int>q;
	int i, j;
	for(int i = 0; i < Top; i++){
		q.push(Stack[i]), ans.push_back(Stack[i]); yes[Stack[i]]=-1;
	}
	Top = 0;
	while(!q.empty()){
		int u = q.front(); q.pop();
		Top = 0;
		if(u<n)
			for(j = 0; j < n; j++)
			{
				mp[j][u] = 'X';
				h[j]++;
				if(yes[j+n]!=-1 && h[j]==n)Stack[Top++] = j+n;
			}
		else {
			u-=n;
			for(j = 0; j < n; j++)
			{
				mp[u][j] = 'O';
				l[j]++;
				if(yes[j]!=-1 && l[j]==n)Stack[Top++] = j;
			}
		}
			sort(Stack, Stack+Top, cmp);
			for(i = 0; i < Top; i++)q.push(Stack[i]), yes[Stack[i]] = -1, ans.push_back(Stack[i]);
	}
	for(int i = 0; i < 2*n; i++)if(yes[i]==0){puts("No solution");return;}
	for(int i = ans.size()-1; i>=0; i--){
		int u = ans[i];
		if(u>=n)printf("R"), u-=n;
		else printf("C");
		printf("%d",u+1);
		i ? printf(" ") : puts("");
	}
}
int main(){
	int T;scanf("%d",&T);
	int i, j;
	while(T--){
		scanf("%d",&n);
		init();
		for(i=0;i<n;i++)scanf("%s",mp[i]);
		for(i=0;i<n;i++)
		{
			for(j = 0; j<n; j++)if(mp[i][j]=='X')h[i]++;
			if(h[i]==n) Stack[Top++] = i+n;
			else if(h[i]==0) yes[i+n] = -1;
		}
		for(i=0;i<n;i++)
		{
			for(j = 0; j<n; j++)if(mp[j][i]=='O')l[i]++;
			if(l[i]==n) Stack[Top++] = i;
			else if(l[i]==0) yes[i] = -1;
		}
		if(Top==0){puts("No solution");continue;}
		work();
	}
	return 0;
}
