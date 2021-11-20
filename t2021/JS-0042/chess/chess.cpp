// 2021.11.20, NOIP2021
// Code by LTb
// 地球最后的告白。
// 再见了……
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define int long long
#define fi first
#define se second
#define debug printf("Passing Line %d in function [%s].\n", __LINE__, __FUNCTION__)
inline void chmax(int &x, int y) {x = max(x, y);}
inline void chmin(int &x, int y) {x = min(x, y);}

const int MOD = 998244353;
inline int add(int x, int y){return (x+y>=MOD)?(x+y-MOD):((x+y<0)?(x+y+MOD):(x+y));}

inline int read() {
	int x=0,f=1;
	char c='.';
	while (c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while (c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return f*x;
}

const int MAXN = 200005;
int n, m, q;
char rd[MAXN];

// 我定义了个啥啊（汗
vector<vector<pair<int, int> > > G[MAXN];
vector<int> c[MAXN], l[MAXN], vis[MAXN];
vector<char> pa[MAXN], pb[MAXN];
int lv, col;

void dfs(int x, int y, bool qwq) {
	vis[x][y] = true;
	if (qwq) return;
	for (auto i : G[x][y]) {
		if (vis[i.fi][i.se]) continue;
		if (!l[i.fi][i.se]) dfs(i.fi, i.se, 0);
		else if (l[i.fi][i.se] <= lv && c[i.fi][i.se] != col) dfs(i.fi, i.se, 1);
	}
}

signed main()

{
	// freopen("chess.in", "r", stdin);
	// freopen("chess.out", "w", stdout);
	int test_case = read();
	while (test_case--) {
		n = read(), m = read(), q = read();
		for (int i = 1; i <= n; i++) {
			G[i].clear(), G[i].resize(m + 3);
			c[i].clear(), c[i].resize(m + 3);
			l[i].clear(), l[i].resize(m + 3);
			pa[i].clear(), pa[i].resize(m + 3);
			pb[i].clear(), pb[i].resize(m + 3);
			vis[i].clear(), vis[i].resize(m + 3);			
		}

		for (int i = 1; i <= n; i++) {
			scanf("%s", rd + 1);
			for (int j = 1; j <= m - 1; j++) {
				int tp = rd[j] - '0';
				if (tp == 3) {
					G[i][j].push_back({i, j + 1});
					G[i][j + 1].push_back({i, j});
				}
			}
		}

		for (int i = 1; i < n; i++) {
			scanf("%s", rd + 1);
			for (int j = 1; j <= m; j++) {
				int tp = rd[j] - '0';
				if (tp == 3) {
					G[i][j].push_back({i + 1, j});
					G[i + 1][j].push_back({i, j});
				}
			}
		}

		while (q--) {
			col = read(), lv = read();
			int x = read(), y = read();
			c[x][y] = col, l[x][y] = lv;
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= m; j++)
					vis[i][j] = false;
			
			dfs(x, y, 1);

			if (pa[x][y - 1] == '1' && (!l[x][y - 1] || c[x][y - 1] != col && l[x][y - 1] <= lv)) vis[x][y - 1] = true;
			if (pb[x + 1][y] == '1' && (!l[x + 1][y] || c[x + 1][y] != col && l[x + 1][y] <= lv)) vis[x + 1][y] = true;
			if (pb[x - 1][y] == '1' && (!l[x - 1][y] || c[x - 1][y] != col && l[x - 1][y] <= lv)) vis[x - 1][y] = true;
			if (pa[x][y + 1] == '1' && (!l[x][y + 1] || c[x][y + 1] != col && l[x][y + 1] <= lv)) vis[x][y + 1] = true;

			bool flag = true;
			// for (int i = x + 1; i <= n; i++) {if ()}
		}
	}
	return 0;
}