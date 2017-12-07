//选取包含点begin的区间中右端点最大的那个；若不存在包含begin的区间，输出-1
#include <vector>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

struct Cow{int l,r;};
bool operator<(Cow a,Cow b){return a.l<b.l;}

vector<Cow>cows;
int N,T;

int main()
{
	scanf("%d%d",&N,&T);
	for(int i=0;i<N;i++){
		Cow x; scanf("%d%d",&x.l,&x.r);
		cows.push_back(x);
	}
	sort(cows.begin(),cows.end());
	int l=0,r=0,last=-1,ans=0;
	while(r<T){
		bool OK=0;
		l=r+1;
		for(int i=0;i<N;i++){
			if(cows[i].l<=l && cows[i].r>r)
				r=cows[i].r , OK=1;
			else if(cows[i].l>l) break;
		}
		if(!OK) break;
		ans++;
	}
	if(r==T) printf("%d\n",ans);
	else printf("-1");
	return 0;
}