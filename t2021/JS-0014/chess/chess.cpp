#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mem(x, v, s) memset(x, v, sizeof(x[0]) * (s))
#define cpy(x, y, s) memcpy(x, y, sizeof(x[0]) * (s))
#define pii pair <int, int>
#define gc getchar()
#define pc(x) putchar(x)
bool Mbe;

inline int read() {
	int x = 0, sgn = 0; char s = gc;
	while(!isdigit(s)) sgn |= s == '-', s = gc;
	while(isdigit(s)) x = x * 10 + s - '0', s = gc;
	return sgn ? -x : x;
}
void rprint(int x) {if(x >= 10) rprint(x / 10); pc(x % 10 + '0');}
void print(int x) {if(x < 0) pc('-'), x = -x; rprint(x);}
void cmin(int &x, int y) {if(x > y) x = y;}
void cmax(int &x, int y) {if(x < y) x = y;}

int n, m, q;
namespace BF {
	const int N = 2500 + 5;
	char rt[N][N], dwn[N][N];
	bool vis[N][N], c[N][N];
	int le[N][N];
	bool leg(int x, int y) {return x && y && x <= n && y <= m && !vis[x][y];}
	void BFS(int x, int y) {
		queue <pii> q; q.push({x, y});
		while(!q.empty()) {
			pii t = q.front(); q.pop();
			if(le[t.fi][t.se]) continue;
			int xx = t.fi + 1, yy = t.se;
			if(leg(xx, yy) && dwn[t.fi][t.se] == '3') vis[xx][yy] = 1, q.push({xx, yy});
			xx = t.fi - 1, yy = t.se;
			if(leg(xx, yy) && dwn[xx][yy] == '3') vis[xx][yy] = 1, q.push({xx, yy});
			xx = t.fi, yy = t.se - 1;
			if(leg(xx, yy) && rt[xx][yy] == '3') vis[xx][yy] = 1, q.push({xx, yy});
			xx = t.fi, yy = t.se + 1;
			if(leg(xx, yy) && rt[t.fi][t.se] == '3') vis[xx][yy] = 1, q.push({xx, yy});
		}
	}
	void solve() {
		mem(le, 0, N), mem(c, 0, N); 
		for(int i = 1; i <= n; i++) scanf("%s", rt[i] + 1);
		for(int i = 1; i < n; i++) scanf("%s", dwn[i] + 1);
		while(q--) {
			int col, lv, x, y; cin >> col >> lv >> x >> y;
			for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) vis[i][j] = 0;
			BFS(x, y), c[x][y] = col, le[x][y] = lv;
			for(int i = x - 1; i; i--) {
				if(dwn[i][y] != '2') break;
				vis[i][y] = 1;
				if(le[i][y]) break;
			}
			for(int i = x + 1; i <= n; i++) {
				if(dwn[i - 1][y] != '2') break;
				vis[i][y] = 1;
				if(le[i][y]) break;
			}
			for(int i = y - 1; i; i--) {
				if(rt[x][i] != '2') break;
				vis[x][i] = 1;
				if(le[x][i]) break;
			}
			for(int i = y + 1; i <= m; i++) {
				if(rt[x][i - 1] != '2') break;
				vis[x][i] = 1;
				if(le[x][i]) break;
			}
			if(x > 1 && dwn[x - 1][y] == '1') vis[x - 1][y] = 1;
			if(x < n && dwn[x][y] == '1') vis[x + 1][y] = 1;
			if(y > 1 && rt[x][y - 1] == '1') vis[x][y - 1] = 1;
			if(y < m && rt[x][y] == '1') vis[x][y + 1] = 1;
			int ans = 0;
			for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++)
				ans += vis[i][j] && (!le[i][j] || c[i][j] != col && lv >= le[i][j]);
			cout << ans << "\n";
		}
	}
}

const int N = 1e5 + 5;
vector <char> dwn[N], rt[N];
vector <int> c[N], le[N];

namespace OnlyNormal {
	void solve() {
		while(q--) {
			int col = read(), lv = read(), x = read(), y = read(), ans = 0; c[x][y] = col, le[x][y] = lv;
			if(x > 1 && dwn[x - 1][y] == '1') ans += !le[x - 1][y] || c[x - 1][y] != col && lv >= le[x - 1][y];
			if(x < n && dwn[x][y] == '1') ans += !le[x + 1][y] || c[x + 1][y] != col && lv >= le[x + 1][y];
			if(y > 1 && rt[x][y - 1] == '1') ans += !le[x][y - 1] || c[x][y - 1] != col && lv >= le[x][y - 1];
			if(y < m && rt[x][y] == '1') ans += !le[x][y + 1] || c[x][y + 1] != col && lv >= le[x][y + 1];
			printf("%d\n", ans);
		}
	}
}

