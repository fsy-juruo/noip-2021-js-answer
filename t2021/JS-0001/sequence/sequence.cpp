#include <bits/stdc++.h>
using namespace std;

const int maxn = 35;
const int maxm = 105;
const int mod = 998244353;
int n, m, k, ans;
int v[maxm], dp[maxm][maxn][maxn][maxn], fac[maxn], ifac[maxn];

void add(int &a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	fac[0] = ifac[0] = fac[1] = ifac[1] = 1;
	for (int i = 2; i <= n; i++) {
		fac[i] = 1LL * fac[i - 1] * i % mod;
		ifac[i] = 1LL * ifac[mod % i] * (mod - mod / i) % mod;
	}
	for (int i = 1; i <= n; i++) ifac[i] = 1LL * ifac[i - 1] * ifac[i] % mod;
	for (int i = 0; i <= m; i++) scanf("%d", &v[i]);
	dp[0][0][0][0] = 1;
	for (int i = 0; i <= m; i++) for (int j = 0; j <= n; j++) for (int p = 0; p <= k; p++) for (int s = 0; s <= n; s++) {
		int cur = dp[i][j][p][s];
		if (!cur) continue;
		for (int q = 0; j + q <= n; q++, cur = 1LL * cur * v[i] % mod) 
			add(dp[i + 1][j + q][p + ((s + q) & 1)][(s + q) >> 1], 1LL * cur * ifac[q] % mod);
	}
	for (int p = 0; p <= k; p++) for (int s = 0; s <= n; s++) {
		int cp = p, tmp = s;
		while (tmp) cp += (tmp & 1), tmp >>= 1;
		if (cp <= k)
			add(ans, dp[m + 1][n][p][s]);
	}
	printf("%d\n", int(1LL * ans * fac[n] % mod));
	return 0;
} 
