int C[maxn][maxn], d[maxn];//组合  错排

void init()
{
    memset(C,0,sizeof(C));
    for(int i=0;i<maxn;i++){
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
    d[0]=1; d[1]=0; d[2]=1;
    for(int i=3;i<maxn;i++)//错排
        d[i]=((d[i-1]+d[i-2])%mod)*(i-1)%mod;
}
