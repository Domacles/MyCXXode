/***
������n���˷ֳ�k�飬ÿ�����ٰ��ض�˳��ΧȦ�ķ��鷽������Ŀ
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

˵�������ǵ�n+1����Ʒ��n+1���Ե�������һ���ǿ�ѭ�����У�����ǰn����Ʒ����k-1���ǿ�ѭ�����У�������Ϊs(n,k-1)��Ҳ����ǰn����Ʒ����k���ǿ�ѭ�����У�����n+1����Ʒ�����i����Ʒ����ߣ�����n*s(n,k)�ַ�����
***/
const int maxn =100;

ll stir[111][111];//��һ��˹������

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
