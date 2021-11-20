//Programmed by Fw
//qwq
#define tsk "chess"
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
#define mem(x) memset(x, 0, sizeof(x));
constexpr int MAXN = 1e5 + 10, MAXNM = 2e5 + 10;

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

bool vis[MAXNM];
bool col[MAXNM];
int n, m, q, ans, lv[MAXNM],
	head[MAXNM], ver[MAXNM << 3], nxt[MAXNM << 3], edge[MAXNM << 3], tot;

inline void add(int x, int y, int z) {
	edge[++ tot] = z; ver[tot] = y; nxt[tot] = x; head[x] = tot;
}

inline void read1(int p) {
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar());
	for (int q = 1; isdigit(ch); ch = getchar(), ++ q) {
		add(m * (p - 1) + q, m * (p - 1) + q + 1, ch ^ '0');
		add(m * (p - 1) + q + 1, m * (p - 1) + q, ch ^ '0');
	}
}
inline void read2(int p) {
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar());
	for (int q = 1; isdigit(ch); ch = getchar(), ++ q) {
		add(m * (p - 1) + q, m * p + q, ch ^ '0');
		add(m * p + q, m * (p - 1) + q, ch ^ '0');
	}
}
void dfs(int x, int y, int cl) {
	if (x < 1 || x > m || y < 1 || y > n) return;
	if (vis[m * (x - 1) + y]) return;
	vis[m * (x - 1) + y] = 1; ++ ans;
	int u = m * (x - 1) + y;
	fore(i, u) {
		int v = ver[i], w = edge[i];
		if (w == cl) {
			
		}
	}
}

signed main() {
#ifndef LOCAL
	freopen(tsk".in",  "r", stdin);
	freopen(tsk".out", "w", stdout);
#endif
	int T; rd(T);
	while (T --) {
		rep (i, 1, n) read1(i);
		rep (i, 1, n - 1) read2(i);
		while (q --) {
			int cl, lvl, x, y;
			rd(cl, lvl, x, y);
			col[m * (x - 1) + y] = cl;
			lv[m * (x - 1) + y] = lvl;
			rep (i, 1, 3) {
				mem(vis);
				dfs(x, y, i);
			}
			printf("%d\n", ans);
		}
		mem(col); mem(lv); mem(head); mem(nxt); mem(edge); mem(ver);
		tot = 0;
	}
	return 0;
}

