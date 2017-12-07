/*
    Author: xiaodao
    Prog: ZOJ 2612. Stable Sets
    Status: Accepted
    Last modifiy: GMT +8 Aug. 29th 17:49
	http://blog.sina.com.cn/s/blog_778e7c6e0100q64k.html
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include "bignum.h"
using namespace std;
const int N = 101;
int A[N], n; int P[N];
int r; bignum ans;

int Find(int x){
    if ( P[x] != x ) P[x] = Find(P[x]) ;
    return P[x];
}

void Union(int x,int y){
    x = Find(x); y = Find(y);
    if (x < y) P[x] = y ; // # 
    else P[y] = x;
}

int p(int x){
    int res = 0;
    for (int i=n;i>=0;i--)
        res = ((res * x) + A[i]) % r;
    return res;
}

void input(){
    scanf("%d", &n);
    for (int i=n;i>=0;i--)
        scanf("%d", &A[i]);

    int in[N];
    memset(in, 0, sizeof(in));
    for (int i=0;i<r;i++) in[p(i)]++;

    int L = 0, R = 0, Q[N];
    for (int i=0;i<r;i++)
        if (in[i]==0) Q[R++] = i;
    while (L<R){
        int x = p(Q[L]); in[x]--;
        if (in[x]==0) Q[R++] = x;
        L++;
    }

    for (int i=0;i<R;i++)
        Union(Q[i], r);
    for (int i=0;i<r;i++)
        if (in[i]!=0 && Find(i)!=r) Union(i, p(i));
}

void stat(){
    int component = 0;
    for (int i=0;i<r;i++ )
        if (P[i]==i) component++;
    ans = pow(2, component);
}

void init(){
    for (int i=0;i<=r;i++)
        P[i] = i;
}

int main(){
    while (cin >> r && r>0){
        init(); input(); input(); stat();
        cout << ans << endl;
    }
}