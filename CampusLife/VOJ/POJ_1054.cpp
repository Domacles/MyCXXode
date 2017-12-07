#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;
const int MAX = 5005;
 
struct data{
    int r, c;
}fro[MAX];
int row, col;
bool map[MAX][MAX];
 
bool cmp(data a, data b){
    if(a.c == b.c) return a.r < b.r;
    return a.c < b.c;
}
 
bool inMap(int r, int c){
    if(r > 0 && r <= row && c > 0 && c <= col) return true;
    return false;
}
 
int getSum(int r, int c, int dr, int dc){
    int sum = 0;
    while(inMap(r, c)){
        if(!map[r][c]) return 0;
        r += dr;
        c += dc;
        sum ++;
    }
    return sum;
}
 
int main(){
    int n, i, j;
    int r, c, dr, dc;
    while(scanf("%d%d", &row, &col) != EOF){
        memset(map, 0, sizeof(map));
        scanf("%d", &n);
        for(i = 0; i < n; i ++){
            scanf("%d%d", &r, &c);
            map[r][c] = 1;
            fro[i].r = r;
            fro[i].c = c;
        }
        sort(fro, fro+n, cmp);
        int ans = 2;
        for(i = 0; i < n-1; i ++)
            for(j = i+1; j < n; j ++){
                dr = fro[j].r - fro[i].r;
                dc = fro[j].c - fro[i].c;
                if(fro[i].c + ans*dc > col) break;   // 剪枝1。
                if(inMap(fro[i].r-dr, fro[i].c-dc)) continue;   // 剪枝2：不能跳进来。
                if(!inMap(fro[i].r+ans*dr, fro[i].c+ans*dc)) continue;   // 剪枝3。
                ans = max(ans, getSum(fro[i].r, fro[i].c, dr, dc));
            }
        if(ans < 3) printf("0\n");
        else printf("%d\n", ans);
    }
    return 0;
}