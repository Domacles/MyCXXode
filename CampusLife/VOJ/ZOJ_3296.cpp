/**********
	首先 对所有的对称轴共2n-1个 求出最长回文串长度 得到2n-1个回文串,
	对每个区间，以其起始坐标为关键字，从小到大排序。再依次找每查询一次能覆盖到的最大的区间，假设还没有看过的书页为(sta , end)，每次可以查询的小段区间用(xi , yi) 表示，
那么对于没有找过的每段区间，我们都是找 xi<=sta，并且yi > sta的区间中yi最大的区间，然后sta=y1，循环 ,直到yi = end为止。
最后统计区间的个数，即为最少的查询次数。
**********/
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
#define MAX 50005
#define INF 100000000
char str[MAX];
char a[MAX*2];
int n,l;
int sa[MAX*2];
int Rank[MAX*2];
int h[MAX*2];
int height[MAX*2];
int k;
int temp[MAX*2];
struct seg
{
    int l,r;
    void set(int t1,int t2)
    {
        l=t1;
        r=t2;
    }
};
seg r[MAX*4];
int sr;
bool cmp1(int i,int j)
{
    return a[i]<a[j];
}
int b[MAX*2];
int e[MAX*2];
int st[MAX*2][2];
int s;
void insert(int i,int p) //把数i插入到插槽p
{
    st[s][0]=i;
    st[s][1]=0;
    if(b[p]==0)b[p]=s;
    else st[e[p]][1]=s;
    e[p]=s;
    s++;
}
void list()
{
    int i;
    int sk=1;
    for(i=0; i<=n; i++)
    {
        int p=b[i];
        while(p)
        {
            sa[sk++]=st[p][0];
            p=st[p][1];
        }
    }
}
void radix_sort()
{
    int i;
    for(i=0; i<=n; i++)b[i]=e[i]=0;
    s=1;
    for(i=1; i<=n; i++)
    {
        int p=0;
        if(sa[i]+k<=n)p=Rank[sa[i]+k];
        insert(sa[i],p);
    }
    list();
    for(i=0; i<=n; i++)b[i]=e[i]=0;
    s=1;
    for(i=1; i<=n; i++)insert(sa[i],Rank[sa[i]]);
    list();
}
void cal_sa()
{
    int i;
    for(i=1; i<=n; i++)sa[i]=i;
    sort(sa+1,sa+1+n,cmp1);
    for(i=1; i<=n; i++)
    {
        Rank[sa[i]]=i;
        while(i+1<=n&&a[sa[i+1]]==a[sa[i]])
        {
            Rank[sa[i+1]]=Rank[sa[i]];
            i++;
        }
    }
    for(k=1; k<=n; k=k*2)
    {
        radix_sort();
        for(i=1; i<=n; i++)
        {
            temp[sa[i]]=i;
            while(i+1<=n&&Rank[sa[i+1]]==Rank[sa[i]])
            {
                int p1=0,p2=0;
                if(sa[i+1]+k<=n)p1=Rank[sa[i+1]+k];
                if(sa[i]+k<=n)p2=Rank[sa[i]+k];
                if(p1==p2)temp[sa[i+1]]=temp[sa[i]];
                else break;
                i++;
            }
        }
        for(i=1; i<=n; i++)Rank[i]=temp[i];
    }
}
void cal_lcp()
{
    int i,j,p;
    for(i=1; i<=n; i++)
    {
        if(Rank[i]==1)
        {
            h[i]=0;
            continue;
        }
        p=sa[Rank[i]-1];
        if(i==1||h[i-1]<=1)j=0;
        else j=h[i-1]-1;
        for(; p+j<=n&&i+j<=n&&a[p+j]==a[i+j]; j++);
        h[i]=j;
    }
    for(i=1; i<=n; i++)height[i]=h[sa[i]];
}
int d[30];
int dp[MAX*2][30];
inline int min(int i,int j)
{
    if(i<j)return i;
    return j;
}
inline int max(int i,int j)
{
    if(i>j)return i;
    return j;
}
void rmq()
{
    int i,j;
    for(i=1; i<=n; i++)dp[i][0]=height[i];
    for(j=1; d[j]<=n; j++)
    {
        for(i=1; i+d[j]-1<=n; i++)dp[i][j]=min(dp[i][j-1],dp[i+d[j-1]][j-1]);
    }
}
int find(int k)
{
    int i;
    for(i=0; i<30; i++)
    {
        if(d[i]<=k&&d[i+1]>k)return i;
    }
}
int query(int i,int j)
{
    int k=find(j-i+1);
    return min(dp[i][k],dp[j-d[k]+1][k]);
}
int cal(int i,int j)
{
    int p1=Rank[i],p2=Rank[j];
    if(p1<p2)return query(p1+1,p2);
    else return query(p2+1,p1);
}
bool cmp2(seg t1,seg t2)
{
    if(t1.l!=t2.l)return t1.l<t2.l;
    return t1.r>t2.r;
}
void solve()
{
    cal_sa();
    cal_lcp();
    rmq();
    sr=0;
    int i;
    int t=cal(1,n);
    if(t)r[sr++].set(2-t,t);
    for(i=2; i<=l; i++) //枚举回文的中心位置
    {
        int t=cal(i,n+1-i);
        if(t)r[sr++].set(i+1-t,i+t-1);
        t=cal(i,n+2-i);
        if(t)r[sr++].set(i-t,i+t-1);
    }
    sort(r,r+sr,cmp2);
    int ans=0;
    int end=0;
    for(i=0; i<sr;)
    {
        int se=-1;
        while(i<sr&&r[i].l<=end+1)
        {
            if(se<r[i].r)se=r[i].r;
            i++;
        }
        if(end<se)end=se;
        ans++;
        if(end>=l)break;
    }
    printf("%d\n",ans-1);
}
int main()
{
    int i;
    d[0]=1;
    for(i=1; i<30; i++)d[i]=d[i-1]*2;
    while(scanf("%s",str+1)!=EOF)
    {
        l=strlen(str+1);
        if(l==1)
        {
            printf("0\n");
            continue;
        }
        n=2*l+1;
        a[l+1]='$';
        for(i=1; i<=l; i++)
        {
            a[i]=str[i];
            a[n+1-i]=str[i];
        }
        a[n+1]='\0';
        solve();
    }
}
