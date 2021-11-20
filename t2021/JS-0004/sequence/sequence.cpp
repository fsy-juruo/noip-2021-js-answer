#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
void Add(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}
inline int qp(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % mod;
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return res;
}
int n, m, k, v[105][31], dp[2][31][31][31], ppc[31], fact[31], ifact[31];
int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	ppc[0] = 0;
	for (int i = 1; i <= n; i++) ppc[i] = ppc[i >> 1] + (i & 1);
	fact[0] = ifact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = 1ll * fact[i - 1] * i % mod;
		ifact[i] = qp(fact[i], mod - 2);
	}
	for (int i = 0; i <= m; i++) {
		scanf("%d", &v[i][1]);
		v[i][0] = 1;
		for (int j = 2; j <= n; j++) v[i][j] = 1ll * v[i][j - 1] * v[i][1] % mod;
	}
	int cur = 0, lst = 1;
	memset(dp[cur], 0, sizeof(dp[cur]));
	dp[cur][0][0][0] = 1;
	for (int i = 0; i <= m; i++) {
		swap(cur, lst);
		memset(dp[cur], 0, sizeof(dp[cur]));
		for (int j = 0; j <= n; j++) {
			for (int c = 0; c <= k; c++) {
				for (int d = 0; d <= n; d++) if (dp[lst][j][c][d]) {
					for (int e = 0; e <= n - j; e++) {
						if (c + (d + e) % 2 <= k) {
							Add(dp[cur][j + e][c + (d + e) % 2][(d + e) / 2], 1ll * dp[lst][j][c][d] * v[i][e] % mod * ifact[e] % mod);
						}
					}
				}
			}
		}
	}
	int ans = 0;
	for (int c = 0; c <= k; c++) {
		for (int d = 0; d <= n; d++) if (dp[cur][n][c][d] && c + ppc[d] <= k) {
			Add(ans, dp[cur][n][c][d]);
		}
	}
	ans = 1ll * ans * fact[n] % mod;
	printf("%d\n", ans);
	return 0;
}
