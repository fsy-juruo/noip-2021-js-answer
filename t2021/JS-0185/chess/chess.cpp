#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 450;
int n, m, q;
char gc() {
	for(; ; ) {
		char c = getchar();
		if (c >= '0' && c <= '3') return c;
	}
}
int opt[2][MAXN][MAXN];
bool col[MAXN][MAXN];
int lvl[MAXN][MAXN];

bool vis[MAXN][MAXN];
int dtot = 0;
void dfs(int x, int y, int c, int l) {
	if (vis[x][y]) return;
	vis[x][y] = 1;
	if (lvl[x][y] != -1) {
		dtot += col[x][y] != c && lvl[x][y] <= l;
		return;
	}
	++dtot;
	const int ndir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	const int edir[4][3] = {{1, -1, 0}, {1, 0, 0}, {0, 0, -1}, {0, 0, 0}};
	for (int dir = 0; dir < 4; ++dir) {
		if (x == 1 && dir == 0) continue;
		if (x == n && dir == 1) continue;
		if (y == 1 && dir == 2) continue;
		if (y == m && dir == 3) continue;
		int tx = x + ndir[dir][0],
			ty = y + ndir[dir][1],
			te = opt[edir[dir][0]][x + edir[dir][1]][y + edir[dir][2]];
		if (te == 3 && !vis[tx][ty]) dfs(tx, ty, c, l);
	}
}

int solve(int x, int y, int c, int l) {
	int ans = 0;
	// up down left right
	const int ndir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	const int edir[4][3] = {{1, -1, 0}, {1, 0, 0}, {0, 0, -1}, {0, 0, 0}};
	memset(vis, 0, sizeof(vis));
	vis[x][y] = true;
	dtot = 0;
	
	for (int dir = 0; dir < 4; ++dir) {
		if (x == 1 && dir == 0) continue;
		if (x == n && dir == 1) continue;
		if (y == 1 && dir == 2) continue;
		if (y == m && dir == 3) continue;
		int tx = x + ndir[dir][0],
			ty = y + ndir[dir][1],
			te = opt[edir[dir][0]][x + edir[dir][1]][y + edir[dir][2]];
		if (te == 3) dfs(tx, ty, c, l);
	}
	
	for (int dir = 0; dir < 4; ++dir) {
		if (x == 1 && dir == 0) continue;
		if (x == n && dir == 1) continue;
		if (y == 1 && dir == 2) continue;
		if (y == m && dir == 3) continue;
		int tx = x + ndir[dir][0],
			ty = y + ndir[dir][1],
			te = opt[edir[dir][0]][x + edir[dir][1]][y + edir[dir][2]];
		// printf("%d %d %d\n", tx, ty, te);
		if (te == 0) continue;
		if (lvl[tx][ty] != -1) {
			if (!vis[tx][ty]) ans += col[tx][ty] != c && lvl[tx][ty] <= l;
		} else {
			if (te == 1) {
				ans += !vis[tx][ty];
			} else if (te == 2) {
				for(; ; ) {
					ans += !vis[tx][ty];
					if (tx == 1 && dir == 0) break;
					if (tx == n && dir == 1) break;
					if (ty == 1 && dir == 2) break;
					if (ty == m && dir == 3) break;
					te = opt[edir[dir][0]][tx + edir[dir][1]][ty + edir[dir][2]];
					tx += ndir[dir][0];
					ty += ndir[dir][1];
					if (te != 2) break;
					if (lvl[tx][ty] != -1) {
						if (vis[tx][ty]) break;
						ans += col[tx][ty] != c && lvl[tx][ty] <= l;
						break;
					}
				}
			}
		}
	}
	//printf(">>%d %d\n", ans, dtot);
	return ans + dtot;
}

int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for (; t--; ) {
		memset(lvl, -1, sizeof(lvl));
		scanf("%d %d %d", &n, &m, &q);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m - 1; ++j)
				opt[0][i][j] = gc() - '0';
		}
		for (int i = 1; i <= n - 1; ++i) {
			for (int j = 1; j <= m; ++j)
				opt[1][i][j] = gc() - '0';
		}
		for (; q--; ) {
			int rc, rl, rx, ry;
			scanf("%d %d %d %d", &rc, &rl, &rx, &ry);
			lvl[rx][ry] = rl;
			col[rx][ry] = rc;
			printf("%d\n", solve(rx, ry, rc, rl));
		}
	}
	return 0;
}

