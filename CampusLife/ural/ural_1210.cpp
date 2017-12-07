/***
    0~N²ãµÄ×î¶ÌÂ·£¬dp
****/
#include <queue>
#include <stack>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAX = 35;
int dp[MAX];
int dpp[MAX];
int lev;
int main()
{
	int ind,cost,l;
	char str[5];
	scanf("%d",&lev);
	dpp[1] = 0;
	for(int i=1; i<=lev; i++)
	{
		for(int k=0; k<MAX; k++)
			dp[k] = INT_MAX;
		scanf("%d",&l);
		for(int k=1; k<=l; k++)
			while( scanf("%d",&ind) && ind )
			{
				scanf("%d",&cost);
				if( dp[k] > dpp[ind] + cost )
					dp[k] = dpp[ind] + cost;
			}
		if( i != lev ) scanf("%s",str);
		memcpy(dpp,dp,sizeof(dp));
	}
	int mmin = INT_MAX;
	for(int i=1; i<=l; i++)
		if( dpp[i] < mmin )
			mmin = dpp[i];
	printf("%d\n",mmin);
return 0;
}
