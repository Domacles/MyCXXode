/************
	特殊图中求哈密顿回路,这个特殊图实际上是由很多个度为2的节点将一些完全图联通起来形成的图
	
	思路:使用并查集将完全图缩成一个点,然后统计新图中各点的度,判断是否能形成欧拉回路;
		如果能形成,则找出欧拉回路,然后,对于新图中的度数大于2的点,再加一条内部的路径
************/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 10000;
const int M = 200000;

int n, m, a[M], b[M], edge_count, first_edge[N], from[M], to[M], next_edge[M], degree[N], parent[N];
bool visit[N];
vector <int> path;

int find(int i) {
    if (parent[i] != i) {
        parent[i] = find(parent[i]);
    }
    return parent[i];
}

void add_edge(int u, int v) {
    from[edge_count] = u;
    to[edge_count] = v;
    next_edge[edge_count] = first_edge[find(u)];
    first_edge[find(u)] = edge_count ++;
}

void dfs(int u) {
    for (int iter = first_edge[u]; iter != -1; iter = next_edge[iter]) {
        if (!visit[iter >> 1]) {
            visit[iter >> 1] = true;
            dfs(find(to[iter]));
            path.push_back(to[iter]);
            path.push_back(from[iter]);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    memset(degree, 0, sizeof(degree));
    for (int i = 0; i < m; ++ i) {
        scanf("%d%d", a + i, b + i);
        a[i] --;
        b[i] --;
        degree[a[i]] ++;
        degree[b[i]] ++;
    }
    for (int i = 0; i < n; ++ i) {
        parent[i] = i;
    }
    for (int i = 0; i < m; ++ i) {
        if (degree[a[i]] > 2 && degree[b[i]] > 2 && find(a[i]) != find(b[i])) {
            parent[find(a[i])] = find(b[i]);
        }
    }
    edge_count = 0;
    memset(first_edge, -1, sizeof(first_edge));
    memset(degree, 0, sizeof(degree));
    for (int i = 0; i < m; ++ i) {
        if (find(a[i]) != find(b[i])) {
            degree[find(a[i])] ++;
            degree[find(b[i])] ++;
            add_edge(a[i], b[i]);
            add_edge(b[i], a[i]);
        }
    }
    bool check = true;
    for (int i = 0; i < n; ++ i) {
        if (parent[i] == i) {
            check &= (degree[i] & 1) == 0;
        }
    }
    if (!check) {
        puts("-1");
    } else {
        int start = 0;
        while (parent[start] != start) {
            start ++;
        }
        memset(visit, 0, sizeof(visit));
        dfs(start);
        if (path.back() == path.front()) {
            path.pop_back();
        }
        for (int i = 0; i < (int)path.size(); ++ i) {
            if (i == 0 || path[i - 1] != path[i]) {
                printf("%d ", path[i] + 1);
            }
        }
        puts("");
    }
    return 0;
}

