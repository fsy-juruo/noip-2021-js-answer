#include <bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
using namespace std;
typedef long long ll;
const int Inf = 0x3f3f3f3f;

void inline chmin(ll &a, ll b) {
	a = min(a, b);
}

ll f[105][105];
ll dp[101][101][6005];
int N;
int a[405], d[405];

int main() {
	freopen("variance.in", "r", stdin);
	#ifndef Acetyl
	freopen("variance.out", "w", stdout);
	#endif
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", a + i);
	if (N == 1) return puts("0"), 0;
	--N; for (int i = 1; i <= N; ++i) d[i] = a[i + 1] - a[i];
	sort(d + 1, d + N + 1);
	for (int i = 1; i <= N; ++i) a[i] = a[i - 1] + d[i];
	for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j) f[i][j] = min(i, j) * (N - max(i, j) + 1);
	memset(dp, Inf, sizeof(dp));
	for (int i = 1; i <= N; ++i) dp[i][i][d[1] * (N + 1 - i)] = f[i][i] * d[1] * d[1];
	for (int l = 1; l < N; ++l) {
		for (int i = 1; i <= N - l + 1; ++i) {
			int j = i + l - 1;
			for (int k = 0; k <= N * a[l]; ++k) {
				int kl = k, kr = a[l] * (N + 1) - k;
				if (i > 1) {
					chmin(dp[i - 1][j][k + d[l + 1] * (N + 2 - i)], dp[i][j][k] + 2 * kl * (i - 1) * d[l + 1] + d[l + 1] * d[l + 1] * f[i - 1][i - 1]);
				}
				if (j < N) {
					chmin(dp[i][j + 1][k + d[l + 1] * (N - j)], dp[i][j][k] + 2 * kr * (N - j) * d[l + 1] + d[l + 1] * d[l + 1] * f[j + 1][j + 1]);
				}
			}
		}
	}
	printf("%lld\n", *min_element(dp[1][N], dp[1][N] + (N * a[N] + 1)));
	return 0;
}
