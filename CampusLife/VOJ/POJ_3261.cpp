/*****
	给定一个序列，从中选择重复次数大于k次的的最长可重叠子段
*****/
#include <stdio.h>
#include <string.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 1000010


int n,renum,arr[MAX],brr[MAX];
int wn[MAX],wv[MAX],wa[MAX],wb[MAX];
int sa[MAX],rank[MAX],h[MAX];


int cmp(int *r,int a,int b,int l) {

	return r[a] == r[b] && r[a+l] == r[b+l];
}
void Da(int *r,int n,int m) {//后缀数组

	int i,j,k,p;
	int *x = wa,*y = wb,*t;


	for (i = 0; i < m; ++i) wn[i] = 0;
	for (i = 0; i < n; ++i) wn[x[i]=r[i]]++;
	for (i = 1; i < m; ++i) wn[i] += wn[i-1];
	for (i = n - 1; i >= 0; --i) sa[--wn[x[i]]] = i;


	for (j = 1,p = 1; p < n; j *= 2,m = p) {

		for (p = 0, i = n - j; i < n; ++i) y[p++] = i;
		for (i = 0; i < n; ++i) if (sa[i] >= j) y[p++] = sa[i] - j;
		

		for (i = 0; i < n; ++i) wv[i] = x[y[i]];
		for (i = 0; i < m; ++i) wn[i] = 0;
		for (i = 0; i < n; ++i) wn[wv[i]]++;
		for (i = 1; i < m; ++i) wn[i] += wn[i-1];
		for (i = n - 1; i >= 0; --i) sa[--wn[wv[i]]] = y[i];

	
		t = x,x = y,y = t,p = 1;
		for (x[sa[0]] = 0,i = 1; i < n; ++i)
			x[sa[i]] = cmp(y,sa[i-1],sa[i],j) ? p - 1 : p++;
	}
}
void CalHeight(int *r,int n) {//高度数组

	int i,j,k = 0;
	for (i = 1; i <= n; ++i) rank[sa[i]] = i;
	for (i = 0; i < n; h[rank[i++]] = k)
		for (k ? k-- : 0,j = sa[rank[i]-1];r[i+k] == r[j+k]; k++);
}


int Solve() {

	int i,j,k,tot,maxx = 0;
	int low,high,mid;


	low = 1,high = n;
	while (low <= high) {

		mid = low + (high - low) / 2;
		for (tot = 1,i = 1; i <= n; ++i) { //i是排名

			if (h[i] >= mid) tot++;	//相邻排名的最长公共子串长度
			else tot = 1;
			if (tot >= renum) break;
		}


		if (tot >= renum) low = mid + 1,maxx = mid;
		else high = mid - 1;
	}
	return maxx;
}


int main()
{
	int i,j,k,ans;


	while (scanf("%d%d",&n,&renum) != EOF) {

		memset(arr,0,sizeof(arr));
		for (i = 0; i < n; ++i) 
			scanf("%d",&brr[i]),arr[i] = brr[i];
		arr[n] = 0;
		

		Da(arr,n+1,MAX);	//算后缀数组的时候要把最后一个算在内，排名才是从1开始的。
		CalHeight(arr,n);


		ans = Solve();
		printf("%d\n",ans);
	}
}