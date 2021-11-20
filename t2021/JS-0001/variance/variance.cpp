#include <bits/stdc++.h>
using namespace std;

const int maxn = 10005;
const int maxm = 605;
const int maxs = 500005;
const long long Inf = 1e18;
int n, m, s, sum;
int a[maxn], b[maxn];
long long ans;
long long dp[maxs], ndp[maxs];

void ckmin(long long &a, long long b) {
	if (b < a) a = b;
}

int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (i > 1) b[i - 1] = a[i] - a[i - 1]; 
	}
	sort(b + 1, b + n);
	m = a[n] - a[1];
	s = (n - 1) * m;
	for (int j = 0; j <= s; j++)
		dp[j] = ndp[j] = Inf;
	dp[0] = 0;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 0; j <= s; j++) if (dp[j] != Inf) {
			ckmin(ndp[j + b[i] * i], dp[j] + 2LL * b[i] * j + 1LL * b[i] * b[i] * i);
			ckmin(ndp[j + sum + b[i]], dp[j] + 1LL * (sum + b[i]) * (sum + b[i]));
		}
		for (int j = 0; j <= s; j++)
			dp[j] = ndp[j], ndp[j] = Inf;
		sum += b[i];
	}
	ans = Inf;
	for (int j = 0; j <= s; j++) if (dp[j] != Inf)
		ckmin(ans, n * dp[j] - 1LL * j * j);
	printf("%lld\n", ans);
	return 0; 
}
 
