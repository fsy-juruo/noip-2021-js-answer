// pts: 48
#include <cstdio>
#include <algorithm>
#include <functional>

#define int long long

#define _N 10010

int n;

int a[_N], b[_N];

int ans = 0x3f3f3f3f3f3f3f3f;

void dfs(int cur, int lpt, int rpt) {
	if (cur == n) {
		int respw = 0, ressum = 0;
		for (int i = 1; i <= n; i++) {
			respw += a[i] * a[i];
			ressum += a[i];
		}
		ans = std::min(ans, n * respw - ressum * ressum);
		return;
	}
	a[lpt] = a[lpt - 1] + b[cur];
	dfs(cur + 1, lpt + 1, rpt);
	a[rpt] = a[rpt + 1] - b[cur];
	dfs(cur + 1, lpt, rpt - 1);
}

signed main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	for (int i = 1; i < n; i++) {
		b[i] = a[i + 1] - a[i];
	}
	std::sort(b + 1, b + n, std::greater<int>());
	dfs(1, 2, n - 1);
	printf("%lld\n", ans);
	return 0;
}
