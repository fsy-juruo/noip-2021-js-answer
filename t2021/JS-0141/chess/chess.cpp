
#include <bits/stdc++.h>
using namespace std;
#ifdef _LOCAL_JUDGE
#define eprintf(...) ({ fprintf(stderr, __VA_ARGS__); fflush(stderr); })
#else
#define eprintf(...)
#endif

static constexpr int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int n, m, q;
vector<vector<int>> row, col;
vector<vector<int>> grid;
struct node {
  int col, lev;
  node() = default;
  node(int c, int l) : col(c), lev(l) { }
};
inline bool valid(int x, int y) {
  return x >= 1 && x <= n && y >= 1 && y <= m;
} // valid
inline int get_col(int x, int y, int dir) {
  if (dir == 0) return row[x][y];
  if (dir == 1) return col[x][y];
  if (dir == 2) return row[x][y - 1];
  if (dir == 3) return col[x - 1][y];
} // get_col

namespace sol_1 {
  static constexpr int Maxn = 5005;
  node nd[Maxn];
  inline bool match(int x, int y) {
    return nd[x].col != nd[y].col && nd[x].lev >= nd[y].lev;
  } // match
  bool c[Maxn][Maxn];
  int sz, sx[Maxn * Maxn], sy[Maxn * Maxn];
  #define append_answer(x, y) \
    if (!c[x][y]) sx[++sz] = x, sy[sz] = y, c[x][y] = true
  void calc(int i, int x, int y, int col, int dir) {
    if (col == 0) return ;
    if (grid[x][y] != 0) {
      if (match(i, grid[x][y])) append_answer(x, y);
      return ;
    }
    if (col == 1) {
      append_answer(x, y);
      return ;
    }
    if (col == 2) {
      append_answer(x, y);
      do {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (!valid(nx, ny)) break;
        if (get_col(x, y, dir) != 2) break;
        if (grid[nx][ny] != 0) {
          if (match(i, grid[nx][ny])) append_answer(nx, ny);
          break;
        }
        x = nx, y = ny;
        append_answer(x, y);
      } while (true);
      return ;
    }
    static int que[Maxn * Maxn * 2];
    int qh = 0, qe = 0;
    que[qe++] = x, que[qe++] = y;
    int ans = 0;
    static bool vis[Maxn][Maxn];
    vis[x][y] = true;
    while (qh < qe) {
      int ux = que[qh++], uy = que[qh++];
      append_answer(ux, uy);
      for (int dir = 0; dir < 4; ++dir) {
        int nx = ux + dx[dir], ny = uy + dy[dir];
        if (!valid(nx, ny)) continue;
        if (get_col(ux, uy, dir) != 3) continue;
        if (grid[nx][ny] != 0) {
          if (match(i, grid[nx][ny]))
            append_answer(nx, ny);
          continue;
        }
        if (!vis[nx][ny])
          que[qe++] = nx, que[qe++] = ny, vis[nx][ny] = true;
      }
    }
    for (int i = 0; i < qe; i += 2)
      vis[que[i]][que[i + 1]] = false;
  }
  void main(void) {
    for (int i = 1; i <= q; ++i) {
      int x, y;
      scanf("%d%d%d%d", &nd[i].col, &nd[i].lev, &x, &y);
      grid[x][y] = i;
      sz = 0;
      for (int dir = 0; dir < 4; ++dir) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if (!valid(nx, ny)) continue;
        calc(i, nx, ny, get_col(x, y, dir), dir);
      }
      printf("%d\n", sz);
      for (int i = 1; i <= sz; ++i)
        c[sx[i]][sy[i]] = 0;
    }
  } // sol_1::main
} // namespace sol_1

int main(void) {
  freopen("chess.in", "r", stdin);
  freopen("chess.out", "w", stdout);
  int tests; scanf("%d", &tests);
  while (tests--) {
    scanf("%d%d%d", &n, &m, &q);
    row.assign(n + 1, vector<int>(m, 0));
    col.assign(n, vector<int>(m + 1, 0));
    grid.assign(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
      static char str[200005];
      scanf("%s", str + 1);
      for (int j = 1; j <= m - 1; ++j)
        row[i][j] = str[j] - '0';
    }
    for (int i = 1; i <= n - 1; ++i) {
      static char str[200005];
      scanf("%s", str + 1);
      for (int j = 1; j <= m; ++j)
        col[i][j] = str[j] - '0';
    }
    if ((n * m <= 5000 || (n <= 1000 && m <= 1000)) && q <= 2000) {
      sol_1::main(); continue;
    }
  }
  exit(EXIT_SUCCESS);
} // main

