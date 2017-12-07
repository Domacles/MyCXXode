/**********
    1，将P视为不能到达的点，从矩形的四条边往里搜，凡是没有dfs到的P点，都是Ghost，这里理解错了题意；
    2，剩下的点进行BFS找联通块，最大的联通块大小即为答案。
**********/
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1000;

int r, l;
char c[N + 1][N + 1];
int d1[][2] = {1, 0, 1, 1, 1, -1, 0, 1, 0, -1, -1, -1, -1, 1, -1, 0};
int d2[][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int visited[N + 1][N + 1];
int cnt;

void dfs(int row, int col)
{
    if (c[row][col] == 'P') {
        visited[row][col] = 2;
        return;
    } else
        visited[row][col] = 1;
    int x, y, i;
    for (i = 0; i < 4; i++) {
        x = row + d2[i][0];
        y = col + d2[i][1];
        if (x >= 0 && x < r && y >= 0 && y < l && !visited[x][y]) dfs(x, y);
    }
}

void search(int row, int col)
{
    visited[row][col] = 1;
    cnt++;
    int i, x, y;
    for (i = 0; i < 8; i++) {
        x = row + d1[i][0];
        y = col + d1[i][1];
        if (x >= 0 && x < r && y >= 0 && y < l && c[x][y] == 'P' && visited[x][y] == 2) search(x, y);
    }
}

int main ()
{
    int i, j, mmax;
    while (scanf("%d%d", &r, &l) != EOF) {
        getchar();
        for (i = 0; i < r; i++) scanf("%s",c[i]);
        memset(visited, 0, sizeof(visited));
        for (j = 0; j < l; j++)
            if (!visited[0][j]) dfs(0, j);
        for (i = 1; i < r; i++)
            if (!visited[i][0]) dfs(i, 0);
        for (i = 1; i < r; i++)
            if (!visited[i][l - 1]) dfs(i, l - 1);
        for (j = 1; j < l - 1; j++)
            if (!visited[r - 1][j]) dfs(r - 1, j);

        mmax = 0;
        for (i = 0; i < r; i++)
            for (j = 0; j < l; j++)
                if (c[i][j] == 'P' && visited[i][j] == 2) {
                    cnt = 0;
                    search(i, j);
                    mmax = max(cnt, mmax);
                }

        printf("%d\n", mmax);
    }
}

