/***
    Solution :
    http://hi.baidu.com/aekdycoin/item/2d54f9c0fef55457ad00efd6
    : binary + vector
***/

#define X first
#define Y second
typedef pair<double,double> PDD;
int N,M;
vector<PDD> A,B;

void init(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int x,y; scanf("%d%d",&x,&y);
        A.push_back(PDD(x,y));
    }
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        int x,y; scanf("%d%d",&x,&y);
        B.push_back(PDD(x,y));
    }
}

double cross(PDD a,PDD b,PDD c)
{//>0 b at middle of a and c, <0 b at left of a  (c is at right of a)
    return (b.X-a.X)*(c.Y-a.Y)-(b.Y-a.Y)*(c.X-a.X);
}

bool check(PDD p)
{
    if(cross(A[0],p,A[1])<=0 || cross(A[0],p,A[N-1])>=0) return 0;
    int l=0,r=N-1,tag=0;
    while(l<=r){
        int m=(l+r)>>1;
        if(cross(A[0],p,A[m])>=0)
            tag=m, l=m+1;
        else r=m-1;
    }
    l=tag,r=tag+1;
    if(cross(A[l],p,A[r])<=0) return 0;
    return 1;
}

void solve(){
    int flag=1;
    for(int i=0;i<M;i++)
        if(!check(B[i])){
            flag=0; break;
        }
    if(flag) puts("YES");
    else puts("NO");
}

int main()
{
    freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    init();
    solve();
    return 0;
}

