#include <bits/stdc++.h>
using namespace std;

template <typename T> void read(T &x) {
	x = 0; int op = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') op = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	x *= op;
}

int T, mx;
int q[200005];

namespace Sub1 {
	const int MN = 300000 + 10;
	const int L = 300000;

	int f[MN];
	int nxt[MN];
	
	bool check(int x) {
		bool flag = 0;
		while (x) flag |= (x % 10 == 7), x /= 10;
		return flag;
	}
	
	void solve() {
		int x = 1;
		for (int i = 2; i <= L; ++ i) {
			if (!f[i]) {
				if (check(i)) f[i] = 1;
				if (f[i]) {
					for (int j = i + i; j <= L; j += i) f[j] = 1;
				}
			}
			if (!f[i]) {
				nxt[x] = i;
				x = i;
			}
		}
		for (int i = 1; i <= T; ++ i) {
			if (f[q[i]]) puts("-1");
			else printf("%d\n", nxt[q[i]]);
		}
	}
	
}

namespace Sub2 {
	const int MN = 10000100 + 10;
	const int L = 10000100;

	int f[MN];
	int nxt[MN];
	
	bool check(int x) {
		bool flag = 0;
		while (x) flag |= (x % 10 == 7), x /= 10;
		return flag;
	}
	
	void solve() {
		int x = 1;
		for (int i = 2; i <= L; ++ i) {
			if (!f[i]) {
				if (check(i)) f[i] = 1;
				if (f[i]) {
					for (int j = i + i; j <= L; j += i) f[j] = 1;
				}
			}
			if (!f[i]) {
				nxt[x] = i;
				x = i;
			}
		}
		for (int i = 1; i <= T; ++ i) {
			if (f[q[i]]) puts("-1");
			else printf("%d\n", nxt[q[i]]);
		}
	}
}


int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	read(T);
	for (int i = 1; i <= T; ++ i) {
		read(q[i]);
		mx = max(mx, q[i]);
	}
	if (mx <= 200000) Sub1::solve();
	else Sub2::solve();
	
	return 0;
}
