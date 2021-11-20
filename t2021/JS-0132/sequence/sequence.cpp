#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 15;
const ll MOD = 998244353;
int n, m, k, v[N], a[N];
ll ans;
int nums (int x) {
	int ret = 0;
	while (x) {
		ret += (x & 1);
		x >>= 1;
	}
	return ret;
}
void solve (int val, int sums, int step) {
	if (step > n) {
		if (nums (sums) > k)
			return ;
		ans += val;
		ans %= MOD;
		return ;
	}
	for (int i = 0; i <= m; i ++) {
		a[step] = i;
		solve (1LL * val * v[i] % MOD, sums + (1 << i), step + 1);
	}
	return ;
}
int main () {
	freopen ("sequence.in", "r", stdin);
	freopen ("sequence.out", "w", stdout);
	scanf ("%d%d%d", &n, &m, &k);
	for (int i = 0; i <= m; i ++)
		scanf ("%d", &v[i]);
	solve (1, 0, 1);
	printf ("%lld\n", ans);
	return 0;
}

