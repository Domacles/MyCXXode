/****
	维护一个集合，插入与删除操作，每一步结束之后，输出中位数
****/
#include<iostream>  
#include<cstdio>  
#include<map>  
#include<cstring>  
#include<cmath>  
#include<vector>  
#include<queue>  
#include<algorithm>  
#include<set> 
#include<string>
#define inf 1<<30
#define N 100005  
#define maxn 100005  
#define Min(a,b) ((a)<(b)?(a):(b))  
#define Max(a,b) ((a)>(b)?(a):(b))  
#define pb(a) push_back(a)  
#define mem(a,b) memset(a,b,sizeof(a))  
#define eps 1e-9  
#define zero(a) fabs(a)<eps  
#define LL long long  
#define ULL unsigned long long  
#define lson (step<<1)  
#define rson (step<<1|1)  
#define MOD 1000000007  
#define mp(a,b) make_pair(a,b)  
using namespace std;  
struct SBT{
	//左子树指针，右子树指针，大小，键值
	int left,right,size;
	LL key;
	void Init(){
		left=right=key=0;
		size=1;
	}
}T[N];
int root,tot; //根的位置以及节点个数
//左旋转处理
void Left_rot(int &x){  
	int k=T[x].right;
	T[x].right=T[k].left;
	T[k].left=x;
	T[k].size=T[x].size;
	T[x].size=T[T[x].left].size+T[T[x].right].size+1;
	x=k;
}
//右旋转处理
void Right_rot(int &x){
	int k=T[x].left;
	T[x].left=T[k].right;
	T[k].right=x;
	T[k].size=T[x].size;
	T[x].size=T[T[x].left].size+T[T[x].right].size+1;
	x=k;
}
//调整处理
void Maintain(int &r,bool flag){
	if(flag){  //更新右子树
		if(T[T[T[r].right].right].size>T[T[r].left].size)
			Left_rot(r);
		else if(T[T[T[r].right].left].size>T[T[r].left].size){
			Right_rot(T[r].right);
			Left_rot(r);
		}
		else
			return;
	} 
	else{   //更新在左子树
		if(T[T[T[r].left].left].size>T[T[r].right].size)
			Right_rot(r);
		else if(T[T[T[r].left].right].size>T[T[r].right].size){
			Left_rot(T[r].left);
			Right_rot(r);
		}
		else 
			return;
	}
	//更新子树，然后再更新根，直到平衡为止
	Maintain(T[r].left,false);
	Maintain(T[r].right,true);
	Maintain(r,false);
	Maintain(r,true);
}
//插入新节点
void Insert(int &r,LL k){
	if(r==0){
		r=++tot;
		T[r].Init();
		T[r].key=k;
	}
	else{
		T[r].size++;
		if(k<T[r].key)
			Insert(T[r].left,k);
		else
			Insert(T[r].right,k);
		//插入后要调整，保证平衡
		Maintain(r,k>=T[r].key);
	}
}
//删除结点，利用的是前驱替换
LL Remove(int &r,LL k){
	int d_key;
	if(!r)
		return 0;
	T[r].size--;
	//前者说明就是要删的节点，后两者说明不存在此节点
	if(T[r].key==k||(T[r].left==0&&k<T[r].key)||(T[r].right==0&&k>T[r].key)){
		d_key=T[r].key;
		if(T[r].left&&T[r].right)
			T[r].key=Remove(T[r].left,k+1);
		else
			r=T[r].left+T[r].right;
		return d_key;
	}
	else return Remove(k<T[r].key?T[r].left:T[r].right,k);

}
//取得第K大的数
LL Get_Max_Kth(int &r,LL k){
	int t=T[T[r].right].size+1;
	if(t==k) return T[r].key;
	if(t<k) return Get_Max_Kth(T[r].left,k-t);
	else return Get_Max_Kth(T[r].right,k);
}
//查找树中是否存在元素
int Find(int &r,LL k){
	if(!r) return 0;
	if(T[r].key==k) return 1;
	if(k<T[r].key) return Find(T[r].left,k);
	else return Find(T[r].right,k);
}
int main(){
	int t,q;
	
	scanf("%d",&t);
	while(t--){
		scanf("%d",&q);
		tot=root=0;
		int cnt=0;
		LL k;
		char str[10];
		while(q--){
			scanf("%s%lld",str,&k);
			if(str[0]=='a'){
				Insert(root,k);
				cnt++;
				if(cnt&1) printf("%lld\n",Get_Max_Kth(root,cnt/2+1));
				else {
					LL ans=(LL)Get_Max_Kth(root,cnt/2)+(LL)Get_Max_Kth(root,cnt/2+1);
					if(ans&1)printf("%.1f\n",ans/2.0);
					else printf("%lld\n",ans/2);
				}
			}
			else{
				if(!Find(root,k)) {printf("Wrong!\n");continue;}
				cnt--;
				Remove(root,k);
				if(cnt==0){printf("Empty!\n");continue;}
				if(cnt&1) printf("%lld\n",Get_Max_Kth(root,cnt/2+1));
				else {
					LL ans=(LL)Get_Max_Kth(root,cnt/2)+(LL)Get_Max_Kth(root,cnt/2+1);
					if(ans&1)printf("%.1f\n",ans/2.0);
					else printf("%lld\n",ans/2);
				}
			}
			
		}
	}
	return 0;
}