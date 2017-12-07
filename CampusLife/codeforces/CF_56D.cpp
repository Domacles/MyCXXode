/****
	未阅
****/
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
int lenA,lenB;
char A[1001],B[1001];
int  dp[1001][1001];
bool vis[1001][1001];

int calc(int i,int j)
{
    if(i==lenA && j==lenB) return 0;
    if(!vis[i][j])
	{
        vis[i][j]=true;
        dp[i][j]=1024;
        if(i<lenA && j<lenB)
		{
            if(A[i]==B[j])
                dp[i][j]=min(dp[i][j],calc(i+1,j+1));
            else
			{
                dp[i][j]=min(dp[i][j],1+calc(i+1,j+1));
                dp[i][j]=min(dp[i][j],1+calc(i,j+1));
                dp[i][j]=min(dp[i][j],1+calc(i+1,j));
            }
        }else if(i<lenA)
            dp[i][j]=min(dp[i][j],1+calc(i+1,j));
        else
            dp[i][j]=min(dp[i][j],1+calc(i,j+1));
    }
    return dp[i][j];
}
void print(int i,int j,int h)
{
    if(i==lenA && j==lenB)
        return;
    if(i<lenA && j<lenB)
	{
        if(A[i]==B[j] && dp[i][j]==calc(i+1,j+1))
            print(i+1,j+1,h);
        else if(dp[i][j]==1+calc(i+1,j+1))
		{
            printf("REPLACE %d %c\n",i+h,B[j]);
            print(i+1,j+1,h);
        }else if(dp[i][j]==1+calc(i,j+1))
		{
            printf("INSERT %d %c\n",i+h,B[j]);
            print(i,j+1,h+1);
        }else
		{
            printf("DELETE %d\n",i+h);
            print(i+1,j,h-1);
        }
    }else if(i<lenA)
	{
        printf("DELETE %d\n",i+h);
        print(i+1,j,h-1);
    }else
	{
        printf("INSERT %d %c\n",i+h,B[j]);
        print(i,j+1,h+1);
    }
}
int main()
{
    gets(A);
    gets(B);
    lenA=strlen(A);
    lenB=strlen(B);
    printf("%d\n",calc(0,0));
    print(0,0,1);
    return 0;
}