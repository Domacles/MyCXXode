#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
struct Point{
	double x,y;
	Point(){}
	Point(double xx,double yy){x=xx;y=yy;}
}b,d;
int N;
char  Map[211][211];
//正方形
void DoneSq(Point a,Point c)
{//已知a c,求b d
    double x,y,mx,my;
    mx = (a.x+c.x)/2.0, my = (a.y+c.y)/2.0;     
    x = a.x-mx;   y = a.y-my;
    b.x = y+mx;   b.y = x+my;
    x = c.x-mx;   y = c.y-my;
    d.x = y+mx;   d.y = x+my;
}

int main()
{
	//freopen("D:\\bigsq\\bigsq.5.in","r",stdin);
	//freopen("D:\\bigsq1\\bigsq.4.out","w",stdout);
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%s",Map[i]+1);
	
	double ans=0;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++){
			if(Map[i][j]!='J') continue;
	for(int p=N;p>=i;p--) for(int q=N;q>0;q--){
			if(Map[p][q]!='J') continue;
			if(p==i&&q==j)     continue;
			
			Point a,c;    
			a.x=i; a.y=j; c.x=p; c.y=q;
			b=a,d=c;
			if(((b.x-d.x)*(b.x-d.x)+(b.y-d.y)*(b.y-d.y))/2.0 <= ans) continue;
			
			//tx:=(i+p)/2;ty:=(j+q)/2;
            //x1:=i-tx;x2:=p-tx;y1:=j-ty;y2:=q-ty;
			double x,y,mx,my;
			mx=(a.x+c.x)/2,my=(a.y+c.y)/2;
			x = a.x-mx;    y = a.y-my;
			b.x =-y+mx;    b.y = x+my;
			x = c.x-mx;    y = c.y-my;
			d.x =-y+mx;    d.y = x+my;
			
			int x1=(int)b.x, x2=(int)d.x, y1=(int)b.y, y2=(int)d.y;
			if(b.x-x1>=1e-6 || d.x-x2>=1e-6 || 
			   b.y-y1>=1e-6 || d.y-y2>=1e-6)       continue;
			if(x1<1 || x1>N || x2<1 || x2>N)       continue;
			if(y1<1 || y1>N || y2<1 || y2>N)       continue;
			if(Map[x1][y1]=='B'||Map[x2][y2]=='B') continue;
			if(Map[x1][y1]=='*'&&Map[x2][y2]=='*') continue;
			ans=max(((b.x-d.x)*(b.x-d.x)+(b.y-d.y)*(b.y-d.y))/2.0,ans);
			//cout<<i<<","<<j<<"  "<<p<<","<<q<<endl;
			//cout<<b.x<<","<<b.y<<"  "<<d.x<<","<<d.y<<endl;
			//cout<<x1<<","<<y1<<"  "<<x2<<","<<y2<<endl;
			//printf("%lf\n",((b.x-d.x)*(b.x-d.x)+(b.y-d.y)*(b.y-d.y))/2.0);
		}
	}
	printf("%.0f\n",ans);
	return 0;
}