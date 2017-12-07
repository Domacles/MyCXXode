#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

struct Cow{int minSPF,maxSPF;} cow[2555];
struct Bottle{int SPF,num;} B[2555];
int cmp1(Cow a,Cow b){return a.maxSPF<b.maxSPF;}//按最大值排序
int cmp2(Bottle a,Bottle b){return a.SPF<b.SPF;}

int C,L;

int main()
{
	while(~scanf("%d%d",&C,&L)){
		for(int i=0;i<C;i++) scanf("%d%d",&cow[i].minSPF,&cow[i].maxSPF);
		sort(cow,cow+C,cmp1);
		
		for(int i=0;i<L;i++) scanf("%d%d",&B[i].SPF,&B[i].num);
		sort(B,B+L,cmp2);
		
		int ans=0;
		for(int i=0;i<C;i++)
			for(int j=0;j<L;j++){
				if(cow[i].minSPF<=B[j].SPF&&B[j].SPF<=cow[i].maxSPF&&B[j].num)
				{ans++;B[j].num--;break;}
				if(B[j].SPF>cow[i].maxSPF) break;
			}
		printf("%d\n",ans);
	}
	return 0;
}