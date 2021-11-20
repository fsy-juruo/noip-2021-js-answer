#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 35
#define maxm 105
const ll mod = 998244353;

int n, m, k;
ll powv[maxm][maxn], c[maxn][maxn], f[maxm][maxn][maxn][17];

int main() {
  freopen("sequence.in", "r", stdin);
  freopen("sequence.out", "w", stdout);
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i <= m; i++) {
    scanf("%lld", &powv[i][1]);
    powv[i][0] = 1;
  }
  for (int i = 0; i <= m; i++) {
    for (int j = 2; j <= n; j++) {
      powv[i][j] = powv[i][j - 1] * powv[i][1] % mod;
    }
  }
  c[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
  }
  for (int i = 0; i <= n; i++) {
    f[0][i][i & 1][i >> 1] = powv[0][i];
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j <= n; j++) {
      for (int cnt = 0; cnt <= k; cnt++) {
        for (int msk = 0; msk < 16; msk++) {
          for (int t = 0; j + t <= n; t++) {
            int a = msk + t;
            (f[i + 1][j + t][cnt + (a & 1)][a >> 1] += f[i][j][cnt][msk] * c[j + t][t] % mod 
                                                        * powv[i + 1][t]) %= mod;
          }
        }
      }
    }
  }
  ll ans = 0;
  for (int cnt = 0; cnt <= k; cnt++) {
    for (int msk = 0; msk < 16; msk++) {
      if (cnt + __builtin_popcount(msk) <= k)
        (ans += f[m][n][cnt][msk]) %= mod;
    }
  }
  printf("%lld\n", (ans + mod) % mod);
  return 0;
}
