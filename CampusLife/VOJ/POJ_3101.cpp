#include<cstdio>
#include<cstring>
#include<cmath>
int prime[5000],head,Div[5000];
bool isprime[10005];
void getPrime(){
    head=0;
    memset(isprime,0,sizeof(isprime));
    for(int i=2;i<10000;i++)if(!isprime[i]){
        prime[head++]=i;
        for(int j=2*i;j<10000;j+=i){
            isprime[j]=true;
        }
    }
}
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return a*b/gcd(a,b);
}
const int MAXNUM=1005;
int d[MAXNUM],den[MAXNUM];
int main(){
    int n,i,j,k,f,numerator;
    getPrime();
    while(~scanf("%d",&n)){
        numerator=0;
        memset(Div,0,sizeof(Div));
        memset(den,0,sizeof(den));
        den[0]=1;
        for(i=0;i<n;i++){
            scanf("%d",&d[i]);
        }
        for(i=1;i<n;i++){
                if(d[i]==d[0])continue;
                int LCM=lcm(d[i],d[0]);  //求分母
                f=2*(int)fabs(LCM/d[i]-LCM/d[0]);  //求分子
                int temp=gcd(LCM,f);
                LCM/=temp;  //分子分母约分
                f/=temp;
                numerator=gcd(numerator,f);  //求最大公约数
                for(j=0;j<head;j++){  //分解质因数
                    int t=0;
                    while(LCM%prime[j]==0){
                        t++;LCM/=prime[j];
                    }
                    if(Div[j]<t)Div[j]=t;  //记录较大的指数
                    if(LCM==1)break;
                }
        }
        for(i=0;i<head;i++){
            for(j=0;j<Div[i];j++){
                int temp=0;
                for(k=0;k<MAXNUM;k++){  //大数表示
                    den[k]=den[k]*prime[i]+temp; 
                    temp=den[k]/10000;
                    den[k]%=10000;
                    
                }
            }
        }
        for(i=MAXNUM-1;i>=0;i--)if(den[i]!=0)break;
        printf("%d",den[i]);
        while(i>0)printf("%04d",den[--i]);  //由于表示的4位数可能有前头0，所以强制输出4位
        printf(" %d\n",numerator);
    }
    return 0;
}