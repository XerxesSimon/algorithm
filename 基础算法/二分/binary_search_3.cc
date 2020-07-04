#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int a[N];

int cal(int l, int r, int x)
{
    if (a[r] <= x) {
        return -1;
    }
    int res = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (a[mid] > x) {
            r = mid - 1;
            res = mid;
        } else {
            l = mid + 1;
        }
    }
    return a[res];
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
        printf("%d\n", cal(0, n - 1, x));
    }
    return 0;
}
