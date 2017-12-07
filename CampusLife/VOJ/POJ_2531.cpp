#include<iostream>

using namespace std;

const int Max = 21;
const bool A = true;
const bool B = false;
 
int n, map[Max][Max], mini;
bool set[Max];
 
void dfs(int dep, int val){
    if(val > mini)  return;
    if(dep > n){mini = val; return;}
 
    int i, m;
    m = 0;
    set[dep] = A;
    for(i = 1; i < dep; i ++)
        if(set[i] == A) m += map[i][dep];
    dfs(dep + 1, val + m);
 
    m = 0;
    set[dep] = B;
    for(i = 1; i < dep; i ++)
        if(set[i] == B) m += map[i][dep];
    dfs(dep + 1, val + m);
}
 
int main(){
    cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++){
            cin >> map[i][j];
            sum += map[i][j];
        }
    mini = 99999999;
    dfs(1, 0);
    cout << sum/2 - mini << endl;
    return 0;
}