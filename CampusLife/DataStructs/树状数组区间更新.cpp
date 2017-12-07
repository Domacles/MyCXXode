#include <stdio.h>

#define DEBUG

#ifdef DEBUG
#define debug(...) printf( __VA_ARGS__)
#else
#define debug(...)
#endif

#define N 100002

#define lowbit(i) ( i & (-i) )

/* ��delta[i]��ʾ

[i,n]�Ĺ������� */
long long c1[N];	/* ά��delta[i]��ǰ׺�� */
long long c2[N];	/*

ά��delta[i]*i��ǰ׺�� */
long long sum[N];
int 	  A[N];
int n;

long long query(long long *array, int i)
{
    long long tmp;
    tmp = 0;
    while (i > 0)
    {
        tmp += array[i];
        i -= lowbit(i);
    }
    return tmp;
}

void update(long long *array, int i, long long d)
{
    while (i <= n)
    {
        array[i] += d;
        i += lowbit(i);
    }
}

int main()
{
    int 		q, i, s, t, d;
    long long 	ans;
    char		action;
    scanf("%d %d", &n, &q);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", A+i);
    }
    for (i = 1; i <= n; i++)
    {
        sum[i] = sum[i-1] + A[i];
    }
    while (q--)
    {
        getchar();
        scanf("%c %d %d", &action, &s, &t);
        if(action == 'Q')
        {
            ans = sum[t] - sum[s-1];
            ans+= (t+1)*query(c1, t) - query(c2, t);
            ans -= (s*query(c1, s-1) - query(c2, s-1));
            printf("%I64d\n", ans);
        }
        else
        {
            scanf("%d", &d);
            /* ��delta[i](s<=i<=t)��d��������
            *�Ȱ�[s,n]�ڵ�������d���ٰ�[t+1,n]��������d
             */
            update(c1, s, d);
            update(c1, t+1, -d);
            update(c2,s, d*s);
            update(c2, t+1, -d*(t+1));
        }
    }
    return 0;
}
