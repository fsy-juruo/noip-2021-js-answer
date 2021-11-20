#include <bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x)
{
	int f = 1; x = 0; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}
template <typename T> inline void write(T x)
{
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> inline void writeln(T x) { write(x); putchar('\n'); } 
const int N = 200005;
int n, m, q;
vector < vector <int> > L, R, U, D;
vector < vector <char> > row, col;
vector < vector < pair <int, int> > > chess;
vector < vector <bool> > vis;
int rRoot[N], cRoot[N], cnt;
struct node { int dat, lc, rc; } tree[N * 45];
inline int newnode()
{
	cnt++;
	tree[cnt].dat = tree[cnt].lc = tree[cnt].rc = 0;
	return cnt;
}
inline void modify(int &s, int l, int r, int pos, int val)
{
	if (!s) s = ++cnt;
	tree[s].dat = max(tree[s].dat, val);
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (pos <= mid) modify(tree[s].lc, l, mid, pos, val);
	else modify(tree[s].rc, mid + 1, r, pos, val);
}
inline int query(int s, int l, int r, int L, int R)
{
	if (!s) return 0;
	if (l >= L && r <= R) return tree[s].dat;
	int mid = (l + r) >> 1;
	int res = 0;
	if (L <= mid) res = max(res, query(tree[s].lc, l, mid, L, R));
	if (mid < R) res = max(res, query(tree[s].rc, mid + 1, r, L, R));
	return res;
}
set <int> rSet[N][2], cSet[N][2];
inline void init()
{
	L.clear(); L.resize(n + 5); for (int i = 1; i <= n; i++) L[i].resize(m + 5);
	R.clear(); R.resize(n + 5); for (int i = 1; i <= n; i++) R[i].resize(m + 5); 
	U.clear(); U.resize(n + 5); for (int i = 1; i <= n; i++) U[i].resize(m + 5);
	D.clear(); D.resize(n + 5); for (int i = 1; i <= n; i++) D[i].resize(m + 5); 
	row.clear(); row.resize(n + 5); for (int i = 1; i <= n; i++) row[i].resize(m + 5);
	col.clear(); col.resize(n + 5); for (int i = 1; i <= n; i++) col[i].resize(m + 5);
	chess.clear(); chess.resize(n + 5); for (int i = 1; i <= n; i++) chess[i].resize(m + 5);
	vis.clear(); vis.resize(n + 5); for (int i = 1; i <= n; i++) vis[i].resize(m + 5);
	for (int i = 1; i <= n; i++) rRoot[i] = 0;
	for (int i = 1; i <= m; i++) cRoot[i] = 0;
	cnt = 0;
	for (int i = 1; i <= n; i++) rSet[i][0].clear(), rSet[i][1].clear();
	for (int i = 1; i <= m; i++) cSet[i][0].clear(), cSet[i][1].clear();
}
char s[N];
pair <int, int> now;
inline bool check(int x, int y)
{
	if (chess[x][y] == make_pair(0, 0)) return 1;
	if (now.first != chess[x][y].first && now.second >= chess[x][y].second) return 1;
	return 0;
}
queue < pair <int, int> > Q;
inline void dfs(int x, int y)
{
	if (vis[x][y]) return;
	vis[x][y] = 1;
	Q.push(make_pair(x, y));
	if (chess[x][y] != make_pair(0, 0)) return;
	if (y > 1 && row[x][y - 1] == '3' && check(x, y - 1)) dfs(x, y - 1);
	if (y < m && row[x][y] == '3' && check(x, y + 1)) dfs(x, y + 1);
	if (x > 1 && col[x - 1][y] == '3' && check(x - 1, y)) dfs(x - 1, y);
	if (x < n && col[x][y] == '3' && check(x + 1, y)) dfs(x + 1, y);
}
inline void solve()
{
	read(n); read(m); read(q);
	init();
	bool flaga = 1, flagb = 1;
	for (int i = 1; i <= n; i++)
	{
		scanf ("%s", s + 1);
		for (int j = 1; j < m; j++) row[i][j] = s[j];
		for (int j = 1; j < m; j++) if (s[j] == '2') flaga = 0;
		for (int j = 1; j < m; j++) if (s[j] == '3') flagb = 0;
	}
	for (int i = 1; i < n; i++)
	{
		scanf ("%s", s + 1);
		for (int j = 1; j <= m; j++) col[i][j] = s[j];
		for (int j = 1; j <= m; j++) if (s[j] == '2') flaga = 0;
		for (int j = 1; j <= m; j++) if (s[j] == '3') flagb = 0;
	}
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
	{
		if (j > 1 && row[i][j - 1] == '2') L[i][j] = L[i][j - 1]; else L[i][j] = j;
		if (i > 1 && col[i - 1][j] == '2') U[i][j] = U[i - 1][j]; else U[i][j] = i;
 	}
 	for (int i = n; i >= 1; i--)
 	for (int j = m; j >= 1; j--)
 	{
 		if (j < m && row[i][j] == '2') R[i][j] = R[i][j + 1]; else R[i][j] = j;
 		if (i < n && col[i][j] == '2') D[i][j] = D[i + 1][j]; else D[i][j] = i;
	}
	while (q--)
	{
		int c, lv, x, y;
		read(c); read(lv); read(x); read(y);
		if (n * m > 5000 && q > 2000 && flaga == 0 && flagb)
		{
			int ans = 0;
			now = make_pair(c, lv);
			if (y > 1 && row[x][y - 1] == '1' && check(x, y - 1)) ans++;
			if (y < m && row[x][y] == '1' && check(x, y + 1)) ans++;
			if (x > 1 && col[x - 1][y] == '1' && check(x - 1, y)) ans++;
			if (x < n && col[x][y] == '1' && check(x + 1, y)) ans++;
			int Lpos = L[x][y], Rpos = R[x][y], Upos = U[x][y], Dpos = D[x][y];
			set <int> :: iterator it;
			it = rSet[x][c].lower_bound(y);
			if (it == rSet[x][c].end()) Rpos = min(Rpos, m);
			else Rpos = min(Rpos, (*it) - 1);
			if (it == rSet[x][c].begin()) Lpos = max(Lpos, 1);
			else { it--; Lpos = max(Lpos, (*it) + 1); }
			it = cSet[y][c].lower_bound(x);
			if (it == cSet[y][c].end()) Dpos = min(Dpos, n);
			else Dpos = min(Dpos, (*it) - 1);
			if (it == cSet[y][c].begin()) Upos = max(Upos, 1);
			else { it--; Upos = max(Upos, (*it) + 1); }
			int l, r, mid;
			l = Lpos, r = y;
			while (l <= r)
			{
				mid = (l + r) >> 1;
				if (query(rRoot[x], 1, m, mid, y) >= lv) { Lpos = mid; l = mid + 1; }
				else r = mid - 1;
			}
			l = y, r = Rpos;
			while (l <= r)
			{
				mid = (l + r) >> 1;
				if (query(rRoot[x], 1, m, y, mid) >= lv) { Rpos = mid; r = mid - 1; }
				else l = mid + 1;
			}
			l = Upos, r = x;
			while (l <= r)
			{
				mid = (l + r) >> 1;
				if (query(cRoot[y], 1, n, mid, x) >= lv) { Upos = mid; l = mid + 1; }
				else r = mid - 1;
			}
			l = x, r = Dpos;
			while (l <= r)
			{
				mid = (l + r) >> 1;
				if (query(cRoot[y], 1, n, x, mid) >= lv) { Dpos = mid; r = mid - 1; }
				else l = mid + 1;
			}
			if (query(rRoot[x], 1, m, Lpos, y) > lv) Lpos++;
			if (query(rRoot[x], 1, m, y, Rpos) > lv) Rpos--;
			if (query(cRoot[y], 1, n, Upos, x) > lv) Upos++;
			if (query(cRoot[y], 1, n, x, Dpos) > lv) Dpos--; 
			ans += max(0, Rpos - Lpos) + max(0, Dpos - Upos);
			writeln(ans);
			chess[x][y] = make_pair(c, lv);
			modify(rRoot[x], 1, m, y, lv);
			modify(cRoot[y], 1, n, x, lv);
			rSet[x][c].insert(y); cSet[y][c].insert(x);
			continue;
		}
		now = make_pair(c, lv);
		dfs(x, y);
		if (y > 1 && row[x][y - 1] == '1' && check(x, y - 1)) vis[x][y - 1] = 1, Q.push(make_pair(x, y - 1));
		if (y < m && row[x][y] == '1' && check(x, y + 1)) vis[x][y + 1] = 1, Q.push(make_pair(x, y + 1));
		if (x > 1 && col[x - 1][y] == '1' && check(x - 1, y)) vis[x - 1][y] = 1, Q.push(make_pair(x - 1, y));
		if (x < n && col[x][y] == '1' && check(x + 1, y)) vis[x + 1][y] = 1, Q.push(make_pair(x + 1, y));
		for (int i = x, j = y; j > 1 && row[i][j - 1] == '2' && check(i, j - 1); j--) { vis[i][j - 1] = 1; Q.push(make_pair(i, j - 1)); if (chess[i][j - 1] != make_pair(0, 0)) break; }
		for (int i = x, j = y; j < m && row[i][j] == '2' && check(i, j + 1); j++) { vis[i][j + 1] = 1; Q.push(make_pair(i, j + 1)); if (chess[i][j + 1] != make_pair(0, 0)) break; }
		for (int i = x, j = y; i > 1 && col[i - 1][j] == '2' && check(i - 1, j); i--) { vis[i - 1][j] = 1; Q.push(make_pair(i - 1, j)); if (chess[i - 1][j] != make_pair(0, 0)) break; }
		for (int i = x, j = y; i < n && col[i][j] == '2' && check(i + 1, j); i++) { vis[i + 1][j] = 1; Q.push(make_pair(i + 1, j)); if (chess[i + 1][j] != make_pair(0, 0)) break; }
		int ans = 0;
		vis[x][y] = 0;
		while (!Q.empty())
		{
			pair <int, int> now = Q.front(); Q.pop();
			if (vis[now.first][now.second]) { ans++; vis[now.first][now.second] = 0; }
		}
		writeln(ans);
		chess[x][y] = now;
	}
}
int main()
{
	freopen ("chess.in", "r", stdin);
	freopen ("chess.out", "w", stdout);
	int T;
	read(T);
	while (T--) solve();
	return 0;
}
