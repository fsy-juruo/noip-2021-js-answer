#include <bits/stdc++.h>
using namespace std;
int n, m, k;
const int N = 107;
const int mod = 998244353;
int v[N], a[N], cnt[N];
#define ll long long
ll pow2[N], inv[N], fac[N], ans;
ll ksm (ll x, int y) {
	ll res = 1;
	while (y) {
		if (y & 1) res = res * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return res;
}
int count (ll x) { 
	int res = 0;
	while (x) {
		if (x & 1) res++;
		x >>= 1;
	}
	return res;
}
void dfs (ll x, int p, int last) {
	if (x < 0) return;
	if (x > 1ll * pow2[m] * (n - p)) return;
	if (p == n) {
		if (x) return;
		ll res = 1, t = fac[n];
		for (int i = 1; i <= n; i++)
			res = res * v[a[i]] % mod, cnt[a[i]]++;
		for (int i = 0; i <= m; i++)
			t = t * inv[cnt[i]] % mod, cnt[i] = 0;
		ans = (ans + res * t) % mod;
		return;
	}
	for (int i = last; i <= m; i++) {
		a[p + 1] = i;
		dfs (x - pow2[i], p + 1, i);
	}
}
int main() {
	freopen ("sequence.in", "r", stdin);
	freopen ("sequence.out", "w", stdout);
	cin >> n >> m >> k;
	fac[0] = 1;
	for (int i = 1; i <= 50; i++) fac[i] = fac[i - 1] * i % mod;
	inv[50] = ksm (fac[50], mod - 2);
	for (int i = 49; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
	for (int i = 0; i <= m; i++) cin >> v[i];
	pow2[0] = 1;
	for (int i = 1; i <= 50; i++) pow2[i] = pow2[i - 1] * 2;
	for (ll i = n; i <= 1ll * n * pow2[m]; i++)
		if (count(i) <= k) dfs(i, 0, 0);
	cout << ans;
	fclose (stdin);
	fclose (stdout);
	return 0;
}
