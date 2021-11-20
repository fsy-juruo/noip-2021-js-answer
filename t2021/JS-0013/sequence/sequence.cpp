#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a, 0, sizeof(a))
#define fill1(a) memset(a, -1, sizeof(a))
#define fillbig(a) memset(a, 63, sizeof(a))
#define mp make_pair
#define pb push_back
#define ppb pop_back
template<typename T1, typename T2> void chkmin(T1 &x, T2 y) {
	if (x > y) x = y;
}
template<typename T1, typename T2> void chkmax(T1 &x, T2 y) {
	if (x < y) x = y;
}
typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
template<typename T> void read(T &x) {
	x = 0; char c = getchar(); bool neg = 0;
	while (!isdigit(c)) neg |= (c == '-'), c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (neg) x = -x;
}
const int MAXN = 30;
const int MAXM = 101;
const int MOD = 998244353;
int n, m, k, a[MAXM + 5], dp[MAXM + 5][MAXN + 5][MAXN + 5][MAXN + 5];
int fac[MAXN + 5], ifac[MAXN + 5], pw[MAXM + 5][MAXN + 5];
void init_fac(int n) {
	for (int i = (fac[0] = ifac[0] = ifac[1] = 1) + 1; i <= n; i++)
		ifac[i] = 1ll * ifac[MOD % i] * (MOD - MOD / i) % MOD;
	for (int i = 1; i <= n; i++) {
		fac[i] = 1ll * fac[i - 1] * i % MOD;
		ifac[i] = 1ll * ifac[i - 1] * ifac[i] % MOD;
	}
}
int ppc(int x) {
	int cnt = 0;
	while (x) {
		cnt++;
		x &= (x - 1);
	}
	return cnt;
}
int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k); ++m; init_fac(MAXN);
	for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
	dp[0][0][0][0] = 1;
	for (int i = 1; i <= m; i++) {
		pw[i][0] = 1;
		for (int j = 1; j <= n; j++) pw[i][j] = 1ll * pw[i][j - 1] * a[i] % MOD;
	}
	for (int i = 0; i < m; i++) for (int j = 0; j <= n; j++) for (int c = 0; c <= k; c++)
		for (int l = 0; l <= n; l++) if (dp[i][j][c][l]) {
			for (int t = 0; t + j <= n; t++) {
				int nt = (l + t) >> 1;
				dp[i + 1][j + t][c + ((l + t) & 1)][(l + t) >> 1] =
				(dp[i + 1][j + t][c + ((l + t) & 1)][(l + t) >> 1] +
				 1ll * dp[i][j][c][l] * ifac[t] % MOD * pw[i + 1][t]) % MOD;
			}
		}
	int res = 0;
	for (int c = 0; c <= k; c++) for (int l = 0; l <= n; l++)
		if (c + ppc(l) <= k) res = (res + dp[m][n][c][l]) % MOD;
	res = 1ll * res * fac[n] % MOD;
	printf("%d\n", res);
	return 0;
}
/*
8 9 4
934258593 150407625 187068439 162292791 219945760 512449588 803393963 983648121 484675481 412407699
*/
