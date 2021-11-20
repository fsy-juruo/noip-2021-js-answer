#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int) (n); ++ i)
#define rep1(i, n) for (int i = 1; i <= (int) (n); ++ i)

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int N, M, K;
LL v[105];
LL fac[105], ifac[105];
LL dp[2][35][(1 << 4) + 6][35][35];
LL Pow[105][35];
int nlen[(1 << 4) + 6][35][35];
int nk[(1 << 4) + 6][35][35];
int bts[105];

LL pw(LL x, LL y)
{
	LL ret = 1;
	for ( ; y; y >>= 1, x = x * x % MOD)
		if (y & 1) ret = ret * x % MOD;
	return ret;
}

void inc(LL& x, LL y)
{
	x += y;
	if (x >= MOD) x -= MOD;
}

int main()
{
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	
	fac[0] = 1;
	for (int i = 1; i <= 100; ++ i) fac[i] = fac[i - 1] * i % MOD;
	ifac[100] = pw(fac[100], MOD - 2);
	for (int i = 99; i >= 0; -- i) ifac[i] = ifac[i + 1] * (i + 1) % MOD;
	
	bts[0] = 0;
	for (int i = 1; i <= 100; ++ i) bts[i] = bts[i >> 1] + (i & 1);
	
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i <= M; ++ i) scanf("%lld", &v[i]);
	
	for (int i = 0; i <= M; ++ i) {
		Pow[i][0] = 1;
		for (int j = 1; j <= N; ++ j) {
			Pow[i][j] = Pow[i][j - 1] * v[i] % MOD;
		}
	}
	
	rep(msk, 1 << 4) rep(len, N + 1) {
		LL smsk = msk;
		rep(p, len) smsk |= (1ll << (p + 4));
		rep(c, N + 1) {
			LL cd = (smsk << 1) + c;
			int n_len = 0, n_k = 0, lp = 4;
			while (cd >> lp & 1) {
				n_len ++, lp ++;
			}
			while ((1ll << lp) <= cd) {
				if (cd >> lp & 1) {
					n_k ++;
				}
				lp ++;
			}
			nlen[msk][len][c] = n_len;
			nk[msk][len][c] = n_k;
		}
	}
	
	dp[(M + 1) & 1][0][0][0][0] = 1;
	for (int i = M + 1; i > 0; -- i) {
		int id = i & 1;
		rep(j, N + 1) rep(msk, 1 << 4) rep(len, N + 1) {
			LL smsk = msk;
			rep(p, len) smsk |= (1ll << (p + 4));
			rep(k, K + 1) if (dp[id][j][msk][len][k]) {
				for (int c = 0; j + c <= N; ++ c) {
					LL cd = (smsk << 1) + c;
					int nmsk = cd & ((1 << 4) - 1);
					int n_len = nlen[msk][len][c], n_k = nk[msk][len][c] + k;
					if (n_k <= K) {
						inc(dp[id ^ 1][j + c][nmsk][n_len][n_k], dp[id][j][msk][len][k] * Pow[i - 1][c] % MOD * ifac[c] % MOD);
					}
				}
				dp[id][j][msk][len][k] = 0;
			}
		}
	}
	
	LL ret = 0;
	rep(msk, 1 << 4) rep(len, N + 1) rep(k, N + 1) if (dp[0][N][msk][len][k]) {
		int calc = bts[msk] + len + k;
		if (calc <= K) {
			inc(ret, dp[0][N][msk][len][k]);
		}
	}
	
	ret = ret * fac[N] % MOD;
	
	printf("%lld\n", ret);
	
	return 0;
}
