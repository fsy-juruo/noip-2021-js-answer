#include <bits/stdc++.h>

#define LL long long
#define ull unsigned long long
#define F(i, j, k) for (int i = j; i <= k; ++i)
#define DF(i, j, k) for (int i = j; i >= k; --i)

using namespace std;

template <typename T> inline void read(T &n) {
    T w = 1; n = 0; char ch = getchar();
    while (!isdigit(ch) && ch != EOF) { if (ch == '-') w = -1; ch = getchar(); }
    while (isdigit(ch) && ch != EOF) { n = (n << 3) + (n << 1) + (ch & 15); ch = getchar(); }
    n *= w;
}

template <typename T> inline void write(T &x) {
    T l = 0; ull y = 0;
    if (!x) { putchar(48); return; }
    if (x < 0) { x = -x; putchar('-'); }
    while (x) { y = y * 10 + x % 10; x /= 10; ++l; }
    while (l) { putchar(y % 10 + 48); y /= 10; --l; }
}

template <typename T> inline void writes(T x) {
    write(x);
    putchar(' ');
}

template <typename T> inline void writeln(T x) {
    write(x);
    puts("");
}

template <typename T> inline void checkmax(T &a, T b) { a = a > b ? a : b; }
template <typename T> inline void checkmin(T &a, T b) { a = a < b ? a : b; }

const int MOD = 998244353;

const int N = 33, M = 150, MX = 120;

int n, m, K, cm[M][N], s[M][N][N << 1][N], dp[M][N][N << 1], fac[M], inv[M];

inline int ksm(int x, int y) {
	int k = 1;
	while (y) {
		if (y & 1) k = (LL)k * x % MOD;
		x = (LL)x * x % MOD;
		y >>= 1;
	}
	return k;
}

inline int add(int x, int y) { x += y; return x >= MOD ? x - MOD : x; }
inline int dec(int x, int y) { x -= y; return x < 0 ? x + MOD : x; }

inline int C(int x, int y) { return (LL)fac[x] * inv[y] % MOD * inv[x - y] % MOD; }

int main() {
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
    read(n); read(m); read(K);
    F(i, 0, m) {
    	cm[i][0] = 1;
		read(cm[i][1]);
		F(j, 2, n) cm[i][j] = (LL)cm[i][j - 1] * cm[i][1] % MOD;
	}
	fac[0] = 1; F(i, 1, 110) fac[i] = (LL)fac[i - 1] * i % MOD;
	inv[110] = ksm(fac[110], MOD - 2); DF(i, 109, 0) inv[i] = (LL)inv[i + 1] * (i + 1) % MOD;
	int ans = 0;
	F(l, 0, K)
	F(i, 0, m + 7)
		F(jt, 0, n)
			F(k, 0, n) {
				if (i != 0) {
					s[i][jt][k][l] = s[i - 1][jt][k * 2][l];
					if (l >= 1) s[i][jt][k][l] = add(s[i][jt][k][l], s[i - 1][jt][k * 2 + 1][l - 1]);
				}
				else {
					if (l == 0) if (k * 2 == jt) s[i][jt][k][l] = cm[0][jt];
					if (l == 1) if (k * 2 + 1 == jt) s[i][jt][k][l] = cm[0][jt]; 
				}
				if (i <= m) { 
				F(jf, 0, jt - 1) {
					int x = jt - jf;
					if (k * 2 - x >= 0 && i - 1 >= 0) {
						int fr1 = s[i - 1][jf][k * 2 - x][l];
						s[i][jt][k][l] = add(s[i][jt][k][l], (LL)fr1 * C(jt, x) % MOD * cm[i][x] % MOD);
					}
					if (l > 0 && k * 2 - x + 1 >= 0 && i - 1 >= 0) {
						int fr2 = s[i - 1][jf][k * 2 - x + 1][l - 1];
						//cerr << k << ' ' << x << ' ' << i - 1 << ' ' << jf << ' ' << k * 2 - x + 1 << ' ' << fr2 << endl;
						s[i][jt][k][l] = add(s[i][jt][k][l], (LL)fr2 * C(jt, x) % MOD * cm[i][x] % MOD);
					}
					//cerr << i << ' ' << jt << ' ' << k << ' ' << l << ' ' << s[i][jt][k][l] << endl;
				}
				}
				//cerr << i << ' ' << jt << ' ' << k << ' ' << l << ' ' << s[i][jt][k][l] << endl;
				if (i == m + 7 && k == 0 && jt == n) {
					ans = add(ans, s[i][jt][k][l]);
					//cerr << i << ' ' << jt << ' ' << k << ' ' << l << ' ' << s[i][jt][k][l] << endl;
				}
			}
/*	dp[0][0][0] = 1;
	dp[0][1][1] = (LL)cm[0][1] * n % MOD;
	F(i, 1, MX)
		F(jt, 0, n)
			F(k, 0, K) {
				dp[i][jt][k] = dp[i - 1][jt][k];
				if (k == 0) continue;
				F(jf, 0, jt - 1) {
					int x = jt - jf;
					int fr = dp[i - 1][jf][k - 1];
					int sv;
					if (i <= m) { sv = s[i - 1][x][1]; if (x == 1) sv = add(sv, cm[i][1]); }
					else {
						if (i - m > 8 || (1 << (i - m - 1)) > n) sv = 0;
						else sv = s[m][x][1 << (i - m - 1)];
					}
					dp[i][jt][k] = add(dp[i][jt][k], (LL)fr * C(n - jf, x) % MOD * sv % MOD);
				}
			}
	int ans = 0;
	F(i, 1, K) ans = add(ans, dp[MX][n][i]);*/
	writeln(ans);
    return 0;
}

/*
dp[i][j][k]
s[i][j][k]
*/

/*
为所有爱执着的痛
为所有恨执着的伤
我已分不清爱与恨
是否就这样
血和眼泪在一起滑落
我的心破碎风化
颤抖的手却无法停止
无法原谅
*/


