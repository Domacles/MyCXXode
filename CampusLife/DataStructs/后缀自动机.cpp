struct SAM {
    struct Node {
        int ch[26];
        int f, len;
        void init() {
            f = -1, len = 0;
            memset(ch, 0xff, sizeof (ch));
        }
    };
    Node sn[N<<1];
    int idx, last;
    void init() {
        idx = last = 0;
        sn[idx++].init();
    }
    int newnode() {
        sn[idx].init();
        return idx++;
    }
    void add(int c) {
        int end = newnode();
        int tmp = last;
        sn[end].len = sn[last].len + 1;
        for ( ; tmp != -1 && sn[tmp].ch[c] == -1; tmp = sn[tmp].f) {
            sn[tmp].ch[c] = end;
        }
        if (tmp == -1) sn[end].f = 0; // 所有的上一轮可接受点都没有指向字符c的孩子节点 
        else {
            int nxt = sn[tmp].ch[c];
            if (sn[tmp].len + 1 == sn[nxt].len) sn[end].f = nxt; // 如果可接受点有向c的转移，且长度只加1，那么该孩子可以替代当前的end，并且end的双亲指向该孩子 
            else {
                int np = newnode();
                sn[np] = sn[nxt];
                sn[np].len = sn[tmp].len + 1;
                sn[end].f = sn[nxt].f = np;
                for (; tmp != -1 && sn[tmp].ch[c] == nxt; tmp = sn[tmp].f) {
                    sn[tmp].ch[c] = np;
                }
            }
        }
        last = end;
    }
};