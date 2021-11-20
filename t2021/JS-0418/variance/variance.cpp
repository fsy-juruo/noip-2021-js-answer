#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 10, inf = 0x3f3f3f3f;

int n, ans = inf, res = inf;
int a[maxn], id[maxn], b[maxn], c[maxn];

double myrand() {
	return (double)rand() / RAND_MAX;
}
int calc() {
	for (int i = 1; i <= n; i++) b[i] = b[i - 1] + a[i];
	int cur = 0, sum = 0;
	for (int i = 1; i <= n; i++) {
		cur += b[i] * b[i];
		sum += b[i];
	}
	return cur * n - sum * sum;
}

int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	srand(time(nullptr));
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = n; i >= 1; i--) a[i] -= a[i - 1]; 
	if (n <= 10) {
		for (int i = n; i >= 1; i--) id[i] = i;
		do {
			for (int i = 1; i <= n; i++) b[i] = b[i - 1] + a[id[i]];
			int cur = 0, sum = 0;
			for (int i = 1; i <= n; i++) {
				cur += b[i] * b[i];
				sum += b[i];
			}
			ans = min(ans, cur * n - sum * sum);
		} while (next_permutation(id + 2, id + n + 1));
		cout << ans << "\n";
	} else {
		double t0 = n * 100, dt = 0.999, tt0 = t0 * 2;
		ans = res = calc();
		while (t0 >= 1) {
			int len = min((int)t0, n);
			for (int i = 2; i + len - 1 <= n; i++) {
				copy(a + 1, a + n + 1, c + 1);
				random_shuffle(a + i, a + i + len);
				int tmp = calc();
				res = min(res, tmp);
				if (tmp < ans) {
					ans = tmp;
				} else if (myrand() <= t0 / tt0) {
					ans = tmp;
				} else {
					copy(c + 1, c + n + 1, a + 1);
				}
			}
			t0 *= dt;
		}
		cout << res << "\n";
	}
	return 0;
}
