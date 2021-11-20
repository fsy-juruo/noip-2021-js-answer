#include <bits/stdc++.h>

using namespace std;

const int MN = 200005;

int n, m, q, mp1[MN], mp2[MN];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0}, MP[MN][4];
char m1[MN], m2[MN], ch[MN];
bool vis[MN];
queue<pair<int, int> > Q;

#define fi first
#define se second

#define de(x) cerr << (#x) << ":" << x << endl
#define deb(x, y) cerr << (#x) << "[" << y << "]:" << x[y] << endl

void read(int &x) {
	x = 0; int op = 1;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') op = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	x *= op;
}

int cg(int x, int y) { return (x - 1) * n + y; }

int query(int col, int lv, int x, int y) {
	for (int i = 1; i <= n; ++ i) for (int j = 1; j <= m; ++ j)
		vis[cg(i, j)] = 0;
	int ans = 0;
	vis[cg(x, y)] = 1;
	for (int i = 0; i < 4; ++ i) {
		int xx = x + dx[i], yy = y + dy[i];
		if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
		if (MP[cg(x, y)][i] == 0) continue;
		if (mp1[cg(xx, yy)] != 0) {
			if (mp1[cg(xx, yy)] == col) continue;
			if (mp2[cg(xx, yy)] > lv) continue;
			vis[cg(xx, yy)] = 1;
			ans ++;
			continue;
		}
		if (i & 1) {
			if (MP[cg(x, y)][i] != 3) {
				if (MP[cg(x, y)][i] == 1) {
					vis[cg(xx, yy)] = 1;
					ans ++;
				}
				else {
					int nowx = xx;
					while (MP[cg(nowx, y)][i] == 2) {
						vis[cg(nowx, yy)] = 1, ans ++, nowx += dx[i];
						if (mp1[cg(nowx, yy)] != 0) {
							if (mp1[cg(nowx, yy)] == col) continue;
							if (mp2[cg(nowx, yy)] > lv) continue;
							vis[cg(nowx, yy)] = 1;
							ans ++;
							break;;
						}
					}
				}
			}
			else Q.push(make_pair(xx, yy));
		}
		else {
			if (MP[cg(x, y)][i] != 3) {
				if (MP[cg(x, y)][i] == 1){
					vis[cg(xx, yy)] = 1;
					ans ++;
				}
				else {
					int nowy = yy;
					ans ++;
					while (MP[cg(x, nowy)][i] == 2) {
						vis[cg(x, nowy)] = 1, ans ++, nowy += dy[i];
						if (mp1[cg(xx, nowy)] != 0) {
							if (mp1[cg(xx, nowy)] == col) continue;
							if (mp2[cg(xx, nowy)] > lv) continue;
							vis[cg(xx, nowy)] = 1;
							ans ++;
							break;;
						}
					}
				}
			}
			else Q.push(make_pair(xx, yy));
		}
	}
	while (!Q.empty()) {
		int x_0 = Q.front().fi, y_0 = Q.front().se; Q.pop();
		if (vis[cg(x_0, y_0)]) continue;
		vis[cg(x_0, y_0)] = 1;
		ans ++;
		for (int i = 0; i < 4; ++ i) {
			int xx = x_0 + dx[i], yy = y_0 + dy[i];
			if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
			if (MP[cg(x_0, y_0)][i] != 3) continue;
			if (mp1[cg(xx, yy)] != 0) {
				if (mp1[cg(xx, yy)] == col) continue;
				if (mp2[cg(xx, yy)] > lv) continue;
				vis[cg(xx, yy)] = 1;
				ans ++;
				continue;
			}
			if (MP[cg(x_0, y_0)][i] == 3) Q.push(make_pair(xx, yy));
		}
	}
	return ans;
}

void clear() {
	for (int i = 1; i <= n; ++ i) for (int j = 1; j <= m; ++ j) 
		mp1[cg(i, j)] = mp2[cg(i, j)] = 0;
}

int main() {
	freopen ("chess.in", "r", stdin);
	freopen ("chess.out", "w", stdout);
	int T; read(T);
	while (T --) {
		read(n); read(m); read(q);
		clear();
		for (int i = 1; i <= n; ++ i) {
			scanf("%s", ch + 1);
			for (int j = 1; j < m; ++ j) 
				MP[cg(i, j)][0] = MP[cg(i, j + 1)][2] = ch[j] - '0';
		}
		for (int i = 1; i < n; ++ i) {
			scanf("%s", ch + 1);
			for (int j = 1; j <= m; ++ j)
				MP[cg(i, j)][1] = MP[cg(i + 1, j)][3] = ch[j] - '0';
		}
		while (q --) {
			int x, lv, y, col;
			read(col), read(lv), read(x), read(y);
			printf("%d\n", query(col + 1, lv, x, y));
			mp1[cg(x, y)] = col + 1; mp2[cg(x, y)] = lv;
		}
	}
	return 0;
}
//Thanks for my teachers.
