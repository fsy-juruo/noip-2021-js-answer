#include<bits/stdc++.h>
#define VI vector<int>
#define pii pair<int, int>
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define per(i, a, b) for(int i = (b); i >= (a); --i)
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int) x.size())
#define N 200015
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define ll long long
using namespace std;
int T, n, m, q;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int G[N][4], dis[N], from[N];
bool ok[N];
pii tok[N];
char s[N];
int I(int x, int y) { return x * m + y;}
bool valid(int x, int y) { return 0 <= x && x < n && 0 <= y && y < m;}
namespace sub1 {
	queue<int> Q;
	void bfs(int typ, int x, int y) {
		rep(i, 0, n * m) dis[i] = -1;
		Q.push(I(x, y));
		dis[I(x, y)] = 0;
		from[I(x, y)] = -1;
		while(SZ(Q)) {
			int u = Q.front();
			Q.pop();
			int ux = u / m, uy = u % m;
			rep(d, 0, 3) {
				int vx = ux + dx[d], vy = uy + dy[d], v = I(vx, vy);
				if(!valid(vx, vy) || G[u][d] != typ || ~dis[v]) continue;
				if(tok[v] != mp(-1, -1) && (tok[v].fi == tok[I(x, y)].fi || tok[v].se > tok[I(x, y)].se)) continue;
				if(typ == 1 && dis[u] != 0) continue; // dis >= 1
				if(typ == 2 && ~from[u] && d != from[u]) continue; // line
				dis[v] = dis[u] + 1;
				from[v] = d;
				if(tok[v] == mp(-1, -1)) Q.push(v); // no token
			}
		}
		rep(i, 0, n * m) if(~dis[i]) ok[i] = 1;
	}
	void solve() {
		rep(_, 1, q) {
			int col, lvl, x, y;
			scanf("%d%d%d%d", &col, &lvl, &x, &y);
			x--;
			y--;
			tok[I(x, y)] = mp(col, lvl);
			rep(i, 0, n * m) ok[i] = 0;
			rep(p, 1, 3) bfs(p, x, y);
			int ans = 0;
			rep(i, 0, n * m - 1) if(ok[i] && i != I(x, y)) ans++;
			printf("%d\n", ans);
		}
	}
}
namespace sub2 {
	int f[N][4];
	set<pii> R[N], C[N];
	void solve() {
		rep(i, 0, n - 1) R[i].clear();
		rep(j, 0, m - 1) C[j].clear();
		rep(i, 0, n - 1) {
			rep(j, 0, m - 1) {
				int d = 3;
				f[I(i, j)][d] = 1;
				int ni = i + dx[d], nj = j + dy[d];
				if(!valid(ni, nj) || G[I(i, j)][d] != 2) continue;
				f[I(i, j)][d] = f[I(ni, nj)][d] + 1;
			}
			per(j, 0, m - 1) {
				int d = 2;
				f[I(i, j)][d] = 1;
				int ni = i + dx[d], nj = j + dy[d];
				if(!valid(ni, nj) || G[I(i, j)][d] != 2) continue;
				f[I(i, j)][d] = f[I(ni, nj)][d] + 1;
			}
		}
		rep(i, 0, n - 1) {
			rep(j, 0, m - 1) {
				int d = 1;
				f[I(i, j)][d] = 1;
				int ni = i + dx[d], nj = j + dy[d];
				if(!valid(ni, nj) || G[I(i, j)][d] != 2) continue;
				f[I(i, j)][d] = f[I(ni, nj)][d] + 1;
			}
		}
		per(i, 0, n - 1) {
			rep(j, 0, m - 1) {
				int d = 0;
				f[I(i, j)][d] = 1;
				int ni = i + dx[d], nj = j + dy[d];
				if(!valid(ni, nj) || G[I(i, j)][d] != 2) continue;
				f[I(i, j)][d] = f[I(ni, nj)][d] + 1;
			}
		}
		while(q--) {
			int col, lvl, x, y;
			scanf("%d%d%d%d", &col, &lvl, &x, &y);
			x--;
			y--;
			tok[I(x, y)] = mp(col, lvl);
			int ans = 0;
			auto check = [&](int v) {
				if(tok[v] != mp(-1, -1) && (tok[v].fi == tok[I(x, y)].fi || tok[v].se > tok[I(x, y)].se)) return 0;
				return 1;
			};
			rep(d, 0, 3) {
				int nx = x + dx[d], ny = y + dy[d], v = I(nx, ny);
				if(!valid(nx, ny)) continue;
				if(G[I(x, y)][d] == 1) {
					ans += check(v);
				}
			}
			auto it = C[y].lower_bound(mp(x, 0));
			if(G[I(x, y)][2] == 2) {
				int u = f[I(x, y)][2];
				if(it != C[y].end()) {
					if(it -> fi < x + u - 1) {
						ans += it -> fi - x - 1;
						if(check(it -> se)) ans++;
					} else ans += u - 1;
				} else ans += u - 1;
			}
			if(G[I(x, y)][3] == 2) {
				int u = f[I(x, y)][3];
				if(it != C[y].begin()) {
					it = prev(it);
					if(it -> fi > x - u + 1) {
						ans += x - it -> fi - 1;
						if(check(it -> se)) ans++;
					} else ans += u - 1;
				} else ans += u - 1;
			}
			it = R[x].lower_bound(mp(y, 0));
			if(G[I(x, y)][0] == 2) {
				int u = f[I(x, y)][0];
				if(it != R[x].end()) {
					if(it -> fi < y + u - 1) {
						ans += it -> fi - y - 1;
						if(check(it -> se)) ans++;
					} else ans += u - 1;
				} else ans += u - 1;
			}
			if(G[I(x, y)][1] == 2) {
				int u = f[I(x, y)][1];
				if(it != R[x].begin()) {
					it = prev(it);
					if(it -> fi > y - u + 1) {
						ans += y - it -> fi - 1;
						if(check(it -> se)) ans++;
					} else ans += u - 1;
				} else ans += u - 1;
			}
			printf("%d\n", ans);
			R[x].insert(mp(y, I(x, y)));
			C[y].insert(mp(x, I(x, y)));
		}
	}
}
int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &n, &m, &q);
		rep(i, 0, n - 1) {
			scanf("%s", s);
			rep(j, 0, m - 2) G[I(i, j)][2] = s[j] - '0', G[I(i, j + 1)][3] = s[j] - '0';
		}
		rep(i, 0, n - 2) {
			scanf("%s", s);
			rep(j, 0, m - 1) G[I(i, j)][0] = s[j] - '0', G[I(i + 1, j)][1] = s[j] - '0';
		}
		rep(i, 0, n * m - 1) tok[i] = mp(-1, -1);
		if(n * m <= 5000 && q <= 2000) sub1::solve();
		else sub2::solve();
	}
	return 0;
}
