#include <bits/stdc++.h>
using namespace std;

vector<bool> v(10000001);

bool seven(int x) {
  while (x > 0) {
    if (x % 10 == 7) {
      return true;
    } else {
      x /= 10;
    }
  }
  return false;
}

int main() {
  freopen("number.in", "r", stdin);
  freopen("number.out", "w", stdout);
  for (int i = 1; i <= 10000000; i++) {
    if(seven(i)) {
      for (int j = i; j <= 10000000; j += i) {
        v[j] = true;
      }
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    if (v[x]) {
      cout << "-1\n";
    } else {
      do {
        x++;
      } while (v[x]);
      cout << x << endl;
    }
  }
  return 0;
}

