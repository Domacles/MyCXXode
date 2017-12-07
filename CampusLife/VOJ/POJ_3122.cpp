#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;
const double eps=1e-5; 
const double pi=acos(-1.0);
const int maxn = 11111;
double s[maxn];
int n,f;

bool OK(double x)
{
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=floor(s[i]/x);
	}
	if(sum>=f+1) return 1;
	else return 0;
}

int main()
{
	int T;scanf("%d",&T);
	while(~scanf("%d%d",&n,&f)){
		double sum=0,maxs=0;
		for(int i=0;i<n;i++){
			int x;scanf("%d",&x);
			s[i]=(double)x*(double)x*pi;
			sum+=s[i],maxs=max(maxs,s[i]);
		}
		double l=maxs/(f+1),r=sum/(f+1);
		while(l+eps<r){
			double mid=(l+r)/2.0;
			if(OK(mid)) l=mid;
			else r=mid;
		}
		printf("%.4lf\n",r);
	}
	return 0;
}