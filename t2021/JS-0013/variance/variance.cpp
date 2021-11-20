#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a, 0, sizeof(a))
#define fill1(a) memset(a, -1, sizeof(a))
#define fillbig(a) memset(a, 63, sizeof(a))
#define mp make_pair
#define pb push_back
#define ppb pop_back
template<typename T1, typename T2> void chkmin(T1 &x, T2 y) {
	if (x > y) x = y;
}
template<typename T1, typename T2> void chkmax(T1 &x, T2 y) {
	if (x < y) x = y;
}
typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
template<typename T> void read(T &x) {
	x = 0; char c = getchar(); bool neg = 0;
	while (!isdigit(c)) neg |= (c == '-'), c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (neg) x = -x;
}
const int MAXN = 400;
const int MAXV = 4000;
int n, a[MAXN + 5];
unordered_map<int, ll> dp[MAXN + 5][MAXN + 5];
void upd(int l, int r, int p, ll v) {
	if (!dp[l][r].count(p)) dp[l][r][p] = v;
	else chkmin(dp[l][r][p], v);
}
int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	scanf("%d", &n);
	if (n == 1) return puts("0"), 0;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i < n; i++) a[i] = a[i + 1] - a[i];
	--n; sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) dp[i][i][(n - i + 1) * a[1]] = a[1] * a[1];
	int sum = 0;
	for (int len = 1; len < n; len++) {
		sum += a[len];
		for (int l = 1, r = len; r <= n; l++, r++) {
			for (unordered_map<int, ll> :: iterator it = dp[l][r].begin(); it != dp[l][r].end(); it++) {
				int j = it -> fi; ll v = it -> se;
				if (r != n) upd(l, r + 1, j + a[len + 1] * (n - r), v + 1ll * (sum + a[len + 1]) * (sum + a[len + 1]));
				if (l != 1) upd(l - 1, r, j + a[len + 1] * (n - l + 2), v + 1ll * a[len + 1] * a[len + 1] * (r - l + 2) + 2ll * (j - (n - r) * sum) * a[len + 1]);
			}
		}
	}
	ll mn = 1e18;
	for (unordered_map<int, ll> :: iterator it = dp[1][n].begin(); it != dp[1][n].end(); it++) {
		int j = (it -> fi); ll v = it -> se;
		chkmin(mn, 1ll * v * (n + 1) - 1ll * j * j);
	}
	printf("%lld\n", mn);
	return 0;
}
/*
10
6 19 34 35 56 63 82 82 83 99

50
1 6 25 27 27 28 29 30 32 32 32 32 32 32 32 32 32 32 32 34 36 38 39 40 40 42 45 49 50 51 52 53 53 54 54 54 56 57 57 57 59 59 59 59 61 63 63 63 64 66
*/
