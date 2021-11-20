#include<bits/stdc++.h>
using namespace std;

#define U(x, y, z) for (int x = y; x <= z; ++x)
#define D(x, y, z) for (int x = y; x >= z; --x)

const int N = 1e4 + 10;

template <typename T> inline void read(T &n) {
    n = 0; char ch; bool f = 1;
    for (ch = getchar(); !isdigit(ch); ch = getchar()) if (ch == '-') f = 0;
    for (; isdigit(ch); ch = getchar()) n = (n << 1) + (n << 3) + (ch ^ 48);
    if (f == 0) n = -n;
}

template <typename T> inline void chkmin(T &x, T y) {
	if (x > y) x = y;
}

template <typename T> inline void chkmax(T &x, T y) {
	if (x < y) x = y;
}

inline void file(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

#define LL long long

int n;
int a[N];
LL sum1, sum2;
inline LL sqr(int a) {
	return a * a;
}

int main() {
	file("variance");
	read(n);
	U(i, 1, n) read(a[i]);
	bool tag = 1;
	U(i, 1, n) sum1 += a[i] * a[i];
	U(i, 1, n) sum2 += a[i];
	int tot = 0;
	srand(time(0));
	LL ans = LONG_LONG_MAX;
	chkmin(ans, sum1 * n - sum2 * sum2);
	while (tot <= 2e7) {
		++tot;
		int ps = rand() % (n - 2);
		ps += 2;	
//		U(i, ps, ps) {
			int i = ps;
			sum1 -= sqr(a[i]), sum2 -= a[i];
			a[i] = a[i - 1] + a[i + 1] - a[i];
			sum1 += a[i] * a[i], sum2 += a[i];
//		}
		chkmin(ans, sum1 * n - sum2 * sum2);
	}
	cout << ans << endl;
    return 0;
}
