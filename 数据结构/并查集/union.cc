#include <bits/stdc++.h>
using namespace std;

int n, m;
int fa[1010];

int finds(int x)
{
    if (fa[x] != x) {
        fa[x] = finds(fa[x]);
    }
    return fa[x];
}

void merge(int x, int y)
{
    int fx = finds(x);
    int fy = finds(y);
    if (fx != fy) {
        fa[fx] = fy;
    }
}

int main()
{
    while (cin >> n >> m && n) {
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
        }
        while (m--) {
            int x, y;
            cin >> x >> y;
            merge(x, y);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (fa[i] == i) {
                ans++;
            }
        }
        cout << ans - 1 << endl;
    }
    return 0;
}
