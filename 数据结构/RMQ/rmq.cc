#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 9;
const int M = 22;

int lg[M], a[N], f[N][M];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    lg[0] = -1;
    for (int i = 1; i <= n; i++) {
        lg[i] = lg[i >> 1] + 1;
        f[i][0] = a[i];
    }
    for (int j = 1; j < M; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int i = 1; i <= n; i++) {
        int x = max(1, i - m);
        int y = i - 1;
        if (y <= 0) {
            cout << 0 << endl;
            continue;
        }
        int s = lg[y - x + 1];
        cout << min(f[x][s], f[y - (1 << s) + 1][s]) << endl;
    }
    return 0;
}

// https://www.luogu.com.cn/problem/P1440
