#include <bits/stdc++.h>

using namespace std;

template<typename T> void read(T &x) {
	x = 0; bool f = false; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) f ^= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	if (f) x = -x;
}
template<typename T> void write(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar((x % 10) ^ 48);
}

using ll = long long;

const int maxn = 30, maxm = 105, mod = 998244353;

int n, m, k;
int num[maxm];
ll ans, res;
ll v[maxm], jc[maxn], ni[maxn], pdt[maxm];

void dfs(int p) {
	if (p == m + 1) {
		if (n || __builtin_popcount(res) > k) return;
		ll tmp = 1;
		for (int i = 0; i <= m; i++) {
			tmp = tmp * ni[num[i]] % mod;
			tmp = tmp * pdt[i] % mod;
		}
		ans = (ans + tmp) % mod;
		return;
	}
	ll tmp = 1;
	for (int i = 0; i <= n; i++) {
		num[p] = i;
		pdt[p] = tmp;
		n -= i;
		res += (1ll << p) * i;
		dfs(p + 1);
		res -= (1ll << p) * i;
		n += i;	
		tmp = tmp * v[p] % mod;
	}
}

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	read(n), read(m), read(k);
	jc[0] = 1;
	for (int i = 1; i <= n; i++) jc[i] = jc[i - 1] * i % mod;
	ni[0] = ni[1] = 1;
	for (int i = 2; i <= n; i++) ni[i] = (mod - mod / i) * ni[mod % i] % mod;
	for (int i = 2; i <= n; i++) ni[i] = ni[i] * ni[i - 1] % mod;
	for (int i = 0; i <= m; i++) read(v[i]);
	dfs(0);
	write(ans * jc[n] % mod), putchar('\n');
	return 0;
} 
