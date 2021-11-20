#include <bits/stdc++.h>
using namespace std;

const int Mod = 998244353;
inline int Pls(int x, const int y) {return (x += y) >= Mod ? x - Mod : x;}
inline int Sub(int x, const int y) {return (x -= y) < 0 ? x + Mod : x;}
inline void Plus(int &x, const int y) {(x += y) >= Mod ? x -= Mod : 0;}
int power(int x, int p) {
	int ret = 1;
	while (p) {
		if (p & 1) ret = 1ll * ret * x % Mod;
		x = 1ll * x * x % Mod; p >>= 1;
	} return ret;
}

int fac[35], ifac[35];
void process(int n = 30) {
	fac[0] = 1;
	for (int i = 1; i <= n; ++ i) fac[i] = 1ll * fac[i - 1] * i % Mod;
	ifac[n] = power(fac[n], Mod - 2);
	for (int i = n; i >= 1; -- i) ifac[i - 1] = 1ll * ifac[i] * i % Mod;
}


int n, m, K, v[105][35];
int ppc[35], trs[35][35][35], cnt[35][35];
int dp[35][105][35][35], ans;

int trans(int s, int d) {
	s = s >> d;
	int i = 0;
	while (s >> i & 1) s ^= (1 << i), ++ i;
	s |= (1 << i);
	return s;
}
int get(int s, int d) {
	int ret = 0;
	for (int i = 0; i < d; ++ i) ret += (s >> i & 1);
	return ret;
}

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	
	scanf("%d%d%d", &n, &m, &K);
	process();
	for (int i = 0; i <= m; ++ i) {
		scanf("%d", &v[i][1]);
		for (int j = 2; j <= n; ++ j) v[i][j] = 1ll * v[i][j - 1] * v[i][1] % Mod;
	}
	for (int i = 1; i < (1 << 5); ++ i) ppc[i] = ppc[i - (i & -i)] + 1;
	for (int s = 0; s < (1 << 5); ++ s) for (int d = 1; d < 5; ++ d) {
		trs[s][d][1] = trans(s, d);
		for (int j = 2; j < n; ++ j) trs[s][d][j] = trans(trs[s][d][j - 1], 0);
		cnt[s][d] = get(s, d);
	}
	for (int i = 1; i <= n; ++ i) for (int j = 0; j <= m; ++ j) dp[i][j][0][i] = 1ll * v[j][i] * ifac[i] % Mod;
	int val;
	for (int i = 1; i <= n; ++ i) {
		for (int j = 0; j <= m; ++ j) {
			for (int k = 0; k <= K; ++ k) {
				for (int s = 0; s < (1 << 5); ++ s) if (dp[i][j][k][s]) {
					for (int ni = i + 1; ni <= n; ++ ni) {
						for (int nj = j + 1; nj <= m; ++ nj) {
							val = 1ll * dp[i][j][k][s] * v[nj][ni - i] % Mod * ifac[ni - i] % Mod;
							if (nj - j >= 5) {
								Plus(dp[ni][nj][k + ppc[s]][ni - i], val);
							} else {
								int ns = trs[s][nj - j][ni - i];
								Plus(dp[ni][nj][k + cnt[s][nj - j]][ns], val);
							}
						}
					}
				}
			}
		}
	}
	for (int j = 0; j <= m; ++ j) {
		for (int k = 0; k <= n; ++ k) if (k <= K) {
			for (int s = 0; s < (1 << 5); ++ s) {
				if (k + ppc[s] <= K) {
					ans = Pls(ans, dp[n][j][k][s]);
				}
			}
		}
	}
	ans = 1ll * ans * fac[n] % Mod;
	printf("%d", ans);
	
	return 0;
}
