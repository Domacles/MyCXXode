#include<iostream>
#include<cmath>
#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int INF = 99999999;
 
int map[10][10];
int dp[16][10][10][10][10];
 
int getDp(int k, int x1, int y1, int x2, int y2){
    int mid, ans = INF;
    for(mid = x1+1; mid < x2; mid ++){
        ans = min(ans, dp[k-1][x1][y1][mid][y2] + dp[1][mid][y1][x2][y2]);
        ans = min(ans, dp[k-1][mid][y1][x2][y2] + dp[1][x1][y1][mid][y2]);
    }
    for(mid = y1+1; mid < y2; mid ++){
        ans = min(ans, dp[k-1][x1][y1][x2][mid] + dp[1][x1][mid][x2][y2]);
        ans = min(ans, dp[k-1][x1][mid][x2][y2] + dp[1][x1][y1][x2][mid]);
    }
    return ans;
}
 
int main(){
    int n, i, j, k, x1, x2, y1, y2;
    scanf("%d", &n);
    for(i = 1; i <= 8; i ++)
        for(j = 1; j <= 8; j ++){
            scanf("%d", &map[i][j]);
            map[i][j] += map[i-1][j]+map[i][j-1]-map[i-1][j-1];
        }
    for(x1 = 0; x1 < 8; x1 ++)
        for(y1 = 0; y1 < 8; y1 ++)
            for(x2 = x1+1; x2 <= 8; x2 ++)
                for(y2 = y1+1; y2 <= 8; y2 ++){
                    int tmp = map[x2][y2]-map[x1][y2]-map[x2][y1]+map[x1][y1];
                    dp[1][x1][y1][x2][y2] = tmp * tmp;
                }
    for(k = 2; k <= n; k ++)
        for(x1 = 0; x1 < 8; x1 ++)
            for(y1 = 0; y1 < 8; y1 ++)
                for(x2 = x1+1; x2 <= 8; x2 ++)
                    for(y2 = y1+1; y2 <= 8; y2 ++)
                        dp[k][x1][y1][x2][y2] = getDp(k, x1, y1, x2, y2);
    double ans = 1.0*dp[n][0][0][8][8]/n - 1.0*map[8][8]*map[8][8]/(n*n);
    printf("%.3f\n", sqrt(ans));
    return 0;
}