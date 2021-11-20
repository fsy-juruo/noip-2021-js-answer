#include <bits/stdc++.h>

using i64 = int64_t;
// using std::map;
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

const i64 mod = 998244353;
vector<size_t> num;
vector<size_t> numcp;
vector<i64> v;
size_t n, m, k;
i64 res;

size_t lowbit(size_t x) {
    return x & ((~x) + 1);
}

i64 qpowm(i64 a, i64 b) {
    i64 r = 1;
    while (b) {
        if (b & 1) {
            r = r * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return r;
}

void solve(size_t p, i64 remain) {
    // std::cerr << p << ' ' << remain << '\';
    if (p == 0) {
        numcp[p] = num[p] = remain;
        for (size_t i = 0; i < m + 4; ++i) {
            size_t cur = lowbit(num[i]);
            if (cur == 1) {
                num[i] -= cur;
            }
            while (num[i] > 0) {
                const auto lb = lowbit(num[i]);
                num[i + log2(lb)] += 1; // may panic
                num[i] -= lb;
            }
            if (cur == 1) {
                num[i] = cur;
            }
        }
        size_t cnt = 0;
        for (const auto& i : num) {
            if (i) {
                cnt += 1;
            }
        }
        if (cnt > k)  {
            return;
        }
        i64 gain = 0;
        i64 factor = 1;
        // code below will overflow
        for (size_t i = 2; i <= n; ++i) {
            factor *= n;
        }
        for (size_t i = 0; i < m + 1; ++i) {
            if (numcp[i]) {
                gain += qpowm(v[i], numcp[i]);
                gain %= mod;
                factor /= numcp[i];
            }
        }
        res = res + gain * factor % mod;
        return;
    }
    for (i64 i = 0; i <= remain; ++i) {
        numcp[p] = num[p] = i;
        solve(p - 1, remain - i);
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
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out ", "w", stdout);
    n = read(), m = read(), k = read();
    v.resize(m + 1);
    num.resize(m + 10);
    numcp.resize(m + 10);
    for (auto& i : v) {
        i = read();
    }
    solve(m + 1, n);
    std::cout << res;
    std::cout.flush();
    return 0;
}