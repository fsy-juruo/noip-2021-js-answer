#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e5 + 5;

struct Chess {
	int x, y;
	bool col;
	int lvl;

	Chess(): x(), y(), col(), lvl() {}	
	Chess(int _x, int _y, bool _col, int _lvl): x(_x), y(_y), col(_col), lvl(_lvl) {}
	
	bool operator < (const Chess &oth) const {
		return lvl != oth.lvl ? lvl < oth.lvl : std::make_pair(x, y) < std::make_pair(oth.x, oth.y);
	}
	
	bool eat(const Chess &oth) const {
		return col != oth.col && lvl >= oth.lvl;
	}
};

int n, m, q;
std::vector <int> typer[mxn], typed[mxn];
Chess qry[mxn];
int ans[mxn];
int su2[mxn], sd2[mxn], sl2[mxn], sr2[mxn];

int get_type(int x0, int y0, int x1, int y1) {
	if (x0 < 0 || y0 < 0 || x0 >= n || y0 >= m) return -1;
	if (x1 < 0 || y1 < 0 || x1 >= n || y1 >= m) return -1;
	if (x0 == x1) return typer[x0][std::min(y0, y1)];
	else return typed[std::min(x0, x1)][y0];
} 

using namespace __gnu_pbds;

struct Solver {
	struct UnionFind {
		int fa[mxn], sz[mxn];
		tree <Chess, null_type, std::less <>, rb_tree_tag, tree_order_statistics_node_update> tr[mxn][2];
		tree <int, null_type, std::less <>, rb_tree_tag, tree_order_statistics_node_update> th[mxn], tv[mxn];

		void init(int N) {
			rep(i, N) {
				fa[i] = i, sz[i] = 1;
				rep(c, 2) tr[i][c].clear();
				th[i].clear(); tv[i].clear();
			}
		}
		
		inline int find(int x) {
			return x == fa[x] ? x : fa[x] = find(fa[x]);
		}
		
		void merge(int x, int y) {
			x = find(x), y = find(y);
			if (x == y) return ;
			if (sz[x] > sz[y]) std::swap(x, y);
			fa[x] = y, sz[y] += sz[x];
			rep(c, 2) {
				auto &t0 = tr[x][c], &t1 = tr[y][c];
				if (t0.size() > t1.size()) std::swap(t0, t1);
				for (auto cs : t0) t1.insert(cs);
				t0.clear();
			}
			for (auto cs : th[x]) th[y].insert(cs);
			th[x].clear();
			for (auto cs : tv[x]) tv[y].insert(cs);
			tv[x].clear();
		}
	} uf;

	Chess now[mxn];
	std::vector <int> adj[mxn];

	void init() {
		rep(i, n * m) adj[i].clear();
	}

	inline int id(int x, int y) {
		return x * m + y;
	}	
	
	inline void add_edge(int ux, int uy, int vx, int vy) {
		adj[id(ux, uy)].push_back(id(vx, vy));
	}
	
	void solve() {
		uf.init(n * m);
		rep(i, n) rep(j, m) uf.th[id(i, j)].insert(i * m + j);
		rep(i, n) rep(j, m) uf.tv[id(i, j)].insert(j * n + i);
		rep(i, n) rep(j, m) now[id(i, j)] = Chess(i, j, 0, -1);
		rep(i, q) now[id(qry[i].x, qry[i].y)] = qry[i];
		rep(i, n) rep(j, m) if (now[id(i, j)].lvl < 0) {
			int u = id(i, j);
			for (int v : adj[u]) {
				if (now[v].lvl >= 0) uf.tr[uf.find(u)][now[v].col].insert(now[v]);
				else uf.merge(u, v);
			}
		}
		for (int i = q - 1; ~i; -- i) {
//			eprintf("(%d, %d) %d %d %d %d\n", qry[i].x, qry[i].y, su2[i], sd2[i], sl2[i], sr2[i]);
			int u = id(qry[i].x, qry[i].y);
			now[u] = Chess(qry[i].x, qry[i].y, 0, -1);
			for (int v : adj[u]) if (now[v].lvl < 0) uf.merge(u, v);
			uf.tr[uf.find(u)][qry[i].col].erase(qry[i]);
			for (int v : adj[u]) if (now[v].lvl >= 0) uf.tr[uf.find(u)][now[v].col].insert(now[v]);
			# define COUNT(T, l, r) ((T).order_of_key((r) + 1) - (T).order_of_key(l))
			ans[i] -= COUNT(uf.th[uf.find(u)], qry[i].x * m + sl2[i], qry[i].x * m + sr2[i]) - 1;
			ans[i] -= COUNT(uf.tv[uf.find(u)], qry[i].y * n + su2[i], qry[i].y * n + sd2[i]) - 1;
			const auto &T = uf.tr[uf.find(u)][qry[i].col ^ 1];
			if (now[id(su2[i], qry[i].y)].lvl >= 0) ans[i] -= T.find(now[id(su2[i], qry[i].y)]) != T.end();
			if (now[id(sd2[i], qry[i].y)].lvl >= 0) ans[i] -= T.find(now[id(sd2[i], qry[i].y)]) != T.end();
			if (now[id(qry[i].x, sl2[i])].lvl >= 0) ans[i] -= T.find(now[id(qry[i].x, sl2[i])]) != T.end();
			if (now[id(qry[i].x, sr2[i])].lvl >= 0) ans[i] -= T.find(now[id(qry[i].x, sr2[i])]) != T.end();
			ans[i] += uf.sz[uf.find(u)] - 1;
			ans[i] += T.order_of_key(Chess(-1, -1, qry[i].col, qry[i].lvl + 1));
			for (int dx = -1; dx <= +1; ++ dx) {
				for (int dy = -1; dy <= +1; ++ dy) {
					if (std::abs(dx) + std::abs(dy) == 1) {
						int nx = qry[i].x + dx, ny = qry[i].y + dy;
						if (get_type(qry[i].x, qry[i].y, nx, ny) == 1) {
							if (now[id(nx, ny)].lvl >= 0) {
								if (qry[i].eat(now[id(nx, ny)]) && T.find(now[id(nx, ny)]) == T.end()) ++ ans[i];
							} else {
								if (uf.find(u) != uf.find(id(nx, ny))) ++ ans[i];
							}
						}
					}
				}
			}
		}
	}
} A;

