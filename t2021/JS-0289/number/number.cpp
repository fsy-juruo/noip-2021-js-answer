#include <bits/stdc++.h>

using namespace std;

const int MAXX = 1e4 + 10;
int t, x;
int vis[MAXX];

bool cpr(int n) {
	while (n) {
		if (n % 10 == 7) return true;
		n /= 10;
	}
	return false;
}

void fir() {
	for (int i(1); i <= MAXX; ++i) {
		if (vis[i]) continue;
		if (cpr(i)) {
			vis[i] = true;
			for (int j(2); j * i <= MAXX; ++j)
				vis[i * j] = true;
		}
	}
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	fir();
	cin >> t;
	while (t--) {
		cin >> x;
		if (vis[x]) cout << -1 << endl;
		else for (int i(x + 1); i <= MAXX; ++i) {
			if (!vis[i]) {
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}

