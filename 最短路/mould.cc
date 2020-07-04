#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 9;
const int N = 2e2 + 9;
const int inf = 0x3f3f3f3f;

struct edge {
    int v;
    int w;
    int next;
} e[M];

int p[N], eid;
void init()
{
    eid = 0;
    memset(p, -1, sizeof p);
}
void add(int u, int v, int w)
{
    e[eid].v = v;
    e[eid].w = w;
    e[eid].next = p[u];
    p[u] = eid++;
}

int main()
{
    int n;
    int m;
    while (cin >> n >> m, n | m) {
        init();
        while (m--) {
            int u, v, w;
            cin >> u >> v >> w;
            add(u, v, w);
            add(v, u, w);
        }
    }
    return 0;
}
