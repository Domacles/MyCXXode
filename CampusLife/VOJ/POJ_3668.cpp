/************
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <cmath>

using namespace std;
#define INF 0x3fffffff
struct Node{int x,y;
	Node(){}
	Node(int xx,int yy){x=xx;y=yy;}
};
vector<Node>a;
int hash[2][2020][2020],hx0,hy0;
int N;

int gcd(int x,int y)
{
	if(x<y) swap(x,y);
	while(y){
		int t=y;
		y=x%y; x=t;
	}
	return x;
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		a.push_back(Node(x,y));
	}
	for(int i=0;i<N;i++) for(int j=i+1;j<N;j++){
		int d=1, flag=0, x1=a[i].x, x2=a[j].x, y1=a[i].y, y2=a[j].y;
		int dx=x2-x1,dy=y2-y1;
		if(dx==0){
			hx0++;continue;
		}
		if(dy==0){
			hy0++;continue;
		}
		
		if(dx*dy<0) 
			flag=1;
		dx=abs((double)dx),dy=abs((double)dy);
		if(dx>0&&dy>0) 
			d=gcd(dx,dy);
		dx/=d,dy/=d;
		hash[flag][dx][dy]++;
	}
	int sum=0;
	for(int flag=0;flag<2;flag++)
		for(int i=1;i<2020;i++) for(int j=1;j<2020;j++)
			if(hash[flag][i][j])
				sum++;
	if(hx0) sum++;
	if(hy0) sum++;
	printf("%d\n",sum);
	return 0;
}
//AC
***********/
#include <cstdio>
#include <cstdlib>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
#define F(i,m,n) for (int i = m; i < n; ++i)
typedef pair<int, int> PII;
set<PII> lines;
int x[202], y[202];

int main() {
	int dx, dy, N;

	while (scanf("%d", &N) == 1) {
		lines.clear();
		F(i, 0, N) scanf("%d %d", &x[i], &y[i]);
		F(i, 0, N-1) F(j, i+1, N) {
			dx = x[j] - x[i], dy = y[j] - y[i];
			int gcd = __gcd(dx, dy);
			dx /= gcd, dy /= gcd;
			lines.insert(PII(dx, dy));
		}
		printf("%lu\n", lines.size());
	}

	return 0;
}
