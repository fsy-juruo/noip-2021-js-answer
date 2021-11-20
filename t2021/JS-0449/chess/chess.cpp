#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
typedef pair<int, int> pii;
int T, n, m, q, ans, col, lv, xx, yy;
int r[N][N], d[N][N];
bool vis[N][N];
pii s[N][N];
queue<pii> qq, Q;
//1 left 2 up 3 right 4 down
inline bool valid(int x, int y){
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
void dfs(int x, int y, int dir, int op){
	if (vis[x][y] || !valid(x, y)) return;
	if (s[x][y].first){
		if (s[x][y].first != col && lv >= s[x][y].second){
			qq.push(make_pair(x, y));
			++ans;
			vis[x][y] = 1;
		}
		return;
	}
	qq.push(make_pair(x, y));
	vis[x][y] = 1;
	++ans;
	if (op == 1) return;
	if ((dir == -1 || dir == 1) && r[x][y - 1] && (op == -1 || op == r[x][y - 1])){
		dfs(x, y - 1, r[x][y - 1] == 2 ? 1 : -1, r[x][y - 1]);
	}
	if ((dir == -1 || dir == 2) && d[x - 1][y] && (op == -1 || op == d[x - 1][y])){
		dfs(x - 1, y, d[x - 1][y] == 2 ? 2 : -1, d[x - 1][y]);
	}
	if ((dir == -1 || dir == 3) && r[x][y] && (op == -1 || op == r[x][y])){
		dfs(x, y + 1, r[x][y] == 2 ? 3 : -1, r[x][y]);
	}
	if ((dir == -1 || dir == 4) && d[x][y] && (op == -1 || op == d[x][y])){
		dfs(x + 1, y, d[x][y] == 2 ? 4 : -1, d[x][y]);
	}
}
inline void solve(){
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; ++i){
		char ch;
		for (int j = 1; j < m; ++j){
			scanf(" %c", &ch);
			r[i][j] = ch - '0';
		}
	}
	for (int i = 1; i < n; ++i){
		char ch;
		for (int j = 1; j <= m; ++j){
			scanf(" %c", &ch);
			d[i][j] = ch - '0';
		}
	}
	while (q --){
		scanf("%d%d%d%d", &col, &lv, &xx, &yy);	
		++col, ans = 0;
		dfs(xx, yy, -1, -1);
		printf("%d\n", ans - 1);		
		while (qq.size()){
			pii cur = qq.front(); qq.pop();
			vis[cur.first][cur.second] = 0;
		}
		Q.push(make_pair(xx, yy));
		s[xx][yy] = make_pair(col, lv);
	}
	while (Q.size()){
		pii cur = Q.front(); Q.pop();
		s[cur.first][cur.second] = make_pair(0, 0);
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			r[i][j] = d[i][j] = 0;
}
int main(){
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	scanf("%d", &T);
	while (T--) 
		solve();
	return 0;
}

