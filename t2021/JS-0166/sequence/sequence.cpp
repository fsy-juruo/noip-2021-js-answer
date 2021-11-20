#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int n, m, K;
int val[110];
int fac[35], inv[35];
int dp[110][35][35][35], f[35][35][35], p[110][35];

template <typename Tp>
void read(Tp &x) {
	x = 0; int f = 1; char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = - 1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	x *= f;
}

int qpow(int a, int b) {
	int ans = 1;
	for (; b; b >>= 1) {
		if (b & 1) ans = 1ll * a * ans % mod;
		a = 1ll * a * a % mod;
	}
	return ans;
}

int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n), read(m), read(K);
	for (int i = 0; i <= m; ++ i) read(val[i]);
	fac[0] = 1;
	for (int i = 1; i <= n; ++ i) fac[i] = 1ll * i * fac[i - 1] % mod;
	inv[n] = qpow(fac[n], mod - 2);
	for (int i = n - 1; i >= 0; -- i) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
	for (int i = 0; i <= m; ++ i) {
		for (int j = 0; j <= n; ++ j) {
			p[i][j] = qpow(val[i], j);
		}
	}
	for (int i = 0; i <= n; ++ i) {
		if ((i & 1) == 0) {
			int sum = 0;
			for (int j = 0; j <= 5; ++ j) if ((i >> j) & 1) sum ++;
			dp[m + 1][0][i / 2][sum] = fac[n];
		}
	}
	for (int i = m; i >= 0; -- i) {
		for (int j = 0; j <= n; ++ j) {
			for (int k = 0; k <= n - j; ++ k) {
				for (int l = 0; l <= K; ++ l) {
					f[j][k][l] = 0;
					if (l > 0 && ((k - 1) % 2 == 0) && k > 0) f[j][k][l] = (f[j][k][l] + dp[i + 1][j][(k - 1) / 2][l - 1]) % mod;
					if (k % 2 == 0) f[j][k][l] = (f[j][k][l] + dp[i + 1][j][k / 2][l]) % mod;
				}
			}
		}
		for (int j = 0; j <= n; ++ j) {
			for (int k = 0; k <= n - j; ++ k) {
				for (int l = 0; l <= K; ++ l) {
					for (int c = 0; c <= n; ++ c) {
						if (j >= c && k + c <= n) dp[i][j][k][l] = (dp[i][j][k][l] + 1ll * f[j - c][k + c][l] * inv[c] % mod * p[i][c] % mod) % mod;
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= K; ++ i) {
		ans = (ans + dp[0][n][0][i]) % mod;
	}
	printf("%d\n", ans);
	return 0;
}
