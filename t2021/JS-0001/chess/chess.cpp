#include <bits/stdc++.h>
using namespace std;

namespace io {
	const int size = 1 << 22 | 1;
	char iBuf[size], *iS, *iT, c;
	char getc() {
		if (iS == iT) {
			iS = iBuf;
			iT = iBuf + fread(iBuf, 1, size, stdin); 
		}
		if (iS == iT) return EOF;
		return *iS++;
	}
	int read_one() {
		for (c = getc(); c < '0' || c > '9'; c = getc());
		return c - '0';
	}
	template <class T> void read_int(T &x) {
		int f = 1;
		for (c = getc(); c < '0' || c > '9'; c = getc())
			if (c == '-') f = -1;
		for (x = 0; c >= '0' && c <= '9'; c = getc())
			x = (x << 3) + (x << 1) + (c & 15);
		x *= f;
	}
}

const int maxq = 100005;
const int maxn = 200005;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int T, n, m, q;
int r[maxn], c[maxn], x[maxq], y[maxq], col[maxq], lv[maxq], dat[maxn], ans[maxq], ord[maxn], rk[maxn], pos[maxn];
int f[maxn], sz[maxn], rtx[maxn], rty[maxn], rtlv[maxn][2], gl[maxn], gr[maxn], gu[maxn], gd[maxn];
set<int>sr[maxn], sc[maxn];

bool cmp(int a, int b) {
	return lv[a] < lv[b];
}

namespace Segtree1 {
	const int maxv = maxq * 200;
	int tot1;
	int ls[maxv], rs[maxv], sum[maxv];
	void clear1() {
		for (int i = 1; i <= tot1; i++)
			ls[i] = rs[i] = sum[i] = 0;
		tot1 = 0;
	}
	void update1(int &cur, int l, int r, int k, int val) {
		if (!cur) cur = ++tot1;
		if (l == r) {
			sum[cur] = min(1, sum[cur] + val);
			assert(0 <= sum[cur] && sum[cur] <= 1);
			return;
		}
		int mid = l + r >> 1;
		if (k <= mid) update1(ls[cur], l, mid, k, val);
		else update1(rs[cur], mid + 1, r, k, val);
		sum[cur] = sum[ls[cur]] + sum[rs[cur]]; 
	}
	int merge1(int cur1, int cur2, int l, int r) {
		if (!cur1 || !cur2) return cur1 ^ cur2;
		if (l == r) {
			sum[cur1] = min(1, sum[cur1] + sum[cur2]);
			return cur1;
		}
		int mid = l + r >> 1;
		ls[cur1] = merge1(ls[cur1], ls[cur2], l, mid);
		rs[cur1] = merge1(rs[cur1], rs[cur2], mid + 1, r);
		sum[cur1] = sum[ls[cur1]] + sum[rs[cur1]];
		return cur1;
	}
	int query1(int cur, int l, int r, int vl, int vr) {
		if (!cur) return 0;
		if (l >= vl && r <= vr) return sum[cur];
		int mid = l + r >> 1;
		int sl = mid >= vl ? query1(ls[cur], l, mid, vl, vr) : 0;
		int sr = mid < vr ? query1(rs[cur], mid + 1, r, vl, vr) : 0;
		return sl + sr; 
	}
}

namespace Segtree2 {
	const int maxv = maxq * 40;
	int tot2;
	int lson[maxv], rson[maxv], rt1[maxv];
	void clear2() {
		for (int i = 1; i <= tot2; i++)
			lson[i] = rson[i] = rt1[i] = 0;
		tot2 = 0;
	}
	void update2(int &cur, int l, int r, int k2, int n1, int k1, int val) {
		if (!cur) cur = ++tot2;
		if (l == r) {
			Segtree1::update1(rt1[cur], 0, n1 - 1, k1, val);
			return;
		}
		int mid = l + r >> 1;
		if (k2 <= mid) update2(lson[cur], l, mid, k2, n1, k1, val);
		else update2(rson[cur], mid + 1, r, k2, n1, k1, val);
	}
	int merge2(int cur1, int cur2, int l, int r, int n1) {
		if (!cur1 || !cur2) return cur1 ^ cur2;
		if (l == r) {
			rt1[cur1] = Segtree1::merge1(rt1[cur1], rt1[cur2], 0, n1 - 1);
			return cur1;
		}
		int mid = l + r >> 1;
		lson[cur1] = merge2(lson[cur1], lson[cur2], l, mid, n1);
		rson[cur1] = merge2(rson[cur1], rson[cur2], mid + 1, r, n1);
		return cur1;
	}
	int query2(int cur, int l, int r, int k, int n1, int l1, int r1) {
		if (!cur) return 0;
		if (l == r) 
			return Segtree1::query1(rt1[cur], 0, n1 - 1, l1, r1);
		int mid = l + r >> 1;
		if (k <= mid) return query2(lson[cur], l, mid, k, n1, l1, r1);
		else return query2(rson[cur], mid + 1, r, k, n1, l1, r1);
	}
}

