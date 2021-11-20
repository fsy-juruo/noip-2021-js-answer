
#include <bits/stdc++.h>
using namespace std;
#ifdef _LOCAL_JUDGE
#define eprintf(...) ({ fprintf(stderr, __VA_ARGS__); fflush(stderr); })
#else
#define eprintf(...)
#endif

static constexpr int mod = 998244353;
inline int add(int x, int y) { return (x += y) >= mod ? x - mod : x; }
inline int mul(int x, int y) { return (long long)x * y - (long long)x * y / mod * mod; }
inline int &add_eq(int &x, int y) { return x = add(x, y); }
inline int &mul_eq(int &x, int y) { return x = mul(x, y); }
inline int qpow(int x, int y) {
  int r = 1;
  for (; y; y >>= 1, mul_eq(x, x))
    (y & 1) && mul_eq(r, x);
  return r;
}

static constexpr int Maxn = 32, Maxm = 105;

int n, m, K;
int w[Maxm];
int f[2][Maxm][Maxn][Maxn][Maxn];

int popcnt[100001];
inline int popcount(int x) {
  return popcnt[x & 65535] + popcnt[x >> 16];
} // popcount

int main(void) {
  freopen("sequence.in", "r", stdin);
  freopen("sequence.out", "w", stdout);
  
  register int i, j, k, l, ll, jj, nc, nk, nl, nll, coef, bm;
  for (int i = 1; i <= 100000; ++i)
    popcnt[i] = popcnt[i ^ (i & -i)] + 1;
  static int inv[10000];
  for (int i = 1; i < 10000; ++i) inv[i] = qpow(i, mod - 2);
  scanf("%d%d%d", &n, &m, &K);
  for (int i = 0; i <= m; ++i) scanf("%d", &w[i]);
  memset(f, 0, sizeof(f));
  f[0][0][0][0][0] = 1;
  for (i = 0; i < n; ++i) {
    memset(f[i & 1 ^ 1], 0, sizeof(f[i & 1 ^ 1]));
    for (j = 0; j <= m; ++j)
      for (k = 0; k <= i; ++k) for (l = 0; l <= i; ++l) for (ll = 0; ll <= l; ++ll) {
        if (f[i & 1][j][k][l][ll]) {
          for (jj = j; jj <= m; ++jj) {
            bm = (jj - j >= 10 ? l : (((1 << jj - j) - 1) & l));
            nl = (jj - j >= 10 ? 0 : (l >> jj - j)) + 1;
            nc = popcnt[bm & 65535] + popcnt[bm >> 16];
            nk = nc + k; nll = (j == jj ? ll + 1 : 1);
            coef = mul(n - i, inv[nll]);
            add_eq(f[i & 1 ^ 1][jj][nk][nl][nll], mul(mul(f[i & 1][j][k][l][ll], w[jj]), coef));
          }
        }
      }
  }
  int ans = 0;
  for (int j = 0; j <= m; ++j)
    for (int k = 0; k <= K; ++k)
      for (int l = 0; l <= n; ++l)
        if (popcount(l) + k <= K)
          for (int ll = 0; ll <= l; ++ll)
            add_eq(ans, f[n & 1][j][k][l][ll]);
  printf("%d\n", ans);
  eprintf("ans = %d\n", ans);

  exit(EXIT_SUCCESS);
} // main

