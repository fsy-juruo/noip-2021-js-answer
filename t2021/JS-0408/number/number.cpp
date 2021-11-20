#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i <= (b); ++i)
#define DF(i, a, b) for (int i = (a); i >= (b); --i)
#define SZ(x) (int)x.size() - 1
#define all(x) x.begin(), x.end()

using namespace std;
template <typename T> inline void read(T& x) {
	x = 0; int f = 1; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	x *= f;
}
template <typename T> inline void write(T x) {
	if (x < 0) { putchar('-'); x *= -1; }
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
template <typename T> inline void writes(T x) { write(x); putchar(' '); }
template <typename T> inline void writeln(T x) { write(x); puts(""); }
template <typename T> inline void chkmax(T& x, T y) { x = max(x, y); }
template <typename T> inline void chkmin(T& x, T y) { x = min(x, y); }

const int N = 2e7 + 10;
bool h[N];
int nxt[N];
bool check(int x) {
	while (x) {
		if (x % 10 == 7) return true;
		x /= 10;
	}
	return false;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int lim = 1e7 + 10;
	F(i, 1, lim) {
		if (h[i]) continue;
		if (check(i)) {
			for (int j = i; j <= lim; j += i) h[j] = true;
		}
	}
	int lst = 0;
	F(i, 1, lim) {
		if (h[i]) continue;
		nxt[lst] = i;
		lst = i;
	}
//	cout << sizeof(h) / 1024 / 1024 << endl;
	int _; read(_);
	while (_--) {
		int x; read(x);
		if (h[x]) {
			puts("-1");
			continue;
		}
		writeln(nxt[x]);
	}
	return 0;
}

