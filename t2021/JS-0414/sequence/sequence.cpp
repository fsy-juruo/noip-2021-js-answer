#include <bits/stdc++.h>

using llt = long long;

constexpr int N = 35, M = 105;
constexpr llt P = 998244353LL;

int n, m, mx;
llt v[M];
llt f[M][N][N][N];

llt fct[N];

llt kypow(llt x, llt y) {
    x %= P;
    llt r = 1;
    while (y > 0) {
        if (y & 1) {
            r *= x; r %= P;
        }
        x *= x; x %= P;
        y >>= 1;
    }
    return r % P;
}

llt comb(int x, int y) {
    return fct[x] * kypow(fct[y], P - 2) % P * kypow(fct[x - y], P - 2) % P;
}

int main(void) {
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
    
    fct[0] = 1;
    for (int i = 1; i < N; ++i) {
        fct[i] = fct[i - 1] * i; fct[i] %= P;
    }
    
    scanf("%d%d%d", &n, &m, &mx);
    for (int i = 0; i <= m; ++i) {
        scanf("%lld", &v[i]);
    }
    
    memset(f, 0, sizeof(f));
    for (int j = 0; j <= n; ++j) {
        f[0][j][j][0] = kypow(v[0], j);
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int num = 0; j + num <= n; ++num) {
                for (int t = 0; t <= n; ++t) {
                    for (int p = 0; p <= n; ++p) {
                        f[i + 1][j + num][t / 2 + num][p + (t % 2)]
                          += f[i][j][t][p] * kypow(v[i + 1], num) % P * comb(j + num, num) % P;
                        f[i + 1][j + num][t / 2 + num][p + (t % 2)] %= P;
                    }
                }
            }
        }
    }
    llt ans = 0;
    for (int t = 0; t <= n; ++t) {
        for (int p = 0; p <= n; ++p) {
            int tot = p, tt = t;
            while (tt > 0) {
                tot += (tt & 1);
                tt >>= 1;
            }
            if (tot <= mx) {
                ans += f[m][n][t][p];
                ans %= P;
            }
        }
    }
    printf("%lld\n", ans);
    
    return 0;
}

