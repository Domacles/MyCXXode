/****
    一段字符串中，已给的字符串出现了几个。AC自动机
****/
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

//MAX_NODE = StringNumber * StringLength
const int MAX_NODE = 10100 * 50;

//节点个数,一般字符形式的题26个
const int CHILD_NUM = 26;
const int MAXN = 1000100;

struct ACAutomaton {

    int chd[MAX_NODE][CHILD_NUM];//每个节点的儿子,即当前节点的状态转移
    int val[MAX_NODE];           //记录题目给的关键数据
    int fail[MAX_NODE];          //传说中的fail指针
    int Q[MAX_NODE];             //队列,用于广度优先计算fail指针
    int ID[128];                 //字母对应的ID
    int sz;                      //已使用节点个数

    //初始化,计算字母对应的儿子ID,如:'a'->0 ... 'z'->25
    void Initialize(){
        fail[0]=0;
        for (int i=0;i<CHILD_NUM;i++) ID[i+'a']=i;
    }
    //重新建树需先Reset
    void Reset(){
        memset(chd[0],0,sizeof(chd[0]));
        memset(val,0,sizeof(val));
        sz=1;
    }
    //将权值为key的字符串a插入到trie中
    void Insert(char *a, int key){
        int p=0;
        for( ;*a;a++){
            int c =ID[(int)(*a)];
            if(!chd[p][c]){
                memset(chd[sz],0,sizeof(chd[sz]));
                val[sz]=0;
                chd[p][c]=sz++;
            }
            p=chd[p][c];
        }
        val[p]+=key;
    }
    //建立AC自动机,确定每个节点的权值以及状态转移
    void Construct(){
        int *s=Q , *e=Q;
        for(int i=0;i<CHILD_NUM;i++){
            if(chd[0][i]){
                fail[chd[0][i]]=0;
                *e++ =chd[0][i];
            }
        }
        while(s!=e){
            int u= *s++;
            for(int i=0;i<CHILD_NUM;i++){
                int &v=chd[u][i];
                if(v){
                    *e++ = v;
                    fail[v]=chd[fail[u]][i];
                    //以下一行代码要根据题目所给val的含义来写
                    //val[v]|=val[fail[v]];
                }else{
                    v=chd[fail[u]][i];
                }
            }
        }
    }

    int Search(char *str)
    {
        int ans=0;
        int i=0;
        int p=0;
        while (str[i])
        {
            int c=ID[(int)(str[i])];
            while(p!=0 && !chd[p][c]) p=fail[p];
            if(chd[p][c]) p=chd[p][c];
            else p=0;

            int tmp=p;
            while(tmp!=0 && val[tmp]!=0)
            {
                ans+=val[tmp];
                val[tmp]=0;
                tmp=fail[tmp];
            }
            i++;
        }
        return ans;
    }
}AC;

int N;
char str[MAXN];

int main()
{
    AC.Initialize();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        char tmp[60];
        scanf("%d",&N);
        AC.Reset();
        for(int i=0;i<N;i++)
        {
            scanf("%s",tmp);
            AC.Insert(tmp,1);
        }
        AC.Construct();
        scanf("%s",str);
        printf("%d\n",AC.Search(str));
    }
    return 0;
}
