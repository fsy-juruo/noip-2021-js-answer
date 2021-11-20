#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e4 + 10, MAXM = 6e2 + 10;
int n, a[MAXN];
long long ans = 0x3f3f3f3f;
bool v[MAXN][MAXM];

long long fc() {
	long long an = 0, d;
	for (int i = 1; i <= n; i++)
		an += a[i];
	d = an * an;
	for (int i = 1; i <= n; i++)
		d += a[i] * (a[i] * n - an * 2);
	return d;
}

void dfs() {
	ans = min(ans, fc());
	for (int i = 2; i <= n - 1; i++) {
		int at = a[i - 1] + a[i + 1] - a[i], att = a[i];
		if (v[i][at]) continue;
		v[i][at] = 1;
		a[i] = at;
		dfs();
		a[i] = att;
	}
}

int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		v[i][a[i]] = 1;
	}
	dfs();
	cout << ans << endl;
	return 0;
}

