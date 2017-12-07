/**************
    任何自然数是最多三个三角形数的和。高斯发现了这个规律
***************/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

const int max_n=1000000000;
vector<int> V;
void init()
{
    V.clear();
    int i=1,pre;
    do
    {
        pre=i*(i+1)/2;
        V.push_back(pre);
        ++i;
    }while(pre<max_n);
}

int main()
{
    init();
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        if(binary_search(V.begin(),V.end(),n))//一段
        {
            printf("%d\n",(int)(sqrt(n*2+0.25)-0.5));
        }
        else
        {
            int i=0,j,pre,prej;
            do
            {
                ++i;
                pre=i*(i+1)/2;
            }while(pre<n&&!binary_search(V.begin(),V.end(),n-pre));
            if(pre<n)//两段
            {
                printf("%d %d\n",i,(int)(sqrt((n-pre)*2+0.25)-0.5));
            }
            else//三段
            {
                i=0;
                do
                {
                    ++i;
                    pre=i*(i+1)/2;
                    j=i-1;
                    do
                    {
                        ++j;
                        prej=pre+j*(j+1)/2;
                    }while(prej<n&&!binary_search(V.begin(),V.end(),n-prej));
                    if(prej<n)break;
                }while(pre<n);
                printf("%d %d %d\n",i,j,(int)(sqrt((n-prej)*2+0.25)-0.5));
            }
        }
    }
    return 0;
}
