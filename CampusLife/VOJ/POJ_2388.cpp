#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
vector<int>a;
int N;

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int x; scanf("%d",&x);
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	printf("%d\n",a[N/2]);
	return 0;
}