#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int) (n); ++ i)
#define rep1(i, n) for (int i = 1; i <= (int) (n); ++ i)

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int N, M, Q;
int row[5005][5005];
int col[5005][5005];
int lv[5005][5005];
int color[5005][5005];
int vis[5005][5005];
string str;

bool check(int c, int l, int x, int y)
{
	if (color[x][y] == c) return false;
	if (color[x][y] == (c ^ 1) && lv[x][y] > l) return false;
	return true;
}

void dfs(int c, int l, int x, int y)
{
	vis[x][y] = 2;
	if (color[x][y] != -1) return ;
	if (col[x - 1][y] == 3 && check(c, l, x - 1, y) && vis[x - 1][y] != 2) dfs(c, l, x - 1, y);
	if (col[x][y] == 3 && check(c, l, x + 1, y) && vis[x + 1][y] != 2) dfs(c, l, x + 1, y);
	if (row[x][y - 1] == 3 && check(c, l, x, y - 1) && vis[x][y - 1] != 2) dfs(c, l, x, y - 1);
	if (row[x][y] == 3 && check(c, l, x, y + 1) && vis[x][y + 1] != 2) dfs(c, l, x, y + 1);
}

void solve()
{
	cin >> N >> M >> Q;
	rep1(i, N) rep1(j, M) row[i][j] = col[i][j] = -1;
	rep1(i, N) {
		cin >> str;
		rep1(j, M - 1) row[i][j] = str[j - 1] - '0';
	}
	rep1(i, N - 1) {
		cin >> str;
		rep1(j, M) col[i][j] = str[j - 1] - '0';
	}
	rep1(i, N) rep1(j, M) {
		lv[i][j] = 0;
		color[i][j] = -1;
	}
	while (Q --) {
		int cnt = 0;
		int c, l, x, y;
		cin >> c >> l >> x >> y;
		rep1(i, N) rep1(j, M) vis[i][j] = 0;
		for (int i = x - 1; i > 0; -- i) {
			if (col[i][y] != 2) break;
			if (!check(c, l, i, y)) break;
			vis[i][y] = 1;
			if (color[i][y] != -1) break;
		}
		for (int i = x + 1; i <= N; ++ i) {
			if (col[i - 1][y] != 2) break;
			if (!check(c, l, i, y)) break;
			vis[i][y] = 1;
			if (color[i][y] != -1) break;
		}
		for (int j = y - 1; j > 0; -- j) {
			if (row[x][j] != 2) break;
			if (!check(c, l, x, j)) break;
			vis[x][j] = 1;
			if (color[x][j] != -1) break;
		}
		for (int j = y + 1; j <= M; ++ j) {
			if (row[x][j - 1] != 2) break;
			if (!check(c, l, x, j)) break;
			vis[x][j] = 1;
			if (color[x][j] != -1) break;
		}
		if (col[x - 1][y] == 1 && check(c, l, x - 1, y)) vis[x - 1][y] = 1;
		if (col[x][y] == 1 && check(c, l, x + 1, y)) vis[x + 1][y] = 1;
		if (row[x][y - 1] == 1 && check(c, l, x, y - 1)) vis[x][y - 1] = 1;
		if (row[x][y] == 1 && check(c, l, x, y + 1)) vis[x][y + 1] = 1;
		dfs(c, l, x, y);
		rep1(i, N) rep1(j, M) if (vis[i][j]) cnt ++;
		cout << cnt - 1 << endl;
		color[x][y] = c;
		lv[x][y] = l;
	}
}

int main()
{
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int T; cin >> T;
	while (T --) solve();
	
	
	return 0;
}
