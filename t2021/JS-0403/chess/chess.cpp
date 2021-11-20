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
const int MAXN = 2e5 + 10;
const int MAXM = 8e5 + 10;
const int MAXK = 5005;
const int INFL = 0x3f3f3f3f3f3f3f3f;
using pii = pair<int, int>;
struct edge {
	int u, v, opt;
};
struct unionset {
	int fa[MAXN];
	void init(int n) {
		for (int i = 1; i <= n; ++i)
			fa[i] = i;
	}
	int father(int x) {
		return fa[x] == x ? x : fa[x] = father(fa[x]);
	}
	bool merge(int x, int y) {
		x = father(x), y = father(y);
		if (x == y)
			return false;
		fa[y] = x;
		return true; 
	}
};
int n, m, tot, q, dir[4];
int col[MAXN], lev[MAXN];
int inpc[MAXN], inpl[MAXN], inpp[MAXN];
int head[MAXN], nxt[MAXM], edcnt;
int pre[MAXN][4];
edge e[MAXM];
char buf[MAXN];
queue<pii> que;
bool tag[MAXK][4];
unionset us;
void clear() {
	edcnt = 0;
	fill(head + 1, head + tot + 1, 0);
	fill(col + 1, col + tot + 1, -1);
	fill(lev + 1, lev + tot + 1, -1);
}
void addedge(int u, int v, int t) {
	e[++edcnt] = edge{u, v, t};
	nxt[edcnt] = head[u];
	head[u] = edcnt; 
}
int posi(int x, int y) {
	return (x - 1) * m + y;
}
bool comp(int u, int c, int l) {
	if (col[u] == -1)
		return true;
	if (col[u] == c)
		return false;
	return l >= lev[u];
}
void solve() {
	read(n), read(m), read(q);
	int cntop2 = 0, cntop3 = 0;
	dir[0] = -1, dir[1] = 1;
	dir[2] = -m, dir[3] = m;
	tot = n * m, clear();
	for (int i = 1; i <= n; ++i) {
		scanf("%s", buf + 1);
		for (int j = 1; j < m; ++j) {
			int u = posi(i, j), v = posi(i, j + 1);
			if (buf[j] == '0')
				continue;
			addedge(u, v, buf[j] - '0');
			addedge(v, u, buf[j] - '0');
			if (buf[j] - '0' == 2)
				++cntop2;
			if (buf[j] - '0' == 3)
				++cntop3;
		}
	}
	for (int i = 1; i < n; ++i) {
		scanf("%s", buf + 1);
		for (int j = 1; j <= m; ++j) {
			int u = posi(i, j), v = posi(i + 1, j);
			if (buf[j] == '0')
				continue;
			addedge(u, v, buf[j] - '0');
			addedge(v, u, buf[j] - '0');
			if (buf[j] - '0' == 2)
				++cntop2;
			if (buf[j] - '0' == 3)
				++cntop3;
		}
	}
	for (int i = 1; i <= q; ++i) {
		int x, y;
		read(inpc[i]), read(inpl[i]);
		read(x), read(y);
		inpp[i] = posi(x, y);
	}
	if (n * m <= 5000 && q <= 2000) {
		for (int t = 1; t <= q; ++t) {
			memset(tag, 0, sizeof(tag));
			int p = inpp[t], c = inpc[t], l = inpl[t];
			tag[p][1] = tag[p][2] = tag[p][3] = true;
			for (int i = head[p]; i; i = nxt[i]) {
				if (e[i].opt != 1)
					continue;
				for (int k = 0; k < 4; ++k)
					if (e[i].v == p + dir[k]) {
						if (comp(e[i].v, c, l))
							tag[e[i].v][1] = true;
					}
			}
			while (!que.empty())
				que.pop();
			for (int i = head[p]; i; i = nxt[i]) {
				if (e[i].opt != 2)
					continue;
				for (int k = 0; k < 4; ++k)
					if (e[i].v == p + dir[k]) {
						if (comp(e[i].v, c, l))
							tag[e[i].v][2] = true;
						if (col[e[i].v] == -1)
							que.push({e[i].v, k});
					}
			}
			while (!que.empty()) {
				pii t = que.front();
				que.pop();
				int u = t.first, d = t.second;
				for (int i = head[u]; i; i = nxt[i]) {
					if (e[i].opt != 2)
						continue;
					if (tag[e[i].v][2])
						continue;
					if (e[i].v == u + dir[d]) {
						if (comp(e[i].v, c, l))
							tag[e[i].v][2] = true;
						if (col[e[i].v] == -1)
							que.push({e[i].v, d});
					}
				}
			}
			que.push({p, 0});
			while (!que.empty()) {
				pii t = que.front();
				que.pop();
				int u = t.first;
				for (int i = head[u]; i; i = nxt[i]) {
					if (e[i].opt != 3)
						continue;
					if (tag[e[i].v][3])
						continue;
					if (comp(e[i].v, c, l))
						tag[e[i].v][3] = true;
					if (col[e[i].v] == -1)
						que.push({e[i].v, 0});
				}
			}
			int ans = 0;
			for (int i = 1; i <= tot; ++i)
				if (tag[i][1] || tag[i][2] || tag[i][3])
					++ans;
			col[p] = c, lev[p] = l;
			write(ans - 1), putchar('\n');
		}
	} else if (!cntop2 && !cntop3) {
		for (int t = 1; t <= q; ++t) {
			int p = inpp[t], c = inpc[t], l = inpl[t], ans = 0;
			for (int i = head[p]; i; i = nxt[i]) {
				if (e[i].opt == 1 && comp(e[i].v, c, l))
					++ans;
			}
			col[p] = c, lev[p] = l;
			write(ans), putchar('\n');
		}
	}
}
signed main() {
	resetIO(chess);
	int t;
	read(t);
	while (t--)
		solve();
	return 0;
}

