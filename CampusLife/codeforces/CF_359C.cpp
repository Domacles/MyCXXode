#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long li;

const li MOD = 1000000007;

li bpow(li x, li v) {	
	if (v == 0)
		return 1 % MOD;

	if (v % 2 == 1)
		return (x * bpow(x, v - 1)) % MOD;

	li r = bpow(x, v / 2);

	return (r * r) % MOD;	
}

int main() {
	int n, x;
	cin >> n >> x;
	vector < li > a(n), b;
	li sum = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];	
	}
	for(int i = 0; i < n; i++)
	 	b.push_back(sum - a[i]);
	sort(b.rbegin(), b.rend());
                 

	while (true) {
		li v = b[b.size() - 1];
    
    	int cnt = 0;
		while (b.size() > 0 && b[b.size() - 1] == v) {
			cnt ++;
			b.pop_back();
		}
        
        if (cnt % x != 0) {
                        v = min(v, sum);
			cout << bpow(x, v) << endl;
			return 0;
		}
		else {
			cnt /= x;
			for(int i = 0; i < cnt; i++) 
				b.push_back(v + 1);
		}	
	}
}
/**
Obviously, the answer is xv. Let sum = a1 + a2 + ... + an. Also let si = sum - ai (the array of degrees). After that let's find value v by the following algorithm: Let's consider a sequence of degrees as decreasing sequence. Now we will perform the following operation until it's possible to perfom it. Take the minimum degree v from the array of degrees and calculate the number of elements cnt, which have the same degree. If cnt multiples of x, then replace all cnt elements by cnt / x elements of the form v + 1. Since the sequence of degrees is a decreasing sequence, we can simply assign them to the end. If cnt is not a multiple of x, then we found the required value v. Also you need to check, that v is not greater then sum. Otherwise, v will be equals to sum.
**/
