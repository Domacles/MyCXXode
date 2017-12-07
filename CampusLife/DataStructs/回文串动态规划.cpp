using namespace std;
#define maxn 100000

char s[maxn];
int  slen[maxn];
int  len;

void Manacher()
{
    int maxid=1;
    int id=1;
    len=strlen(s);
    for(int i=1;i<len;i++){
        if(maxid>i)//核心,减少许多不必要的运算
            slen[i]=min(slen[2*id-i],maxid-i);
        else
            slen[i]=1;

        while(s[i+slen[i]]==s[i-slen[i]])
            slen[i]++;

        if(i+slen[i]>maxid){
            maxid=i+slen[i]; id=i;
        }
    }
}
