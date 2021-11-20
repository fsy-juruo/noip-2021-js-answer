#include <bits/stdc++.h>
using namespace std;
int t;
int n, m, q;
/*
int lin[110][110], col[110][110];
bool chess[110][110];
int lev[110][110];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

struct node{
	int x, y, ch, dir;
	node(int _x, int _y, int _ch, int _dir){
		x = _x;
		y = _y;
		ch = _ch;
		dir = _dir;
	}
};
queue<node> q;
bool vis[4][110][110];

bool in(int x, int y){
	return 0 < x && x <= n && 0 < y && y <= m;
}

void bfs(int c, int l, int x, int y){
	int cnt = 0;
	for (int i = 0; i < 2; i++){
		int ty = y + dy[i];
		if (in(x, ty)){
			int tp = (dy == 1 ? y : y - 1);
			q.push(node(x, ty, lin[tx][tp], i));
			vis[lin[tx][tp]][x][ty] = 1;
		}
	}
	for (int i = 2; i < 4; i++){
		int tx = x + dx[i];
		if (in(tx, y)){
			int tp = (dx == 1 ? x : x - 1);
			q.push(node(tx, y, col[tp][y], i));
			vis[col[tp][y]][tx][y] = 1;
		}
	}
	while (!q.empty()){
		
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cnt += vis[1][i][j] | vis[2][i][j] | vis[3][i][j];
		}
	}
	printf("%d\n", cnt);
	return;
}
*/
struct node{
	int c, l;
	node(int _c, int _l){
		c = _c;
		l = _l;
	}
};

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d", &t);
	while (t--){
		scanf("%d%d%d", &n, &m, &q);
		vector<node> chess[200010];
		for (int i = 1; i < 2 * n; i++){
			char s[200010];
			scanf("%s", s);
		}
		for (int i = 0; i < q; i++){
			int c, l, x, y;
			scanf("%d%d%d%d", &c, &l, &x, &y);
			if (chess[x].size() <= y){
				for (int i = chess[x].size(); i < y; i++){
					chess[x].push_back(node(c, l));
				}
			}
		}
	}
	return 0;
}
