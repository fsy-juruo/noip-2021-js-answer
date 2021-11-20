#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
const int N = 2e5 + 8;
const int dx[4] = {1, -1, 0, 0}; // down, up, right, left
const int dy[4] = {0, 0, 1, -1}; // down, up, right, left
int T, n, m, q;
int r[N], d[N], col[N], lv[N];
int edge[N][4];
bool qz[N];
char tmp[N];

inline int idx(int i, int j) {
	return (i - 1) * m + j;
}

inline bool check(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

void clear() {
	memset(r, 0, sizeof(r));
	memset(d, 0, sizeof(d));
	memset(col, 0, sizeof(col));
	memset(lv, 0, sizeof(lv));
	memset(edge, 0, sizeof(edge));
	memset(qz, 0, sizeof(qz));
}

struct Node {
	int x, y, op, d;
};

bool ckill(int u, int v) {
	return col[u] != col[v] && lv[u] >= lv[v];
}

bool vis[N];
stack<int> sta;

void bfs(int sx, int sy) {
	int su = idx(sx, sy);
	int ans = 0;
	vis[su] = 1;
	sta.push(su);
	queue<Node> qu;
	for (int i = 0; i < 4; ++i) {
		if (edge[su][i] == 0) continue;
		int nx = sx + dx[i], ny = sy + dy[i];
		if (!check(nx, ny)) continue;
		int v = idx(nx, ny);
		if (qz[v]) {
			if (ckill(su, v)) {
				vis[v] = 1;
				sta.push(v);
				++ans;
			}
		} else {
			vis[v] = 1;
			sta.push(v);
			++ans;
			if (edge[su][i] == 2) qu.push(Node{nx, ny, 2, i});
			else if (edge[su][i] == 3) qu.push(Node{nx, ny, 3, i});
		}
	}
	while (!qu.empty()) {
		int x = qu.front().x, y = qu.front().y;
		int op = qu.front().op, d = qu.front().d;
		int u = idx(x, y);
		qu.pop();
		if (op == 2) {
			if (edge[u][d] == 2) {
				int nx = x + dx[d], ny = y + dy[d];
				if (!check(nx, ny)) continue;
				int v = idx(nx, ny);
				if (vis[v]) continue;
				if (qz[v]) {
					if (ckill(su, v)) {
						vis[v] = 1;
						sta.push(v);
						++ans;
					}
				} else {
					vis[v] = 1;
					sta.push(v);
					++ans;
					qu.push(Node{nx, ny, 2, d});
				}
			}
		} else {
			for (int d = 0; d < 4; ++d) {
				if (edge[u][d] == 3) {
					int nx = x + dx[d], ny = y + dy[d];
					if (!check(nx, ny)) continue;
					int v = idx(nx, ny);
					if (vis[v]) continue;
					if (qz[v]) {
						if (ckill(su, v)) {
							vis[v] = 1;
							sta.push(v);
							++ans;
						}
					} else {
						vis[v] = 1;
						sta.push(v);
						++ans;
						qu.push(Node{nx, ny, 3, d});
					}
				}
			}
		}
	}
	while (!sta.empty()) {
		vis[sta.top()] = 0;
		sta.pop();
	}
	printf("%d\n", ans);
}

int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &m, &q);
		for (int i = 1; i <= n; ++i) {
			scanf("%s", tmp + 1);
			for (int j = 1; j <= m - 1; ++j) {
				r[idx(i, j)] = tmp[j] - '0';
				edge[idx(i, j)][2] = edge[idx(i, j + 1)][3] = r[idx(i, j)];
			}
		}
		for (int i = 1; i <= n - 1; ++i) {
			scanf("%s", tmp + 1);
			for (int j = 1; j <= m; ++j) {
				d[idx(i, j)] = tmp[j] - '0';
				edge[idx(i, j)][0] = edge[idx(i + 1, j)][1] = d[idx(i, j)];
			}
		}
		while (q--) {
			int c, w, x, y;
			scanf("%d%d%d%d", &c, &w, &x, &y);
			int u = idx(x, y);
			qz[u] = 1;
			col[u] = c;
			lv[u] = w;
			bfs(x, y);
		}
		clear();
	}
	return 0;
}
