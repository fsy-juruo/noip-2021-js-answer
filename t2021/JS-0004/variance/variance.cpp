#include <bits/stdc++.h>
using namespace std;
int n, a[10005], d[10005];
int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i < n; i++) d[i] = a[i + 1] - a[i];
	sort(d + 1, d + n);
	long long ans = 1e18;
	do {
		long long cur = 0, sum = 0;
		for (int i = 1; i < n; i++) {
			sum += 1ll * i * (n - i) * d[i] * d[i] + 2ll * (n - i) * d[i] * cur;
			cur += i * d[i];
		}
		ans = min(ans, sum);
	} while (next_permutation(d + 1, d + n));
	printf("%lld\n", ans);
	return 0;
}
