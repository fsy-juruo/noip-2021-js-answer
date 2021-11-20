#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int k, ans;
void dfs(int n, int m, int s, long long v) {
  if (n == 0) {
    if (__builtin_popcount(s) <= k) {
      ans = (ans + v) % 998244353;
    }
  } else {
    for (int i = 0; i <= m; i++) {
      dfs(n - 1, m, s + (1 << i), v * a[i] % 998244353);
    }
  }
}

int main() {
  freopen("sequence.in", "r", stdin);
  freopen("sequence.out", "w", stdout);
  int n, m;
  cin >> n >> m >> k;
  a.resize(++m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  dfs(n, m - 1, 0, 1ll);
  cout << ans << endl;
  return 0;
}