namespace SMALLQ {
	int x[N], col[N], lv[N], y[N];
	void solve() {
		for(int i = 1; i <= q; i++) col[i] = read(), lv[i] = read(), x[i] = read(), y[i] = read();
		
	}
}

namespace NO3 {
	vector <int> lm[N], rm[N], um[N], dm[N];
	set <int> row[N], col[N];
	void solve() {
		for(int i = 1; i <= n; i++) lm[i].clear(), rm[i].clear(), lm[i].resize(m + 2), rm[i].resize(m + 2), row[i].clear();
		for(int i = 1; i <= m; i++) um[i].clear(), dm[i].clear(), um[i].resize(n + 2), dm[i].resize(n + 2), col[i].clear();
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				if(j == 1) lm[i][j] = 1;
				else if(rt[i][j - 1] != '2') lm[i][j] = j;
				else lm[i][j] = lm[i][j - 1];
			}
			for(int j = m; j; j--) {
				if(j == m) rm[i][j] = m;
				else if(rt[i][j] != '2') rm[i][j] = j;
				else rm[i][j] = rm[i][j + 1];
			}
		}
		for(int j = 1; j <= m; j++) {
			for(int i = 1; i <= n; i++) {
				if(i == 1) um[i][j] = 1;
				else if(dwn[i - 1][j] != '2') um[i][j] = i;
				else um[i][j] = um[i - 1][j];
			}
			for(int i = n; i; i--) {
				if(i == n) dm[i][j] = n;
				else if(dwn[i][j] != '2') dm[i][j] = i;
				else dm[i][j] = dm[i + 1][j];
			}
		}
		
		while(q--) {
			int co = read(), lv = read(), x = read(), y = read(), ans = 0;
			c[x][y] = co, le[x][y] = lv;
			
			int up = um[x][y];
			auto it = col[y].lower_bound(x);
			if(it != col[y].begin()) cmax(up, *--it);
			if(x > 1 && dwn[x - 1][y] == '1') cmin(up, x - 1);
			
			int down = dm[x][y];
			it = col[y].lower_bound(x);
			if(it != col[y].end()) cmin(down, *it);
			if(x < n && dwn[x][y] == '1') cmax(down, x + 1);
			
			int lft = lm[x][y];
			it = row[x].lower_bound(y);
			if(it != row[x].begin()) cmax(lft, *--it);
			if(y > 1 && rt[x][y - 1] == '1') cmin(lft, y - 1);
			
			int right = rm[x][y];
			it = row[x].lower_bound(y);
			if(it != row[x].end()) cmin(right, *it);
			if(y < m && rt[x][y] == '1') cmax(right, y + 1);
			
			if(up < x) {
				ans += x - up - 1;
				if(!le[up][y] || c[up][y] != co && lv >= le[up][y]) ans++;
			}
			if(down > x) {
				ans += down - x - 1;
				if(!le[down][y] || c[down][y] != co && lv >= le[down][y]) ans++;
			}
			if(lft < y) {
				ans += y - lft - 1;
				if(!le[x][lft] || c[x][lft] != co && lv >= le[x][lft]) ans++; 
			}
			if(right > y) {
				ans += right - y - 1;
				if(!le[x][right] || c[x][right] != co && lv >= le[x][right]) ans++;
			}
			
			col[y].insert(x), row[x].insert(y);
			printf("%d\n", ans);
		}
	}
}

void solve() {
	cin >> n >> m >> q;
	cerr << n << " " << m << " " << q << endl;
	if(n * m <= 5e3 && q <= 2000) return BF :: solve(), void();
	for(int i = 1; i <= n; i++) dwn[i].clear(), rt[i].clear(), c[i].clear(), le[i].clear();
	for(int i = 1; i <= n; i++) dwn[i].resize(m + 2), rt[i].resize(m + 2), c[i].resize(m + 2), le[i].resize(m + 2);
	for(int i = 1; i <= n; i++) scanf("%s", rt[i].begin() + 1);
	for(int i = 1; i < n; i++) scanf("%s", dwn[i].begin() + 1);
	
	bool check = 1;
	for(int i = 1; i <= n; i++) for(int j = 1; j < m; j++) check &= rt[i][j] <= '1';
	for(int i = 1; i < n; i++) for(int j = 1; j <= m; j++) check &= dwn[i][j] <= '1';
	if(check) return OnlyNormal :: solve(), void(); check = 1;
	
	for(int i = 1; i <= n; i++) for(int j = 1; j < m; j++) check &= rt[i][j] != '3';
	for(int i = 1; i < n; i++) for(int j = 1; j <= m; j++) check &= dwn[i][j] != '3';
	if(check) return NO3 :: solve(), void();
}

bool Med;
int main() {
	fprintf(stderr, "%.3lf\n", (&Mbe - &Med) / 1048576.0);
	int t = clock();
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	int T; cin >> T;
	while(T--) solve();
	return cerr << "Time : " << clock() - t << endl, 0;
}
