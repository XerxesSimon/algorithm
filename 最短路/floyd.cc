#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 9;
const int inf = 0x3f3f3f3f;
int n;
int m;
int f[N][N];

void floyd()
{
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    return;
}

int main()
{
    while (cin >> n >> m, n | m) {
        memset(f, inf, sizeof f);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            f[u][v] = f[v][u] = w;
        }
        floyd();
        cout << f[1][n] << endl;
    }
    return 0;
}
