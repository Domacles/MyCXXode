#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
#define maxn 222
int N,f[maxn],next[maxn];

void Getf()//每一位的循环数 总的循环数为LCM
{
	for(int i=1;i<=N;i++) scanf("%d",&next[i]);
	for(int i=1;i<=N;i++){
		int j=next[i],count=1;
		while(i!=j){
			count++;
			j=next[j];
		}
		f[i]=count;
	}
}

int main()
{
	while(~scanf("%d",&N)&&N){
		Getf();
		int  len,time;
		char str[555];
		char ans[555];
		while(~scanf("%d",&time)&&time){
			getchar();
			gets(str+1);
			len=strlen(str+1);
			for(int i=len+1;i<=N;i++) str[i]=' ';
			
			memset(ans,0,sizeof(ans));
			
			for(int i=1;i<=N;i++){
				int pos=i;
				for(int j=1;j<=time%f[i];j++)
					pos=next[pos];
				ans[pos]=str[i];
			}
			puts(ans+1);
		}
		puts("");
	}
	return 0;
}