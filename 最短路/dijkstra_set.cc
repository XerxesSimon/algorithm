#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
const int M = 2e5 + 9;
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
    bool operator < (const node b) const {
        if (dis != b.dis) {
            return dis > b.dis;
        }
        return u < b.u;
    }
};
int dis[N] ;
void dijkstra(int u)
{
    memset(dis, inf, sizeof dis);
    dis[u] = 0;
    set<node> q;
    q.insert((node){u, 0});
    while (!q.empty()) {
        node now = (*q.begin());
        q.erase(q.begin());
        u = now.u;
        for (int i = p[u]; ~i; i = e[i].next) {
            int v = e[i].v;
            int w = e[i].w;
            if (dis[v] > dis[u] + w) {
                q.erase((node){v, dis[v]});
                dis[v] = dis[u] + w;
                q.insert((node){v, dis[v]});
            }
        }
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
        dijkstra(1);
        cout << dis[n] << endl;
    }
    return 0;
}
