#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 35;
const int MAXM = 105;
const int MAXS = 1 << 5;
const int MOD = 998244353;

int n, m, K, v[MAXM], f[MAXM][MAXN][MAXN][MAXS], C[MAXN][MAXN];

void addmod(int &x, const int y) {
    x += y; if (x >= MOD) x -= MOD;
}

int add(int x, const int y) {
    addmod(x, y); return x;
}


int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w",stdout);
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 0; i <= m; i++) scanf("%d", &v[i]);
    C[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
    }
    for (int i = 0; i <= m; i++) {
        for (int j = 1, t = v[i]; j <= n; j++, t = (ll)t * v[i] % MOD) {
            int x = __builtin_popcount(j);
            f[i][j][x][j] = (ll)t * C[n][j] % MOD;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= n; k++) {
                for (int S = 0; S < 32; S++) {
                    if (f[i][j][k][S] == 0) continue;
                    for (int p = 0, t = 1; p + j <= n; p++, t = (ll)t * v[i + 1] % MOD) {
                        int T = p + (S >> 1); if (T >= 32) continue;
                        int nk = k - __builtin_popcount(S >> 1) + __builtin_popcount(T);
                        addmod(f[i + 1][j + p][nk][T], (ll)f[i][j][k][S] * t % MOD * C[n - j][p] % MOD);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int k = 1; k <= K; k++)
        for (int S = 0; S < 32; S++)
            addmod(ans, f[m][n][k][S]);
    printf("%d\n", ans);
	return 0;
} 
