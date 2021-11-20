#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mod = 998244353;

int n, m, K;
int v[115];
int comb[35][35];
int dp[35][35][35];

inline void uadd(int &x, int y) {
	x += y - mod;
	x += x >> 31 & mod;
}

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &K);
	for (int i = 0; i <= m; ++ i) scanf("%d", &v[i]);
	rep(i, n + 1) rep(j, i + 1) comb[i][j] = j ? (comb[i - 1][j - 1] + comb[i - 1][j]) % mod : 1;
	memset(dp, 0, sizeof(dp));
	dp[0][0][0] = 1;
	for (int i = 0; i <= m + 10; ++ i) {
		static int pw[35];
		rep(j, n + 1) pw[j] = j ? 1LL * pw[j - 1] * v[i] % mod : 1;
		static int ndp[35][35][35];
		memset(ndp, 0, sizeof(ndp));
		for (int s = 0; s <= n; ++ s) {
			for (int k = 0; k <= K; ++ k) {
				for (int c = 0; c <= n; ++ c) {
					if (dp[s][k][c]) {
//						eprintf("%d %d %d %d = %d\n", i, s, k, c, dp[s][k][c]);
						for (int x = 0; s + x <= n; ++ x) {
							int val = 1LL * dp[s][k][c] * comb[s + x][s] % mod * pw[x] % mod;
							uadd(ndp[s + x][k + ((c + x) & 1)][(c + x) >> 1], val);
						}
					}
				}
			}
		}
		memcpy(dp, ndp, sizeof(dp));
	}
	int ans = 0;
	for (int k = 0; k <= K; ++ k) uadd(ans, dp[n][k][0]);
	printf("%d\n", ans);
	return 0;
}

