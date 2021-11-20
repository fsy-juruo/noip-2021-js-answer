#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

template <typename T>
void input(T& num) {
    num = 0;
    T sign = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') sign = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        num = num * 10 + ch - '0';
        ch = getchar();
    }
    num *= sign;
}

const int maxb = 200;
typedef bitset<maxb> bits;
const int maxm = 105;
const i64 mod = 998244353;
int n, m, k, t;
int v[maxm];
i64 fac, ans;

bool operator<=(const bits& a, const bits& b) {
    for (int i = maxb - 1; i >= 0; --i)
        if (a[i] ^ b[i]) return b[i];
    return true;
}

bits operator+(const bits& a, const bits& b) {
    vector<int> vec;
    vec.resize(maxb, 0);
    for (int i = 0; i < maxb; ++i) vec[i] += a[i] + b[i];
    for (int i = 0; i < maxb; ++i) {
        if (vec[i] == 2) {
            vec[i] = 0;
            if (i < maxb - 1) ++vec[i + 1];
        }
    }
    bits res;
    for (int i = 0; i < maxb; ++i) res[i] = vec[i];
    return res;
}

i64 qpow(i64 a, i64 b) {
    i64 ans = 1;
    while (b > 0) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

void dfs1(int dep, int minbit, int tmp, i64 mul, i64 cnt, bits sum,
          const bits& sta) {
    if (dep > n) return;
    if (sum == sta) {
        ans = (ans + mul * cnt % mod) % mod;
        return;
    }
    for (int i = minbit; sum + bits(1 << i) <= sum; ++i)
        dfs1(dep + 1, i, i == minbit ? tmp + 1 : 1, mul * v[i] % mod,
             cnt * qpow(tmp, mod - 2), sum + bits(1 << i), sta);
}

void dfs2(int dep, bits sta) {
    if ((int)sta.count() > k) return;
    if (dep == t) {
        dfs1(0, 0, 1, 1, fac, 0, sta);
        return;
    }
    dfs2(dep + 1, sta);
    dfs2(dep + 1, sta | bits(1 << dep));
}

int main() {
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
    input(n);
    input(m);
    input(k);
    for (int i = 0; i <= m; ++i) input(v[i]);
    while (1 << (t + 1) <= n) ++t;
    t += m;
    for (int i = 1; i <= k; ++i) fac = fac * i % mod;
    dfs2(0, 0);
    cout << ans << endl;
    return 0;
}
