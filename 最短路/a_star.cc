#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 9;
const int M = 2e4 + 9;
const int inf = 0x3f3f3f3f;

struct edge {
    int v, w, next;
} e[M];
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
struct node {
    int u, dis;
    friend bool operator < (const node a, const node b) {
        if (a.dis != b.dis) {
            return a.dis > b.dis;
        }
        return a.u < b.u;
    }
};
int g[N]; // g[i]  表示估计未来的长度，g[i] 表示从 i 到 n 的距离
void dijkstra(int u)
{
    memset(g, inf, sizeof g);
    g[u] = 0;
    set<node> q;
    q.insert((node){u, 0});
    while (!q.empty()) {
        node now = (*q.begin());
        q.erase(q.begin());
        u = now.u;
        for (int i = p[u]; ~i; i = e[i].next) {
            int v = e[i].v;
            int w = e[i].w;
            if (g[v] > g[u] + w) {
                q.erase((node){v, g[v]});
                g[v] = g[u] + w;
                q.insert((node){v, g[v]});
            }
        }
    }
}
struct data {
    int u;
    int dis; // dis 表示已经走过的路径长度
    bool vis[N];
    friend bool operator < (const data a, const data b) {
        return a.dis + g[a.u] > b.dis + g[b.u];
    }
};
int a_star(int u, int n)
{
    int cnt = 0;
    priority_queue<data> q;
    data s;
    s.u = u;
    s.dis = 0;
    memset(s.vis, false, sizeof s.vis);
    s.vis[u] = true;
    q.push(s);
    while (!q.empty()) {
        s = q.top();
        q.pop();
        if (s.u == n) {
            cnt++;
            if (cnt == 1) { // 第一短路的意思
                return s.dis;
            }
        }
        for (int i = p[u]; ~i; i = e[i].next) {
            int v = e[i].v;
            int w = e[i].w;
            if (s.vis[v]) {
                continue;
            }
            data tmp = s;
            tmp.u = v;
            tmp.dis = s.dis + w;
            tmp.vis[v] = true;
            q.push(tmp);
        }
    }
    return -1;
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
        dijkstra(n); // 如果是有向图，需要构建反向图，求出预估值 g
        cout << a_star(1, n) << endl;
    }
    return 0;
}
