#include <bits/stdc++.h>
using namespace std;

const int N = 101;
const int P = 998244353;
int a[N], n, v[N], m, k;
int XGJDXJ[N];
int sum;

void init() {
	XGJDXJ[0] = 1;
	for (int i = 1; i < N; i++) 
		XGJDXJ[i] = XGJDXJ[i - 1] << 1;
}

void dfs(int dep) {
	if (dep > n) {
		int s = 0, res = 1;
		for (int i = 1; i <= n; i++) {
			res = 1ll * res * v[a[i]] % P;
			s += XGJDXJ[a[i]];
		}
		int cnt = 0;
		while (s) {
			cnt++, s -= s & -s;
		}
		if (cnt > k) return;
		sum = (sum + res) % P;
		return;
	}
	for (int i = 0; i <= m; i++) {
		a[dep] = i;
		dfs(dep + 1);
	}
}

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);

	init();
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i <= m; i++)
		scanf("%d", &v[i]);
	dfs(1);
	cout << sum << endl;

	return 0;
}


