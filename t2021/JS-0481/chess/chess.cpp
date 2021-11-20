#include <bits/stdc++.h>
// xgj nb!
using namespace std;
typedef pair<int, int> PII;

const int N = 5010, DN = 4, M = 100010;

struct chess {
	int col, lev;
} ch[M];

inline int in() {
	int x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x;
}

inline string instr() {
	string s = ""; char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) s += c, c = getchar();
	return s;
}

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int g[N][N], n, m, q;
int path[N][N][DN];
//bool vis[N][N];

inline bool corvalid(int x, int y) {
	return x > 0 && y > 0 && x <= n && y <= m; 
}

//inline bool valid(int x, int y) {
//	return corvalid(x, y) && !vis[x][y];
//}

//int dfs2row(int x, int y, int col, int lev, int del) {
//	int res = 1;
//	while (valid(x, y + del) && path[x][y][delta == 1 ? 3 : 1] == 2 && !g[x][y]) {
//		x += del, res++;
//	}
//	if (g[x][y] )
//	return res;
//}
//int dfs2col(int x, int y, int col, int lev, int delta) {
//	int res = 1;
//	while (valid(x, y) && path[x][y][delta == 1 ? 0 : 2] == 2 && (!g[x][y + del] || (g[x][y + del]
//		&& ch[g[x][y + del]].col != col && ch[g[x][y + del]].lev <= lev))) {
//		x += del, res++;
//		if (g[x][y]) break;
//	}
//	return res;
//}
//int dfs(int x, int y, int col, int lev) {
//	int res = 0;
//	for (int d = 0; d < 4; d++) {
//		int xx = x + dx[d], yy = y + dy[d];
//		if (!corvalid(xx, yy)) continue; 
//		if (path[x][y][d] == 1) {
//			if (!g[xx][yy])
//		} else if (path[x][y][d] == 2) {
//			if (d == 0) res += dfs2row(xx, yy, col, lev, 1);
//			else if (d == 1) res += dfs2col(xx, yy, col, lev, 1);
//			else if (d == 2) res += dfs2row(xx, yy, col, lev, -1);
//			else res += dfs2col(xx, yy, col, lev, -1);
//			 
//		}
//		memset(vis, 0, sizeof(vis));
//	}
//}

int main() {
	 freopen("chess.in", "r", stdin);
	 freopen("chess.out", "w", stdout);
	
	int tt = in();
	while (tt--) {
		n = in(), m = in(), q = in();
		memset(g, 0, sizeof(g));
		for (int i = 1; i <= n; i++) {
			string s = instr();
			for (int j = 1; j < m; j++) 
				path[i][j][0] = path[i][j + 1][2] = s[j - 1] ^ 48;
		}
		for (int i = 1; i < n; i++) {
			string s = instr();
			for (int j = 1; j <= m; j++)
				path[i][j][1] = path[i + 1][j][3] = s[j - 1] ^ 48;
		}
		for (int i = 1; i <= q; i++) {
//			memset(vis, 0, sizeof(vis));
			ch[i].col = in(), ch[i].lev = in(); int x = in(), y = in();
			int res = 0;
			for (int d = 0; d < 4; d++) {
				int xx = x + dx[d], yy = y + dy[d];
				if (path[x][y][d] == 0) continue;
				if (corvalid(xx, yy) && (!g[xx][yy] || (ch[g[xx][yy]].col != ch[i].col && ch[g[xx][yy]].lev <= ch[i].lev))) 
					res++;
			}
			g[x][y] = i;
			printf("%d\n", res);
		}
	}

	return 0;
}


