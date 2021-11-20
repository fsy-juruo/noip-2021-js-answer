#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 10007;
int a[N], d[N], p[N];
long long ans = ~0ULL >> 1;
long long calc() {
	long long res = 0, s = 0;
	for (int i = 1; i <= n; i++) a[i] = a[i - 1] + p[i - 1], s += a[i];
	for (int i = 1; i <= n; i++)
	res += 1ll * (n * a[i] - s) * (n * a[i] - s);
	res /= n;
	return res;
}
void dfs (int l, int r, int x) {
	if (l > r) {
		ans = min (ans, calc());
		return;
	}
	p[l] = d[x]; dfs (l + 1, r, x - 1); p[l] = 0;
	p[r] = d[x]; dfs (l, r - 1, x - 1); p[r] = 0;
}
int main() {
	freopen ("variance.in", "r", stdin);
	freopen ("variance.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) scanf ("%d", &a[i]);
	for (int i = 1; i < n; i++) d[i] = a[i + 1] - a[i];
	p[0] = a[1];
	sort (d + 1, d + n);
	dfs (1, n - 1, n - 1);
	cout << ans;
	fclose (stdin);
	fclose (stdout);
	return 0;
}
