#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

template <typename T>
void input(T &num) {
    num = 0;
    T sign = 1;
    char ch = cin.get();
    while (ch < '0' || ch > '9') {
        if (ch == '-') sign = -1;
        ch = cin.get();
    }
    while (ch >= '0' && ch <= '9') {
        num = num * 10 + ch - '0';
        ch = cin.get();
    }
    num *= sign;
}

using pii = pair<int, int>;
using ppiii = pair<pii, int>;
const int maxnm = 200005;
int n, m, q;
char str[maxnm];
map<pii, pii> maze;
map<pii, vector<ppiii>> g;
set<pii> s;
set<pii> vis;
set<ppiii> svis;
const int xnone = 0, xleft = 1, xright = 2, xup = 3, xdown = 4, xnormal = 5,
          xany = 6;

void dfs(int x, int y, int sta, int col, int lv) {
    if (vis.count(pii(x, y))) return;
    if (svis.count(ppiii(pii(x, y), sta))) return;
    if (maze.count(pii(x, y))) {
        auto tmp = maze[pii(x, y)];
        if (tmp.first != col && tmp.second <= lv) s.insert(pii(x, y));
        return;
    }
    vis.insert(pii(x, y));
    svis.insert(ppiii(pii(x, y), sta));
    s.insert(pii(x, y));
    for (auto i : g[pii(x, y)]) {
        if (i.second == xnormal) {
            if (sta == xnone)
                dfs(i.first.first, i.first.second, xnormal, col, lv);
        } else {
            if (sta == i.second || sta == xnone)
                dfs(i.first.first, i.first.second, i.second, col, lv);
        }
    }
    vis.erase(pii(x, y));
}

void ac() {
    input(n);
    input(m);
    input(q);
    maze.clear();
    g.clear();
    for (int i = 1; i <= n; ++i) {
        cin >> str;
        for (int j = 1; j <= m - 1; ++j) {
            switch (str[j - 1]) {
                case '1':
                    g[pii(i, j)].push_back(ppiii(pii(i, j + 1), xnormal));
                    g[pii(i, j + 1)].push_back(ppiii(pii(i, j), xnormal));
                    break;
                case '2':
                    g[pii(i, j)].push_back(ppiii(pii(i, j + 1), xright));
                    g[pii(i, j + 1)].push_back(ppiii(pii(i, j), xleft));
                    break;
                case '3':
                    g[pii(i, j)].push_back(ppiii(pii(i, j + 1), xany));
                    g[pii(i, j + 1)].push_back(ppiii(pii(i, j), xany));
                    break;
            }
        }
    }
    for (int i = 1; i <= n - 1; ++i) {
        cin >> str;
        for (int j = 1; j <= m; ++j) {
            switch (str[j - 1]) {
                case '1':
                    g[pii(i, j)].push_back(ppiii(pii(i + 1, j), xnormal));
                    g[pii(i + 1, j)].push_back(ppiii(pii(i, j), xnormal));
                    break;
                case '2':
                    g[pii(i, j)].push_back(ppiii(pii(i + 1, j), xdown));
                    g[pii(i + 1, j)].push_back(ppiii(pii(i, j), xup));
                    break;
                case '3':
                    g[pii(i, j)].push_back(ppiii(pii(i + 1, j), xany));
                    g[pii(i + 1, j)].push_back(ppiii(pii(i, j), xany));
                    break;
            }
        }
    }
    for (int t = 1; t <= q; ++t) {
        int col, lv, x, y;
        input(col);
        input(lv);
        input(x);
        input(y);
        vis.clear();
        svis.clear();
        s.clear();
        dfs(x, y, xnone, col, lv);
        s.erase(pii(x, y));
        cout << s.size() << "\n";
        maze[pii(x, y)] = pii(col, lv);
    }
}

int main() {
    freopen("chess.in", "r", stdin);
    freopen("chess.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    input(t);
    while (t--) ac();
    return 0;
}
