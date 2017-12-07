struct Matrix
{
    int val[8][8] =
    {
     //  0  1  2  3  4  5  6  7
        {0, 0, 0, 0, 0, 0, 0, 1},//0
        {0, 0, 0, 0, 0, 0, 1, 0},//1
        {0, 0, 0, 0, 0, 1, 0, 0},//2
        {0, 0, 0, 0, 1, 0, 0, 1},//3
        {0, 0, 0, 1, 0, 0, 0, 0},//4
        {0, 0, 1, 0, 0, 0, 0, 0},//5
        {0, 1, 0, 0, 0, 0, 0, 1},//6
        {1, 0, 0, 1, 0, 0, 1, 0} //7
    };

    void init1()
    {
        init0();
        for (int i = 0; i < 8; i++)
            val[i][i] = 1;
    }

    void init0()
    {
        memset(val, 0, sizeof(val));
    }

    Matrix operator*(Matrix y) const
    {
        Matrix temp;
        temp.init0();
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                for (int k = 0; k < 8; k++)
                    temp.val[i][j] = (temp.val[i][j] + val[i][k] * y.val[k][j]) % mod;
        return temp;
    }
} Ma;

Matrix Pow(int n)
{
    Matrix res;
    res.init1();
    while (n)
    {
        if (n & 1) res = res * Ma;
        Ma = Ma * Ma, n >>= 1;
    }
    return res;
}

int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    int N;
    scanf("%d", &N);
    Ma = Pow(N);
    printf("%d\n", Ma.val[7][7]);
    return 0;
}