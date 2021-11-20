#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 35;
const int M = 105;
const int mod = 998244353;
template <typename Ta, typename Tb> inline void inc(Ta &x, Tb y) { x = (x + y >= mod) ? x + y - mod : x + y; }
inline int power(int a, int p)
{
	int ret = 1;
	for (; p; p >>= 1, a = (LL) a * a % mod) if (p & 1) ret = (LL) ret * a % mod;
	return ret;
}
int n, m, k, v[M], val[M][N];
int fac[N], ifac[N];
int f[M][N][N][N];
int main()
{
	freopen ("sequence.in", "r", stdin);
	freopen ("sequence.out", "w", stdout);
	scanf ("%d%d%d", &n, &m, &k);
	for (int i = 0; i <= m; i++) scanf ("%d", &v[i]);
	fac[0] = ifac[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		fac[i] = (LL) fac[i - 1] * i % mod;
		ifac[i] = power(fac[i], mod - 2);
	}
	for (int i = 0; i <= m; i++)
	{
		val[i][0] = 1;
		for (int j = 1; j <= n; j++) val[i][j] = (LL) val[i][j - 1] * v[i] % mod;
	}
	for (int i = 0; i <= n; i++) f[0][i][0][i] = (LL) val[0][i] * ifac[i] % mod;
	for (int i = 0; i < m; i++)
	for (int j = 0; j <= n; j++)
	for (int p = 0; p <= k; p++)
	for (int q = 0; q <= n; q++)
	if (f[i][j][p][q])
	{
		if (p + (q & 1) > k) continue;
		for (int s = 0; s <= n - j; s++)
		inc(f[i + 1][j + s][p + (q & 1)][q / 2 + s], (LL) f[i][j][p][q] * val[i + 1][s] % mod * ifac[s] % mod);
	}
	int ans = 0;
	for (int p = 0; p <= k; p++)
	for (int q = 0; q <= n; q++)
	{
		int sum = p, cur = q;
		while (cur) { sum += (cur & 1); cur >>= 1; }
		if (sum <= k) inc(ans, f[m][n][p][q]);
	}
	ans = (LL) ans * fac[n] % mod;
	printf ("%d\n", ans);
	return 0;
}
