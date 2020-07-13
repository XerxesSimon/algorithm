#include <bits/stdc++.h>
using namespace std;

int a[1010], f[1010];

void merge(int l, int m, int r)
{
    int i = l, j = m + 1, k = 0;
    int n = r;
    while (i <= m || j <= n) {
        if (j > n || (i <= m && a[i] <= a[j])) {
            f[k++] = a[i++];
        } else {
            f[k++] = a[j++];
        }
    }
    for (int i = 0; i < k; i++) {
        a[l + i] = f[i];
    }
}

void sort(int l, int r)
{
    if (l < r) {
        int m = l + r >> 1;
        sort(l, m);
        sort(m + 1, r);
        merge(l, m, r);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(0, n - 1);
        for (int i = 0; i < n; i++) {
            cout << a[i] << (i == n - 1 ? '\n' : ' ');
        }
    }
    return 0;
}
