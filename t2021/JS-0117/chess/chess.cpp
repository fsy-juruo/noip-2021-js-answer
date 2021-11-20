#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

template <class t>
t read() {
    t x = 0; bool f = false;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        f |= ch == '-';
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return f ? -x : x;
}

int n, m;

class matrix {
    int *f, a, b;
public:
    matrix(int n, int m) {
        a = n, b = m;
        f = (int*)calloc(n * m, sizeof(int));
    }
    ~matrix() { delete[] f; }
    int &at(int x, int y) {
        return f[x * b + y];
    }
};

int main() {
    int t = read<int>();
    while (t--) {
        freopen("chess.in", "r", stdin);
        freopen("chess.out", "w", stdout);
        n = read<int>(), m = read<int>();
        const int q = read<int>();
        matrix lr(n, m), ud(n, m), color(n, m), rank(n, m);
        for (int i = 0; i < n - 1; i++) {
            getchar();
            for (int j = 0; j < m - 1; j++) {
                int way = getchar() - '0';
                lr.at(i, j) = way;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            getchar();
            for (int j = 0; j < m - 1; j++) {
                int way = getchar() - '0';
                ud.at(i, j) = way;
            }
        }
        for (int i = 0; i < q; i++) {
            int ans = 0;
            int c = read<int>(), r = read<int>(), x = read<int>(), y = read<int>();
            c++, x--, y--;
            if (x > 0 && ud.at(x - 1, y) && color.at(x - 1, y) != c && rank.at(x - 1, y) <= r)
                ans++;
            if (x < n && ud.at(x + 1, y) && color.at(x + 1, y) != c && rank.at(x + 1, y) <= r)
                ans++;
            if (y > 0 && lr.at(x, y - 1) && color.at(x, y - 1) != c && rank.at(x, y - 1) <= r)
                ans++;
            if (y < m && lr.at(x, y + 1) && color.at(x, y + 1) != c && rank.at(x, y + 1) <= r)
                ans++;
            color.at(x, y) = c, rank.at(x, y) = r;
            printf("%d\n", ans);
        }
    }
}