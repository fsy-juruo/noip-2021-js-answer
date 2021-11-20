#include <bits/stdc++.h>

using namespace std;
const int MAXM = 100 + 10, MOD = 998244353;
int n, m, k, a[MAXM], v[MAXM], ans;
long long p[MAXM];

void dfs(int t, int sum, int an) {
	if (sum > an) return;
	if (sum == an && t < n) return;
	if (t == n) {
		if (sum == an) {
			int t = 1;
			for (int i = 0; i <= m; i++)
				for (int j = 0; j < a[i]; j++)
					t = (t * v[i]) % MOD;
			ans = (ans + t) % MOD;
		}
		return;
	}
	for (int i = 0; i <= m; i++) {
		a[i]++;
		dfs(t + 1, sum + p[i], an);
		a[i]--;
	}
}

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	p[0] = 1;
	for (int i = 1; i < MAXM; i++)
		p[i] = p[i - 1] * 2;
	cin >> n >> m >> k;
	for (int i = 0; i <= m; i++)
		cin >> v[i];
	for (int i = p[0]; i <= n * p[m]; i *= 2) {
		if (i >= n) dfs(0, 0, i);
	}
	cout << ans << endl;
	return 0;
}

