#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
struct an
{
    int w,lab;
}p[200];
bool cmp(const an &a,const an &b)
{
    return a.w<b.w;
}
int main()//排序后只需要考虑最后一组的变化
{
    int i,j,n,sa,sb,ans,a,b;
    cin>>n;
    for(i=0;i<3*n;i++){
        cin>>p[i].w;
        p[i].lab=i+1;
    }
    sort(p,p+3*n,cmp);
    sa=0;sb=0;
    for(i=n;i<n+n;i++)
        sa+=p[i].w;
    for(i=n+n;i<3*n;i++)
        sb+=p[i].w;
	//去掉了前面n个最小的
    ans=n*500;
    bool flag=0;
    if(sa>ans&&sb>ans) flag=1;
    while(!flag){//随机化交换
        a=rand()%n+n;//第一组中的随机位置
        b=rand()%n+2*n;//第二组中的随机位置
        sa=sa-p[a].w+p[b].w;
        sb=sb-p[b].w+p[a].w;
        swap(p[a],p[b]);
        if(sa>ans&&sb>ans){
            flag=1;
            break;
        }
    }
    for(i=0;i<3*n;i++)
        cout<<p[i].lab<<endl;
    return 0;
}