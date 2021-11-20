#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e7 + 10;
int a[MAXN], b[MAXN], tt;
bool p[MAXN];

bool qi(int x) {
	if (x == 7) return 1;
	if (x <= 13) return 0;
	while (x) {
		if (qi(x % 10)) return 1;
		x /= 10;
	}
	return 0;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for (int i = 1; i < MAXN; i++) {
		if (!p[i] && qi(i)) {
			for (int j = i; j < MAXN; j += i)
				p[j] = 1;
		}
	}
	for (int i = 1; i < MAXN; i++) {
		if (!p[i]) {
			a[i] = tt;
			b[tt] = i;
			tt++;
		}
	}
	int t, x;
	cin >> t;
	while (t--) {
		cin >> x;
		if (p[x]) cout << -1 << endl;
		else cout << b[a[x] + 1] << endl;
	}
	return 0;
}

