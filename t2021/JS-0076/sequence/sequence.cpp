#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 35;
const int M = 105;
const int mod = 998244353;

int n, m, k, v[M][M], c[M], d[M], ans;
int fac[M][M];

#define de(x) cerr << (#x) << ":" << x << endl
#define deb(x, y) cerr << (#x) << "[" << y << "]:" << x[y] << ' '

void read(int &x) {
	x = 0; int op = 1;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') op = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	x *= op;
}

bool check() {
	int tot = 0, q = 1ll;
	for (int i = 0; i <= m; ++ i) d[i] = c[i];
	for (int i = 0; i < m; ++ i) {
		d[i + 1] += d[i] / 2ll;
		d[i] %= 2ll;
		tot += (d[i] == 1ll);
	}
	while (q < d[m]) q <<= 1ll;
	while (d[m]) {
		if (d[m] >= q) d[m] -= q, tot ++;
		q >>= 1ll;
	}
	return tot <= k;
}

int calc() {
	int tmp = 1ll, q = n;
	for (int i = 0; i <= m; ++ i) {
		tmp = tmp * fac[q][q - c[i]] % mod;
		q -= c[i];
	}
	for (int i = 0; i <= m; ++ i) tmp = tmp * v[i][c[i]] % mod;
	return tmp;
}

void dfs(int step, int res) {
	if (step == m) {
		c[step] = res;
		if (check()) ans = (ans + calc()) % mod;
		return;
	}
	for (int i = 0; i <= res; ++ i) {
		c[step] = i;
		dfs(step + 1, res - i);
		c[step] = 0;
	}
}

void init() {
	for (int i = 0; i <= m; ++ i) v[i][0] = 1ll;
	for (int j = 2; j <= n; ++ j)
		for (int i = 0; i <= m; ++ i) 
			v[i][j] = v[i][j - 1] * v[i][1] % mod;
	fac[0][0] = 1ll;
	for (int i = 1; i <= n; ++ i) {
		fac[i][0] = 1ll;
		for (int j = 1; j <= i; ++ j)
			fac[i][j] = (fac[i - 1][j - 1] + fac[i - 1][j]) % mod;
	}
}

signed main() {
	freopen ("sequence.in", "r", stdin);
	freopen ("sequence.out", "w", stdout);
	read(n); read(m); read(k);
	for (int i = 0; i <= m; ++ i) read(v[i][1]);
	init();
	dfs(0, n);
	printf("%lld\n", ans);
	return 0;
}

