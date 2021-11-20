#include <bits/stdc++.h>
#define LL long long
#define _rep(i, x, y) for(int i = x; i <= y; i++)
#define _per(i, x, y) for(int i = x; i >= y; i--)

template <typename T>
inline void read(T &x) {
	x = 0; T f = (T) 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-') f = -f;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T>
inline void write(T x) {
	if(x < 0) x = -x, putchar('-');
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T>
inline void writesp(T x, char sp = ' ') {
	write(x); putchar(sp);
}

const int mod = 998244353;
int n, m, k, v[102], dp[102][32][102][65], ppcnt[128], fac[100], facinv[100];
int pow_mod(int a, int b, int p) {
	int sum = 1;
	while(b) {
		if(b & 1) sum = 1ll * sum * a % p;
		a = 1ll * a * a % p; b >>= 1;
	}
	return sum;
}
int binom(int n, int m) {
	if(n < m) return 0;
	if(n == 0 || m == 0) return 1;
	return 1ll * fac[n] * facinv[m] % mod * facinv[n - m] % mod;
}
int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	read(n); read(m); read(k); 
	_rep(i, 1, m + 1) read(v[i]);
	
	int Lim = 1;
	while(Lim < n) Lim <<= 1;
	Lim <<= 1;
	ppcnt[0] = 0; fac[0] = fac[1] = facinv[0] = 1;
	_rep(i, 2, Lim) fac[i] = 1ll * fac[i - 1] * i % mod;
	facinv[Lim] = pow_mod(fac[Lim], mod - 2, mod);
	_per(i, Lim - 1, 1) facinv[i] = 1ll * facinv[i + 1] * (i + 1) % mod;
	_rep(i, 1, Lim - 1) ppcnt[i] = ppcnt[i >> 1] + (i % 2);
	dp[0][0][0][0] = 1;
	_rep(alpha, 1, m + 1) {
		_rep(beta, 0, n) {
			_rep(g, 0, alpha - 1) {
				_rep(mask, 0, Lim - 1) {
					int p = 1;
//					if(alpha == 3 && beta == 3 && g == 1 && mask == 1) std::cout << "debug" << "\n";
					_rep(cnt, 0, beta) {
						if(mask < cnt) continue;
//						if(alpha == 3 && beta == 3 && g == 1 && mask == 1) std::cout << dp[alpha][beta][g][mask] << "\n";
//						if(g + (mask & 1) > alpha) continue;
						int newmask = ((mask - cnt) << 1);
						if(newmask <= Lim - 1) dp[alpha][beta][g][mask] = (dp[alpha][beta][g][mask] + 1ll * dp[alpha - 1][beta - cnt][g][newmask] * p % mod * binom(beta, cnt) % mod) % mod;
//						if(alpha == 3 && beta == 3 && g == 1 && mask == 1) std::cout << dp[alpha][beta][g][mask] << "\n";
						if(g >= 1) {
							newmask = ((mask - cnt) << 1 | 1);
							if(newmask <= Lim - 1) dp[alpha][beta][g][mask] = (dp[alpha][beta][g][mask] + 1ll * dp[alpha - 1][beta - cnt][g - 1][newmask] * p % mod * binom(beta, cnt) % mod) % mod;
						}
//						if(alpha == 3 && beta == 3 && g == 1 && mask == 1) std::cout << dp[alpha][beta][g][mask] << "\n";
//						dp[alpha][beta][g][mask] = (dp[alpha][beta][g][mask] + 1ll * dp[alpha - 1][beta - cnt][g][mask] * p % mod) % mod;
//						if(alpha == 1 && beta == 3 && g == 0 && mask == 0) std::cout << g + (mask & 1) << " " << ((mask >> 1) ^ cnt) << " " << cnt << " " << 1ll * dp[alpha - 1][beta - cnt][g][mask] * p << " " << binom(beta, cnt) % mod << "\n";
						p = 1ll * p * v[alpha] % mod;
					}
				}
			}
		}
	}
	int ans = 0;
	_rep(g, 0, m) {
		_rep(mask, 0, Lim - 1) {
			if(g + ppcnt[mask] > k) continue;
			ans = (ans + dp[m + 1][n][g][mask]) % mod;
		}
	}
 	writesp(ans, '\n');
	return 0;
}


