#include <bits/stdc++.h>
using namespace std;
void readin(int &x) {
	x = 0;
	char ch = getchar();
	for (; ch > '9' || ch < '0'; ch = getchar());
	for (; ch <= '9' && ch >= '0'; ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
}
const int LIM = 2e5 + 5;
namespace BF{
	vector <int> vis[5][LIM], a[5][LIM], arv[LIM]; // 1 : lef; 2 : rig; 3 : up; 4 : down
	char s[LIM];
	vector <pair <int, int> > chs[LIM];
	int typ, lv, sum, tot, drt;
	const int dx[5] = {0, 0, 0, -1, 1}, dy[5] = {0, -1, 1, 0, 0};
	void dfs(int x, int y, int rod) {
		//cout << x << ' ' << y << endl;
		sum += (arv[x][y] != tot);
		vis[rod][x][y] = tot;
		arv[x][y] = tot;
		int xi, yi;
		for (int i = 1; i <= 4; i ++) {
			if (a[i][x][y] != rod || (rod == 2 && i != drt)) continue;
			xi = x + dx[i]; yi = y + dy[i];
			if (vis[rod][xi][yi] == tot) continue; 
			if (chs[xi][yi].first != typ) {
				if (chs[xi][yi].first != -1) {
					sum += (chs[xi][yi].second <= lv && arv[xi][yi] != tot);
					arv[xi][yi] = tot;
					vis[rod][xi][yi] = tot;
					//cout << xi << ' ' << yi << endl;
					continue;
				}
				dfs(xi, yi, rod);
			}
		}
	}
	void work(int n, int m, int q) {
		for (int i = 1; i <= 4; i ++) {
			for (int j = 0; j <= n + 1; j ++) {
				while (!a[i][j].empty()) a[i][j].pop_back();
				a[i][j].resize(m + 2, 0);
				while (!vis[i][j].empty()) vis[i][j].pop_back();
				vis[i][j].resize(m + 2, 0);
			}
		}
		for (int i = 0; i <= n + 1; i ++) {
			while (!chs[i].empty()) chs[i].pop_back();
			chs[i].resize(m + 2, make_pair(-1, 0));
			while (!arv[i].empty()) arv[i].pop_back();
			arv[i].resize(m + 2, 0);
		}
		for (int i = 1; i <= n; i ++) {
			scanf("%s", s + 1);
			for (int j = 1; j <= m - 1; j ++) {
				a[2][i][j] = a[1][i][j + 1] = s[j] - '0';
			}
		}
		for (int i = 1; i <= n - 1; i ++) {
			scanf("%s", s + 1);
			for (int j = 1; j <= m; j ++) {
				a[4][i][j] = a[3][i + 1][j] = s[j] - '0';
			}
		}
		int x, y, xi, yi;
		for (int i = 1; i <= q; i ++) {
			tot = i;
			readin(typ); readin(lv); readin(x); readin(y);
			sum = 0;
			vis[1][x][y] = vis[2][x][y] = vis[3][x][y] = vis[4][x][y] = arv[x][y] = tot;
			for (int j = 1; j <= 4; j ++) {
				if (a[j][x][y] == 0) continue;
				xi = x + dx[j]; yi = y + dy[j];
				if (vis[a[j][x][y]][xi][yi] == tot) continue;
				if (chs[xi][yi].first != typ) {
					if (chs[xi][yi].first != -1) {
						if (chs[xi][yi].second <= lv) {
							sum += (arv[xi][yi] != tot);
							vis[a[j][x][y]][xi][yi] = arv[xi][yi] = tot;
						}
					}
					else if (a[j][x][y] == 1) {
						sum += (arv[xi][yi] != tot);
						vis[a[j][x][y]][xi][yi] = arv[xi][yi] = tot;
					}
					else {
						if (a[j][x][y] == 2) drt = j;
						dfs(xi, yi, a[j][x][y]);
					}
				}
			}
			chs[x][y] = make_pair(typ, lv);
			printf("%d\n", sum);
		}
	}
}
int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	int T;
	readin(T);
	while (T --) {
		int n, m, q;
		readin(n); readin(m); readin(q);
		if (n * m <= LIM) BF::work(n, m, q); 
	}
	return 0;
}

