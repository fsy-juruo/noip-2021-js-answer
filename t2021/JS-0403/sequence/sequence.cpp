#include <bits/stdc++.h>
using namespace std;
#define resetIO(x) \
	freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define debug(fmt, ...) \
	fprintf(stderr, "[%s:%d] " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)
template <class _Tp>
inline _Tp& read(_Tp& x) {
	bool sign = 0;
	char ch = getchar();
	long double tmp = 1;
	for (; !isdigit(ch); ch = getchar())
		sign |= (ch == '-');
	for (x = 0; isdigit(ch); ch = getchar())
		x = x * 10 + (ch ^ 48);
	if (ch == '.')
		for (ch = getchar(); isdigit(ch); ch = getchar())
			tmp /= 10.0, x += tmp * (ch ^ 48);
	return sign ? (x = -x) : x;
}
template <class _Tp>
inline void write(_Tp x) {
	if (x < 0)
		putchar('-'), x = -x;
	if (x > 9)
		write(x / 10);
	putchar((x % 10) ^ 48);
}
const int MAXN = 105;
const int MAXK = 5e4 + 10;
const int INFI = 0x3f3f3f3f;
const int MOD = 998244353;
int n, m, k, v[MAXN];
int add(int x, int y) {
	x += y;
	return x >= MOD ? x - MOD : x;
}
namespace solve1 {
	int ans, cnt[MAXK];
	int popcnt(int x) {
		int ret = 0;
		while (x) ++ret, x -= (x & -x);
		return ret; 
	}
	void dfs(int x, int s, int p) {
		if (p == n + 1) {
			if (cnt[x] <= k)
				ans = add(ans, s);
			return;
		}
		for (int i = 0; i <= m; ++i)
			dfs(x + (1ll << i), 1ll * s * v[i] % MOD, p + 1);
	}
	void main() {
		for (int i = 0; i < MAXK; ++i)
			cnt[i] = popcnt(i);
		dfs(0, 1, 1);
		write(ans), putchar('\n');
	}
}
namespace solve2 {
	int f[MAXN][MAXN];
	void main() {
		
	}
}
signed main() {
	resetIO(sequence);
	read(n), read(m), read(k);
	for (int i = 0; i <= m; ++i)
		read(v[i]);
	if (m <= 12) {
		solve1::main();
	} else if (k == 1) {
		solve2::main();
	} else {
		
	}
	return 0;
}

