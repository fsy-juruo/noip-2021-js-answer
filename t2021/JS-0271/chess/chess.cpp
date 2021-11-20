#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 2e5 + 5;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int n, m, Q, flag1 = 1, flag2 = 1;
char h[MAXN], v[MAXN], typ[MAXN][4];

int getH(const int i, const int j) {return (i - 1) * (m - 1) + j;}
int getV(const int i, const int j) {return (i - 1) * m + j;}
int check(const int x, const int y) {return x >= 1 && x <= n && y >= 1 && y <= m;}

struct Chess {
    int col, lv;
} grid[MAXN];
bool used[MAXN], vis[MAXN], can_go[MAXN];

bool can_eat(const Chess &x, const Chess &y) {
    return x.col != y.col && x.lv >= y.lv;
}

bool is_valid(int id, int nid) {
    return (!used[nid] || (used[nid] && can_eat(grid[id], grid[nid])));
}

namespace SubTask1 {
    void dfs(int x, int y, const Chess &c) {
        // cout << x << " " << y << endl;
        int id = getV(x, y); vis[id] = 1;
        if (used[id]) {
            if (can_eat(c, grid[id])) can_go[id] = true;
            return;
        }
        can_go[id] = true;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d], nid = getV(nx, ny);
            if (!check(nx, ny) || vis[nid]) continue;
            if (typ[id][d] != '3') continue;
            dfs(nx, ny, c);
        }
    }

    void solve_q() {
        int col, lv, x, y; scanf("%d%d%d%d", &col, &lv, &x, &y); 
        for (int i = 1; i <= n * m; i++) can_go[i] = vis[i] = false;
        const int id = getV(x, y); grid[id] = (Chess){col, lv}; vis[id] = used[id] = true; 
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d], nid = getV(nx, ny);
            if (!check(nx, ny)) continue;
            // cout << x << " " << y << " ; " << nx << " " << ny << endl;
            // cout << typ[id][d] << endl;
            if (typ[id][d] == '0') continue;
            if (typ[id][d] == '1') {
                if (is_valid(id, nid)) can_go[nid] = 1;
                continue;
            }
            if (typ[id][d] == '2') {
                while (is_valid(id, getV(nx, ny))) {
                    can_go[getV(nx, ny)] = 1;
                    if (used[getV(nx, ny)]) break;
                    if (typ[getV(nx, ny)][d] == '2')
                        nx += dx[d], ny += dy[d];
                    else break;
                }
                continue;
            }
            if (typ[id][d] == '3') {
                dfs(nx, ny, grid[id]);
                continue;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n * m; i++) ans += can_go[i];
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= m; j++)
        //         cout << can_go[getV(i, j)] << " ";
        //     cout << endl;
        // }
        printf("%d\n", ans);
    }

    void Solve() {
        // Q = 2;
        for (int i = 1; i <= n * m; i++) used[i] = false;
        while (Q--) solve_q();
    }
}

namespace SubTask2 {
    void solve_q() {
        int col, lv, x, y; scanf("%d%d%d%d", &col, &lv, &x, &y); 
        const int id = getV(x, y); grid[id] = (Chess){col, lv}; used[id] = true; 
        int ans = 0;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d], nid = getV(nx, ny);
            if (!check(nx, ny)) continue;
            // cout << x << " " << y << " ; " << nx << " " << ny << endl;
            // cout << typ[id][d] << endl;
            if (typ[id][d] == '0') continue;
            if (typ[id][d] == '1') {
                if (is_valid(id, nid)) ans += 1;
                continue;
            }
        }
        printf("%d\n", ans);
    }

    void Solve() {
        // Q = 2;
        for (int i = 1; i <= n * m; i++) used[i] = false;
        while (Q--) solve_q();
    }
}

void Solve() {
    scanf("%d%d%d", &n, &m, &Q);
    for (int i = 1; i <= n; i++) {
        scanf("%s", h + (i - 1) * (m - 1) + 1);
        for (int j = 1; j < m; j++) {
            if (h[getH(i, j)] == '3') flag1 = flag2 = 0;
            if (h[getH(i, j)] == '2') flag2 = 0;
        }
        for (int j = 1; j < m; j++)
            typ[getV(i, j)][0] = h[getH(i, j)];
        for (int j = 2; j <= m; j++)
            typ[getV(i, j)][1] = h[getH(i, j - 1)];
    }
    for (int i = 1; i < n; i++) {
        scanf("%s", v + (i - 1) * m + 1);
        for (int j = 1; j <= m; j++) {
            if (v[getV(i, j)] == '3') flag1 = flag2 = 0;
            if (v[getV(i, j)] == '2') flag2 = 0;
        }
        for (int j = 1; j <= m; j++)
            typ[getV(i, j)][2] = v[getV(i, j)];
        for (int j = 1; j <= m; j++)
            typ[getV(i + 1, j)][3] = v[getV(i, j)];
    }
    // for (int i = 1; i < n; i++) {
    //     for (int j = 1; j <= n; j++)
    //         cout << typ[getV(i, j)][2];
    //     cout << endl;
    // }
    if (flag2) SubTask2::Solve();
    else SubTask1::Solve();
}

int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w",stdout);
    int T; scanf("%d", &T); while (T--) Solve();
	return 0;
} 
