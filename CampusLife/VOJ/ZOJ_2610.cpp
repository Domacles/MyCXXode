/****
	判断后,旋转;再判断,再旋转;再判断...
****/
#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int N;
string map[60];

void rotate()
{
    int i,j;
    string tmap[60];
    for(i=0;i<N;i++)
    {
        for(j=0;j<i;j++)
        {
            tmap[i]+=map[N-j-1][2*(i-j)];
            tmap[i]+=map[N-j-1][2*(i-j)-1];
        }
        tmap[i]+=map[N-i-1][0];
    }
    for(i=0;i<N;i++) map[i]=tmap[i];
}

bool work()
{
    int i,j;
    bool f1,f2;
    f1=f2=1;
    for(i=0;i<N;i++)
    {
        string::iterator it1=map[i].begin();
        string::iterator it2=map[i].end();
        f1&=count(find(it1,it2,'0'),it2,'1')==0;
        f2&=count(find(it1,it2,'1'),it2,'0')==0;
    }
    return f1||f2;
}

int main()
{
    int i,j;
    int test=0;
    while(scanf("%d",&N)==1&&N)
    {
        for(i=0;i<N;i++) cin>>map[i];
        bool ok=false;
        if(work()) ok=true;
        rotate();//旋转
        if(work()) ok=true;
        rotate();//旋转
        if(work()) ok=true;
        printf("Puzzle %d\n",++test);
        if(ok) puts("Parts can be separated");
        else puts("Parts cannot be separated");
    }
    return 0;
}