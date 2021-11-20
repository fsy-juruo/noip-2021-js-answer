//Programmed by Fw
//qwq
#define tsk "variance"
//#undef LOCAL

#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define getchar gc
#endif
char buf[1 << 21], *p1 = buf, *p2 = buf;
#define rep(i, a, b) for (int i = (a); i <= (b); ++ i)
#define per(i, a, b) for (int i = (a); i >= (b); -- i)
#define fore(i, x) for (int i = head[x]; i; i = nxt[x])
constexpr int MAXN = 51;

inline char gc() {
	return p1 == p2 && (p2 = (p1 = buf) +
		fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1 ++;
}
inline void rd(auto& p) {
	p = 0; char ch = getchar(); bool sgn = false;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') sgn ^= 1;
	for (;  isdigit(ch); ch = getchar()) p = p * 10 + (ch ^ '0');
	if (sgn) p = -p;
}
template <typename T, typename... _T>
inline void rd(T& p, _T&... _p) { rd(p); rd(_p...); }

int n, ans;
set< array<int, MAXN> > st;

struct Node {
	array<int, MAXN> sq;
	double a, d;
	inline void init() {
		a = d = 0;
		rep (i, 1, n) a += sq[i];
		a /= n;
		rep (i, 1, n) d += (sq[i] - a) * (sq[i] - a);
		d *= n;
	}
	inline void calc(int p, const Node& x) {
		sq = x.sq; sq[p] = x.sq[p - 1] + x.sq[p + 1] - x.sq[p];
		double dlt = x.sq[p - 1] + x.sq[p + 1] - 2 * x.sq[p];
		a = (x.a * n + dlt) / n;
		d = x.d - dlt * dlt + n * (x.sq[p - 1] + x.sq[p + 1] - 2 * x.a) * dlt;
//		cout << x.d << ' ' << dlt * dlt << ' ' << (x.sq[p - 1] + x.sq[p + 1] - 2 * x.a) << ' ' << dlt << endl;
//		cout << d << ' ' << a << endl;
	}
	Node(const Node& x) { sq = x.sq; a = x.a; d = x.d; }
	Node() { sq = {0}; a = 0; d = 0;}
} a;

signed main() {
#ifndef LOCAL
	freopen(tsk".in",  "r", stdin);
	freopen(tsk".out", "w", stdout);
#endif
	rd(n);
	rep (i, 1, n) rd(a.sq[i]);
	a.init();
	
	queue<Node> q;
	q.push(a);
	ans = a.d;
	while (!q.empty()) {
		Node x(q.front()); q.pop();
		if (st.find(x.sq) != st.end()) continue;
		st.insert(x.sq);
//		rep (i, 1, n) printf("%d ", x.sq[i]); puts("");
//		printf("%lf %lf\n", x.a, x.d);
//		printf("%d ", ans);
		ans = min(ans, (int)round(x.d));
//		printf("%d\n", ans);
		rep (i, 2, n - 1) {
			if (x.sq[i] != x.sq[i - 1] + x.sq[i + 1] - x.sq[i]) {
				Node nx; nx.calc(i, x);
				if (st.find(nx.sq) != st.end()) continue;
				q.push(nx);
			}
		}
	}
	
	printf("%d\n", ans);
	return 0;
}

