#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

void ADD(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

int C[40][40];
int dp[110][40][40][40];
int n, m, k;
long long pw[110][40];
int a[110];

int GetCnt(int x) {
	int cnt = 0;
	while (x) cnt += x & 1, x >>= 1;
	return cnt;
}

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	for (int i = 0; i <= 35; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			ADD(C[i][j] = C[i - 1][j - 1], C[i - 1][j]);
		}
	}
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i <= m; i++) {
		scanf("%d", &a[i]);
		pw[i][0] = 1;
		for (int j = 1; j <= n; j++) {
			pw[i][j] = pw[i][j - 1] * a[i] % mod;
		}
	}
	for (int p = 0; p <= n / 2; p++) {
		int cnt = GetCnt(p);
		for (int q = 0; q <= k; q++) {
			if (q >= cnt) dp[m + 1][0][p][q] = 1;
		}
	}
	for (int i = m; i >= 0; i--) {
		for (int j = 0; j <= n; j++) {
			for (int p = 0; p <= n / 2; p++) {
				for (int q = 0; q <= k; q++) {
					int &res = dp[i][j][p][q] = 0;
					for (int t = 0; t <= j; t++) {
						int np = p + t >> 1, nq = q - (p + t & 1), nj = j - t;
						if (nq >= 0) ADD(res, 1ll * dp[i + 1][nj][np][nq] * C[j][t] % mod * pw[i][t] % mod);
					}
				}
			}
		}
	}
	printf("%d\n", dp[0][n][0][k]);
	return 0;
}

