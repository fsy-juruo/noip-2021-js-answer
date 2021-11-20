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

#define maxn 55
int n, a[maxn], b[maxn], ans;

int calc() {
  int sum = 0, cur = 0, res = 0;
  for (int i = 0; i < n; i++) {
    res += cur * cur;
    sum += cur;
    cur += b[i];
  }
  return res * n - sum * sum;
}

int main() {
  freopen("variance.in", "r", stdin);
  freopen("variance.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a + i);
  if (n == 1) {
    puts("0");
    return 0;
  }
  for (int i = 0; i < n - 1; i++) {
    a[i] = a[i + 1] - a[i];
  }
  sort(a, a + n - 1, greater<int>());
  ans = INF;
  for (int S = 0; S < (1 << (n - 2)); S++) {
    int k = 0;
    for (int i = 0; i < n - 2; i++) {
      if (S >> i & 1)
        b[k++] = a[i];
    }
    b[k++] = a[n - 2];
    for (int i = n - 3; i >= 0; i--) {
      if (!(S >> i & 1))
        b[k++] = a[i];
    }
    chmin(ans, calc());
  }
  printf("%d\n", ans);
  return 0;
}

