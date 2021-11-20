#include <bits/stdc++.h>
using namespace std;

const int dir[2][4] = {{-1, 0, 0, 1}, {0, -1, 1, 0}};

int main() {
  freopen("chess.in", "r", stdin);
  freopen("chess.out", "w", stdout);
  int t;
  cin >> t;
  while (t--) {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<vector<int>>> way(n, vector<vector<int>>(m, vector<int>(4)));
    vector<vector<int>> c(n, vector<int>(m, -1)), l(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m - 1; j++) {
        cin >> way[i][j][2];
        way[i][j - 1][1] = way[i][j][2];
      }
    }
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < m; j++) {
        cin >> way[i][j][3];
        way[i - 1][j][0] = way[i][j][3];
      }
    }
    while (q--) {
      int col, lv, x, y;
      cin >> col >> lv >> x >> y;
      x--;
      y--;
      int ans = 0;
      for (int i = 0; i < 4; i++) {
        int X = x + dir[0][i], Y = y + dir[1][i];
        if (way[x][y][i] == 1 and c[X][Y] != col and l[X][Y] <= lv) {
          ans++;
        } 
      }
      cout << ans << endl;
      c[x][y] = col;
      l[x][y] = lv;
    }
  }
  return 0;
}

