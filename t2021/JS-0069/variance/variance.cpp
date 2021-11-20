#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
typedef long long LL;
const int N = 10005;
int n, a[N], b[N];
int sum;
inline int check(int a, int b) { return abs(a - sum) < abs(b - sum) ? a : b; }
inline LL calc()
{
	int suma = 0, sumb = 0;
	for (int i = 1; i <= n; i++) { suma += b[i] * b[i]; sumb += b[i]; }
	return (LL) n * suma - (LL) sumb * sumb;
}
const int base = 99991;
ULL p[N];
map <ULL, bool> vis;
LL ans;
inline void dfs(ULL now, int suma, int sumb)
{
	if (vis.count(now)) return;
	vis[now] = 1;
	ans = min(ans, (LL) n * suma - (LL) sumb * sumb);
	for (int i = 2; i <= n - 1; i++)
	{
		int tmp = a[i];
		a[i] = a[i - 1] + a[i + 1] - a[i];
		dfs(now - p[i] * tmp + p[i] * a[i], suma - tmp * tmp + a[i] * a[i], sumb - tmp + a[i]);
		a[i] = tmp;
	}
}
int main()
{
	freopen ("variance.in", "r", stdin);
	freopen ("variance.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) scanf ("%d", &a[i]);
	if (n <= 15)
	{
		p[0] = 1;
		for (int i = 1; i <= n; i++) p[i] = p[i - 1] * base;
		int suma = 0, sumb = 0;
		ULL now = 0;
		for (int i = 1; i <= n; i++)
		{
			now += p[i] * a[i];
			suma += a[i] * a[i];
			sumb += a[i];
		}
		ans = 1e18;
		dfs(base, suma, sumb);
		printf ("%lld\n", ans);
		return 0;
	}
	ans = 1e18;
	for (sum = n; sum <= n * a[n]; sum++)
	{
		int p = -1;
		for (int i = 1; i <= n; i++) if (a[i] < 1.0 * sum / n && a[i + 1] >= 1.0 * sum / n) { p = i; break; }
		if (p == -1) continue;
		for (int r = p; r < n; r++)
		{
			for (int i = 1; i <= n; i++) b[i] = a[i];
			for (int i = r; i >= p + 1; i--) b[i] = max(b[i], b[i - 1] + b[i + 1] - b[i]);
			for (int i = r + 1; i < n; i++) b[i] = max(b[i], b[i - 1] + b[i + 1] - b[i]);
			for (int i = p; i > 1; i--) b[i] = max(b[i], b[i - 1] + b[i + 1] - b[i]);
			ans = min(ans, calc());
		}
		for (int l = p + 1; l > 1; l--)
		{
			for (int i = 1; i <= n; i++) b[i] = a[i];
			for (int i = l; i <= p; i++) b[i] = max(b[i], b[i - 1] + b[i + 1] - b[i]);
			for (int i = l - 1; i > 1; i--) b[i] = max(b[i], b[i - 1] + b[i + 1] - b[i]);
			for (int i = p + 1; i < n; i++) b[i] = max(b[i], b[i - 1] + b[i + 1] - b[i]);
			ans = min(ans, calc());
		}
	}
	printf ("%lld\n", ans);
	return 0;
}
