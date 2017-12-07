#include <cstdio>
#include <iostream>

using namespace std;
const int maxn = 11114;
int ans[maxn];

int gcd(int a,int b)
{
	while(b){
		int t=b;
		b=a%b; a=t;
	}
	return a;
}

void init()
{
	for(int i=2;i<=10000;i++)
		for(int j=1;j<i;j++){
			if(gcd(i,j)==1)
				ans[i]++;
		}
}

int main()
{
	//freopen("/home/domacles/Code/input.txt","r",stdin);
	int n;
	//init();
	while(cin>>n){
		//cout<<ans[n]<<endl;
		int temp=0;
		for(int i=1;i<n;i++){
			if(gcd(n,i)==1)	temp++;
		}
		cout<<temp<<endl;
	}
	return 0;
}
