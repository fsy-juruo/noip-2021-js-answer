#include <bits/stdc++.h>

using namespace std;
const int MAXN = 5e3 + 10, MAXQ = 2e3 + 10;
int n, mm, q, col[MAXQ], lv[MAXQ], qx[MAXQ], qy[MAXQ], m[MAXN][MAXN], c[MAXN][MAXN][4], dx[4] = {0, 1, 0, 1}, dy[4] = {1, 0, 1, 0}, ans;
string a[MAXN], b[MAXN];
bool v[MAXN][MAXN], v2[MAXN][MAXN];

void dfs1(int x, int y, int co, int l) {
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i], yy = y + dy[i];
		if (xx < 1 || xx > n || yy < 1 || yy > mm || c[xx][yy][i] != 1) continue;
		if (v[xx][yy]) ans--;
		if (m[xx][yy]) {
			if (col[m[xx][yy]] != co && lv[m[xx][yy]] <= l) ans++;
			continue;
		}
		ans++;
	}
}

void dfs2(int x, int y, int co, int l, int d) {
	ans++;
	int xx = x + dx[d], yy = y + dy[d];
	if (xx < 1 || xx > n || yy < 1 || yy > mm || c[xx][yy][d] != 2) return;
	if (v[xx][yy]) ans--;
	if (m[xx][yy]) {
		if (col[m[xx][yy]] != co && lv[m[xx][yy]] <= l) ans++;
		return;
	}
	v[xx][yy] = 1;
	dfs2(xx, yy, co, l, d);
}

void dfs3(int x, int y, int co, int l) {
	ans++;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i], yy = y + dy[i];
		if (xx < 1 || xx > n || yy < 1 || yy > mm || c[xx][yy][i] != 3 || v2[xx][yy]) continue;
		if (v[xx][yy]) ans--;
		if (m[xx][yy]) {
			if (col[m[xx][yy]] != co && lv[m[xx][yy]] <= l) ans++;
			continue;
		}
		v[xx][yy] = 1;
		v2[xx][yy] = 1;
		dfs3(xx, yy, co, l);
	}
}

int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		memset(m, 0, sizeof m);
		cin >> n >> mm >> q;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			a[i] = '0' + a[i] + '0';
		}
		for (int i = 1; i < n; i++) {
			cin >> b[i];
			b[i] = '0' + b[i];
		}
		for (int i = 0; i <= mm; i++)
			b[n] += '0';
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= mm; j++) {
				c[i][j][0] = a[i][j] - '0';
				c[i][j][1] = b[i][j] - '0';
				c[i][j][2] = a[i][j - 1] - '0';
				c[i][j][3] = b[i - 1][j] - '0';
			}
		}
		for (int i = 1; i <= q; i++) {
			cin >> col[i] >> lv[i] >> qx[i] >> qy[i];
			m[qx[i]][qy[i]] = i;
			ans = 0;
			dfs1(qx[i], qy[i], col[i], lv[i]);
			for (int j = 0; j < 4; j++)
				dfs2(qx[i], qy[i], col[i], lv[i], j);
			dfs3(qx[i], qy[i], col[i], lv[i]);
			cout << ans - 5 << endl;
		}
	}
	return 0;
}

