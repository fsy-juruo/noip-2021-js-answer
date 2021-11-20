// I love this problem.
#include <bits/stdc++.h>
using namespace std;

#define mk make_pair
#define fi first
#define se second
#define lob lower_bound
#define upb upper_bound
#define SZ(a) ((int)((a).size()))

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int MAXN = 2e5, MAXQ = 1e5, MAXS = 2e7;


int n, m, q, N;
int hl[MAXN + 5], vl[MAXN + 5];
int r2[MAXN + 5], l2[MAXN + 5], d2[MAXN + 5], u2[MAXN + 5];
char str[MAXN + 5];

set<int> seth[MAXN + 5], setv[MAXN + 5];

struct Qizi {
	int col, lv, x, y;
} qz[MAXQ + 5];
int ans[MAXQ + 5];

int st[MAXN + 5]; // state (start with final)

int fa[MAXN + 5], sz[MAXN + 5], vid[2][MAXN + 5]; // dsu
vector<int> vvv[2][MAXN + 5];
void ins(vector<int>& vec, int x) {
	int t = lob(vec.begin(), vec.end(), x) - vec.begin();
	vec.insert(vec.begin() + t, x);
}
void del(vector<int>& vec, int x) {
	int t = lob(vec.begin(), vec.end(), x) - vec.begin();
	assert(t < SZ(vec) && vec[t] == x);
	vec.erase(vec.begin() + t);
}

int get_fa(int u) {
	if (u == fa[u]) {
		return u;
	} else {
		return fa[u] = get_fa(fa[u]);
	}
}
void unite(int u, int v) {
	int uu = get_fa(u);
	int vv = get_fa(v);
	fa[uu] = vv;
	sz[vv] += sz[uu];
	
	for (int t = 0; t <= 1; ++t) {
#define V vvv[t][vid[t][vv]]
#define U vvv[t][vid[t][uu]]
		if (SZ(V) < SZ(U)) {
			swap(vid[t][vv], vid[t][uu]);
		}
		for (int i = 0; i < SZ(U); ++i) {
			int x = U[i];
			ins(V, x);
		}
		vector<int>().swap(U);
#undef V
#undef U
	}
}

