#include <bits/stdc++.h>
using namespace std;

const int MN = 10005;

int n, a[MN];

namespace Sub1 {
	int b[10];
	bool vis[10005];
	queue <int> q;
	long long ans;
	int get() {
		int ret = 0;
		for (int i = 1; i <= n; ++ i) ret = ret * 10 + (a[i] - 1);
		return ret;
	}
	void trans(int x) {
		for (int i = n; i >= 1; -- i) {
			b[i] = x % 10 + 1;
			x /= 10;
		}
	}
	long long calc() {
		int s = 0;
		for (int i = 1; i <= n; ++ i) s += a[i];
		long long ret = 0;
		for (int i = 1; i <= n; ++ i) {
			ret += 1ll * (n * a[i] - s) * (n * a[i] - s);
		}
		return ret;
	}
	void solve() {
		q.push(get());
		vis[get()] = 1;
		ans = calc();
		while (!q.empty()) {
			int x = q.front(); q.pop();
			trans(x);
			for (int i = 2; i < n; ++ i) {
				for (int j = 1; j <= n; ++ j) a[j] = b[j];
				a[i] = a[i + 1] + a[i - 1] - a[i];
				int y = get();
				if (!vis[y]) {
					vis[y] = 1;
					q.push(y);
					ans = min(ans, calc());
				}
			}
		}
		printf("%lld", ans / n);
	}
}

namespace Sub2 {
	long long calc() {
		int s = 0;
		for (int i = 1; i <= n; ++ i) s += a[i];
		long long ret = 0;
		for (int i = 1; i <= n; ++ i) {
			ret += 1ll * (n * a[i] - s) * (n * a[i] - s);
		}
		return ret;
	}
	long long ans;
	void solve() {
		ans = calc();
		srand(time(0));
		int T = 5000, i, v;
		while (T --) {
			i = rand() % (n - 2) + 2;
			v = a[i];
			a[i] = a[i + 1] + a[i - 1] - a[i];
			ans = max(ans, calc());
			if (rand() & 1) a[i] = v;
		}
		printf("%lld", ans / n);
	}
}

int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) scanf("%d", &a[i]);
	if (n <= 4) Sub1::solve();
	else Sub2::solve();
	
	return 0;
}
