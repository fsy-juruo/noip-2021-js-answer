#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a, 0, sizeof(a))
#define fill1(a) memset(a, -1, sizeof(a))
#define fillbig(a) memset(a, 63, sizeof(a))
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define y1 y1145141919810
template<typename T1, typename T2> void chkmin(T1 &x, T2 y) {
	if (x > y) x = y;
}
template<typename T1, typename T2> void chkmax(T1 &x, T2 y) {
	if (x < y) x = y;
}
typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
template<typename T> void read(T &x) {
	x = 0; char c = getchar(); bool neg = 0;
	while (!isdigit(c)) neg |= (c == '-'), c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (neg) x = -x;
}
template<typename T> void recursive_print(T x) {
	if (!x) return; recursive_print(x / 10);
	putchar('0' + x % 10);
}
template<typename T> void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x == 0) putchar('0');
	recursive_print(x);
}
template<typename T> void print(T x, char c) {
	print(x); putchar(c);
}
const int MAXN = 2e5;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int n, m, qu;
string R[MAXN + 5], C[MAXN + 5];
int gettyp(int x1, int y1, int x2, int y2) {
	if (x1 == x2) return R[x1][min(y1, y2)] - '0';
	else return C[min(x1, x2)][y1] - '0';
}
namespace sub1 {
	vector<pii> cc[MAXN + 5];
	vector<int> vis[MAXN + 5];
	void solve() {
		for (int i = 1; i <= n; i++) cc[i].resize(m + 1);
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
			cc[i][j] = mp(0, 0);
		for (int i = 1; i <= n; i++) vis[i].resize(m + 1);
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) vis[i][j] = 0;
		while (qu--) {
			int col, lv, x, y, res = 0; scanf("%d%d%d%d", &col, &lv, &x, &y);
			for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) vis[i][j] = 0;
			vis[x][y] = 1; queue<pii> q; q.push(mp(x, y));
			while (!q.empty()) {
				pii p = q.front(); q.pop(); int x = p.fi, y = p.se;
				for (int d = 0; d < 4; d++) {
					int nx = x + dx[d], ny = y + dy[d];
					if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
					if (gettyp(x, y, nx, ny) != 3) continue;
					if (cc[nx][ny].se) continue;
					if (!vis[nx][ny]) {
						vis[nx][ny] = 1;
						q.push(mp(nx, ny));
					}
				}
			}
			for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
				if (cc[i][j].se && cc[i][j].se <= lv && cc[i][j].fi != col) {
					for (int d = 0; d < 4; d++) {
						int nx = i + dx[d], ny = j + dy[d];
						if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
						if (gettyp(i, j, nx, ny) != 3) continue;
						if (cc[nx][ny].se) continue;
						if (vis[nx][ny]) vis[i][j] = 1;
					}
				}
			for (int d = 0; d < 4; d++) {
				int nx = x + dx[d], ny = y + dy[d];
				if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
				if (gettyp(x, y, nx, ny) != 1) continue;
				if (cc[nx][ny].se > lv) continue;
				if (cc[nx][ny].se && cc[nx][ny].fi == col) continue;
				vis[nx][ny] = 1;
			}
			for (int i = x - 1; i; i--) {
				if (gettyp(i, y, i + 1, y) != 2) break;
				if (cc[i][y].se > lv) break;
				if (cc[i][y].se && cc[i][y].fi == col) break;
				vis[i][y] = 1;
				if (cc[i][y].se) break;
			}
			for (int i = x + 1; i <= n; i++) {
				if (gettyp(i, y, i - 1, y) != 2) break;
				if (cc[i][y].se > lv) break;
				if (cc[i][y].se && cc[i][y].fi == col) break;
				vis[i][y] = 1;
				if (cc[i][y].se) break;
			}
			for (int i = y - 1; i; i--) {
				if (gettyp(x, i, x, i + 1) != 2) break;
				if (cc[x][i].se > lv) break;
				if (cc[x][i].se && cc[x][i].fi == col) break;
				vis[x][i] = 1;
				if (cc[x][i].se) break;
			}
			for (int i = y + 1; i <= m; i++) {
				if (gettyp(x, i, x, i - 1) != 2) break;
				if (cc[x][i].se > lv) break;
				if (cc[x][i].se && cc[x][i].fi == col) break;
				vis[x][i] = 1;
				if (cc[x][i].se) break;
			}
			for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
				res += vis[i][j];
//			for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
//				printf("%d%c", (int)vis[i][j], " \n"[j == m]);
			printf("%d\n", res - 1);
			cc[x][y] = mp(col, lv);
		}
	}
}
namespace sub2 {
	bool on_condition() {
		for (int i = 1; i <= n; i++) for (int j = 1; j < m; j++) {
			if (R[i][j] >= '2') return 0;
		}
		for (int i = 1; i < n; i++) for (int j = 1; j <= m; j++) {
			if (C[i][j] >= '2') return 0;
		}
		return 1;
	}
	vector<pii> cc[MAXN + 5];
	void solve() {
		for (int i = 1; i <= n; i++) cc[i].resize(m + 1);
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
			cc[i][j] = mp(0, 0);
		while (qu--) {
			int col, lv, x, y, res = 0;
			scanf("%d%d%d%d", &col, &lv, &x, &y);
			for (int d = 0; d < 4; d++) {
				int nx = x + dx[d], ny = y + dy[d];
				if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
				if (gettyp(x, y, nx, ny) != 1) continue;
				if (cc[nx][ny].se > lv) continue;
				if (cc[nx][ny].se && cc[nx][ny].fi == col) continue;
				res++;
			}
			cc[x][y] = mp(col, lv);
			printf("%d\n", res);
		}
	}
}
namespace sub3 {
	bool on_condition() {
		for (int i = 1; i <= n; i++) for (int j = 1; j < m; j++) {
			if (R[i][j] >= '3') return 0;
		}
		for (int i = 1; i < n; i++) for (int j = 1; j <= m; j++) {
			if (C[i][j] >= '3') return 0;
		}
		return 1;
	}
	vector<int> prex[MAXN + 5], nxtx[MAXN + 5], prey[MAXN + 5], nxty[MAXN + 5];
	set<pair<int, pii> > stx[MAXN + 5], sty[MAXN + 5];
	vector<pii> cc[MAXN + 5];
	bool caneat(int c1, int l1, int c2, int l2) {
		if (c1 == c2 || l1 < l2) return 0;
		return 1;
	}
	void solve() {
		for (int i = 1; i <= n; i++) cc[i].resize(m + 1);
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
			cc[i][j] = mp(0, 0);
		for (int i = 1; i <= n; i++) {
			prex[i].resize(m + 1); nxtx[i].resize(m + 1);
			prey[i].resize(m + 1); nxty[i].resize(m + 1);
			for (int j = 1; j <= m; j++) {
				prex[i][j] = nxtx[i][j] = prey[i][j] = nxty[i][j] = 0;
			}
		}
		for (int i = 1; i <= n; i++) stx[i].clear();
		for (int i = 1; i <= m; i++) sty[i].clear();
		for (int i = 1; i <= n; i++) {
			int lst = 1;
			for (int j = 1; j <= m; j++) {
				if (j != 1 && gettyp(i, j, i, j - 1) != 2) lst = j;
				prex[i][j] = lst;
			}
		}
		for (int i = 1; i <= n; i++) {
			int lst = m;
			for (int j = m; j; j--) {
				if (j != m && gettyp(i, j, i, j + 1) != 2) lst = j;
				nxtx[i][j] = lst;
			}
		}
		for (int i = 1; i <= m; i++) {
			int lst = 1;
			for (int j = 1; j <= n; j++) {
				if (j != 1 && gettyp(j, i, j - 1, i) != 2) lst = j;
				prey[j][i] = lst;
			}
		}
		for (int i = 1; i <= m; i++) {
			int lst = n;
			for (int j = n; j; j--) {
				if (j != n && gettyp(j, i, j + 1, i) != 2) lst = j;
				nxty[j][i] = lst;
			}
		}
//		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
//			printf("%d%c", prey[i][j], " \n"[j == m]);
		for (int i = 1; i <= n; i++) {
			stx[i].insert(mp(0, mp(0, 0)));
			stx[i].insert(mp(m + 1, mp(0, 0)));
		}
		for (int i = 1; i <= m; i++) {
			sty[i].insert(mp(0, mp(0, 0)));
			sty[i].insert(mp(n + 1, mp(0, 0)));
		}
		while (qu--) {
			int col, lv, x, y, res = 0;
			scanf("%d%d%d%d", &col, &lv, &x, &y);
			for (int d = 0; d < 4; d++) {
				int nx = x + dx[d], ny = y + dy[d];
				if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
				if (gettyp(x, y, nx, ny) != 1) continue;
				if (cc[nx][ny].se > lv) continue;
				if (cc[nx][ny].se && cc[nx][ny].fi == col) continue;
				res++;
			}
			pair<int, pii> px = *--stx[x].lower_bound(mp(y, mp(0, 0)));
			pair<int, pii> nx = *stx[x].lower_bound(mp(y, mp(0, 0)));
			pair<int, pii> py = *--sty[y].lower_bound(mp(x, mp(0, 0)));
			pair<int, pii> ny = *sty[y].lower_bound(mp(x, mp(0, 0)));
			int lx = max(prex[x][y], px.fi + 1);
			int rx = min(nxtx[x][y], nx.fi - 1);
			int ly = max(prey[x][y], py.fi + 1);
			int ry = min(nxty[x][y], ny.fi - 1);
//			printf("%d %d %d %d %d\n", lx, rx, ly, ry, res);
			res += (rx - lx);
			res += (ry - ly);
			if (px.fi >= prex[x][y] && caneat(col, lv, px.se.fi, px.se.se)) res++;
			if (nx.fi <= nxtx[x][y] && caneat(col, lv, nx.se.fi, nx.se.se)) res++;
			if (py.fi >= prey[x][y] && caneat(col, lv, py.se.fi, py.se.se)) res++;
			if (ny.fi <= nxty[x][y] && caneat(col, lv, ny.se.fi, ny.se.se)) res++;
			cc[x][y] = mp(col, lv);
			stx[x].insert(mp(y, mp(col, lv)));
			sty[y].insert(mp(x, mp(col, lv)));
			printf("%d\n", res);
		}
	}
}
void solve() {
	scanf("%d%d%d", &n, &m, &qu);
	for (int i = 1; i <= n; i++) R[i].clear(), C[i].clear();
	for (int i = 1; i <= n; i++) {
		static char buf[MAXN + 5];
		scanf("%s", buf + 1); int len = strlen(buf + 1);
		R[i].pb(' ');
		for (int j = 1; j <= len; j++) R[i].pb(buf[j]);
	}
	for (int i = 1; i < n; i++) {
		static char buf[MAXN + 5];
		scanf("%s", buf + 1); int len = strlen(buf + 1);
		C[i].pb(' ');
		for (int j = 1; j <= len; j++) C[i].pb(buf[j]);
	}
	if (1ll * n * m <= 10000 && qu <= 2000) sub1 :: solve();
	else if (sub2 :: on_condition()) sub2 :: solve();
	else if (sub3 :: on_condition()) sub3 :: solve();
}
int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}
/*
1
3 3 5
22
01
21
212
222
0 2 1 2
1 3 2 2
0 1 3 1
0 2 3 2
1 3 2 1
*/
