/*
循环字符串的最小表示法的问题可以这样描述：
对于一个字符串S，求S的循环的同构字符串S’中字典序最小的一个。
*/
#include <cstring>
#include <iostream>

using namespace std;

int MinAndMaxRepresentation(string s, bool bMin=true)//默认最小表示法
{
    int i=0, j=1, k=0, l=s.length(), sub;
    while (i<l && j<l && k<l){
        sub=s[(i+k)%l]-s[(j+k)%l];
        if(sub==0) k++;
        else{
            if(bMin? sub>0:sub<0)  i+=k+1;
            else j+=k+1;
            if(i==j) j++;
            k=0;
        }
    }
    return i<j?i:j;
}
