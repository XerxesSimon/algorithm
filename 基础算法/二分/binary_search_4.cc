#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int a[N];

int ok(int l, int r, int x)
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

int calL(int l, int r, int x)
{
    int res = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (a[mid] >= x) {
            r = mid - 1;
            res = mid;
        } else {
            l = mid + 1;
        }
    }
    return res;
}
int calR(int l, int r, int x)
{
    if (a[r] <= x) {
        return r + 1;
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
    return res;
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
        if (!ok(0, n - 1, x)) {
            puts("0");
        } else {
            printf("%d\n", calR(0, n - 1, x) - calL(0, n - 1, x));
        }
    }
    return 0;
}
