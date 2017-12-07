/****
	单调栈
****/
#include<stdio.h>
#include<iostream>
using namespace std;

int stack[50010],top;
int main()
{
	int n,t,i,j,x,y,ans;
	scanf("%d%d",&n,&t);
	top=ans=0;
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		if(y<stack[top-1])
		{
			while(y<stack[top-1])
			{
				top--;
			}			
		}//添加：          不为0或当前无点
		if(y>stack[top-1]&&y!=0||top==0&&y!=0) {stack[top++]=y;ans++;}
	}
	printf("%d",ans);
}
