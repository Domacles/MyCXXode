/**题目：给定一个长为n的串，问：它的前缀(长度至少为2)中有多少是由相同的子串连续连接形成的，输出前缀长度及连续子串最大连续数**/
/**KMP 同上题的思路,枚举前缀即可**/
#include <iostream>
#include<cstdio>
#include<cstring>

using namespace std;
#define maxn 1000010

char s[maxn];
int n;
int next[maxn];
void GetNext()
{
    int i=0,j=-1;
    next[0]=-1;
    while(i<n)
    {
        if(j==-1||s[i]==s[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else
            j=next[j];
    }
}

int main()
{
    int testCase=1;
    while(scanf("%d",&n)!=EOF&&n)
    {
        scanf("%s",s);
        GetNext();
        printf("Test case #%d\n",testCase++);
        for(int i=2;i<=n;i++)//枚举前缀
             if(next[i]!=0&&i%(i-next[i])==0)
                 printf("%d %d\n",i,i/(i-next[i]));
         printf("\n");
    }
    return 0;
}
