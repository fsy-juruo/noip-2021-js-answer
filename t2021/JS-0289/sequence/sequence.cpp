#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 998244353;
const int MAXM = 110;
int n, m, k;
ll ans;
ll v[MAXM], a[MAXM];
ll d[11] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

ll maths() {
	ll res = (v[a[1]] + MOD) % MOD;
	for (int i(2); i <= n; ++i)
		res = (res * v[a[i]] + MOD) % MOD;
	return res;
}

void dfs(int pos) {
	if (pos == n + 1) {
		int s = 0, tot = 0;
		for (int i(1); i <= n; ++i)
			s += d[a[i]];
		while (s) {
			if ((s & 1)) tot++;
			s = (s >> 1);
		}
		if (tot <= k) ans = (ans + maths() + MOD) % MOD;
		return;
	}
	for (int i(0); i <= m; ++i) {
		a[pos] = i;
		dfs(pos + 1);
	}
}

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i(0); i <= m; ++i)
		cin >> v[i];
	dfs(1);
	cout << ans << endl;
	return 0;
}

