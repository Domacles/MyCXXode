#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int maxn = 1000100;
int Primer[maxn],K[1111];
int pnum=0,Prim[maxn/10];
char str[1111];
int num=0;

void init()
{
	pnum=0;
	memset(K,0,sizeof(K));
	for(int i=2;i<maxn;i++){
		if(Primer[i]) continue;
		for(int j=i+i;j<maxn;j+=i)
			Primer[j]=1;
		Prim[pnum++]=i;
	}
}

void GetK()
{
	int len=strlen(str);
	for(int i=len-1;i>=0;i-=3){
		int x=0;
		for(int j=2;j>=0;j--){
			x*=10;
			if(i-j>=0) x+=str[i-j]-'0';
		}
		K[num++]=x;
	}
/*
	for(int i=num-1;i>=0;i--){
		if(i==num-1) {cout<<K[i];continue;}
		if(K[i]<1000)
			if(K[i]<100)
				if(K[i]<10)
					cout<<"000"<<K[i];
				else cout<<"00"<<K[i];
			else cout<<"0"<<K[i];
		else cout<<K[i];
		cout<<" "<<endl;
	}
*/
}

void Action(int N)
{
	int pmin=0;
	while(Prim[pmin]<N&&pmin<pnum){
		int last=0;
		for(int i=num-1;i>=0;i--)
			last=(last*1000+K[i])%Prim[pmin];
		if(last==0){
			printf("BAD %d\n",Prim[pmin]);return;
		}
		else pmin++;
	}
	printf("GOOD\n");
}

int main(){
	int N;init();
	while(~scanf("%s%d",str,&N)){
		if(!N) break;
		num=0,GetK();
		Action(N);
	}
	return 0;
}