#include <bits/stdc++.h>
using namespace std;

int calc(deque<int> v) {
  int a = 0, b = 0;
  for (int i = 0; i < v.size(); i++) {
    a += v[i];
    b += v[i] * v[i];
  }
  return v.size() * b - a * a;
}

int main() {
  freopen("variance.in", "r", stdin);
  freopen("variance.out", "w", stdout);
  int n, a;
  cin >> n >> a;
  vector<int> b(--n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    b[i] -= a;
    a += b[i];
  }
  sort(b.begin(), b.end());
  int ans = INT_MAX;
  for (int i = 0; i < 1 << n; i++) {
    deque<int> d(1);
    for (int j = 0; j < n; j++) {
      if ((i & (1 << j)) == 0) {
        d.push_front(d.front() - b[j]);
      } else {
        d.push_back(d.back() + b[j]);
      }
    }
    ans = min(ans, calc(d));
  }
  cout << ans << endl;
  return 0;
}

