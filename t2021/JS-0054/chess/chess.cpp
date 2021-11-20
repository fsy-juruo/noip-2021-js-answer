//pts: 8
#include <cstdio>
#include <cstring>

#define _S 200010

int T;

int n, m, q;

char input[_S];

bool map[_S][4];
int type[_S];
int level[_S];

int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};

int inline code(int i, int j) {
	return (i - 1) * m + j;
}
void inline decode(int x, int& i, int& j) {
	i = (x - 1) / m;
	j = x - i * m;
}

void clear() {
	memset(map, 0x00, sizeof(map));
	memset(level, 0xff, sizeof(level));
}

int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		clear();
		scanf("%d%d%d", &n, &m, &q);
		for (int i = 1; i <= n; i++) {
			scanf("%s", input + 1);
			for (int j = 1; j < m; j++) {
				if (input[j] == '1') {
					map[code(i, j)][2] = map[code(i, j + 1)][0] = true;
				}
			}
		}
		for (int i = 1; i < n; i++) {
			scanf("%s", input + 1);
			for (int j = 1; j <= m; j++) {
				if (input[j] == '1') {
					map[code(i, j)][3] = map[code(i + 1, j)][1] = true;
				}
			}
		}
		while (q--) {
			int col, lv, x, y;
			scanf("%d%d%d%d", &col, &lv, &x, &y);
			type[code(x, y)] = col;
			level[code(x, y)] = lv;
			int cnt = 0;
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir], ny = y + dy[dir];
				if (1 <= nx && nx <= n && 1 <= ny && ny <= m 
					&& map[code(x, y)][dir] 
					&& (level[code(nx, ny)] == -1 || (type[code(x, y)] != type[code(nx, ny)] && level[code(nx, ny)] <= level[code(x, y)]))) {
					cnt++;
				}
			}
			printf("%d\n", cnt);
		}
	}
	return 0;
}
