#include <bits/stdc++.h>

using i64 = int64_t;
using std::vector;

i64 read() {
    i64 n = 0, f = 1;
    char c = getchar();
    while (c > '9' || c < '0') {
        if (c == '-') {
            f = -1;
        }
        c = getchar();
    }
    while (c <= '9' && c >= '0') {
        n = (n << 1) + (n << 3) + (c - '0');
        c = getchar();
    }
    return n * f;
}

size_t n;
vector<i64> a, origin;
i64 res;

void solve(size_t p, i64 s) {
    for (size_t i = 1; i + 1 < a.size(); ++i) {
        if (i != p) {
            i64 delta = a[i - 1] + a[i + 1] - 2 * a[i];
            if (delta == 0) {
                continue;
            }
            a[i] += delta;
            if (a == origin) {
                return;
            }
            i64 ss = s + delta;
            i64 dd = 0;
            for (auto& j : a) {
                dd += ((n * j - ss) * (n * j - ss));
            }
            if (dd < res)  {
                res = dd;
            }
            solve(i, ss);
            a[i] -= delta;
        }
    }
}

int main() {
    // checklist
    // freopen stdio
    // fully optimized
    // flush cout
    // not overflow
    // file name
    std::ios::sync_with_stdio(false);
    freopen("variance.in", "r", stdin);
    freopen("variance.out", "w", stdout);
    i64 d = 0, s = 0;
    n = read();
    a.resize(n);
    for (auto& i : a) {
        i = read();
        s += i;
    }
    origin = a;
    for (auto& i : a) {
        d += ((n * i - s) * (n * i - s));
    }
    // d /= n;
    res = d;
    solve(0, s);
    std::cout << res / n;
    std::cout.flush();
    return 0;
}