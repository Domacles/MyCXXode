/***
	���������
		һ������ͼ G=(V��E)��V �ǵ㼯��E �Ǳ߼���ȡ V ��һ���Ӽ� U��
		������ U ������������ u �� v���б� (u,v)��E����ô�� U �� G ��һ����ȫ��ͼ��
		U ��һ���ŵ��ҽ��� U ����������һ���������ȫ��ͼ�С�
		G�������ָ���Ƕ���������һ���š�
	��ϰ��
		1������ŵ������=��ͼ�����������������
		2������ͼ�У����������������+��С���ǵ������=����ͼ�������
		3������ͼ�У���С���ǵ������=���ƥ�������
		4��ͼ��Ⱦɫ�����У�������Ҫ����ɫ������=����ŵ������

***/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

int Map[111][111],N;
int ret,stack[111],dp[111];
//stack:��ǰ�������ż���   dp[i]:i~N-1�У�����ŵĴ�С
void dfs(int now,int num){//num for stack
	int flag;
	for(int i=now+1;i<N;i++){
		if(!Map[now][i]) continue;
		if(dp[i]+num<=ret) return;//��֦2,��Ȼ

		flag=1;

		for(int j=0;j<num;j++)
			if(!Map[i][stack[j]]){
				flag=0;break;
			}
		if(flag){
			stack[num]=i;
			dfs(i,num+1);
		}
	}
	if(num>ret) ret=num;
}

int query()
{
	ret=0;
	for(int i=N-1;i>=0;i--){//��֦1,�Ӻ�ǰ���������������ģ
		stack[0]=i;
		dfs(i,1);
		dp[i]=ret;//��֦2,dp[i]<=Count(i,N-1)
	}
	return ret;
}

int main()
{
	while(~scanf("%d",&N)&&N){
		for(int i=0;i<N;i++) for(int j=0;j<N;j++)
			scanf("%d",&Map[i][j]);
		printf("%d\n",query());
	}
	return 0;
}
