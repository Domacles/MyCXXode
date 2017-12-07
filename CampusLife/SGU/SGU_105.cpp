#include<iostream>
 
using namespace std;
 
int main()
{
	int n;
	cin >> n;
	cout << 2 * (n / 3) + ( n % 3 > 0 ? ( (n % 3)- 1 ) : 0) << endl;
	return 0;
}