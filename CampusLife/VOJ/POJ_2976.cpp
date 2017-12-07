#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
using namespace std;

const int kMAX=10010;
const double kEPS=10E-5;
int n,m,ncase=1;
double num[kMAX],den[kMAX],scores[kMAX];

int main()
{
	while(~scanf("%d%d",&n,&m) && (m+n))
	{
		for(int i=0;i<n;++i)
			scanf("%lf",&num[i]);
		for(int i=0;i<n;++i)
			scanf("%lf",&den[i]);


		double lhs=0,rhs=1.0;

		while(lhs+kEPS<rhs)
		{
			double x=(lhs+rhs)/2;
			for(int i=0;i<n;i++)
				scores[i]=num[i]-den[i]*x;//因为非精确值，不需要用到dp
			sort(scores,scores+n);//贪心即可
			double total=0.0;
			for(int i=m;i<n;i++)
				total+=scores[i];
			if(total>=0.0)
				lhs=x;
			else
				rhs=x;
		}
		printf("%d\n",int(100*lhs+0.5));
	}

	return 0;
}