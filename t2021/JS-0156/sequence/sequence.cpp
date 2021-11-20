//Programmed by Fw
//qwq
#define tsk "sequence"
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
constexpr int MAXM = 1e2 + 10, mod = 998244353;

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

int n, m, k, v[MAXM], ans, cnt;
bool s[MAXM];

void dfs(int dep, int val) {
	if (dep > n) {
		if (cnt <= k) { ans += val; while (ans >= mod) ans -= mod; }
		return;
	}
	rep (i, 0, m) {
		register int pos = i;
		while (s[pos]) s[pos ++] = 0, -- cnt;
		s[pos] = 1; ++ cnt;
		dfs(dep + 1, 1ll * val * v[i] % mod);
		s[pos] = 0; -- cnt;
		rep (j, i, pos - 1) s[j] = 1;
		cnt += pos - i;
	}
}

signed main() {
#ifndef LOCAL
	freopen(tsk".in",  "r", stdin);
	freopen(tsk".out", "w", stdout);
#endif
	rd(n, m, k);
	rep (i, 0, m) rd(v[i]);
	
	dfs(1, 1);
	
	printf("%d\n", ans);
	return 0;
}

