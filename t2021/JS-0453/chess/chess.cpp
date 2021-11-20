#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <vector>
using namespace std;

void file() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out","w",stdout);
}

int dir[4];//left, right, up, down
int line, row;
int statusx[200002], statusy[200002]; 
char status[100002];
pair<int, int> chess[200002];//colour, level
bool visited[200002];

inline bool legalboard(int x, int d) {
	if (!d && x % row == 1) return false;
	if (d == 1 && !(x % row)) return false;
	if (d == 2 && x <= row) return false;
	if (d == 3 && x > row * (line - 1)) return false;
	return true;
}

inline bool legalchess(const int nowcol, const int nowlv, const int tx) {
	return chess[tx].first != nowcol && chess[tx].second <= nowlv;
}

inline bool opposite(int dir1, int dir2) {
	return (dir1 == 0 && dir2 == 1) || (dir1 == 1 && dir2 == 0) || (dir1 == 2 && dir2 == 3) || (dir1 == 3 && dir2 == 2);
}

inline int get_road(int d, int x) {
	switch (d) {
		case 0:
			return statusx[x - 1];
		case 1:
			return statusx[x];
		case 2:
			return statusy[x - row];
		default:
			return statusy[x];
	}
}

int dfs(int x, const int lastdir, const int lastroad, const int &col, const int &lev) {
	if (visited[x]) return 0;
	visited[x] = true;
	if (lastroad == 2) {
		if (chess[x].first != -1) return 1;
		if (legalboard(x, lastdir) && get_road(lastdir, x) == 2 && legalchess(col, lev, x + dir[lastdir])) {
			return dfs(x + dir[lastdir], lastdir, 2, col, lev) + 1;
		}
		return 1;
	}
	if (lastroad == 3) {
		if (chess[x].first != -1) return 1;
		int sum = 1;
		for (int i = 0; i != 4; ++i) {
			if (!opposite(i, lastdir) && legalboard(x, i) && get_road(i, x) == 3 && legalchess(col, lev, x + dir[i]) && !visited[x + dir[i]]) {
				sum += dfs(x + dir[i], i, 3, col, lev);
			}
		}
		return sum;
	}
	if (lastroad == -1) {
		int sum = 0;
		for (int i = 0; i != 4; ++i) {
			int tx = x + dir[i];
			if (legalboard(x, i)) {
				int road = get_road(i, x);
				if (!road) continue;
				if (road == 1) {
					sum += legalchess(col, lev, tx);
					visited[tx] = true;
					continue;
				}
				if (legalchess(col, lev, tx)) {
					sum += dfs(x + dir[i], i, road, col, lev);
				}
			} 
		}
		return sum;
	}
	return 0;
}

int main() {
	file();
	int times;
	scanf("%d", &times);
	while (times--) {
		int t;
		scanf("%d %d %d", &line, &row, &t);
		dir[0] = -1, dir[1] = 1;
		dir[2] = -row, dir[3] = row;
		for (int i = 1; i <= line; ++i) {
			scanf(" %s", status + 1);
			for (int j = 1; j != row; ++j) {
				statusx[(i - 1) * row + j] = status[j] - 48;
			}
		}
		for (int i = 1; i != line; ++i) {
			scanf(" %s", status + 1);
			for (int j = 1; j <= row; ++j) {
				statusy[(i - 1) * row + j] = status[j] - 48;
			}
		}
		memset(chess, -1, sizeof(chess));
		int colour, level, x, y;
		while (t--) {
			scanf("%d %d %d %d", &colour, &level, &x, &y);
			chess[(x - 1) * row + y] = make_pair(colour, level);
			fill(visited + 1, visited + line * row + 1, false);
			int result = dfs((x - 1) * row + y, -1, -1, colour, level);
			printf("%d\n", result);
		}
	}
	return 0;
}
//place[x][y] = status[(x - 1) * row + y]