int id(int x, int y) {
	return (x - 1) * m + y;
}
int revidx(int id) {
	return (id % m == 0) ? (id / m) : (id / m + 1);
}
int revidy(int id) {
	return (id % m == 0) ? m : (id % m);
}
bool inside(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

bool vis[MAXN + 5];
void contrib(int x, int y, int col, int pos, int val) {
	int xx, yy;
	xx = x, yy = y + 1; // right
	if (inside(xx, yy) && !st[id(xx, yy)] && hl[id(x, y)] == 3) {
		int t = get_fa(id(xx, yy));
		if (!vis[t]) {
			if (val == 1) {
				ins(vvv[col][vid[col][t]], pos);
			} else {
				del(vvv[col][vid[col][t]], pos);
			}
			vis[t] = 1;
		}
	}
	xx = x + 1, yy = y; // down
	if (inside(xx, yy) && !st[id(xx, yy)] && vl[id(x, y)] == 3) {
		int t = get_fa(id(xx, yy));
		if (!vis[t]) {
			if (val == 1) {
				ins(vvv[col][vid[col][t]], pos);
			} else {
				del(vvv[col][vid[col][t]], pos);
			}
			vis[t] = 1;
		}
	}
	xx = x, yy = y - 1; // left
	if (inside(xx, yy) && !st[id(xx, yy)] && hl[id(x, yy)] == 3) {
		int t = get_fa(id(xx, yy));
		if (!vis[t]) {
			if (val == 1) {
				ins(vvv[col][vid[col][t]], pos);
			} else {
				del(vvv[col][vid[col][t]], pos);
			}
			vis[t] = 1;
		}
	}
	xx = x - 1, yy = y; // up
	if (inside(xx, yy) && !st[id(xx, yy)] && vl[id(xx, y)] == 3) {
		int t = get_fa(id(xx, yy));
		if (!vis[t]) {
			if (val == 1) {
				ins(vvv[col][vid[col][t]], pos);
			} else {
				del(vvv[col][vid[col][t]], pos);
			}
			vis[t] = 1;
		}
	}
	
	// clear:
	xx = x, yy = y + 1; // right
	if (inside(xx, yy) && !st[id(xx, yy)] && hl[id(x, y)] == 3) {
		int t = get_fa(id(xx, yy));
		vis[t] = 0;
	}
	xx = x + 1, yy = y; // down
	if (inside(xx, yy) && !st[id(xx, yy)] && vl[id(x, y)] == 3) {
		int t = get_fa(id(xx, yy));
		vis[t] = 0;
	}
	xx = x, yy = y - 1; // left
	if (inside(xx, yy) && !st[id(xx, yy)] && hl[id(x, yy)] == 3) {
		int t = get_fa(id(xx, yy));
		vis[t] = 0;
	}
	xx = x - 1, yy = y; // up
	if (inside(xx, yy) && !st[id(xx, yy)] && vl[id(xx, y)] == 3) {
		int t = get_fa(id(xx, yy));
		vis[t] = 0;
	}
}

void solve_case() {
	scanf("%d%d%d", &n, &m, &q);
	N = n * m;
	
	for (int i = 1; i <= n; ++i) {
		scanf("%s", str + 1);
		assert((int)strlen(str + 1) == m - 1);
		for (int j = 1; j < m; ++j) {
			hl[id(i, j)] = str[j] - '0';
			
			if (hl[id(i, j)] != 2) {
				l2[id(i, j)] = 0;
			} else {
				l2[id(i, j)] = ((j == 1) ? 0 : l2[id(i, j - 1)]) + 1;
			}
		}
		for (int j = m - 1; j >= 1; --j) {
			if (hl[id(i, j)] != 2) {
				r2[id(i, j)] = 0;
			} else {
				r2[id(i, j)] = ((j == m - 1) ? 0 : r2[id(i, j + 1)]) + 1;
			}
		}
	}
	for (int i = 1; i < n; ++i) {
		scanf("%s", str + 1);
		assert((int)strlen(str + 1) == m);
		for (int j = 1; j <= m; ++j) {
			vl[id(i, j)] = str[j] - '0';
		}
	}
	for (int j = 1; j <= m; ++j) {
		for (int i = 1; i < n; ++i) {
			if (vl[id(i, j)] != 2) {
				u2[id(i, j)] = 0;
			} else {
				u2[id(i, j)] = ((i == 1) ? 0 : u2[id(i - 1, j)]) + 1;
			}
		}
		for (int i = n - 1; i >= 1; --i) {
			if (vl[id(i, j)] != 2) {
				d2[id(i, j)] = 0;
			} else {
				d2[id(i, j)] = ((i == n - 1) ? 0 : d2[id(i - 1, j)]) + 1;
			}
		}
	}
	
	for (int i = 1; i <= N; ++i) {
		st[i] = 0;
		fa[i] = i;
		sz[i] = 1;
		vid[0][i] = vid[1][i] = i;
		vector<int>().swap(vvv[0][i]);
		vector<int>().swap(vvv[1][i]);
	}
	for (int i = 1; i <= n; ++i) {
		seth[i].clear();
		seth[i].insert(0);
		seth[i].insert(m + 1);
	}
	for (int i = 1; i <= m; ++i) {
		setv[i].clear();
		setv[i].insert(0);
		setv[i].insert(n + 1);
	}
	for (int i = 1; i <= q; ++i) {
		scanf("%d%d%d%d", &(qz[i].col), &(qz[i].lv), &(qz[i].x), &(qz[i].y));
		assert(!st[id(qz[i].x, qz[i].y)]);
		st[id(qz[i].x, qz[i].y)] = i;
		seth[qz[i].x].insert(qz[i].y);
		setv[qz[i].y].insert(qz[i].x);
	}
	
	for (int i = 1; i <= N; ++i) {
		if (st[i] == 0) {
			// empty
			int x = revidx(i), y = revidy(i), xx, yy;
			
			xx = x, yy = y + 1; // right
			if (inside(xx, yy) && !st[id(xx, yy)] && hl[id(x, y)] == 3) {
				unite(id(x, y), id(xx, yy));
			}
			xx = x + 1, yy = y; // down
			if (inside(xx, yy) && !st[id(xx, yy)] && vl[id(x, y)] == 3) {
				unite(id(x, y), id(xx, yy));
			}
			
			// no need left or up
		}
	}
	for (int i = 1; i <= N; ++i) {
		if (st[i] == 0) {
			continue;
		}
		contrib(revidx(i), revidy(i), qz[st[i]].col, qz[st[i]].lv, 1);
	}
	
	for (int i = q; i >= 1; --i) {
		ans[i] = 0;
		
		int x = qz[i].x, y = qz[i].y, xx, yy;
		
		// consider line type 1
		
		xx = x, yy = y + 1; // right
		if (inside(xx, yy) && hl[id(x, y)] == 1) {
			int t = st[id(xx, yy)];
			ans[i] += (t == 0 || (qz[t].col != qz[i].col && qz[t].lv <= qz[i].lv));
		}
		xx = x + 1, yy = y; // down
		if (inside(xx, yy) && vl[id(x, y)] == 1) {
			int t = st[id(xx, yy)];
			ans[i] += (t == 0 || (qz[t].col != qz[i].col && qz[t].lv <= qz[i].lv));
		}
		xx = x, yy = y - 1; // left
		if (inside(xx, yy) && hl[id(x, yy)] == 1) {
			int t = st[id(xx, yy)];
			ans[i] += (t == 0 || (qz[t].col != qz[i].col && qz[t].lv <= qz[i].lv));
		}
		xx = x - 1, yy = y; // up
		if (inside(xx, yy) && vl[id(xx, y)] == 1) {
			int t = st[id(xx, yy)];
			ans[i] += (t == 0 || (qz[t].col != qz[i].col && qz[t].lv <= qz[i].lv));
		}
		/*
		// consider line type 2
		seth[x].erase(y);
		setv[y].erase(x);
		if (inside(x, y + 1)) {
			int Y = (*seth[x].upper_bound(y));
			if (r2[id(x, y)] <= Y - y - 1) {
				ans[i] += r2[id(x, y)];
			} else {
				assert(Y <= m);
				ans[i] += Y - y - 1;
				int t = st[id(x, Y)];
				assert(t != 0);
				ans[i] += (qz[t].col != qz[i].col && qz[t].lv <= qz[i].lv);
			}
		}
		if (inside(x + 1, y)) {
			int X = (*setv[y].upper_bound(x));
			if (d2[id(x, y)] <= X - x - 1) {
				ans[i] += d2[id(x, y)];
			} else {
				assert(X <= n);
				ans[i] += X - x - 1;
				int t = st[id(X, y)];
				assert(t != 0);
				ans[i] += (qz[t].col != qz[i].col && qz[t].lv <= qz[i].lv);
			}
		}
		if (inside(x, y - 1)) {
			set<int>::iterator it = seth[x].lower_bound(y);
			assert(it != seth[x].begin());
			--it;
			int Y = (*it);
			if (l2[id(x, y - 1)] <= y - Y - 1) {
				ans[i] += l2[id(x, y - 1)];
			} else {
				assert(Y >= 1);
				ans[i] += y - Y - 1;
				int t = st[id(x, Y)];
				assert(t != 0);
				ans[i] += (qz[t].col != qz[i].col && qz[t].lv <= qz[i].lv);
			}
		}
		if (inside(x - 1, y)) {
			set<int>::iterator it = setv[y].lower_bound(x);
			assert(it != setv[y].begin());
			--it;
			int X = (*it);
			if (u2[id(x - 1, y)] <= x - X - 1) {
				ans[i] += u2[id(x - 1, y)];
			} else {
				assert(X >= 1);
				ans[i] += x - X - 1;
				int t = st[id(X, y)];
				assert(t != 0);
				ans[i] += (qz[t].col != qz[i].col && qz[t].lv <= qz[i].lv);
			}
		}
		*/
		// consider line type 3
		
		contrib(x, y, qz[i].col, qz[i].lv, -1);
		// connect qz[i] with its surrounding (empty neighbors)
		xx = x, yy = y + 1; // right
		if (inside(xx, yy) && !st[id(xx, yy)] && hl[id(x, y)] == 3) {
			unite(id(x, y), id(xx, yy));
		}
		xx = x + 1, yy = y; // down
		if (inside(xx, yy) && !st[id(xx, yy)] && vl[id(x, y)] == 3) {
			unite(id(x, y), id(xx, yy));
		}
		xx = x, yy = y - 1; // left
		if (inside(xx, yy) && !st[id(xx, yy)] && hl[id(x, yy)] == 3) {
			unite(id(x, y), id(xx, yy));
		}
		xx = x - 1, yy = y; // up
		if (inside(xx, yy) && !st[id(xx, yy)] && vl[id(xx, y)] == 3) {
			unite(id(x, y), id(xx, yy));
		}
		
		// consider its non-empty neighbors, change their contribution
		xx = x, yy = y + 1; // right
		if (inside(xx, yy) && st[id(xx, yy)] && hl[id(x, y)] == 3) {
			contrib(xx, yy, qz[st[id(xx, yy)]].col, qz[st[id(xx, yy)]].lv, -1);
			st[id(x, y)] = 0;
			contrib(xx, yy, qz[st[id(xx, yy)]].col, qz[st[id(xx, yy)]].lv, 1);
			st[id(x, y)] = i;
		}
		xx = x + 1, yy = y; // down
		if (inside(xx, yy) && st[id(xx, yy)] && vl[id(x, y)] == 3) {
			contrib(xx, yy, qz[st[id(xx, yy)]].col, qz[st[id(xx, yy)]].lv, -1);
			st[id(x, y)] = 0;
			contrib(xx, yy, qz[st[id(xx, yy)]].col, qz[st[id(xx, yy)]].lv, 1);
			st[id(x, y)] = i;
		}
		xx = x, yy = y - 1; // left
		if (inside(xx, yy) && st[id(xx, yy)] && hl[id(x, yy)] == 3) {
			contrib(xx, yy, qz[st[id(xx, yy)]].col, qz[st[id(xx, yy)]].lv, -1);
			st[id(x, y)] = 0;
			contrib(xx, yy, qz[st[id(xx, yy)]].col, qz[st[id(xx, yy)]].lv, 1);
			st[id(x, y)] = i;
		}
		xx = x - 1, yy = y; // up
		if (inside(xx, yy) && st[id(xx, yy)] && vl[id(xx, y)] == 3) {
			contrib(xx, yy, qz[st[id(xx, yy)]].col, qz[st[id(xx, yy)]].lv, -1);
			st[id(x, y)] = 0;
			contrib(xx, yy, qz[st[id(xx, yy)]].col, qz[st[id(xx, yy)]].lv, 1);
			st[id(x, y)] = i;
		}
		
		int u = get_fa(id(x, y));
		ans[i] += sz[u] - 1;
		
		int c = (qz[i].col ^ 1);
		int tmp = upb(vvv[c][vid[c][u]].begin(), vvv[c][vid[c][u]].end(), qz[i].lv) - vvv[c][vid[c][u]].begin();
		ans[i] += tmp;
		st[id(x, y)] = 0;
	}
	
	for (int i = 1; i <= q; ++i) {
		printf("%d\n", ans[i]);
	}
}
int main() {
// 仍有 bug, 回家再调~
	
	return 0; // 自杀
	
	
	
	int T;
	scanf("%d", &T);
	while (T--) {
		solve_case();
	}
	return 0;
}
