#include <stdio>
#include <cstring>

#define maxn 200002

using namespace std;

int wa[maxn],wb[maxn],wv[maxn],ws[maxn];
int cmp(int *r,int a,int b,int l)
{return r[a]==r[b]&&r[a+l]==r[b+l];}
void da(int *r,int *sa,int n,int m)
{
     int i,j,p,*x=wa,*y=wb,*t;
     for(i=0;i<m;i++) ws[i]=0;
     for(i=0;i<n;i++) ws[x[i]=r[i]]++;
     for(i=1;i<m;i++) ws[i]+=ws[i-1];
     for(i=n-1;i>=0;i--) sa[--ws[x[i]]]=i;
     for(j=1,p=1;p<n;j*=2,m=p)
     {
       for(p=0,i=n-j;i<n;i++) y[p++]=i;
       for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
       for(i=0;i<n;i++) wv[i]=x[y[i]];
       for(i=0;i<m;i++) ws[i]=0;
       for(i=0;i<n;i++) ws[wv[i]]++;
       for(i=1;i<m;i++) ws[i]+=ws[i-1];
       for(i=n-1;i>=0;i--) sa[--ws[wv[i]]]=y[i];
       for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
       x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
     }
     return;
}
int rank[maxn],height[maxn];
void calheight(int *r,int *sa,int n)
{
     int i,j,k=0;
     for(i=1;i<=n;i++) rank[sa[i]]=i;
     for(i=0;i<n;height[rank[i++]]=k)
     for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
     return;
}

char s[maxn];
int r[maxn],sa[maxn];
int main()
{
    int i,j,n,ans=0;
    scanf("%s",s);
    j=strlen(s);
    s[j]=1;
    scanf("%s",s+j+1);
    n=strlen(s);
    for(i=0;i<n;i++) r[i]=s[i];
    r[n]=0;
    da(r,sa,n+1,128);
    calheight(r,sa,n);
    for(i=2;i<=n;i++)
        if(height[i]>ans)
            if((j<sa[i-1] && j>sa[i])
                || (j>sa[i-1] && j<sa[i])) ans=height[i];
    printf("%d\n",ans);
    return 0;
}


//////////////////////////////////////////////////////////////
int n, k, rank[maxn], tmp[maxn];
bool cmp(int i,int j){
    if(rank[i]!=rank[j]) return rank[i]<rank[j];
    else{
        int ri=i+k<=n?rank[i+k]:-1;
        int rj=j+k<=n?rank[j+k]:-1;
        return ri<rj;
    }
}
void SA(string S,int *sa){
    n=S.length();
    //init rank
    for(int i=0;i<=n;i++){
        sa[i]=i;
        rank[i]=i<n?S[i]:-1;
    }

    for(k=1;k<=n;k*=2){
        sort(sa,sa+n+1,cmp);

        tmp[sa[0]]=0;//tmp save rank
        for(int i=1;i<=n;i++)
            tmp[sa[i]]=tmp[sa[i-1]]+(cmp(sa[i-1],sa[i])?1:0);

        for(int i=0;i<=n;i++) rank[i]=tmp[i];
    }
}
void LCP(string S,int *sa,int *lcp){
    int n=S.length();
    for(int i=0;i<=n;i++) rank[sa[i]]=i;
    int h=0;
    lcp[0]=0;
    for(int i=0;i<n;i++){
        int j=sa[rank[i]-1];
        if(h>0) h--;
        for(;j+h<n && i+h<n;h++)
            if(S[j+h]!=S[i+h]) break;
        lcp[rank[i]-1]=h;
    }
}
