#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int LIM = 10000005;

bool have7(int x) {
  while (x) {
    if (x % 10 == 7)
      return true;
    x /= 10;
  }
  return false;
}

bool bad[LIM + 5];
int nxt[LIM + 5];

int main() {
  freopen("number.in", "r", stdin);
  freopen("number.out", "w", stdout);
  for (int i = 1; i <= 10000000; i++) {
    if (have7(i)) {
      for (int j = i; j <= LIM; j += i) {
        bad[j] = true;
      }
    }
  }
  nxt[10000000] = 10000001;
  for (int i = 9999999; i >= 1; i--) {
    nxt[i] = bad[i + 1] ? nxt[i + 1] : i + 1;
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int x;
    scanf("%d", &x);
    printf("%d\n", bad[x] ? -1 : nxt[x]); 
  }
  return 0;
}

