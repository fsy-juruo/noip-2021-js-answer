#include <bits/stdc++.h>

#define LL long long
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

const int MX = 1e7 + 1;

inline int ck(int x) {
	while (x) {
		if (x % 10 == 7) return 1;
		x /= 10;
	}
	return 0;
}

int p[MX + 10], nx[MX + 10];

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    F(i, 1, MX) {
    	if (p[i]) continue;
    	p[i] = ck(i);
    	if (p[i]) for (int j = i * 2; j <= MX; j += i) p[j] = 2;
    }
    F(i, 1, MX) {
    	if (p[i]) continue;
    	int pos = i + 1;
    	while (p[pos]) ++pos;
    	nx[i] = pos;
    }
    int T; read(T);
    while (T--) {
    	int x; read(x);
    	if (p[x]) puts("-1");
    	else writeln(nx[x]);
    }
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

