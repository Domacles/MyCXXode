#include <cstdio>
#include <cstring>

using namespace std;

const int INF = 1e9+7;


int n;
int dp[1000010][5];
char st[1000010];

void init() {
	scanf("%s",st+1);
	n = strlen(st+1);
}

void add(int &x, int y) {
	x += y;
	if (x >= INF) x -= INF;
}

void solve() {
	dp[0][0] = dp[0][1] = 1;

	for (int i = 1; i <= n; i++) {
		bool g = (st[i] == '?');

		if (g || st[i] == '0') {
			add(dp[i][0], dp[i-1][0]);
			add(dp[i][0], dp[i-1][2]);
		}
		if (g || st[i] == '1') {
			add(dp[i][1], dp[i-1][0]);
			add(dp[i][1], dp[i-1][2]);
			add(dp[i][2], dp[i-1][4]);
		}
		if (g || st[i] == '2') {
			add(dp[i][3], dp[i-1][4]);
		}
		if (g || st[i] == '*') {
			add(dp[i][4], dp[i-1][4]);
			add(dp[i][4], dp[i-1][1]);
			add(dp[i][4], dp[i-1][3]);
		}
	}

	int ans = 0;
	bool g = (st[n] == '?');
	if (g || st[n] == '0')  add(ans, dp[n][0]);
	if (g || st[n] == '1')  add(ans, dp[n][2]);
	if (g || st[n] == '*')  add(ans, dp[n][4]);
	printf("%d\n", ans);
}

int main() 
{
	//freopen("r1.txt","r",stdin);
	init();
	solve();
	return 0;
}