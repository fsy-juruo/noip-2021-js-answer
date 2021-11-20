#include <bits/stdc++.h>

#define hhash(x, y) (((x) - 1) * m + (y))

using namespace std;

using pii = pair<int, int>;

const int maxnm = 2e5 + 10;
const int dx[4]{0, 1, 0, -1}, dy[4]{1, 0, -1, 0};

int T, n, m, q;
int col[maxnm], lv[maxnm];
bool vis[maxnm], vvis[maxnm];
pii qu[maxnm];
string r[maxnm], c[maxnm];

int ask(int x, int y, int xx, int yy) {
	if (x == xx) {
		if (y > yy) swap(y, yy);
		return r[x][y - 1] - '0';
	} else {
		if (x > xx) swap(x, xx);
		return c[x][y - 1] - '0'; 
	}
}
bool eat(int x, int y, int xx, int yy) {
	int t1 = hhash(x, y), t2 = hhash(xx, yy);
	if (!~col[t2]) return true;
	return col[t1] != col[t2] && lv[t1] >= lv[t2];
}

void bfs(int x, int y) {
	vvis[hhash(x, y)] = true;
	int l = 1, r = 0;
	qu[++r] = pii{x, y};
	while (l <= r) {
		pii u = qu[l++];
		for (int i = 0; i < 4; i++) {
			int nx = u.first + dx[i], ny = u.second + dy[i];
			int tmp = hhash(nx, ny);
			if (nx < 1 || nx > n || ny < 1 || ny > m || ask(u.first, u.second, nx, ny) != 3 || vvis[tmp]) continue;
			if (!~col[tmp]) {
				vvis[tmp] = true;
				qu[++r] = pii{nx, ny};
			} else {
				if (eat(x, y, nx, ny)) vis[tmp] = true;
			}
		}
	}
}


int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr); 
	cin >> T;
	while (T--) {
		cin >> n >> m >> q;
		for (int i = 1; i <= n; i++) cin >> r[i];
		for (int i = 1; i < n; i++) cin >> c[i];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) col[hhash(i, j)] = -1;
		}
		if (n * m * q <= 4e8) {
			while (q--) {
				int _col, _lv, x, y;
				cin >> _col >> _lv >> x >> y;
				col[hhash(x, y)] = _col;
				lv[hhash(x, y)] = _lv;
				for (int i = 1; i <= n; i++) {
					for (int j = 1; j <= m; j++) {
						int tmp = hhash(i, j);
						vis[tmp] = vvis[tmp] = false;
					}
				}
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i], ny = y + dy[i];
					if (nx < 1 || nx > n || ny < 1 || ny > m || ask(x, y, nx, ny) != 1) continue;
					if (eat(x, y, nx, ny)) vis[hhash(nx, ny)] = true; 
				}
				for (int i = x + 1; i <= n; i++) {
					if (ask(i, y, i - 1, y) != 2) break;
					int tmp = hhash(i, y);
					vis[tmp] = true;
					if (~col[tmp]) {
						vis[tmp] = eat(x, y, i, y);
						break;
					}
				}
				for (int i = x - 1; i >= 1; i--) {
					if (ask(i, y, i + 1, y) != 2) break;
					int tmp = hhash(i, y);
					vis[tmp] = true;
					if (~col[tmp]) {
						vis[tmp] = eat(x, y, i, y);
						break;
					}
				}
				for (int j = y + 1; j <= m; j++) {
					if (ask(x, j, x, j - 1) != 2) break;
					int tmp = hhash(x, j);
					vis[tmp] = true;
					if (~col[tmp]) {
						vis[tmp] = eat(x, y, x, j);
						break;
					}
				}
				for (int j = y - 1; j >= 1; j--) {
					if (ask(x, j, x, j + 1) != 2) break;
					int tmp = hhash(x, j);
					vis[tmp] = true;
					if (~col[tmp]) {
						vis[tmp] = eat(x, y, x, j);
						break;
					}
				} 
				bfs(x, y);
				int ans = 0;
				for (int i = 1; i <= n; i++) {
					for (int j = 1; j <= m; j++) {
						int tmp = hhash(i, j);
						if (vis[tmp] || vvis[tmp]) ans++;
					}
				}
				cout << ans - 1 << "\n";
			}
		} else {
			while (q--) {
				int _col, _lv, x, y;
				cin >> _col >> _lv >> x >> y;
				col[hhash(x, y)] = _col;
				lv[hhash(x, y)] = _lv;
				int ans = 0;
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i], ny = y + dy[i];
					if (nx < 1 || nx > n || ny < 1 || ny > m || ask(x, y, nx, ny) != 1) continue;
					if (eat(x, y, nx, ny)) ans++; 
				}
				cout << ans << "\n";
			}
		} 
	}
	return 0;
}
