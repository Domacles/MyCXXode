/****
	贪心
当前最优,因为每一次搬运之后剩下的问题和原问题一样,只是规模变小了,故如果每次选出当前最优的解来进行选取,则累计起来的解也是最优的.
所以这是一道贪心题.
选择策略,
1 在二个中间选择之中,能根据time/eat小的那个为最优解
证明:
二个羊中 A,B,属性分别为分别为eatA,timeA,eatB,timeB
选A的时候损失timeA*eatB
选B的时候损失timeB*eatA
双方同除以eatA*eatB.
令time/eat为一个羊的比率x
可以证明x小的那个为最优解.

定理,如果有一个选择在n个选择中是最优的,那么(在包含这个选择的)n-1个选择中也是最优的,

逆否命题,如果一个选择在n-1个选择中不是最优的,那么在n个选择中也不是最优的.

推论,如果一个选择在2个选择中不是最优的,那么在n个选择中也不是最优的

所以将羊按照比率x排序,可以找到一个羊A在与其它所有羊比较的过程中都是最优的,

或者说其它n-1的羊在与别的羊做两个之间选一个的选择的时候不是最优的,所有这n-1个羊不是最优解的.
所以羊A是n头羊中最优解

(这个证明先令x的值都是不同的,对x相同的证明只需要将最优,改成没有更优即可 ^_^ )
****/
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{double time,d,d_time;
	Node(double a,double b){time=a;d=b;d_time=d/time;}
};
bool operator < (Node A,Node B)  {return A.d_time>B.d_time;}
vector<Node>cow;

int main()
{
	int N; long long sum=0;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int x,y;scanf("%d%d",&x,&y);
		sum+=y;
		cow.push_back(Node((double)x,(double)y));
	}
	sort(cow.begin(),cow.end());
	long long ans=0;
	for(int i=0;i<N;i++)
		ans+=2*cow[i].time*(sum-=cow[i].d);
	printf("%lld\n",ans);
	return 0;
}