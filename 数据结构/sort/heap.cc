#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 9;
int A[N], len;

void push(int val)
{
    A[++len] = val;

    int p = len;
    while (p > 1 && A[p / 2] > A[p]) {
        swap(A[p / 2], A[p]);
        p /= 2;
    }
}

int pop()
{
    int res = A[1];
    A[1] = A[len--];

    int p = 1, t;
    while (p * 2 <= len) {
        if (p * 2 + 1 > len || A[p * 2] <= A[p * 2 + 1]) {
            t = p * 2;
        } else {
            t = p * 2 + 1;
        }
        if (A[p] > A[t]) {
            swap(A[p], A[t]);
            p = t;
        } else {
            break;
        }
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            push(x);
        }
        while (n--) {
            cout << pop() << (n == 0 ? '\n' : ' ');
        }
    }
}
