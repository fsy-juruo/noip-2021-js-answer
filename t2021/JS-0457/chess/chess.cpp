#include <cstdio>
#include <vector>
using namespace std;

const int DIR[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

struct node {
	int lv, col;
	node(int _lv = 0, int _col = -1) {
		lv = _lv; col = _col;
	}
};

int t, n, m, q, lv, col, ans;
vector<vector<int> > g1, g2, vis;
vector<vector<node> > chs;

int pathopt(int x, int y, int i) {
	switch (i) {
		case 0:
			if (x < n) return g2[x][y];
			break;
		case 1:
			if (x > 1) return g2[x - 1][y];
			break;
		case 2:
			if (y < m) return g1[x][y];
			break;
		case 3:
			if (y > 1) return g1[x][y - 1];
			break;
	}
	return 0;
}

void go(int x, int y, int opt, int dir);
void dfs(int x, int y, int opt, int dir) {
//	printf("dfs (%d,%d) %d %d\n", x, y, opt, dir);
	if (opt == 1) return;
	for (int i = 0; i < 4; i++) {
		int nx = x + DIR[i][0], ny = y + DIR[i][1];
		int path = pathopt(x, y, i);
		if (!path) continue;
		if (opt == -1) {
			if (path == 3) vis[nx][ny] += 2;
			else vis[nx][ny]++;
			go(nx, ny, path, i);
		}
		else if (opt == 2) {
			if (!(vis[nx][ny] % 2) && dir == i && opt == path) {
				vis[nx][ny]++; //printf("vis:(%d,%d) %d\n", nx, ny, vis[nx][ny]);
				go(nx, ny, path, i);
			}
		}
		else if (opt == 3) {
			if (vis[nx][ny] < 2 && opt == path) {
				vis[nx][ny] += 2; //printf("vis:(%d,%d) %d\n", nx, ny, vis[nx][ny]);
				go(nx, ny, path, i);
			}
		}
	}
}

void go(int x, int y, int opt, int dir) {
	//printf("go (%d,%d) %d %d\n", x, y, opt, dir);
	if (chs[x][y].col == -1) {
		//printf("yes\n");
		dfs(x, y, opt, dir);
	}
	if (chs[x][y].col == col || chs[x][y].lv > lv) {
		//printf("morn\n");
		if (opt != 3) vis[x][y]--;
		else vis[x][y] -= 2;
	}
}

int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &m, &q);
		vector<vector<int> >(n + 2).swap(g1);
		vector<vector<int> >(n + 2).swap(g2);
		vector<vector<int> >(n + 2).swap(vis);
		vector<vector<node> >(n + 2).swap(chs);
		for (int i = 1; i <= n; i++) {
			chs[i].resize(m + 2);
			vis[i].resize(m + 2);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				chs[i][j] = node(0, -1);
			}
		}
		for (int i = 1; i <= n; i++) {
			getchar(); g1[i].push_back(0);
			for (int j = 1; j < m; j++) {
				char ch; ch = getchar();
				g1[i].push_back(ch - '0');
			}
		}
		for (int i = 1; i < n; i++) {
			getchar(); g2[i].push_back(0);
			for (int j = 1; j <= n; j++) {
				char ch; ch = getchar();
				g2[i].push_back((int)ch - '0');
			}
		}
		for (int i = 1; i <= q; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					vis[j][k] = 0;
				}
			}
			ans = 0;
			int x, y; scanf("%d%d%d%d", &col, &lv, &x, &y);
			chs[x][y].lv = lv; chs[x][y].col = col;
			dfs(x, y, -1, -1);
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= m; k++) {
					if (vis[j][k] > 0) {
						ans++;
						//printf("%d: %d,%d\n", i, j, k);
					}
				}
			}
			printf("%d\n", ans);
		}
	}
	
	fclose(stdin); fclose(stdout);
	return 0;
}
