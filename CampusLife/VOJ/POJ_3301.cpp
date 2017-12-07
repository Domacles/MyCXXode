/****
	对图形进行旋转，求得在旋转角度a的情况下的最大的横坐标之差,
					最大的纵坐标之差,取两者之大为L;
	由于L满足关于a的凸性函数,所以可以使用三分法求的L的最小值;
	注: 二分法适合单调函数性质的数列,三分法适合满足凸性函数性质的序列.
****/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
#define eps 1e-8
#define pi  acos(-1.0)
#define MAX 100000000
#define MIN -100000000
double x[33],y[33];
int n;

double cal(double a)
{
	double maxx=MIN,maxy=MIN,minx=MAX,miny=MAX;
	for(int i=1;i<=n;i++){
		double xx=x[i]*cos(a)-y[i]*sin(a);//绕原点旋转后的x位置
        double yy=y[i]*cos(a)+x[i]*sin(a);//绕原点旋转后的y位置
		maxx=max(xx,maxx);
		maxy=max(yy,maxy);
		minx=min(xx,minx);
		miny=min(yy,miny);
	}
	return max(maxx-minx,maxy-miny);
}

int main()
{
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%lf%lf",&x[i],&y[i]);
		
		double l=0,r=pi,ans=0;
		//cal(x)函数图像为下凹状
		while(r-l>eps){
			double mid=(l+r)/2.0;
			double mmid=(mid+r)/2.0;
			ans=cal(mid);
			if(ans<=cal(mmid)) r=mmid;//根据函数单调性可理解
			else l=mid;
		}
		printf("%.2f\n",ans*ans);
	}
	return 0;
}