#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int,int> PII;
typedef long long ll;

const int maxn =1e6;
int hit[maxn],score[maxn],n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) hit[i]=100;
    for (int l=1;l<=m;l++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if (hit[x]>0)
        {
           if (hit[y]>0) score[x]+=3;
           hit[y]-=8;
        }
    }
    for (int i=1;i<=n;i++)
        if (hit[i]>0) score[i]+=hit[i]/2;
    for (int i=1;i<=n;i++)
        printf("%d %d\n",hit[i],score[i]);
    return 0;
}
