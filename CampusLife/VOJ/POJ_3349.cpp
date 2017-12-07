#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<string>
#include<stack>
#include<cmath>
#include<cctype>
#include<iostream>
#include<set>
#include<algorithm>
#include<ctime>
#include<vector>
using namespace std;
#define mem(a) memset(a,0,sizeof(a))
#define MAXN 1000007
int hash[MAXN],next[MAXN];
int snow[100007][6];
bool isfind;
bool judge(int a,int b)//比较下标为a,b的两片雪花是否相同
{
    int i,j,k;
    for(i=0;i<6;i++)
    {
        for(j=i,k=0;k<6;k++,j=(j+1)%6)//顺时针，有一点点小技巧
            if(snow[a][k]!=snow[b][j])break;
        if(k==6)return true;
        for(j=i,k=0;k<6;k++,j=(j+5)%6)//逆时针
            if(snow[a][k]!=snow[b][j])break;
        if(k==6)return true;
    }
    return false;
}

bool try_to_insert(int a[],int index)
{
    int i,u;
    int x=0;
    for(i=0;i<6;i++)//哈希    采用平方取模的方法
        x=(int)((((long long)a[i]*(long long)a[i])+x)%MAXN);
    u=hash[x];//hash里面放的是index，即数组的下标，x作为下标，可用于快速查找
    while(u)
    {
        if(judge(index,u))return false;
        u=next[u];
    }
    next[index]=hash[x];//把下标用next链接起来
    hash[x]=index;//新的下标作为表头
    return true;
}
int main()
{
    int n,j,i;
    while(~scanf("%d",&n))
    {
        for(i=1;i<=n;i++)
            for(j=0;j<6;j++)
                scanf("%d",&snow[i][j]);
        isfind=false;
        mem(next);mem(hash);i=1;
        while(try_to_insert(snow[i],i)&&i<=n)
        {
            i++;
        }
        if(i==n+1)printf("No two snowflakes are alike.\n");
        else printf("Twin snowflakes found.\n");
    }
    return 0;
}