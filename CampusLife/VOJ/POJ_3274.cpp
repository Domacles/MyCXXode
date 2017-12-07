
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int MAXHASH = 100003;
int n,k,f;
int bit[100003][32];
int head[MAXHASH],next[100003];//拉链法处理冲突，只需维护表头和next指针即可
int hash(int v[])
{
	int h = 0;
	for(int i = 0; i < k; i++)
		h = ((h<<2) + (v[i]>>4)) ^ (v[i]<<10);
	h = h % MAXHASH;
	h = h < 0 ? h + MAXHASH : h;
	return h;
}
int main()
{
	scanf("%d%d",&n,&k);
	memset(bit,0,sizeof(bit));
	memset(head,-1,sizeof(head));
	int ans = 0;
	for(int i = 1;i <= n;++i)
	{
		scanf("%d",&f);
		for(int j = 0;j < k;++j)
		{
			bit[i][j] = f & 1;
			f = f >> 1;
		}
	}
	for(int i = 2;i <= n;++i)
		for(int j = 0;j < k;++j)
			bit[i][j] += bit[i-1][j];
	for(int i = 0;i <= n;++i)
	{
		int temp = bit[i][0];
		for(int j = 0;j < k;++j)
			bit[i][j] -= temp;
		int h = hash(bit[i]);
		bool Find = 0;
		for(int e = head[h];e != -1;e = next[e])
		{
			if(memcmp(bit[e],bit[i],sizeof(bit[i])) == 0)
			{
				ans = max(ans,i - e);
				Find = 1;
				break;
			}
		}
		if(!Find)
		{
			next[i] = head[h];
			head[h] = i;
		}
	}	
	printf("%d\n",ans);
	return 0;
}