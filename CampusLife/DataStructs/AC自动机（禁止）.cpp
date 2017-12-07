#include <queue>
#include <stack>
#include <cstdio>
#include <cstring>
using namespace std;
const int CHAR = 26;
const int TOT = 100005;
int next[TOT][CHAR], fail[TOT];
bool virus[TOT];
int L, root;
int m;
int newNode() {
    for (int i=0; i<CHAR; i++)
        next[L][i]=-1;
    fail[L]=0;
    virus[L]=0;
    return L++;
}
void insert(char *s) {
    int now=root;
    for (int i=0; s[i]; i++) {
        int ch=s[i]-'a';
        if (next[now][ch]==-1)
            next[now][ch]=newNode();
        now=next[now][ch];
    }
    virus[now]=1;
}
void build() {
    queue<int> Q;
    for (int i=0; i<m; i++) {
        if (next[root][i]==-1)
            next[root][i]=root;
        else {
            fail[next[root][i]]=root;
            Q.push(next[root][i]);
        }
    }
    while (!Q.empty()) {
        int now=Q.front(); Q.pop();
        virus[now]|=virus[fail[now]];
        for (int i=0; i<m; i++) {
            if (next[now][i]==-1)
                next[now][i]=next[fail[now]][i];
            else {
                fail[next[now][i]]=next[fail[now]][i];
                Q.push(next[now][i]);
            }
        }
    }
}
///////////////////////////////////////////////////////////////////////////
const int maxn = TOT;
const int maxm = TOT*26;
int head[maxn], e, Time, id[maxn], dfn[maxn], low[maxn], sz;
bool vis[maxn];
stack<int> s;
struct node
{
    int v, next;
}edge[maxm];
void add_edge(int u, int v)
{
    edge[e].v=v;
    edge[e].next=head[u];
    head[u]=e++;
}
void init()
{
    memset(head, -1, sizeof(head));
    memset(id, 0, sizeof(id));
    memset(vis, 0, sizeof(vis));
    memset(dfn, 0, sizeof(dfn));
    while (!s.empty()) s.pop();
    e=Time=sz=0;
    L=0;
    root=newNode();
}
int Min(int a, int b)
{
    if (a<=b) return a;
    return b;
}
void tarjan(int u)
{
    int v;
    dfn[u]=low[u]=++Time;
    s.push(u);
    vis[u]=1;
    for (int i=head[u]; i!=-1; i=edge[i].next) {
        v=edge[i].v;
        if (!dfn[v]) {
            tarjan(v);
            low[u]=Min(low[u], low[v]);
        }
        else if (vis[v]) low[u]=Min(low[u], dfn[v]);
    }
    if (dfn[u]==low[u]) {
        sz++;
        do {
            v=s.top();
            s.pop();
            id[v]=sz;
            vis[v]=0;
        }while(v!=u);
    }
}
bool judge()
{
    int cnt;
    for (int i=0; i<L; i++) {
        cnt=0;
        for (int j=head[i]; j!=-1; j=edge[j].next) {
            if (id[i]==id[edge[j].v]) cnt++;
            if (cnt>=2) return 1;
        }
    }
    return 0;
}
char str[1005];
int main()
{
    int cas, n;
    scanf("%d", &cas);
    while(cas--) {
        scanf("%d %d", &n, &m);
        init();
        while (n--) {
            scanf(" %s", str);
            insert(str);
        }
        build();
        for (int i=0; i<L; i++) {
            if (virus[i]) continue;
            for (int j=0; j<m; j++) {
                if (virus[next[i][j]]) continue;
                add_edge(i, next[i][j]);
            }
        }
        for (int i=0; i<L; i++) {
            if (!dfn[i])
                tarjan(i);
        }
        if (judge()) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}