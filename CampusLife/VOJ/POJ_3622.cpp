/***
	贪心
***/
#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<algorithm>
#include<queue>
#include<list>
#include<set>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<ctype.h>
#include<iomanip>
using namespace std;

#define LL long long
#define pi acos(-1)
pair<int,int> cow[100010],grass[100010];
int main()
{
    int n,m;
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%d%d",&cow[i].second,&cow[i].first);
        sort(cow,cow+n,greater<pair<int,int> >());//按照先first后second降序
        for(i=0;i<m;i++)
            scanf("%d%d",&grass[i].second,&grass[i].first);
        sort(grass,grass+m);
        m=unique(grass,grass+m)-grass;//去重
        sort(grass,grass+m,greater<pair<int,int> >());//按照先first后second降序
        multiset<int>  s;
        multiset<int>::iterator it;
        LL ans=0;
        for(i=0,j=0;i<n;i++)
        {
            while(j<m && grass[j].first>=cow[i].first)
            {
                s.insert(grass[j++].second);
            }
            it=s.lower_bound(cow[i].second);//二分查找cow[i]的下界
            if(it!=s.end())//找到
            {
                ans+=*it;//累计花费（first）
                s.erase(it);//去掉该grass
            }
            else//未找到，则不存在满足所有cow的情况，输出-1
            {
                ans=-1;
                break;
            }
        }
        printf("%I64d\n",ans);

    }
    return 0;
}
