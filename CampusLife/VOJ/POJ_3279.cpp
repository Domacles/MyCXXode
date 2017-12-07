/****
	第一行状态确定，count确定
	上一行归零，由下一行反转
****/
#include<iostream>
#include<algorithm>
#include<cstdio> 
#include<cstring>
 
using namespace std;

int M,N;
int a[20][20],flip[20][20],opt[20][20];
int dx[]= {1,-1,0,0,0};
int dy[]= {0,0,1,-1,0};
int get(int x,int y)//此位为1，则下位反转
{//(x,y)位置是否为1，受到自身和其上下左右是否反转影响
    int c=a[x][y];
    for(int i=0; i<5; i++)  
    {
        int tx=x+dx[i],ty=y+dy[i];  
        if(tx>=0&&tx<M&&ty>=0&&ty<N)
            c+=flip[tx][ty];
    }
    return c%2;
}  
int fun()  
{  
    for(int i=1; i<M; i++)  
    {  
        for(int j=0; j<N; j++)  
            if(get(i-1,j)!=0)  
                flip[i][j]=1;  
    }  
    for(int j=0; j<N; j++)//判断最后一行是否为0  
        if(get(M-1,j)!=0) 
            return -1;
    int res=0;
    for(int i=0; i<M; i++)
        for(int j=0; j<N; j++) 
            res+=flip[i][j];
    return res;
}

void solve()
{
    int res=-1;

    for(int i=0; i<(1<<N); i++)//枚举第一行所有的翻转方式
    {
        memset(flip,0,sizeof(flip));
        for(int j=0; j<N; j++)
            flip[0][N-j-1]=i>>j&1;
        int num=fun();
        if(num>=0&&(res<0||res>num))
        {
            res=num;
            memcpy(opt,flip,sizeof(flip));
        }
    }
    if(res<0)  cout<<"IMPOSSIBLE"<<endl;
    else
    {  
        for(int i=0; i<M; i++)  
        {  
            for(int j=0; j<N; j++)  
                if(j!=0)  
                    cout<<' '<<opt[i][j];  
                else cout<<opt[i][j];  
            cout<<endl;  
        }  
    }  
}  
int main()  
{  
    //freopen("in.txt","r",stdin);  
    while(cin>>M>>N)  
    {  
        for(int i=0; i<M; i++)  
            for(int j=0; j<N; j++)  
                cin>>a[i][j];  
        solve();  
    }  
    return 0;  
}  