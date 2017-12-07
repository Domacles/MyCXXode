/****
	注意：不一定所有牛都要上
****/
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct data
{
    int x,y;
    bool operator<(const data &ne)const
    {
        return x+y<ne.x+ne.y;
    }
}po[60000];
int sum[60000];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%d%d",&po[i].x,&po[i].y);
        sort(po+1,po+n+1);
        sum[0]=0;
        int ans=-(1<<29);;
        for(int i=1;i<=n;i++)
        {
            sum[i]=sum[i-1]+po[i].x;
            ans=max(ans,sum[i-1]-po[i].y);//!!求最大！！
        }
        printf("%d\n",ans);
    }
    return 0;
}