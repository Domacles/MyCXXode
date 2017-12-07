#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	double e=2.718281828;
	while(T--)
	{
		int n;
		double y;
		scanf("%d%lf",&n,&y);
		double e_y=pow(e,-y);
		double sum=1,k=1;
		for(int i=1;i<=n;i++)
		{
			k*=1.0/i;
			sum+=pow(y,i)*k;
		}
		sum*=e_y;
		printf("%.3f\n",sum);
	}
	return 0;
}