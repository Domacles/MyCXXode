/*
ѭ���ַ�������С��ʾ���������������������
����һ���ַ���S����S��ѭ����ͬ���ַ���S�����ֵ�����С��һ����
*/
#include <cstring>
#include <iostream>

using namespace std;

int MinAndMaxRepresentation(string s, bool bMin=true)//Ĭ����С��ʾ��
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
