#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
typedef long long ll;

ll a[33333],s[33333];

void init()
{
	for(int i=1;i<31270;i++){
		a[i]=a[i-1]+(int)log10((double)i)+1;
		s[i]=s[i-1]+a[i];
	}
}

int Answer(int n)
{
	int i=1,length=0;
	while(s[i]<n) i++;
	
	int pos=n-s[i-1];
	for(i=1;length<pos;i++){
		length+=(int)log10((double)i)+1;
	}
	return ((i-1)/(int)pow(10.0,length-pos))%10;
}

int main()
{
	int t,n; init();
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%d\n",Answer(n));
	}
	return 0;
}

//HASH

//题意是求一个最长的范围，在这个范围内各种FEATRUE出现的次数相同

//对于SAMPLE的数据的处理
//前导零        000     000
//7---->111---->111---->000
//6---->110---->221---->110(*)
//7---->111---->332---->110
//2---->010---->342---->120
//1---->001---->343---->010
//4---->100---->443---->110(*)
//2---->010---->453---->120
//443 - 221 = 222说明在这个范围内3中特色都有相同的个数2
//看了解题报告才知道最后一步的转化，每个2进制结果所有位减去他们当中的任意位，上面例子取减去最右边那一位
//这样将问题转化为判重,，只要找两位他们是相同的并且距离是最远的即可(加*为答案)，用HASH来解决是O(NK)