#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod = 998244353;
int n, m, k, ans;
int v[313], fac[313], inv[313], c[313];
int cal(LL x) {
	int cnt = 0;
	while (x) x ^= x & -x, cnt++;
	return cnt;
}
int qpow(int a, int b) {
	int ans = 1;
	for (; b; b >>= 1) {
		if (b & 1) ans = 1ll * ans * a % mod;
		a = 1ll * a * a % mod;
	}
	return ans;
}
int cal() {
	int las = 0, cnt = 0;
	for (int i = 0; i <= m; ++i) {
		las = c[i] + (las >> 1);
		cnt += las & 1;
	}
	return cnt += cal(las >> 1);
}
void dfs(int dep, int cnt) {
	if (dep == m - 1) {
		c[m] = n - cnt;
		if (cal() <= k) {
			int sum = fac[n];
			for (int i = 0; i <= m; ++i) sum = 1ll * sum * qpow(v[i], c[i]) % mod * inv[c[i]] % mod;
			ans = (ans + sum) % mod;
		}
		return;
	}
	for (int i = 0; i <= n - cnt; ++i) {
		c[dep + 1] = i; dfs(dep + 1, cnt + i);
	}
}
int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	cin >> n >> m >> k; for (int i = 0; i <= m; ++i) cin >> v[i];
	fac[0] = 1; for (int i = 1; i <= n; ++i) fac[i] = 1ll * fac[i - 1] * i % mod;
	inv[n] = qpow(fac[n], mod - 2); for (int i = n; i; --i) inv[i - 1] = 1ll * inv[i] * i % mod;
	dfs(-1, 0);
	cout << ans << '\n';
	return 0;
}
