/********
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;
#define maxn 1100000
const int INF=1000000000;

int fa[1100000];
int q1[25500],q2[25500],A[25500];
struct Node
{
    int s,t,key;
}node[25500];

int cmp(const void *a,const void *b) {return ((Node *)b)->key - ((Node *)a)->key;}
int ff(int n)
{
    if(n==fa[n]) return n;
    return fa[n]=ff(fa[n]);
}
bool is(int x,int y)
{
    int i;
    for(i=y;i>=x;i--)
    {
        if(!fa[i]) return 0;
        i=ff(i);
    }
    return 1;
}

void update(int x,int y)
{
    int i;
    for(i=y;i>=x;i--)
        if(!fa[i]) fa[i]=x;//存左边界
        else
        {
            i=ff(i);
            if(i>x) fa[i]=x;
        }
}

bool f(int n)
{
    int i,j,m1,m2,k;
    memset(fa,0,sizeof(fa));
    for(i=1;i<=n;i++)// 赋值
        node[i].s=q1[i], node[i].t=q2[i], node[i].key=A[i];
    qsort(node+1,n,sizeof(Node),cmp);//l,r,len_One,cmp ，从大到小排序
    for(i=1;i<=n;i++)//求n个区间的交集
    {
        for(j=i; j<=n && node[j].key==node[i].key; j++) ;
        j--;
        for(m1=0,m2=INF,k=i;k<=j;k++)
        {
            m1=m1>node[k].s ? m1 : node[k].s;
            m2=m2<node[k].t ? m2 : node[k].t;
        }
        if(m1>m2||is(m1,m2))//无交集或者交集中最小值不存在
            return 0;
        for(k=i;k<=j;k++)
            update(node[k].s,node[k].t);
        i=j;
    }
    return 1;
}
int Bsearch(int N)//二分选择ans，判断是否出现矛盾
{
    int l=1,r=N,mid;
    if(f(N)) return 0;
	for(int i=1;i<=N;i++) 
		if(f(i)) cout<<"1 "<<i<<endl;
		else cout<<"0 "<<i<<endl;
	
    while(l<r-1)
    {
        mid=(l+r)>>1;
        if(f(mid)) l=mid;
        else r=mid;
    }
    if(!f(r-1)) return r-1;
    return r;
}
int main()
{
    int N,Q,i;
    scanf("%d%d",&N,&Q);
    for(i=1;i<=Q;i++)
        scanf("%d%d%d",&q1[i],&q2[i],&A[i]);
    printf("%d\n",Bsearch(Q));
	return 0;
}
****/
//不严密

#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;
#define maxn 1100000
const int INF=1000000000;
struct Node{int l,r,A;} q[25500];
int M,N;
int father[maxn];
vector<Node>ques;
bool operator < (Node a,Node b){return a.A>b.A;}//从大到小排序

int find(int x)
{//father[x],代表x位置上最小值的位置
	if(father[x]==x) return x;
	else
		return father[x]=find(father[x]);
}

bool OK(int l,int r)
{//需要赋值的区间[l,r]中存在某位置没有被赋值最小值
	for(int i=r;i>=l;i--){
		if(!father[i]) return 0;
		i=find(i);
	}
	return 1;
}

void update(int l,int r)
{//对需要赋值的区间[l,r]进行赋值，赋值为区间左边界
	for(int i=r;i>=l;i--){
		if(!father[i]) father[i]=l;
		else{
			i=find(i);
			if(i>l) father[i]=l;
		}
	}
}


bool query(int n)
{
	memset(father,0,sizeof(father));
	ques.clear();
	for(int i=0;i<n;i++) ques.push_back(q[i]);
	sort(ques.begin(),ques.end());

	for(int i=0;i<n;i++){
		int l=0,r=INF,ed=i;
		while(ed<n&&ques[ed].A==ques[i].A) ed++;
		ed--;
		for(int j=i;j<=ed;j++){
			l=max(l,ques[j].l);
			r=min(r,ques[j].r);
		}

		if(l>r || OK(l,r)) return 0;
		for(int j=i;j<=ed;j++)
			update(ques[j].l,ques[j].r);
		i=ed;//用最后一个区间判断前面所更新的是否成立
	}
	return 1;
}

int Find_binary()
{
	if(query(N)) return 0;
	int l=1,r=N;
	while(l<r)
    {
        int mid=(l+r)>>1;
        if(query(mid)) l=mid+1;
        else r=mid;
    }
	return r;
}

int main()
{
	scanf("%d%d",&M,&N);
	for(int i=0;i<N;i++) scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].A);
	int ans=Find_binary();
	printf("%d\n",ans);
	return 0;
}


