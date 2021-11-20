#include <bits/stdc++.h>
using namespace std;
template <typename T>
void ri(T& x)
{
    x = 0;
    int flg = 1;
    char c = getchar();
    for (; !isdigit(c) && c != '-'; c = getchar())
        ;
    if (c == '-') {
        flg = -1;
        c = getchar();
    }
    for (; isdigit(c); c = getchar())
        x = x * 10 + c - 48;
    x *= flg;
}
template <typename T, typename... Args>
void ri(T& x, Args&... args)
{
    ri(x), ri(args...);
}
#define FILEIO(x)                        \
    do {                                 \
        freopen(#x ".in", "r", stdin);   \
        freopen(#x ".out", "w", stdout); \
    } while (0)
#define ALL(x) (x).begin(), (x).end()
const int MOD = 998244353;
int madd(int x, int y)
{
    x = x - MOD + y;
    x += (x >> 31) & MOD;
    return x;
}
int mmul(int x, int y)
{
    return int64_t(x) * y % MOD;
}
int qpow(int x, int y)
{
    int res = 1;
    for (; y; y >>= 1) {
        if (y & 1)
            res = mmul(res, x);
        x = mmul(x, x);
    }
    return res;
}
int n, m, q;
int a[1024];
int dp[150][35][35][35];
int C[200][200];

int main()
{
    FILEIO(sequence);
    ri(n, m, q);
    for (int i = 0; i <= m; i++)
        ri(a[i]);
    for (int i = 0; i < 200; i++)
        C[i][0] = 1;
    for (int i = 1; i < 200; i++)
        for (int j = 1; j < 200; j++)
            C[i][j] = madd(C[i - 1][j - 1], C[i - 1][j]);
    dp[0][0][0][0] = -1;
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= q; k++)
                for (int l = 0; l <= n; l++) {
                    if (dp[i][j][k][l] == 0)
                        continue;
                    int cur = dp[i][j][k][l];
                    if (cur == -1)
                        cur = 1;
                    for (int x = 0; x <= n - j; x++) {
                        if (k + (x + l) % 2 > q)
                            continue;
                        int& res = dp[i + 1][j + x][k + (x + l) % 2][(x + l) / 2];
                        res = madd(mmul(mmul(cur, C[j + x][j]), qpow(a[i], x)), res);
                    }
                }
    for (int i = m + 1; i <= m + 10; i++)
        for (int k = 0; k <= q; k++)
            for (int l = 0; l <= n; l++) {
                if (dp[i][n][k][l] == 0)
                    continue;
                int cur = dp[i][n][k][l];
                if (cur == -1)
                    cur = 1;
                if (i > m) {
                    if (k + l % 2 <= q) {
                        int& res = dp[i + 1][n][k + l % 2][l / 2];
                        res = madd(cur, res);
                    }
                }
            }
    int ans = 0;
    for (int i = 0; i <= q; i++)
        ans = madd(ans, dp[m + 11][n][i][0]);
    cout << ans << endl;
    return 0;
}