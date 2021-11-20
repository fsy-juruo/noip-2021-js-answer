#include <bits/stdc++.h>
using namespace std;
#define int long long
#define resetIO(x) \
	freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define debug(fmt, ...) \
	fprintf(stderr, "[%s:%d] " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)
template <class _Tp>
inline _Tp& read(_Tp& x) {
	bool sign = 0;
	char ch = getchar();
	long double tmp = 1;
	for (; !isdigit(ch); ch = getchar())
		sign |= (ch == '-');
	for (x = 0; isdigit(ch); ch = getchar())
		x = x * 10 + (ch ^ 48);
	if (ch == '.')
		for (ch = getchar(); isdigit(ch); ch = getchar())
			tmp /= 10.0, x += tmp * (ch ^ 48);
	return sign ? (x = -x) : x;
}
template <class _Tp>
inline void write(_Tp x) {
	if (x < 0)
		putchar('-'), x = -x;
	if (x > 9)
		write(x / 10);
	putchar((x % 10) ^ 48);
}
const int MAXN = 2e5 + 5;
const int MAXM = 2e7 + 5;
const int MAXP = 2e6 + 5;
const int MAXK = 1e6 + 5;
const int INFL = 0x3f3f3f3f3f3f3f3f;
struct node {
	int x, id;
	bool operator<(const node &o) const {
		return x < o.x;
	}
};
int q, sta[MAXN], ans[MAXN];
int pri[MAXP], fac[MAXM], cntp;
node a[MAXN];
bool mark[MAXM], used[MAXM];
signed main() {
	resetIO(number);
	for (int i = 0; i < MAXK; ++i) {
		for (int j = 0, x = 1; j <= 6; ++j, x *= 10) {
			int tx = i / x, ty = i % x;
			used[tx * x * 10 + 7 * x + ty] = true;
		}
	}
	for (int i = 2; i < MAXM; ++i) {
		if (!mark[i])
			pri[fac[i] = ++cntp] = i;
		for (int j = 1; j <= cntp; ++j) {
			if (i * pri[j] >= MAXM)
				break;
			mark[i * pri[j]] = true;
			fac[i * pri[j]] = j;
			if (i % pri[j] == 0)
				break;
		}
	}
	read(q);
	for (int i = 1; i <= q; ++i)
		read(a[i].x), a[i].id = i;
	sort(a + 1, a + q + 1);
	int pos = 1, cnt = 0, top = 0;
	for (int i = 1; cnt < q; ++i) {
		if (!used[i]) {
			int t = i;
			while (t != 1) {
				if (used[i / pri[fac[t]]]) {
					used[i] = true;
					break;
				}
				t /= pri[fac[t]];
			}
		}
		while (!used[i] && top)
			ans[sta[top--]] = i, ++cnt;
		while (pos <= q && a[pos].x == i) {
			if (used[i])
				ans[a[pos].id] = -1, ++cnt;
			else
				sta[++top] = a[pos].id;
			++pos;
		}
	}
	for (int i = 1; i <= q; ++i)
		write(ans[i]), putchar('\n'); 
	return 0;
}

