#include <bits/stdc++.h>
#define ID(x, y) ((x) * m + (y))
using namespace std;

void read(int &x) {
	char c = getchar(); while (c < '0' || c > '9') c = getchar();
	x = c - '0', c = getchar(); while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
}

void read(char *s) {
	char c = getchar(); while (c < '0' || c > '9') c = getchar();
	*s = c, s++, c = getchar(); while (c >= '0' && c <= '9') *s = c, s++, c = getchar();
	*s = '\0';
}

char st[100];

void print(int x) {
	int tp = 0;
	if (!x) st[tp++] = '0';
	while (x) st[tp++] = x % 10 + '0', x /= 10;
	while (tp--) putchar(st[tp]);
}

int n, m, q;
char ri[200010], dw[200010];
char buf[200010];
int qc[100010], qx[100010], qy[100010], ql[100010];
int che[200010];
int ans[200010];
int fa[200010];
int L[200010], R[200010];
int sz[200010];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return ;
	L[x] = min(L[x], L[y]), R[x] = min(R[x], R[y]);
	sz[x] += sz[y], fa[y] = x;
}

namespace Solver1 {
	bool CanDo() {return n * m <= 10000 && q <= 2000;}
	int vis[10010][5][5], reach[10010];
	int dfs(int x, int y, int col, int lev, char path = '-', int dir = -1) {
		int id = ID(x, y), ans = reach[ID(x, y)] == 0;
		vis[id][path == '-' ? 0 : path - '0'][dir + 1] = 1, reach[ID(x, y)] = 1;
		if (che[id] != -1) {
			if ((che[id] & 1) == col || lev < (che[id] >> 1)) ans = max(0, ans - 1);
			return ans;
		}
		auto Calc = [&](int xx, int yy, char edg, int d) -> void {
			int nid = ID(xx, yy);
			if (edg == '0') return ;
			if (path != '-' && path != edg) return ;
			if (path == '1') return ;
			if (path == '2' && dir != d) return ;
			if (vis[nid][edg - '0'][d + 1]) return ;
			ans += dfs(xx, yy, col, lev, edg, d);
		};
		if (x) Calc(x - 1, y, dw[ID(x - 1, y)], 0);
		if (y) Calc(x, y - 1, ri[ID(x, y - 1)], 1);
		if (x + 1 < n) Calc(x + 1, y, dw[ID(x, y)], 2);
		if (y + 1 < m) Calc(x, y + 1, ri[ID(x, y)], 3);
		return ans;
	}
	void Solve() {
		memset(che, -1, sizeof(che));
		for (int i = 0; i < q; i++) {
			int col = qc[i], lev = ql[i], x = qx[i], y = qy[i];
			for (int j = 0; j < n * m; j++) {
				memset(vis[j], 0, sizeof(vis[j]));
				reach[j] = 0;
			}
			print(dfs(x, y, col, lev) - 1), putchar('\n');
			che[ID(x, y)] = lev << 1 | col;
		}
	}
}

namespace Solver2 {
	bool CanDo() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m - 1; j++) {
				if (ri[ID(i, j)] == '2' || ri[ID(i, j)] == '3') return 0;
			}
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m; j++) {
				if (dw[ID(i, j)] == '2' || dw[ID(i, j)] == '3') return 0;
			}
		}
		return 1;
	}
	void Solve() {
		memset(che, -1, sizeof(che));
		for (int i = 0; i < q; i++) {
			int col = qc[i], lev = ql[i], x = qx[i], y = qy[i];
			int ans = 0;
			auto Calc = [&](int x, int y, char edg) -> void {
				if (edg != '1') return ;
				if (che[ID(x, y)] != -1) {
					if ((che[ID(x, y)] & 1) == col || (che[ID(x, y)] / 2 > lev)) return ;
					ans++;
					return ;
				}
				ans++;
			};
			if (x) Calc(x - 1, y, dw[ID(x - 1, y)]);
			if (y) Calc(x, y - 1, ri[ID(x, y - 1)]);
			if (x + 1 < n) Calc(x + 1, y, dw[ID(x, y)]);
			if (y + 1 < m) Calc(x, y + 1, ri[ID(x, y)]);
			print(ans), putchar('\n');
			che[ID(x, y)] = lev << 1 | col;
		}
	}
}