inline int getid(int x, int y) {
	return x * m + y;
}
inline int getopt(int x, int y, int d) {
	if (x + dx[d] < 0 || x + dx[d] >= n || y + dy[d] < 0 || y + dy[d] >= m) return -1;
	if (d == 0) return c[getid(x - 1, y)];
	else if (d == 1) return r[getid(x, y)];
	else if (d == 2) return c[getid(x, y)];
	else return r[getid(x, y - 1)]; 
}

int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
void merge(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return;
	f[u] = v; 
	sz[v] += sz[u];
	rtx[v] = Segtree2::merge2(rtx[u], rtx[v], 0, n - 1, m);
	rty[v] = Segtree2::merge2(rty[u], rty[v], 0, m - 1, n);
	rtlv[v][0] = Segtree1::merge1(rtlv[u][0], rtlv[v][0], 0, q - 1);
	rtlv[v][1] = Segtree1::merge1(rtlv[u][1], rtlv[v][1], 0, q - 1);
}

void work1(int x, int y, int id, int val) {
	int fr = find(getid(x, y));
	Segtree1::update1(rtlv[fr][col[id]], 0, q - 1, rk[id], val);
}
void work2(int x, int y) {
	int fr = find(getid(x, y));
	Segtree2::update2(rtx[fr], 0, n - 1, x, m, y, 1);
	Segtree2::update2(rty[fr], 0, m - 1, y, n, x, 1);
}
int calcx(int fr, int x, int yl, int yr) {
	if (yl > yr) return 0;
	else return yr - yl + 1 - Segtree2::query2(rtx[fr], 0, n - 1, x, m, yl, yr);
}
int calcy(int fr, int y, int xl, int xr) {
	if (xl > xr) return 0;
	else return xr - xl + 1 - Segtree2::query2(rty[fr], 0, m - 1, y, n, xl, xr);
}
int calcid(int fr, int i, int j) {
	if (col[i] != col[j] && lv[i] >= lv[j]) return 1 - Segtree1::query1(rtlv[fr][col[j]], 0, q - 1, rk[j], rk[j]);
	else return 0; 
}

