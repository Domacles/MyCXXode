/***
		KMP
***/
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int maxn =  1100000;
int next[maxn],S[maxn],P[maxn],slen,plen;

void init()
{
	memset(next,0,sizeof(next));
	memset(S,0,sizeof(S));
	memset(P,0,sizeof(P));
}

void GetNext(){
	int i=0,j=-1;
	next[0]=-1;
	while(i<plen){
		if(j==-1 || P[i]==P[j])
			++i,++j,next[i]=j;
		else
			j=next[j];
	}
}

int KMP(){
	GetNext();
	int i=0,j=0;
	while(i<slen && j<plen){
		if(j==-1 || S[i]==P[j])
			i++,j++;
		else
			j=next[j];

	}
	if(j>=plen) return i-plen+1;
	else return -1;
}
