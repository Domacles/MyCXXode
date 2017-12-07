/****
该题的关键是如果a%n = x;
则(a*10+b)%n == (x*10+b)%n。
例如你要算123456789%3，你只需算((12345678%n)*10+9)%3。

BFS+CuT
**************************
POJ TLE
**************************
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
#define maxn 1000000
int pre[maxn],now[maxn],vis[maxn];
int q[maxn],top,tail;
int M,n,a[maxn];

void init()
{
	memset(pre,0,sizeof(pre));
	memset(vis,0,sizeof(vis));
	memset(now,0,sizeof(now));
	memset(q,0,sizeof(q));
	top=tail=0;
}

void print(int x)
{
	if(pre[x]!=0) print(pre[x]);
	printf("%d",now[x]);
}

int main()
{
	while(~scanf("%d%d",&M,&n))
	{
		init();
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		sort(a,a+n);
		if(M==0)
		{
			puts("0");
			continue;
		}
		for(int i=0;i<n;i++)
			if(a[i])
			{
				if(!vis[a[i]%M]){
					q[tail++]=a[i]%M;
					now[a[i]%M]=a[i];
				}
				vis[a[i]%M]=1;
			}
		while(top<tail)
		{
			int Now=q[top++];
			for(int i=0;i<n;i++)
			{
				if(!vis[(a[i]+Now*10)%M])
				{
					vis[(a[i]+Now*10)%M]=1;
					now[(a[i]+Now*10)%M]=a[i];
					pre[(a[i]+Now*10)%M]=Now;
					q[tail]=(a[i]+Now*10)%M;
					if(vis[0]) break;
					else tail++;	
				}
			}
			if(vis[0]) break;
		}
		if(vis[0])
		{
			print(q[tail]);
			printf("\n");
		}
		else
			printf("0\n");
	}
	return 0;
}
****/
/********
G++ TLE
********/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<cstring>
#include<set>
#include<string>
#include<cmath>
#include<algorithm>
#define LL long long
 
using namespace std;
 
const int N=1005;
bool had[N*5];//标记是否此余数是否出现过
string a[12];
queue<string>str;//防止大整数情况
int MOD(string s,int n)//求余数
{
    int k=0;
    for(int i=0;i<s.size();++i)
        k=(k*10+s[i]-'0')%n;
    return k;
}
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        while(!str.empty()) str.pop();
        memset(had,false,sizeof(had));
        for(int i=0;i<m;++i)
            cin>>a[i];
        
        if(n==0)//0 要特判
        {
            printf("0\n");
            continue;
        }
        sort(a,a+m);//排序
        string ans="0";
        int i;
        for(i=0;i<m;++i)
        {
            if(a[i]!="0")
            {
                int l=MOD(a[i],n);
                if(l==0)//余数为0 的话直接跳出循环
                {
                    ans=a[i];
                    break;
                }
                if(!had[l])//去重
                {
                    had[l]=true;
                    str.push(a[i]);
                }
            }
        }
        if(i>=m)//需要继续广搜
        while(!str.empty())
        {
            string x=str.front();
            str.pop();
            int j;
            for(j=0;j<m;++j)
            {
                string k=x+a[j];
                int l=MOD(k,n);
                if(had[l]==false)//余数不能重
                {
                    had[l]=true;
                    if(l==0)//发现合适的 知道跳出循环
                    {
                        ans=k;
                        break;
                    }
                    str.push(k);
                }
            }
            if(j<m)
            break;
        }
        cout<<ans<<endl;
    }
    return 0;
}