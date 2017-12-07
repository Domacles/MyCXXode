/***
	第一问，符合最小表示法的定义，解之。
	（循环字符串的最小表示法的问题可以这样描述：
    	对于一个字符串S，求S的循环的同构字符串S’中字典序最小的一个。）
	第二问，
		假设某串是由子串s连续连接而成，如P=sssssss....s，p.len=N，s.len=n;
		显然，对于任何P的循环字符串，任何一种出现的次数为N/n.
		证，只有这种情况才会使第二问答案大于1，
		举例：   aba：  aba  1
						aab  1
						baa  1
		同样的，在此例上继续扩展，会发现含有这种串的不同于P的串出现次数仅为1.
***/
#include <string>
#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;
#define maxn 1000005 
int next[maxn];
//string s,p;//s-匹配串    p-模式串
char p[maxn];
int n;//p->len

void GetNext()//next[maxn]  p[maxn]
{
    int j=0,k=-1;
    next[0]=-1;
    while(j<n)
    {
        if(k==-1||p[j]==p[k]){
            k++,j++;
            next[j]=k;
        }
        else k=next[k];
    }
}


int MMR(string s, bool bMin=true)//默认最小表示法
{
    int i=0, j=1, k=0, l=s.length(), sub=0;
    while (i<l && j<l && k<l){
        sub=s[(i+k)%l]-s[(j+k)%l];
        if(sub==0) k++;
        else{
            if(bMin? sub>0:sub<0)  i+=k+1;
            else j+=k+1;
            if(i==j) j++;
            k=0;
        }
    }
    return i<j?i:j;
}


void init(){
	memset(next,0,sizeof(next));
	n=strlen(p);
}

void solve()
{
	GetNext();
	int ans=1;
	if(n%(n-next[n])==0) 
		ans=n/(n-next[n]);//后缀==前缀，可递推
	printf("%d %d %d %d\n",MMR(p)+1,ans,MMR(p,0)+1,ans);
}

int main()
{
	while(~scanf("%s",p)){
		init();
		solve();
	}
	return 0;
}