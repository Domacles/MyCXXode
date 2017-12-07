/**
1、在某个城市 i，1点攻击力能获得的最大钱数 和 1块钱能获得的最大钱数 与 当前拥有的钱数和攻击力 是无关的。
2、钱和攻击力能获得的最大钱数可以分开考虑。
令 att_m[i] 表示带着 1点攻击力 进入城市 i 能获得的最大钱数，mon_m[i] 表示带着 1块钱 进入城市 i 能获得的最大钱数。
初始值：  att_m[n] = b[n] 	, 	mon_m[n] = max(1,1.0/a[n] * b[n])。
转移方程：att_m[i] = mon_m[i+1] * b[i] + att_m[i+1] ，
		  mon_m[i] = max(mon_m[i+1],1.0/a[i] * (b[i] * mon_m[i+1] + att_m[i+1]))。
**/
#include <stdio.h>

const int maxn = 110000;
double a[maxn],b[maxn],X,Y;
double Att_ave[maxn],Mon_ave[maxn];

double max(double a,double b){return a>b?a:b;}

int main()
{
	int n;
	while(~scanf("%d%lf%lf",&n,&X,&Y)){
		for(int i=1;i<=n;i++) scanf("%lf%lf",&a[i],&b[i]);
		Att_ave[n]=b[n]	,  Mon_ave[n]=max(1.0,1.0/a[n]*b[n]);
		for(int i=n-1;i>=1;i--){
			Att_ave[i]= Mon_ave[i+1]*b[i] + Att_ave[i+1];
			Mon_ave[i]=max(Mon_ave[i+1] , 1.0/a[i]*Att_ave[i]);
		}
		printf("%.2f\n",X*Mon_ave[1] + Y*Att_ave[1]);
	}
	return 0;
}