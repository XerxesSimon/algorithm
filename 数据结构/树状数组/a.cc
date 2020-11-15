#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 9;
int c[N];

void add(int x, int val) {
    while (x < N) {
        c[x] += num;
        x += x & -x;
    }
}

int sum(int x) {
    int res = 0;
    while (x) {
        res += c[x];
        x -= x & -x;
    }
    return res;
}

int main() {
    int t;
    int n;
    int x;
    int y;
    string s;
    cin >> t;
    for (int tot = 1; tot <= t; tot++) {
        cout << "Case " << tot << ":" << endl;
        memset(a, 0, sizeof a);
        memset(c, 0, sizeof c);
        cin >> n;
        for (int i = 0; i <= n; i++) {
            cin >> x;
            add(i + 1, x);
        }
        while (cin >> s, s[0] != 'E') {
            cin >> x >> y;
            if (s[0] == 'Q') {
                cout <<  sum(y) - sum(x - 1) << endl;
            } else if (s[0] == 'A') {
                add(x, y);
            } else if (s[0] == 'S') {
                add(x, -y);
            }
        }
    }
    return 0;
}
// https://vjudge.net/problem/HDU-1166
// https://www.cnblogs.com/xenny/p/9739600.html
