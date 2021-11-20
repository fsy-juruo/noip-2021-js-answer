#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i <= (b); ++i)
#define DF(i, a, b) for (int i = (a); i >= (b); --i)
#define SZ(x) (int)x.size() - 1
#define all(x) x.begin(), x.end()

using namespace std;
typedef long long ll;
template <typename T> inline void read(T& x) {
	x = 0; int f = 1; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	x *= f;
}
const int N = 35, M = 110, MOD = 998244353;
template <typename T> inline void chkmax(T& x, T y) { x = max(x, y); }
template <typename T> inline void chkmin(T& x, T y) { x = min(x, y); }
template <typename T> inline void chkadd(T& x, T y) { x = (x + y) % MOD; }

int n, m, K;
ll v[N], f[M][N][N][N];
ll fac[N], ifac[N];

inline ll Quickpow(ll x, ll y) {
	ll ans = 1;
	for (; y; x = x * x % MOD, y >>= 1)
		if (y & 1) ans = ans * x % MOD;
	return ans;
}

inline void init() {
	fac[0] = 1;
	F(i, 1, n) fac[i] = fac[i - 1] * i % MOD;
	ifac[n] = Quickpow(fac[n], MOD - 2);
	DF(i, n - 1, 0) ifac[i] = ifac[i + 1] * (i + 1) % MOD;
}
inline ll C(ll x, ll y) {
	if (y < 0 || y > x) return 0;
	return fac[x] * ifac[x - y] % MOD * ifac[y] % MOD;
}

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	read(n); read(m); read(K);
	F(i, 0, m) read(v[i]);
	init();
	f[0][n][0][K] = 1;
	F(i, 0, m) {
		F(j, 0, n)
			F(k, 0, n / 2)
				F(l, 0, K) {
					if (!f[i][j][k][l]) continue;
					F(q, 0, j) {
						if (l == 0 && (j - q + k) & 1) continue;
//						cout << i << " " << j << " " << k << " " << l << endl;
//						cout << "-> " << i + 1 << " " << q << " " << ((j - q + k) >> 1) << " " << (l - (q - j + k) & 1) << endl;
						chkadd(f[i + 1][q][(j - q + k) >> 1][l - ((j - q + k) & 1)], f[i][j][k][l] * Quickpow(v[i], j - q) % MOD * C(j, q) % MOD);
//						cout << f[i + 1][q][(q - j + k) >> 1][l - (j - q + k) & 1] << endl;
//						if (i == m) cout << q << " " << ((j - q + k) >> 1) << " " << (l - (j - q + k) & 1) << " " << f[i + 1][q][(j - q + k) >> 1][l - (j - q + k) & 1] << endl;
					}
				}
	}
	ll ans = 0;
	F(i, 0, n / 2)
		F(j, 0, K) {
			if (!f[m + 1][0][i][j]) continue;
			int k = i, s = 0;
			while (k) {
				if (k & 1) s++;
				k >>= 1;
			}
//			cout << i << " " << j << endl;
			if (s <= j) chkadd(ans, f[m + 1][0][i][j]);
		}
	cout << ans;
	return 0;
}

