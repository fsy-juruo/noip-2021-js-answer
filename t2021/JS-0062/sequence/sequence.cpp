#include<bits/stdc++.h>
using namespace std;

#define U(x, y, z) for (int x = y; x <= z; ++x)
#define D(x, y, z) for (int x = y; x >= z; --x)
#define LL long long
const int N = 110;
const int M = 31;

template <typename T> inline void read(T &n) {
    n = 0; char ch; bool f = 1;
    for (ch = getchar(); !isdigit(ch); ch = getchar()) if (ch == '-') f = 0;
    for (; isdigit(ch); ch = getchar()) n = (n << 1) + (n << 3) + (ch ^ 48);
    if (f == 0) n = -n;
}

template <typename T> inline void chkmin(T &x, T y) {
	if (x > y) x = y;
}

template <typename T> inline void chkmax(T &x, T y) {
	if (x < y) x = y;
}

inline void file(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int n, m, tms;
int a[N], adt[M];
LL dp[2][16][M][M][M], fac[N], ifac[N];
const int mod = 998244353;
inline LL Qpow(LL a, int b) {
	LL res = 1;
	for (; b; b >>= 1, (a *= a) %= mod) if (b & 1) (res *= a) %= mod;
	return res;
}

inline LL C(int n, int m) {
	return fac[n] * ifac[n - m] % mod * ifac[m] % mod;
}

inline bool chk(int x, int p) {
	return (x >> p) & 1;
}

int main() {
	file("sequence");
	read(n), read(m), read(tms);
	U(i, 0, m) read(a[i]);
	tms = n - tms;
	fac[0] = 1;
	U(i, 1, n) fac[i] = fac[i - 1] * i % mod;
	U(i, 0, n) ifac[i] = Qpow(fac[i], mod - 2);
	memset(dp, 0, sizeof dp);
	dp[(m + 1) & 1][0][0][0][0] = 1;
	U(i, 1, n) {
		int p = 0;
		adt[i] = adt[i - 1];
		while (chk(i - 1, p)) {
			adt[i]++;
			++p;
		}
	}
	D(p, m, 0) {
		LL tmp = 1;
		memset(dp[p & 1], 0, sizeof dp[p & 1]);
		U(nw, 0, n) {
			U(i, 0, 15)  U(j, 0, n - nw) U(k, 0, n - nw) U(l, 0, n - nw) {
				if (!dp[(p + 1) & 1][i][j][k][l]) continue ;
				int ti = (i << 1), temp = 0, ad = adt[nw], bk = 0;
				U(t, 0, 4) {
					int ttmp = chk(ti, t) + chk(nw, t);
					if (ttmp + chk(temp, t) > 1) 
						++ad;
					temp += (ttmp << t);
				}
				if (temp & 16) {
					if (temp & 32) {
						if (j) bk = 1;
						else bk = 2;
						ad += j;
					}
					else bk = j + 1;
				}
				else if (temp & 32) {
					bk = 0;
					ad += j;
				}
				else bk = 0;
				(dp[p & 1][temp - (temp & 32) - (temp & 16)][bk][k + ad][l + nw] += dp[(p + 1) & 1][i][j][k][l] * tmp % mod * C(nw + l, nw)) %= mod;
			}
			(tmp *= a[p]) %= mod;
		}
	}
	LL ans = 0;
	U(i, 0, 15) U(j, 0, n) U(k, tms, n - 1) (ans += dp[0][i][j][k][n]) %= mod;
	cout << ans << endl;
    return 0;
}
/*
5 1 1
2 1
*/
