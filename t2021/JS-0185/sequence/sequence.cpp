#include<cstdio>
using namespace std;
int n, m, k;
int v[100], a[100];

long long ans = 0;

void dfs(int x) {
	if (x == n) {
		int s = 0;
		for (int i = 0; i < n; ++i)
			s += 1 << a[i];
		int cnt = 0;
		for (; s; ) {
			cnt += s % 2;
			s /= 2;
		}
		if (cnt <= k) {
			long long qaq = 1;
			for (int i = 0; i < n; ++i) {
				qaq *= v[a[i]];
				qaq %= 998244353;
			}
			ans += qaq;
			ans %= 998244353;
		}
		return;
	}
	for (int i = 0; i <= m; ++i) {
		a[x] = i;
		dfs(x + 1);
	}
}

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i <= m; ++i)
		scanf("%d", &v[i]);
	dfs(0);
	printf("%lld", ans);
	return 0;
}

