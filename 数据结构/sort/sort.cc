#include <bits/stdc++.h>
using namespace std;

int a[1010];

void qs(int s, int e)
{
    if (s >= e) {
        return;
    }
    int l = s, r = e;
    int x = a[s];
    while (l < r) {
        while (l < r && a[r] >= x) {
            r--;
        }
        a[l] = a[r];
        while (l < r && a[l] <= x) {
            l++;
        }
        a[r] = a[l];
    }
    a[r] = x;
    qs(s, r - 1);
    qs(r + 1, e);
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
        qs(0, n - 1);
        for (int i = 0; i < n; i++) {
            cout << a[i] << (i == n - 1 ? '\n' : ' ');
        }
    }
    return 0;
}
