
#include <bits/stdc++.h>
using namespace std;
#ifdef _LOCAL_JUDGE
#define eprintf(...) ({ fprintf(stderr, __VA_ARGS__); fflush(stderr); })
#else
#define eprintf(...)
#endif
template<typename _Tp> _Tp &min_eq(_Tp &x, _Tp y) { return x = min(x, y); }

int ans = 1e9;
int get_variance(vector<int> x) {
  int n = (int)x.size();
  int s = 0;
  for (int &v: x) s += v;
  for (int &v: x) v *= n;
  int p = 0;
  for (int &v: x) p += (v - s) * (v - s);
  return p / n;
} // get_variance
bool mp[20000000];
int B = (1 << 24) - 1;
int get_hash(const vector<int> &v) {
  int x = 0;
  for (const int &i: v) x = ((x * 41 + i) & B);
  return x;
}
void dfs(vector<int> x) {
  int P = get_hash(x);
  if (mp[P]) return ;
  mp[P] = true;
  min_eq(ans, get_variance(x));
  for (int i = 1; i < (int)x.size() - 1; ++i) {
    x[i] = x[i - 1] + x[i + 1] - x[i];
    dfs(x);
    x[i] = x[i - 1] + x[i + 1] - x[i];
  }
}
void dfs2(vector<int> x) {
  int P = get_variance(x);
  if (mp[P]) return ;
  mp[P] = true;
  min_eq(ans, P);
  for (int i = 1; i < (int)x.size() - 1; ++i) {
    x[i] = x[i - 1] + x[i + 1] - x[i];
    dfs2(x);
    x[i] = x[i - 1] + x[i + 1] - x[i];
  }
}

int main(void) {
  freopen("variance.in", "r", stdin);
  freopen("variance.out", "w", stdout);

  int n; scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  if (n <= 10) {
    dfs(a);
    printf("%d\n", ans);
  } else {
    dfs2(a);
    printf("%d\n", ans);
  }

  exit(EXIT_SUCCESS);
} // main

