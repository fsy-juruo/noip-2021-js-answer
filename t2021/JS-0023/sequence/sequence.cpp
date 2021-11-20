#include <bits/stdc++.h>
using namespace std;
const int N = 31, M = 102, mod = 998244353;
int v[M];
int dp[N][M][N][32][32], inv[M], pct[M], tt[M];
int qp(int x, int y) {
	int res = 1;
	while (y) {
		if (y & 1) res = 1ll * res * x % mod;
		x = 1ll * x * x % mod;
		y >>= 1;
	}
	return res;
}
int ni, nj, nk, ncur, nnum, val, n, m, K;
void update(int i, int j, int k, int cur, int num) {
	//cout << i << ' ' << j << ' ' << j << ' ' << ' ' << num << endl;
	ni = i + 1; val = dp[i][j][k][cur][num];
	for (nj = j; nj <= m; nj ++) {
		ncur = (cur >> nj - j) + 1;
		nk = k - pct[cur & tt[nj - j]];
		nnum = (nj == j) ? num + 1 : 1;
		dp[ni][nj][nk][ncur][nnum] += 1ll * v[nj] * inv[nnum] % mod * val % mod;
		if (dp[ni][nj][nk][ncur][nnum] >= mod) dp[ni][nj][nk][ncur][nnum] -= mod;
	}
}

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	cin >> n >> m >> K;
	for (int i = 1; i <= 100; i ++) {
		pct[i] = pct[i >> 1] + (i & 1);
		tt[i] = (tt[i - 1] << 1) + 1;
	}	
	for (int i = 1; i <= 100; i ++) {
		inv[i] = 1ll * qp(i, mod - 2);
	}
	
	for (int i = 0; i <= m; i ++) cin >> v[i];
	for (int j = 0; j <= m; j ++) {
		dp[1][j][K][1][1] = v[j];
	}
	int i, j, k, cur, num;
	for (i = 1; i < n; i ++) {
		for (j = 0; j <= m; j ++) {
			for (k = 1; k <= K; k ++) {	
				for (cur = 1; cur <= i; cur ++) {
					for (num = 1; num <= i; num ++) {
						if (!dp[i][j][k][cur][num]) continue;
						update(i, j, k, cur, num);
					}
				}
			}
		}
	}
	int ans = 0;
	for (j = 0; j <= m; j ++) {
		for (k = 1; k <= K; k ++) {
			for (cur = 1; cur <= n; cur ++) {
				for (num = 1; num <= n; num ++) {
					if (!dp[n][j][k][cur][num]) continue;
					if (pct[cur] > k) continue;
					ans += dp[n][j][k][cur][num];
					if (ans >= mod) ans -= mod;
				}
			}
		}
	}
	for (i = 1; i <= n; i ++) ans = 1ll * ans * i % mod;
	cout << ans << endl;
	return 0;
}
