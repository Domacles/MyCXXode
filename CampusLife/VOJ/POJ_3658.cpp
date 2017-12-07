#include <cstdio>

using namespace std;
typedef long long ll;
const int MAXN =100005, INF =1000000000;
int index=1, N, w[MAXN], h[MAXN];//width   height 
int prev[MAXN],next[MAXN];
ll  ans[MAXN],total=0;

int main()
{
	scanf("%d",&N);
	h[0]=h[N+1]=INF;
	next[0]=1,prev[N+1]=N;
	for(int i=1;i<=N;i++){
		scanf("%d%d",&w[i],&h[i]);
		prev[i]=i-1,next[i]=i+1;
		if(h[i]<h[index])
			index=i;
	}
	
	while(h[index]<INF){
		ans[index]=total+w[index];
		int L=prev[index],R=next[index];
		next[L]=next[index] , prev[R]=prev[index];
		
		if(h[L]<h[R]){
			total+=(ll)(h[L]-h[index])*w[index];
			w[L]+=w[index];
			index=L;
			while(index>0 && h[prev[index]]<h[index]) index=prev[index];
		}
		else{
			total+=(ll)(h[R]-h[index])*w[index];
			w[R]+=w[index];
			index=R;
			while(index<=N&& h[next[index]]<h[index]) index=next[index];
		}
	}
	for(int i=1;i<=N;i++) printf("%lld\n",ans[i]);
	
	return 0;
}
