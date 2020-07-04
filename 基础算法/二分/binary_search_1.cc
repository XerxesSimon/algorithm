#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int a[N];

int cal(int l, int r, int x)
{
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (a[mid] == x) {
            return 1;
        }
        if (a[mid] > x) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return 0;
}

int main()
{
    int n;
    int m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    while (m--) {
        int x;
        scanf("%d", &x);
        if (cal(0, n - 1, x)) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
}
