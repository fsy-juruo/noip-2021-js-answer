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
const int MAXN = 1.1e5;
vector<vector<int64_t>> dp[MAXN];
vector<vector<int>> pre[MAXN];
int main()
{
    FILEIO(variance);
    int n;
    ri(n);
    vector<int> a(n);
    for (auto& i : a)
        ri(i);
    vector<int> d(n - 1);
    for (int i = 0; i < n - 1; i++) {
        d[i] = a[i + 1] - a[i];
    }
    if (n > 21) {
        int lim = *max_element(ALL(a)) - a[0] + 3;
        for (int i = 0; i < n; i++)
            dp[i].resize(lim, vector<int64_t>(lim, 1e18)), pre[i].resize(lim, vector<int>(lim, 0));
        dp[0][0][0] = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < lim; j++)
                for (int k = 0; k < lim; k++) {
                    if (dp[i][j][k] == 1e18)
                        continue;
                    if (j + d[i] < lim) {
                        int t = (i & 1) * i * abs(k - j - d[i]);
                        if (dp[i + 1][j + d[i]][k] > dp[i][j][k] + t) {
                            dp[i + 1][j + d[i]][k] = dp[i][j][k] + t;
                            pre[i + 1][j + d[i]][k] = 1;
                        }
                    }
                    if (k + d[i] < lim) {
                        int t = (i & 1) * i * abs(k - j + d[i]);
                        if (dp[i + 1][j][k + d[i]] > dp[i][j][k] + t) {
                            dp[i + 1][j][k + d[i]] = dp[i][j][k] + t;
                            pre[i + 1][j][k + d[i]] = -1;
                        }
                    }
                    // cerr << i << " " << j << " " << k << endl;
                }
        }
        int p = 0, q = 0;
        for (int j = 0; j < lim; j++)
            for (int k = 0; k < lim; k++) {
                // cout << dp[n - 1][j][k] << endl;
                if (dp[n - 1][j][k] < dp[n - 1][p][q]) {
                    p = j, q = k;
                }
            }
        deque<int> b;
        int k = n - 1;
        while (k != 0) {
            if (pre[k][p][q] == 1)
                b.push_back(d[k - 1]), p -= d[k - 1];
            else
                b.push_front(d[k - 1]), q -= d[k - 1];
            // cerr << k << " " << p << " " << q << endl;
            k--;
        }
        int64_t ans = 0;
        for (int i = 0; i < n; i++) {
            int64_t tmp = 0;
            for (int j = 0; j < n - 1; j++) {
                if (j >= i)
                    tmp += (j + 1 - n) * b[j];
                else
                    tmp += (j + 1) * b[j];
            }
            ans += tmp * tmp;
        }
        cout << ans / n << endl;
        return 0;
    }
    sort(ALL(d));
    int64_t ans = 1e18;
    // vector<int> ansV;
    for (int mask = 0; mask < (1 << (n - 1)); mask++) {
        deque<int> b;
        for (int i = 0; i < n - 1; i++)
            if (mask & (1 << i)) {
                b.push_back(d[i]);
            } else {
                b.push_front(d[i]);
            }
        int64_t res = 0;
        for (int i = 0; i < n; i++) {
            int64_t tmp = 0;
            for (int j = 0; j < n - 1; j++) {
                if (j >= i)
                    tmp += (j + 1 - n) * b[j];
                else
                    tmp += (j + 1) * b[j];
            }
            res += tmp * tmp;
        }
        if (ans > res) {
            ans = res;
            // ansV = vector<int>(b.begin(), b.end());
        }
    }
    cout << ans / n << endl;
    return 0;
}