#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 32, S = N * (1 << 12) + 8;
const int mod = 998244353;
int n, m, k;
ll v[N], f[N][S];

inline int popc(int x) {
	int res = 0;
	for (; x; x -= x & -x) ++res;
	return res;
}

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i <= m; ++i) scanf("%lld", &v[i]);
	f[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int S = 1; S <= n * (1 << m); ++S) {
			for (int j = 0; j <= m; ++j) {
				if (S >= (1 << j)) {
					f[i][S] = (f[i][S] + f[i - 1][S - (1 << j)] * v[j]) % mod;
				}
			}
		}
	}
	ll ans = 0;
	for (int S = 1; S <= n * (1 << m); ++S)
		if (popc(S) <= k) {
//			cerr << S << ' ' << f[n][S] << endl;
			ans = (ans + f[n][S]) % mod;
		}
	printf("%lld\n", ans);
	return 0;
}
