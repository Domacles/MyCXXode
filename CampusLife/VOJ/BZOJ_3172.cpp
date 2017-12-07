/****
	首先，由于无法快速确定某一节点为某一字符串的末尾节点，因此，
	任何节点按照fail指针的指向方向，从下至上，将节点的数量（fail指针链）逐步统计到fail的记录条目上。
	
	最后，找到每一字符串的结尾节点，此时统计条目上的数字就是答案。

****/
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

const int maxn =1e6;

#define MAXC 26
#define MAXQ 3000000

vector<string> v;

struct ACNode{
    ACNode* fail;
    ACNode* next[MAXC];

    int id;
    int cnt;

    int val;

    void reset(int x){
        id=x;
        cnt=0;
        val=0;
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

    /**data structure**/
    int ID[256];
    int IDSize;

    queue<ACNode*> Q;
    stack<ACNode*> Q1;

    ACAutoman(){nodesMax=0;}
    void init(){
       nodeCount=0;
       root=getNode();

       IDSize=0;
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

    int getcharID(unsigned char c,int needcreate){
        if(!needcreate) return ID[c];
        if(ID[c]==-1) ID[c]=IDSize++;
        return ID[c];
    }

    void insert(char *str,int val){
        ACNode* p=root;
        int id;

        for(int i=0;str[i];i++){
            id=getcharID(str[i],1);

            if(p->next[id]==NULL)
                p->next[id]=getNode();
            p=p->next[id];
            p->val++;
        }
        p->cnt++;
    }

    void construct_tire(){
        ACNode *now;
        ACNode *son;
        ACNode *tmp;

        root->fail=NULL;

        Q.push(root);
        Q1.push(root);
        while(!Q.empty()){
            now=Q.front();Q.pop();

            for(int i=0;i<MAXC;i++){
                son=now->next[i];
                tmp=(now==root)?root:now->fail->next[i];
                if(son==NULL)
                    now->next[i]=tmp;//Not is son !!
                else{
                    son->fail=tmp;
                    Q.push(son);
                    Q1.push(son);
                }
            }
        }
        /* 按照fail构造的晚早顺序，更新now所对应的fail即可 */
        while(!Q1.empty()){
            now=Q1.top(); Q1.pop();
            tmp=now->fail;
            if(tmp==NULL) continue;
            tmp->val+=now->val;
        }
    }

    int work(string str){
        int cnt=0;
        ACNode *p=root;
        int id;

        for(int i=0;str[i];i++){
            id=getcharID(str[i],0);
            p=p->next[id];
        }
        cnt+=p->val;// answer
        return cnt;
    }

}AC;

char temp[maxn];

int main()
{
    //freopen("r.txt","r",stdin);
    int N; scanf("%d",&N);
    AC.init();
    for(int i=0;i<N;i++){
        scanf("%s",temp);
        AC.insert(temp,1);
        v.push_back(string(temp));
    }
    AC.construct_tire();
    for(int i=0;i<N;i++){
        printf("%d\n",AC.work(v[i]));
    }
    return 0;
}
