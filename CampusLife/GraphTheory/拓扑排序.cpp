/*edge[][]��Ϊͼ���ڽӾ���;count[0��i��n-1]:����i�����*/
void TopoOrder(int n)
{
    int i, top = -1;
    for( i=0; i < n; ++i )
        if( count[i] == 0 )  // �±�ģ���ջ
        {
            count[i] = top;
            top = i;
        }
    for( i=0; i < n; ++i )
        if( top == -1 )
        {
            printf("���ڻ�·\n");
            return ;
        }
        else
        {
            int j = top;
            top = count[top];
            printf("%d", j);
            for( int k=0; k < n; ++k )
                if( edge[j][k] && (--count[k]) == 0 )
                {
                    count[k] = top;
                    top = k;
                }
        }
}
