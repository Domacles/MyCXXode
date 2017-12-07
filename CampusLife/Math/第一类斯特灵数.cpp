/***
就是有n个人分成k组，每组内再按特定顺序围圈的分组方法的数目
s(4,2)=11
1, {A,B},{C,D}
2  {A,C},{B,D}
3  {A,D},{B,C}
4  {A},{B,C,D}
5  {A},{B,D,C}
6  {B},{A,C,D}
7  {B},{A,D,C}
8  {C},{A,B,D}
9  {C},{A,D,B}
10 {D},{A,B,C}
11 {D},{A,C,B}

说明：考虑第n+1个物品，n+1可以单独构成一个非空循环排列，这样前n种物品构成k-1个非空循环排列，方法数为s(n,k-1)；也可以前n种物品构成k个非空循环排列，而第n+1个物品插入第i个物品的左边，这有n*s(n,k)种方法。
***/
const int maxn =100;

ll stir[111][111];//第一类斯特灵数

void solve()
{
    for(int i=1;i<=maxn;i++)
        stir[i][0]=0;
    stir[1][1]=1;
    for(int i=1;i<=maxn;i++)
        for(int j=1;j<=i;j++){
            if(i==j)
                stir[i][j]=1;
            else
                stir[i][j]=stir[i-1][j-1]+(i-1)*stir[i-1][j];
        }
    for(int i=1;i<=maxn;i++)
        for(int j=1;j<=maxn;j++)
            if(stir[i][j]<0)
                stir[i][j]=-stir[i][j];
}

int main()
{
   // freopen("r.txt","r",stdin);
    solve();
    int x,y;
    while(cin>>x>>y){
        cout<<stir[x][y]<<endl;
    }
    return 0;
}
