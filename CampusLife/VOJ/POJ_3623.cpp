#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
const int maxn=60010;
/***后缀数组***/
int wa[maxn],wb[maxn],sa[maxn],rk[maxn],w[maxn],v[maxn];
int n;
int cmp(int* r,int a,int b,int l)  
{  
    return r[a]==r[b] && r[a+l]==r[b+l];  
}  
  
void da(char* s,int* sa,int n,int m)  
{  
     int *x=wa,*y=wb,*t,i,j,p;  
     for (i=0;i<m;i++) w[i]=0;  
     for (i=0;i<n;i++) w[x[i]=s[i]]++;  
     for (i=1;i<m;i++) w[i]+=w[i-1];  
     for (i=n-1;i>=0;i--) sa[--w[x[i]]]=i;  
     for (j=1,p=1;p<n;j*=2,m=p)  
     {  
         for (p=0,i=n-j;i<n;i++) y[p++]=i;  
         for (i=0;i<n;i++) if (sa[i]>=j) y[p++]=sa[i]-j;  
         for (i=0;i<n;i++) v[i]=x[y[i]];  
         for (i=0;i<m;i++) w[i]=0;  
         for (i=0;i<n;i++) w[v[i]]++;  
         for (i=1;i<m;i++) w[i]+=w[i-1];  
         for (i=n-1;i>=0;i--) sa[--w[v[i]]]=y[i];  
         for (t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)  
             x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;  
     }  
     for (i=1;i<n;i++) rk[sa[i]]=i; 
}  

char s[maxn],ans[maxn];

int main()
{
    int i,j,tot;
    scanf("%d\n",&n);
    for (i=0;i<n;i++)
        scanf("%c\n",&s[i]);
    s[n]='$';
    for (i=n+1;i<n+n+1;i++)
        s[i]=s[n+n-i];
    s[n+n+1]=0;
    da(s,sa,strlen(s)+1,128);
    tot=0;
    for (i=0,j=n+1;i<n && j<n+n+1;)
    {
        if (rk[i]<rk[j]) ans[tot++]=s[i++];
        else ans[tot++]=s[j++];
        if (tot==n) break;
    }
    for (i=0;i<tot;i++)
    {
        cout << ans[i];
        if (i%80==79) cout << endl;
    }
    return 0;
}
