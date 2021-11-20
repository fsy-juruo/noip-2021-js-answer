#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110;
const int D = 11;
int n, ans = 0x3f;
int a[MAXN], b[MAXN];
int vis[D][D][D][D];

void copy() {
	for (int i(1); i <= n; ++i)
		b[i] = a[i];
	vis[a[1]][a[2]][a[3]][a[4]] = 1;
}

int maths() {
	int res = 0, equal = 0;
	for (int i(1); i <= n; ++i)
		equal += b[i];
	for (int i(1); i <= n; ++i)
		res = res + (n * b[i] - equal) * (n * b[i] - equal) / n;
	return res;
}

int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	int last = 0;
	cin >> n;
	for (int i(1); i <= n; ++i)
		cin >> a[i];
	if (n == 4) {
		copy();
		while (true) {
			if (!last) {
				b[2] = b[1] + b[3] - b[2];
				last = 1;
			}
			else {
				b[3] = b[2] + b[4] - b[3];
				last = 0;
			}
			if (vis[b[1]][b[2]][b[3]][b[4]]) break;
			vis[b[1]][b[2]][b[3]][b[4]] = 1;
			ans = min(ans, maths());
		}
		copy();
		last = 1;
		while (true) {
			if (!last) {
				b[2] = b[1] + b[3] - b[2];
				last = 1;
			}
			else {
				b[3] = b[2] + b[4] - b[3];
				last = 0;
			}
			if (vis[b[1]][b[2]][b[3]][b[4]]) break;
			vis[b[1]][b[2]][b[3]][b[4]] = 1;
			ans = min(ans, maths());
		}
	}
	else if (n == 3) {
		a[2] = a[1] + a[3] - a[2];
		ans = min(ans, maths());
	}
	else if (n <= 2) ans = min(ans, maths());
	cout << ans << endl;
	return 0;
}

