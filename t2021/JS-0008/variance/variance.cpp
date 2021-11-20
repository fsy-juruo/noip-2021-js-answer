#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int n, a[10005], d[10005];
int cnt[10005];
int maxd = 0;
long long ans = 1LL << 60;

int CNT = 0;

void dfs(int, int, long long, long long);

int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n) if (i) d[i - 1] = a[i] - a[i - 1];
	rep(i, n - 1) cnt[d[i]] += 1, maxd = std::max(maxd, d[i]);
	dfs(1, a[0], a[0], 1LL * n * a[0] * a[0]);
	{
		int dsz = 0;
		for (int i = maxd; i >= 0; -- i) {
			for (int j = 0; j < cnt[i] / 2; ++ j) d[dsz ++] = i;
		}
		for (int i = 0; i <= maxd; ++ i) {
			for (int j = 0; j < (cnt[i] + 1) / 2; ++ j) d[dsz ++] = i;
		}
		rep(i, n) a[i + 1] = a[i] + d[i];
		long long sum = 0, cur = 0;
		rep(i, n) {
			sum += a[i];
			cur += 1LL * n * a[i] * a[i];
		}
		cur -= sum * sum;
		if (cur < ans) ans = cur;
	}
	printf("%lld\n", ans);
	return 0;
}

void dfs(int id, int xi, long long sum, long long cur) {
	++ CNT;
	if (CNT > 1000000) return ;
	if (id == n) {
		ans = std::min(ans, cur - sum * sum);
		return ;
	}
	for (int D = 0; D <= maxd; ++ D) {
		if (cnt[D]) {
			-- cnt[D];
			dfs(id + 1, xi + D, sum + xi + D, cur + 1LL * n * (xi + D) * (xi + D));
			++ cnt[D];
		}
		if (CNT > 1000000) return ;
	}
}