const int mxsz = 1 << 24;
char ibuf[mxsz], *iend = ibuf + mxsz, *ipos = iend;
char obuf[mxsz], *oend = obuf + mxsz, *opos = obuf;

inline char get_char() {
	if (ipos == iend) iend = (ipos = ibuf) + fread(ibuf, 1, mxsz, stdin);
	return ipos == iend ? EOF : *ipos ++;
}

inline void fast_flush() {
	fwrite(obuf, 1, opos - obuf, stdout);
	opos = obuf;
}

inline void put_char(char c) {
	if (opos == oend) fwrite(opos = obuf, 1, mxsz, stdout);
	*opos ++ = c;
}

inline void read(int &x) {
	x = 0; char c = get_char();
	while (c <= 32) c = get_char();
	while (c > 32) x = x * 10 + c - 48, c = get_char();
}

inline void read_str(char *s) {
	while (isspace(*s = get_char()));
	while (!isspace(*++ s = get_char()));
	*s = 0;
}

inline void writeln(int x) {
	static char stk[25];
	char *top = stk;
	if (!x) *top ++ = 48;
	while (x) *top ++ = x % 10 + 48, x /= 10;
	while (top -- != stk) put_char(*top);
	put_char(10);
}

void Main() {
	read(n); read(m); read(q);
	rep(i, n) typer[i].resize(m - 1);
	rep(i, n - 1) typed[i].resize(m);
	static char temp[mxn];
	rep(i, n) {
		read_str(temp);
		rep(j, m - 1) typer[i][j] = temp[j] - '0';
	}
	rep(i, n - 1) {
		read_str(temp);
		rep(j, m) typed[i][j] = temp[j] - '0';
	}
	A.init();
	rep(x, n) rep(y, m) {
		for (int dx = -1; dx <= +1; ++ dx) {
			for (int dy = -1; dy <= +1; ++ dy) {
				if (std::abs(dx) + std::abs(dy) == 1) {
					int nx = x + dx, ny = y + dy;
					if (get_type(x, y, nx, ny) == 3) A.add_edge(x, y, nx, ny);
				}
			}
		}
	}
	static std::vector <int> up2[mxn], down2[mxn], left2[mxn], right2[mxn];
	rep(i, n) up2[i].resize(m), down2[i].resize(m), left2[i].resize(m), right2[i].resize(m);
	rep(i, n) rep(j, m) if (get_type(i, j, i - 1, j) == 2) up2[i][j] = up2[i - 1][j]; else up2[i][j] = i;
	for (int i = n - 1; ~i; -- i) rep(j, m) if (get_type(i, j, i + 1, j) == 2) down2[i][j] = down2[i + 1][j]; else down2[i][j] = i;
	rep(j, m) rep(i, n) if (get_type(i, j, i, j - 1) == 2) left2[i][j] = left2[i][j - 1]; else left2[i][j] = j;
	for (int j = m - 1; ~j; -- j) rep(i, n) if (get_type(i, j, i, j + 1) == 2) right2[i][j] = right2[i][j + 1]; else right2[i][j] = j;
	static std::vector <Chess> now[mxn];
	rep(i, n) now[i].resize(m);
	rep(i, n) rep(j, m) now[i][j] = Chess(i, j, 0, -1);
	static std::set <int> sth[mxn], stv[mxn];
	rep(i, n) sth[i].clear(), sth[i].insert(-1), sth[i].insert(m);
	rep(j, m) stv[j].clear(), stv[j].insert(-1), stv[j].insert(n);
	rep(i, q) {
		int x, y, col, lvl;
		read(col); read(lvl); read(x); read(y);
		-- x, -- y;
		now[x][y] = qry[i] = Chess(x, y, col, lvl);
		sth[x].insert(y);
		stv[y].insert(x);
		su2[i] = std::max(*-- stv[y].lower_bound(x), up2[x][y]);
		sd2[i] = std::min(*++ stv[y].lower_bound(x), down2[x][y]);
		sl2[i] = std::max(*-- sth[x].lower_bound(y), left2[x][y]);
		sr2[i] = std::min(*++ sth[x].lower_bound(y), right2[x][y]);
		if (su2[i] != x && now[su2[i]][y].lvl >= 0 && !qry[i].eat(now[su2[i]][y])) ++ su2[i];
		if (sd2[i] != x && now[sd2[i]][y].lvl >= 0 && !qry[i].eat(now[sd2[i]][y])) -- sd2[i];
		if (sl2[i] != y && now[x][sl2[i]].lvl >= 0 && !qry[i].eat(now[x][sl2[i]])) ++ sl2[i];
		if (sr2[i] != y && now[x][sr2[i]].lvl >= 0 && !qry[i].eat(now[x][sr2[i]])) -- sr2[i];
		ans[i] = 0;
		ans[i] += x - su2[i];
		ans[i] += sd2[i] - x;
		ans[i] += y - sl2[i];
		ans[i] += sr2[i] - y;
	}
	A.solve();
	rep(i, q) writeln(ans[i]);
}

int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	int T; read(T);
	while (T --) Main();
	fast_flush();
	return 0;
}

