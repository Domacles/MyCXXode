#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
int in[10000];

using namespace std;

int main()
{
	int n;
	long long sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			sum+=abs(in[i]-in[j]);
		}
	}
	printf("%I64d\n",sum*2);
	return 0;
}