#include <iostream>
#include <cstring>
#define Max 20000
using namespace std;
int F[2][13000];

int main()
{
	int N,M;
	cin>>N>>M;
	int cost[3403];
	int value[3403];
	for (int i=1; i<=N; i++)
	{
		cin>>cost[i]>>value[i];
	} 

	for (int i=1; i<= N; i++)
	{
		for (int v=0; v<cost[i]; v++)
		{
			F[i%2][v] = F[(i-1)%2][v];
		}
		for (int v=cost[i]; v<=M; v++)
		{
			F[i%2][v] = max(F[(i-1)%2][v], F[(i-1)%2][v-cost[i]] + value[i]);
		}
	}
	cout<<F[N%2][M];

	return 0;

}