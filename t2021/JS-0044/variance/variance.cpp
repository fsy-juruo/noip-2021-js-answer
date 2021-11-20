#include <bits/stdc++.h>

#define LL long long
#define int long long
#define ull unsigned long long
#define F(i, j, k) for (int i = j; i <= k; ++i)
#define DF(i, j, k) for (int i = j; i >= k; --i)

using namespace std;

template <typename T> inline void read(T &n) {
    T w = 1; n = 0; char ch = getchar();
    while (!isdigit(ch) && ch != EOF) { if (ch == '-') w = -1; ch = getchar(); }
    while (isdigit(ch) && ch != EOF) { n = (n << 3) + (n << 1) + (ch & 15); ch = getchar(); }
    n *= w;
}

template <typename T> inline void write(T &x) {
    T l = 0; ull y = 0;
    if (!x) { putchar(48); return; }
    if (x < 0) { x = -x; putchar('-'); }
    while (x) { y = y * 10 + x % 10; x /= 10; ++l; }
    while (l) { putchar(y % 10 + 48); y /= 10; --l; }
}

template <typename T> inline void writes(T x) {
    write(x);
    putchar(' ');
}

template <typename T> inline void writeln(T x) {
    write(x);
    puts("");
}

template <typename T> inline void checkmax(T &a, T b) { a = a > b ? a : b; }
template <typename T> inline void checkmin(T &a, T b) { a = a < b ? a : b; }

const int N = 10100;

LL ans = 1e16;

int a[N], la[N], p[N];

signed main() {
    freopen("variance.in", "r", stdin);
    freopen("variance.out", "w", stdout);
    srand(213123);
    int n, del; read(n);
    del = 300;
    F(i, 1, n) read(a[i]); 
    F(i, 1, n) p[i] = i;
    F(i, 1, n) la[i] = a[i];
    F(it, 1, del) {
    F(i, 1, n) a[i] = la[i];
    F(i, 1, 10000) {
    	int x = rand() % (n - 2) + 2;
    	a[x] = a[x - 1] + a[x + 1] - a[x];
    }
    random_shuffle(p + 2, p + n);
    while (1) {
    	int s = 0;
    	F(i, 1, n) s += a[i];
		LL sum = 0;
		F(i, 1, n) sum += (a[i] * n - s) * (a[i] * n - s);
		sum /= n;
		LL nsum = sum, ni = -1;
		F(j, 2, n - 1) {
			a[p[j]] = a[p[j] - 1] + a[p[j] + 1] - a[p[j]];
			s = 0;
			F(i, 1, n) s += a[i];
			sum = 0;
			F(i, 1, n) sum += (a[i] * n - s) * (a[i] * n - s);
			sum /= n;
			if (sum < nsum) { nsum = sum; ni = p[j]; a[p[j]] = a[p[j] - 1] + a[p[j] + 1] - a[p[j]]; }
			else a[p[j]] = a[p[j] - 1] + a[p[j] + 1] - a[p[j]];
		}
		if (ni == -1) { checkmin(ans, nsum); break; }
		a[ni] = a[ni - 1] + a[ni + 1] - a[ni];
	}
	}
	writeln(ans);
    return 0;
}
/*
为所有爱执着的痛
为所有恨执着的伤
我已分不清爱与恨
是否就这样
血和眼泪在一起滑落
我的心破碎风化
颤抖的手却无法停止
无法原谅
*/


