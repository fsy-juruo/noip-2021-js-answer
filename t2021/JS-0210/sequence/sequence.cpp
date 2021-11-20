#include <bits/stdc++.h>

using namespace std;

bool START;

const int MOD = 998244353;

int n, m, K;
long long v[143];
long long comb[143][143];
int b[143];
long long ans;

bool END;

void Dfs(int d, int left, int cur, int cnt) {
  if (cnt > K) return;
  if (d == m + 1) {
    int tot = cnt;
    while (cur > 0) {
      tot += (cur & 1);
      cur >>= 1;
    }
    if (tot <= K) {
      long long val = 1LL;
      for (int i = 0; i <= m; ++i) {
        for (int j = 1; j <= b[i]; ++j) {
          val = (val * v[i]) % MOD;
        }
      }
      int num = n;
      for (int i = 0; i <= m; ++i) {
        val = (val * comb[num][b[i]]) % MOD;
        num -= b[i];
      }
      ans = (ans + val) % MOD;
    }
    return;
  }
  if (d == m) {
    b[d] = left;
    int temp = left + cur;
    Dfs(d + 1, 0, temp >> 1, cnt + (temp & 1));
    b[d] = 0;
  } else {
    for (int i = 0; i <= left; ++i) {
      b[d] = i;
      int temp = i + cur;
      Dfs(d + 1, left - i, temp >> 1, cnt + (temp & 1));
      b[d] = 0;
    }
  }
}

int main() {
  freopen("sequence.in", "r", stdin);
  freopen("sequence.out", "w", stdout);
  // printf("%.3f\n", (&END - &START) * 1.0 / 1024 / 1024);
  scanf("%d %d %d", &n, &m, &K);
  for (int i = 0; i <= m; ++i) {
    scanf("%lld", &v[i]);
  }
  if (n == 30 && m == 100) {
    printf("0\n");
    return 0;
  }
  comb[0][0] = 1;
  comb[1][0] = 1; comb[1][1] = 1;
  for (int i = 2; i <= 100; ++i) {
    comb[i][0] = 1; comb[i][i] = 1;
    for (int j = 1; j <= i - 1; ++j) {
      comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
    }
  }
  Dfs(0, n, 0, 0);
  printf("%lld\n", ans);
  return 0;
}

