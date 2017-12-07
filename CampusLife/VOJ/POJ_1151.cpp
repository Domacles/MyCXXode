#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define maxn 4222

struct LINE
{
	double lx,rx,y;
	int s;
	LINE(){}
	LINE(double l,double r,double y1,double s1){
		s=s1; lx=l; rx=r; y=y1;}
	bool operator <(const LINE &S) const{
		return y<S.y;
	}
};
LINE  line[maxn];
double sum[maxn];
int   flag[maxn];

int num;
double X[maxn],xx[maxn];

void Update(int p,int key,int l,int r,int rt)
{
	if(l==r)
	{
		flag[rt]+=key;
		if(!flag[rt]) sum[rt]=0;
		else sum[rt]=X[r+1]-X[l];
		return ;
	}
	int m=(l+r)>>1;
	if(p<=m) Update(p,key,lson);
	if(p> m) Update(p,key,rson);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void init()
{
	num=0;
	memset(X,0,sizeof(X));
	memset(xx,0,sizeof(xx));
	memset(sum,0,sizeof(sum));
	memset(line,0,sizeof(line));
	memset(flag,0,sizeof(flag));
}

int find(double k,int n)
{
	int l=1,r=n;
	while(l<r)
	{
		int m=(l+r)>>1;
		if(X[m]>=k) r=m;
		else l=m+1;
	}
	return r;
}

int main()
{
	int n,tcase=0;
	while(~scanf("%d",&n)&&n){
		init();

		for(int i=0;i<n;i++){
			double x1,x2,y1,y2;
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			line[++num]=LINE(x1,x2,y1, 1); xx[num]=x1;//离散化
			line[++num]=LINE(x1,x2,y2,-1); xx[num]=x2;//离散化
		}

		sort(line+1,line+1+num);//排序,扫描线
		sort(xx+1,xx+1+num);//排序 去重1

		int N=1;
		X[N]=xx[1];
		for(int i=2;i<=num;i++)//离散化 去重2
			if(xx[i]!=xx[i-1]) X[++N]=xx[i];
		//for(int i=1;i<=N;i++) cout<<"X"<<i<<"="<<X[i]<<endl;
		double ans=0;
		for(int i=1;i<num;i++){
			int l=find(line[i].lx,N);
			int r=find(line[i].rx,N);
			/***
				cout<<"L="<<l<<",R="<<r<<endl;
				cout<<"L="<<X[l]<<",R="<<X[r]<<endl;
			***/
			for(int x=l;x<r;x++)//!!!!  !!!!  !!!!
                Update(x,line[i].s,1,N-1,1);

			ans+=(line[i+1].y-line[i].y)*sum[1];//此条扫描线上的长度
		}
		printf("Test case #%d\n",++tcase);
		printf("Total explored area: %.2f\n\n",ans);
	}
	return 0;
}
