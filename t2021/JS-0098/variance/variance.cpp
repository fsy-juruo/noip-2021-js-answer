#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int read() {
	int x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) x = x * 10 + c - 48, c = getchar();
	return x; }
const int N = 1e4 + 10;
int a[N], c[N], d[N];
int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	int n = read(); LL ans=1ll << 50; for(int i = 1; i <= n; ++i) a[i] = read();
	for (int i = 1; i <= n; ++i) c[i] = a[i] - a[i - 1];
	sort(c + 2, c + n + 1);
	do {
		for (int i = 1; i <= n; ++i) d[i] = d[i - 1] + c[i];
		LL S1 = 0, S2 = 0;
		for (int i = 1; i <= n; ++i) S1 += d[i], S2 += d[i] * d[i];
		if (n * S2 -  S1 * S1 < ans) ans = n * S2 - S1 * S1;
	} while (next_permutation(c + 2, c + n + 1));
	cout << ans << '\n';
	return 0;
}