namespace Solver3 {
	bool CanDo() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m - 1; j++) {
				if (ri[ID(i, j)] == '3') return 0;
			}
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m; j++) {
				if (dw[ID(i, j)] == '3') return 0;
			}
		}
		return 1;
	}
	void Solve() {
		for (int i = 0; i < q; i++) {
			ans[i] = 0;
		}
		memset(che, -1, sizeof(che));
		for (int i = 0; i < q; i++) {
			int col = qc[i], lev = ql[i], x = qx[i], y = qy[i];
			auto Calc = [&](int x, int y, char edg) -> void {
				if (edg != '1') return ;
				if (che[ID(x, y)] != -1) {
					if ((che[ID(x, y)] & 1) == col || (che[ID(x, y)] / 2 > lev)) return ;
					ans[i]++;
					return ;
				}
				ans[i]++;
			};
			if (x) Calc(x - 1, y, dw[ID(x - 1, y)]);
			if (y) Calc(x, y - 1, ri[ID(x, y - 1)]);
			if (x + 1 < n) Calc(x + 1, y, dw[ID(x, y)]);
			if (y + 1 < m) Calc(x, y + 1, ri[ID(x, y)]);
			che[ID(x, y)] = lev << 1 | col;
		}
		for (int i = 0; i < n * m; i++) {
			fa[i] = i, L[i] = i, R[i] = i, sz[i] = 1;
		}
		auto Calc = [&](int i, int j) -> void {
			if (che[ID(i, j)] != -1) return ;
			if (j && ri[ID(i, j - 1)] == '2' && che[ID(i, j - 1)] == -1) merge(ID(i, j - 1), ID(i, j));
			if (j + 1 < m && ri[ID(i, j)] == '2' && che[ID(i, j + 1)] == -1) merge(ID(i, j), ID(i, j + 1));
		};
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) Calc(i, j);
		for (int i = q - 1; i >= 0; i--) {
			int col = qc[i], lev = ql[i], x = qx[i], y = qy[i];
			che[ID(x, y)] = -1, Calc(x, y);
			int rt = find(ID(x, y));
			ans[i] += sz[rt] - 1;
			auto Try = [&](int val) -> int {
				return (val & 1) != col && (val / 2) <= lev;
			};
			if (L[rt] % m > 0 && ri[L[rt] - 1] == '2') ans[i] += Try(che[L[rt] - 1]);
			if (R[rt] % m + 1 < m && ri[R[rt]] == '2') ans[i] += Try(che[R[rt] + 1]);
		}
		for (int i = 0; i < q; i++) {
			int col = qc[i], lev = ql[i], x = qx[i], y = qy[i];
			che[ID(x, y)] = lev << 1 | col;
		}
		for (int i = 0; i < n * m; i++) {
			fa[i] = i, L[i] = i, R[i] = i, sz[i] = 1;
		}
		auto Calc2 = [&](int i, int j) -> void {
			if (che[ID(i, j)] != -1) return ;
			if (i && dw[ID(i - 1, j)] == '2' && che[ID(i - 1, j)] == -1) merge(ID(i - 1, j), ID(i, j));
			if (i + 1 < n && dw[ID(i, j)] == '2' && che[ID(i + 1, j)] == -1) merge(ID(i, j), ID(i + 1, j));
		};
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) Calc2(i, j);
		for (int i = q - 1; i >= 0; i--) {
			int col = qc[i], lev = ql[i], x = qx[i], y = qy[i];
			che[ID(x, y)] = -1, Calc2(x, y);
			int rt = find(ID(x, y));
			ans[i] += sz[rt] - 1;
			auto Try = [&](int val) -> int {
				return (val & 1) != col && (val / 2) <= lev;
			};
			if (L[rt] / m > 0 && dw[L[rt] - m] == '2') ans[i] += Try(che[L[rt] - m]);
			if (R[rt] / m + 1 < n && dw[R[rt]] == '2') ans[i] += Try(che[R[rt] + m]);
		}
		for (int i = 0; i < q; i++) {
			print(ans[i]), putchar('\n');
		}
	}
}

void Main() {
	read(n), read(m), read(q);
	for (int i = 0; i < n; i++) {
		read(buf);
		for (int j = 0; j < m - 1; j++) {
			ri[ID(i, j)] = buf[j];
		}
	}
	for (int i = 0; i < n - 1; i++) {
		read(buf);
		for (int j = 0; j < m; j++) {
			dw[ID(i, j)] = buf[j];
		}
	}
	for (int i = 0; i < q; i++) {
		read(qc[i]), read(ql[i]), read(qx[i]), read(qy[i]);
		qx[i]--, qy[i]--;
	}
	if (Solver1 :: CanDo()) Solver1 :: Solve();
	else if (Solver2 :: CanDo()) Solver2 :: Solve();
	else if (Solver3 :: CanDo()) Solver3 :: Solve();
}

int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	int T; scanf("%d", &T);
	while (T--) Main();
	return 0;
}

