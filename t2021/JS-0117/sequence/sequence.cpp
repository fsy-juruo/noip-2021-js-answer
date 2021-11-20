#include <cstdio>
#include <queue>
#include <map>

using namespace std;
typedef unsigned long long u64;

const u64 MOD = 998244353;

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

u64 pow(u64 x, int y) {
    u64 ret = 1;
    while (y) {
        if (y & 1) ret = ret * x % MOD, y ^= 1;
        else x = x * x % MOD, y >>= 1;
    }
    return ret;
}

int one_count(u64 x) {
    int ret = 0;
    while (x) {
        x ^= x & -x;
        ret++;
    }
    return ret;
}

u64 v[200], ans = 0;
int n, m, k;
int O = 0;
map<pair<u64, int>, u64> f;

u64 dfs(u64 s, int cnt, u64 cur) {
    /*if (f.count({ s, cnt })) {
        ans = (ans + f[{ s, cnt }]) % MOD;
        return f[{ s, cnt }];
    }*/
    if (cnt == n) {
        if (one_count(s) <= k) {
            ans = (ans + cur) % MOD;
            return cur;
        }
        return 0;
    }
    u64 result = 0;
    for (int i = 0; i <= m; i++) {
        u64 tmp = dfs(s + (1ULL << i), cnt + 1, cur * v[i] % MOD);
        result = (result + tmp) % MOD;
    }
    /*if (f.size() < (1 << 23))
        f[{ s, cnt }] = result;*/
    return result;
}

int main() {
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
    n = read<int>(), m = read<int>(), k = read<int>();
    for (int i = 0; i <= m; i++)
        v[i] = read<u64>();
    dfs(0, 0, 1);
    printf("%llu\n", ans);
}