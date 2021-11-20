#include <bits/stdc++.h>
#define LL long long
using namespace std;

bool vis[10005][605];

LL D, ans = INT_MAX, a[10005], D2;

int n;

void dfs(LL tot, LL tot2)
{
	ans = min(ans, n * tot2 - tot * tot);
	for (int i = 2; i <= n - 1; i++)
		if (!vis[i][a[i - 1] + a[i + 1] - a[i]])
		{
			vis[i][a[i - 1] + a[i + 1] - a[i]] = 1;
			int fp = a[i - 1] + a[i + 1] - a[i], t = a[i], x1 = tot, x2 = tot2;
			tot = tot - t + fp;
			tot2 = tot2 - t * t + fp * fp;
			a[i] = fp;
			dfs(tot, tot2);
			a[i] = t;
			tot = x1;
			tot2 = x2;
		}
}

int main()
{
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]), vis[i][a[i]] = 1;
	for (int i = 1; i <= n; i++)
		D += a[i], D2 += a[i] * a[i];
	dfs(D, D2);
	printf("%lld\n", ans);
	return 0;
}

