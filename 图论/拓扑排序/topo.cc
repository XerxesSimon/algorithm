#include <bits/stdc++.h>
using namespace std;
const long long MAX_N = 500005;
const long long MAX_M = 500005;
queue<long long> q;
struct edge {
	long long v, next;
	long long len;
} e[MAX_M];
long long p[MAX_N], eid;
void init() {
	memset(p, -1, sizeof(p));
	eid = 0;
}
void insert(long long u, long long v) {
	e[eid].v = v;
	e[eid].next = p[u];
	p[u] = eid++;
}
long long chu[5005];
long long ru[5005];
long long f[5005];
int main() {
	init();
	long long n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		insert(u, v);
		chu[u]++;
		ru[v]++;
	}
	for(int i = 1; i <= n; i++){
		if(ru[i] == 0){
			f[i] = 1;
			q.push(i);
		}
	}
	long long ans = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = p[u]; i != -1; i = e[i].next){
			int b = e[i].v;//�ӽڵ�
			f[b] += f[u];
			ru[b]--;
			if(chu[b] == 0){
				ans += f[u];
			}
            if (!ru[b]) {
                q.push(b);
            }
		}
	}
	cout << ans << endl;
	return 0;
}

// https://www.luogu.com.cn/problem/P4017
