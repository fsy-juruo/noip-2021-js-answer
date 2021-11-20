//Programmed by Fw
//qwq
#define tsk "number"
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
constexpr int MAXN = 1e7 + 10, MAXT = 77e4;

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

bitset<MAXN> a;

void dfs(int dep, int pos, int val) {
	if (dep > 7) {
		for (int i = val, j = 1; i * j <= 1e7; ++ j) a[i * j] = 1;
		return;
	}
	if (dep == pos) dfs(dep + 1, pos, val * 10 + 7);
	else rep (i, 0, 9) dfs(dep + 1, pos, val * 10 + i);
}

int ans[MAXT], tot;

signed main() {
#ifndef LOCAL
	freopen(tsk".in",  "r", stdin);
	freopen(tsk".out", "w", stdout);
#endif
	rep (i, 1, 7) dfs(1, i, 0);
	rep (i, 1, MAXN) if (!a[i]) ans[++ tot] = i;
//	cout << (sizeof(a) + sizeof(ans) + sizeof(buf)) * 1.0 / 1024 / 1024 << endl;
	int T; rd(T);
	while (T --) {
		int x; rd(x);
		if (a[x]) puts("-1");
		else printf("%d\n", *upper_bound(ans + 1, ans + tot + 1, x));
	}
	return 0;
}

