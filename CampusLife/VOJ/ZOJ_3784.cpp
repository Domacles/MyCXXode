/***************
通过AC自动机，建立不含禁止串的图，看这个图中每个强联通分量是否只有简单圈。假如是，最后建立的无穷串中肯定有循环节，否则输出Yes。
***************/
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

const int maxn = 1e5+10;

#define MAXC 26
#define MAXQ 100005

vector<int>G[maxn];
int N,M;

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

        p->val=val;
        p->cnt++;
    }

    void construct_tire(){
        ACNode *now,*son,*tmp;
        root->fail=NULL;
        Q.push(root);

        while(!Q.empty()){
            now=Q.front();Q.pop();

            if(now->fail){

                // Update the val of now
                //now->val+=now->fail->val;
                now->val|=now->fail->val;

                if(now->isReceiving()){
                    for(int i=0;i<MAXC;i++) now->next[i]=now;
                    continue;
                }
            }

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

    void Build_Graph(){
        for(int i=0;i<nodeCount;i++){
            ACNode *p=nodes[i];
            if(p->val) continue;
            for(int i=0;i<M;i++){
                if(p->next[i]==NULL) continue;
                if(p->next[i]->val) continue;
                G[1+(p->id)].push_back(1+(p->next[i]->id));//只需要使用next，fail是代表失败后的next位置
            }
        }
    }
}AC;

int Stack[maxn],InStack[maxn],top;
int Belong[maxn],dfn[maxn],low[maxn],Index;
vector<int>SCC[maxn];
int scc;

void init()
{
    for(int i=0;i<=AC.nodeCount;i++)
        G[i].clear(),SCC[i].clear();
    scc=0;
    top=0;
    Index=0;
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(Belong,0,sizeof(Belong));
    memset(Stack,0,sizeof(Stack));
    memset(InStack,0,sizeof(InStack));
}

void DFS(int u,int f)
{
    dfn[u]=low[u]=++Index;
    Stack[top++]=u, InStack[u]=1;
    for(int i=0;i<(int)G[u].size();i++){
        int v=G[u][i];
        if(!dfn[v]){
            DFS(v,u);
            low[u]=min(low[u],low[v]);
        }else if(InStack[v])
            low[u]=min(low[u],dfn[v]);
    }
    int j;
    if(dfn[u]==low[u]){
        scc++;
        while((j=Stack[--top])){//node >=1
            InStack[j]=0;
            Belong[j]=scc;
            SCC[scc].push_back(j);
            if(j==u) break;
        }
    }
}

void solve()
{
    for(int i=0;i<AC.nodeCount;i++){
        if(!dfn[i]) DFS(i,i);
    }
    int flag=0;
    for(int i=1;i<=AC.nodeCount;i++){
        int cnt=0;
        for(int j=0;j<(int)G[i].size();j++)
            if(Belong[G[i][j]]==Belong[i]) cnt++;
        if(cnt>=2) {flag=1;break;}
    }
    if(flag) puts("Yes");
    else puts("No");
}

char str[1111];

int main()
{
    //freopen("r.txt","r",stdin);
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&M);
        AC.init();
        while(N--){
            scanf("%s",str);
            AC.insert(str,1);
        }
        AC.construct_tire();
        init();
        AC.Build_Graph();
        solve();
    }
    return 0;
}
