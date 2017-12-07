#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int,int> PII;
typedef long long ll;

const int maxn =1e6+10;

#define MAXC 26
#define MAXQ 555550

struct ACNode{
    ACNode *fail;
    ACNode *next[MAXC];

    int id;
    int val;
    int cnt;

    void reset(int x){
        id=x;
        val=0;
        cnt=0;
        fail=NULL;
        memset(next,0,sizeof(next));
    }

    bool isReceiving(){
        return val!=0;
    }
};

class ACAutoman{
public:
    ACNode* nodes[MAXQ];
    int nodesMax;
    ACNode* root;
    int nodeCount;

    /*data structure*/
    int ID[256];
    int IDSize;

    queue<ACNode*> Q;

    ACAutoman(){nodesMax=0;}
    void init(){
        nodeCount=0;
        IDSize=0;
        root=getNode();
        memset(ID,-1,sizeof(ID));
    }

    ACNode* getNode(){
        if(nodeCount>=nodesMax){
            nodes[nodesMax++]=new ACNode();
        }
        ACNode *p=nodes[nodeCount];
        p->reset(nodeCount++);
        return p;
    }

    int getCharID(unsigned char c,int needcreate){
        if(!needcreate) return ID[c];
        if(ID[c]==-1) ID[c]=IDSize++;
        return ID[c];
    }

    void insert(char *str,int val){
        ACNode *p=root;
        int id;
        for(int i=0;str[i];i++){
            id=getCharID(str[i],1);

            if(p->next[id]==NULL)
                p->next[id]=getNode();
            p=p->next[id];
        }

        //p->val|=val;
        p->cnt++;
    }

    void construct_tire(){
        ACNode *now,*son,*tmp;

        root->fail=NULL;

        //while(!Q.empty()) Q.pop();

        Q.push(root);

        while(!Q.empty()){
            now=Q.front();Q.pop();

/*  ½ûÖ¹ÐòÁÐÖÐvalÐë×ªÒÆ
            if(now->fail){

                // Update the val of now
                //now->val+=now->fail->val;
                //now->val|=now->fail->val;

                if(now->isReceiving()){
                    for(int i=0;i<MAXC;i++)
                        now->next[i]=now;
                    continue;
                }
            }
*/
            for(int i=0;i<MAXC;i++){
                son=now->next[i];
                tmp=(now==root)?root:now->fail->next[i];
                if(son==NULL)
                    now->next[i]=tmp; //Not is son !!
                else{
                    son->fail=tmp;
                    Q.push(son);
                }
            }
        }
    }

    int query(char* str){
        int cnt=0;
        ACNode *p=root;
        ACNode *tmp=NULL;
        int id;
        for(int i=0;str[i];i++){
            id=getCharID(str[i],0);
            if(id==-1){
                p=root;continue;
            }
            p=p->next[id];
            tmp=p;
            while(tmp!=root && tmp->cnt!=-1){
                if(tmp->cnt){
                    cnt+=tmp->cnt;
                    tmp->cnt=-1;
                }
                tmp=tmp->fail;
            }
        }
        return cnt;
    }
}AC;

char S[maxn];

int main()
{
    freopen("r.txt","r",stdin);
    int T; scanf("%d",&T);
    for(int t=1;t<=T;t++){
        AC.init();
        int N; scanf("%d",&N);
        for(int i=0;i<N;i++){
            char str[101]; scanf("%s",str);
            AC.insert(str,1);
        }
        AC.construct_tire();
        scanf("%s",S);
        printf("%d\n",AC.query(S));
    }
    return 0;
}
