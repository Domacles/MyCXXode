#include <iostream>
#include <cstdio>
using namespace std;
#define maxn 1002

int a[maxn][maxn],b[maxn][maxn];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d",&a[i][j]);
    b[n-1][m-1]=a[n-1][m-1];
    for(int j=m-1; j>=0; j--)
        for(int i=n-1; i>=0; i--)
        {
            if(i==n-1&&j==m-1)continue;
            b[i][j]=a[i][j];
            if(i<n-1)        b[i][j]=min(b[i][j],b[i+1][j]);
            if(j<m-1&&i>0)   b[i][j]=min(b[i][j],b[i-1][j+1]);
            if(j<m-1)        b[i][j]=min(b[i][j],b[i][j+1]);
        }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)printf("%d ",b[i][j]);
        printf("\n");
    }
    return 0;
}
