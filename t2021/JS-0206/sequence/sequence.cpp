#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
//#include <cstdlib>
using namespace std;
typedef long long ll;
typedef long long lll;
typedef unsigned long long ull;

inline int read() {
	int val = 0, neg = 1;
	char ch = getchar();
	while (ch > '9' || ch < '0') {
		if (ch == '-') neg = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		val = val * 10 + ch - 48;
		ch = getchar();
	}
	return val * neg;
}

const int MOD = 998244353, N = 35, M = 105;
const lll one = 1;

int a[N], m, n, k, v[M], cnt[M];
ll f[M], inv[M];
ll ans = 0;

bool cnt1() {
	lll tmp = 0;
	for (int i = 1; i <= n; i++) {
		tmp += (one << a[i]);
	}
	int cnt = 0;
	while (tmp) {
		if (tmp & 1) cnt++;
		tmp >>= 1;
	}
	if (cnt <= k) return true;
	else return false;
}

ll qpow(int a, int b) {
	ll res = 1, base = a;
	while (b) {
		if (b & 1) res = res * base % MOD;
		base = base * base % MOD;
		b >>= 1;
	}
	return res;
}

ll comb(ll n, ll m) {
	return f[n] * inv[m] % MOD * inv[n - m] % MOD;
}

void dfs(int now) {
	for (int i = a[now - 1]; i <= m; i++) {
		a[now] = i;
		if (now < n) dfs(now + 1);
		else if (cnt1()) {
			memset(cnt, 0, sizeof(int) * (m + 1));
			for (int j = 1; j <= n; j++) {
				cnt[a[j]]++;
			}
			ll tmp = 1, cc = 1, dd = 0;
			for (int j = 0; j <= m; j++) {
				cc = cc * comb((dd + cnt[j]) % MOD, dd);
				dd = (dd + cnt[j]) % MOD;
				tmp = tmp * qpow(v[j], cnt[j]) % MOD;
			}
			ans = (ans + tmp * cc % MOD) % MOD;
		}
	}
}

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 0; i <= m; i++) {
		v[i] = read();
	}
	
	f[0] = 1;
	for (int i = 1; i < M; i++) f[i] = f[i - 1] * i % MOD;
	inv[M - 1] = qpow(f[M - 1], MOD - 2);
	for (int i = M - 2; i >= 0; i--) {
		inv[i] = inv[i + 1] * (i + 1) % MOD;
	}
	
	dfs(1);
//	cout << sz << endl;
	printf("%lld\n", ans);
	return 0;
}

