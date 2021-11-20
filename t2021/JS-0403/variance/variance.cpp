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
const int MAXN = 1e4 + 10;
const int MAXM = 21;
const int INFL = 0x3f3f3f3f3f3f3f3f;
int n;
struct node {
	int arr[MAXM];
	int calc() {
		int s1 = 0, s2 = 0;
		for (int i = 1; i <= n; ++i)
			s1 += arr[i];
		for (int i = 1; i <= n; ++i)
			s2 += arr[i] * arr[i];
		return s2 * n - s1 * s1; 
	}
	bool operator<(const node &o) const {
		for (int i = 1; i <= n; ++i)
			if (arr[i] != o.arr[i])
				return arr[i] < o.arr[i];
		return false;
	}
};
node st;
set<node> s;
queue<node> que;
signed main() {
	resetIO(variance);
	read(n);
	for (int i = 1; i <= n; ++i)
		read(st.arr[i]);
	que.push(st);
	int ans = INFL;
	while (!que.empty()) {
		node t = que.front();
		que.pop();
		ans = min(ans, t.calc());
		for (int i = 2; i < n; ++i) {
			t.arr[i] = t.arr[i - 1] + t.arr[i + 1] - t.arr[i];
			if (!s.count(t))
				que.push(t), s.insert(t);
			t.arr[i] = t.arr[i - 1] + t.arr[i + 1] - t.arr[i];
		}
	}
	write(ans), putchar('\n');
	return 0;
}