int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	io::read_int(T);
	while (T--) {
		io::read_int(n); io::read_int(m); io::read_int(q);
		Segtree1::clear1();
		Segtree2::clear2();
		for (int i = 0; i < n; i++) sr[i].clear();
		for (int j = 0; j < m; j++) sc[j].clear();
		for (int i = 0; i < n * m; i++) {
			f[i] = i;
			sz[i] = 1;
			dat[i] = -1;
			rtx[i] = rty[i] = rtlv[i][0] = rtlv[i][1] = 0;
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m - 1; j++) r[getid(i, j)] = io::read_one();
		for (int i = 0; i < n - 1; i++)
			for (int j = 0; j < m; j++) c[getid(i, j)] = io::read_one();
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
			int u = getid(i, j);
			if (getopt(i, j, 0) == 2) gu[u] = gu[getid(i - 1, j)];
			else gu[u] = i;
			if (getopt(i, j, 3) == 2) gl[u] = gl[getid(i, j - 1)];
			else gl[u] = j;
		}
		for (int i = n - 1; i >= 0; i--) for (int j = m - 1; j >= 0; j--) {
			int u = getid(i, j);
			if (getopt(i, j, 2) == 2) gd[u] = gd[getid(i + 1, j)];
			else gd[u] = i;
			if (getopt(i, j, 1) == 2) gr[u] = gr[getid(i, j + 1)];
			else gr[u] = j;
		}
		for (int i = 0; i < q; i++) {
			ord[i] = i;
			io::read_int(col[i]);
			io::read_int(lv[i]); lv[i]--;
			io::read_int(x[i]); x[i]--;
			io::read_int(y[i]); y[i]--;
			dat[getid(x[i], y[i])] = i;
			sr[x[i]].insert(y[i]);
			sc[y[i]].insert(x[i]);
		}
		sort(ord, ord + q, cmp);
		for (int i = q - 1; i >= 0; i--){
			rk[ord[i]] = i;
			if (i == q - 1 || lv[ord[i]] < lv[ord[i + 1]]) pos[ord[i]] = i;
			else pos[ord[i]] = pos[ord[i + 1]];
		}
		for (int i = 0; i < q; i++) {
			work1(x[i], y[i], i, 1);
			for (int d = 0; d < 4; d++) if (getopt(x[i], y[i], d) == 3) {
				int nx = x[i] + dx[d], ny = y[i] + dy[d];
				if (dat[getid(nx, ny)] < 0) work1(nx, ny, i, 1);
			}
		}
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (dat[getid(i, j)] < 0){
			work2(i, j);
			for (int d = 0; d < 4; d++) if (getopt(i, j, d) == 3) {
				int nx = i + dx[d], ny = j + dy[d];
				if (dat[getid(nx, ny)] < 0) merge(getid(i, j), getid(nx, ny));
			}
		}
		for (int i = q - 1; i >= 0; i--) {
			work2(x[i], y[i]);
			int u = getid(x[i], y[i]);
			dat[u] = -1;
			for (int d = 0; d < 4; d++) if (getopt(x[i], y[i], d) == 3) {
				int nx = x[i] + dx[d], ny = y[i] + dy[d];
				if (dat[getid(nx, ny)] < 0)
					merge(u, getid(nx, ny));
				else
					work1(x[i], y[i], dat[getid(nx, ny)], 1);
			}
			work1(x[i], y[i], i, -1);
			sr[x[i]].erase(y[i]);
			sc[y[i]].erase(x[i]);
			int fr = find(u);
			ans[i] = sz[fr] - 1 + Segtree1::query1(rtlv[fr][col[i] ^ 1], 0, q - 1, 0, pos[i]);
			for (int d = 0; d < 4; d++) if (getopt(x[i], y[i], d) == 1) {
				int nx = x[i] + dx[d], ny = y[i] + dy[d];
				if (dat[getid(nx, ny)] < 0) ans[i] += calcx(fr, nx, ny, ny);
				else ans[i] += calcid(fr, i, dat[getid(nx, ny)]);
			}
			set<int>::iterator itx = sr[x[i]].lower_bound(y[i]);
			int vr = itx == sr[x[i]].end() ? m : *itx;
			if (getopt(x[i], y[i], 1) == 2)
				ans[i] += calcx(fr, x[i], y[i] + 1, min(gr[u], vr - 1)) + (gr[u] < vr ? 0 : calcid(fr, i, dat[getid(x[i], vr)]));
			int vl = itx == sr[x[i]].begin() ? -1 : *(--itx);
			if (getopt(x[i], y[i], 3) == 2)
				ans[i] += calcx(fr, x[i], max(gl[u], vl + 1), y[i] - 1) + (gl[u] > vl ? 0 : calcid(fr, i, dat[getid(x[i], vl)]));
			set<int>::iterator ity = sc[y[i]].lower_bound(x[i]);
			int vd = ity == sc[y[i]].end() ? n : *ity;
			if (getopt(x[i], y[i], 2) == 2)
				ans[i] += calcy(fr, y[i], x[i] + 1, min(gd[u], vd - 1)) + (gd[u] < vd ? 0 : calcid(fr, i, dat[getid(vd, y[i])]));
			int vu = ity == sc[y[i]].begin() ? -1 : *(--ity);
			if (getopt(x[i], y[i], 0) == 2)
				ans[i] += calcy(fr, y[i], max(gu[u], vu + 1), x[i] - 1) + (gu[u] > vu ? 0 : calcid(fr, i, dat[getid(vu, y[i])])); 
		}
		for (int i = 0; i < q; i++) printf("%d\n", ans[i]);	
	}
	return 0;
}
