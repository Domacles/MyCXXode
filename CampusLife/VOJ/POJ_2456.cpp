#include <cstdio>
#include <queue>
#include <vector>
#include <stack>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N,C;
vector<int>dis;

int solve(int X)
{
	int cnt = 1 , cur = dis[0];  
    for(int i=1;i<N;i++)  
    {  
        while(i<N && dis[i]-cur<X) i++;  
        cur = dis[i];  
        if(i<N && ++cnt == C)  
            return 1;  
    }  
    return 0; 
}

int main()
{
	scanf("%d%d",&N,&C);
	for(int i=0;i<N;i++){
		int x; scanf("%d",&x);
		dis.push_back(x);
	}
	sort(dis.begin(),dis.end());
	int lmin=0x7fffffff;
	for(int i=0;i<N;i++)
		if(i) lmin=min(lmin,dis[i]-dis[i-1]);
	int l=lmin,r=dis[N-1]-dis[0];
	while(l<r){
		int mid=(l+r)>>1;
		if(solve(mid)) l=mid+1;//ans向小的取值，此为本题二分的不同
		else r=mid;
	}
	printf("%d\n",l-1);
	return 0;
}