/*
HDU 1150
题目大意;有两台机器A和B以及N个需要运行的任务。每台机器有M种不同的模式，而每个任务都恰好在一台机器上运行。如果它在机器A上运行，则机器A需要设置为模式xi,如果它在机器B上运行，则机器A需要设置为模式yi。每台机器上的任务可以按照任意顺序执行，但是每台机器每转换一次模式需要重启一次。请合理为每个任务安排一台机器并合理安排顺序，使得机器重启次数尽量少。
二分图的最小顶点覆盖数=最大匹配数

本题就是求最小顶点覆盖数的。

相当于是最小的点消灭掉所有的边，所以是最小顶点覆盖

*/

#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;


/* **************************************************************************
//二分图匹配（匈牙利算法的DFS实现）
//初始化：g[][]两边顶点的划分情况
//建立g[i][j]表示i->j的有向边就可以了，是左边向右边的匹配
//g没有边相连则初始化为0
//uN是匹配左边的顶点数，vN是匹配右边的顶点数
//调用：res=hungary();输出最大匹配数
//优点：适用于稠密图，DFS找增广路，实现简洁易于理解
//时间复杂度:O(VE)
//***************************************************************************/
//顶点编号从0开始的
const int MAXN=110;
int uN,vN;//u,v数目
int g[MAXN][MAXN];
int linker[MAXN];
bool used[MAXN];
bool dfs(int u)//从左边开始找增广路径
{
    int v;
    for(v=0;v<vN;v++)//这个顶点编号从0开始，若要从1开始需要修改
      if(g[u][v]&&!used[v])
      {
          used[v]=true;
          if(linker[v]==-1||dfs(linker[v]))
          {//找增广路，反向
              linker[v]=u;
              return true;
          }
      }
    return false;//这个不要忘了，经常忘记这句
}
int hungary()
{
    int res=0;
    int u;
    memset(linker,-1,sizeof(linker));
    for(u=0;u<uN;u++)
    {
        memset(used,0,sizeof(used));
        if(dfs(u)) res++;
    }
    return res;
}
//******************************************************************************/
int main()
{
    int k;
    int i,u,v;
    while(scanf("%d",&uN),uN)
    {
        scanf("%d%d",&vN,&k);
        memset(g,0,sizeof(g));
        while(k--)
        {
            scanf("%d%d%d",&i,&u,&v);
            if(u>0&&v>0)g[u][v]=1;//初始状态为0，一开始0的边不要加
        }
        printf("%d\n",hungary());
    }
    return 0;
}