#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
const int M = 22;

struct edge {
    int v, w, next;
} e[N];
int p[N], eid;
void init()
{
    memset(p, -1, sizeof p);
    eid = 0;
}
void add(int u, int v, int w)
{
    e[eid].v = v;
    e[eid].w = w;
    e[eid].next = p[u];
    p[u] = eid++;
}

int h[N], dis[N], f[N][M + 3];

int lca(int x, int y)
{
    if (h[x] < h[y]) {
        swap(x, y);
    }
    for (int i = M; i >= 0; i--) {
        if (h[f[x][i]] >= h[y]) {
            x = f[x][i];
        }
    }
    if (x == y) {
        return x;
    }
    for (int i = M; i >= 0; i--) {
        if (f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}

void dfs(int u, int pre)
{
    h[u] = h[pre] + 1;
    for (int i = 0; i <= M; i++) {
        f[u][i + 1] = f[f[u][i]][i];
    }
    for (int i = p[u]; ~i; i = e[i].next) {
        int v = e[i].v;
        if (v != pre) {
            f[v][0] = u;
            dis[v] = dis[u] + e[i].w;
            dfs(v, u);
        }
    }
}

int main()
{
    init();
    int n, m;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        add(x, y, 1);
        add(y, x, 1);
    }
    dfs(1, 0);
    cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        cout << dis[x] + dis[y] - 2 * dis[lca(x, y)] << endl;
    }
    return 0;
}
