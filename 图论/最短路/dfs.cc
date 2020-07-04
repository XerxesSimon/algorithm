#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 9;
const int M = 2e4 + 9;
const int inf = 0x3f3f3f3f;

struct edge {
    int v;
    int w;
    int next;
} e[M];

int p[N], eid;
int dis[N];
void init()
{
    eid = 0;
    memset(p, -1, sizeof p);
    memset(dis, inf, sizeof dis);
}
void add(int u, int v, int w)
{
    e[eid].v = v;
    e[eid].w = w;
    e[eid].next = p[u];
    p[u] = eid++;
}

void dfs(int u, int d)
{
    if (dis[u] <= d) {
        return;
    }
    dis[u] = d;
    for (int i = p[u]; ~i; i = e[i].next) {
        int v = e[i].v;
        int w = e[i].w;
        dfs(v, dis[u] + w);
    }
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
        dfs(1, 0);
        cout << dis[n] << endl;
    }
    return 0;
}
