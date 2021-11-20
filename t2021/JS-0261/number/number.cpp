#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
#ifdef LILYWHITE
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) ;
#endif
using namespace std;
template <typename T>
inline T rd(T &x) {
  T neg = 1;
  x = 0;
  char c = 0;
  while (c < '0' || c > '9') {
    c = getchar();
    if (c == '-') neg = -1;
  }
  while (c >= '0' && c <= '9'){
    x = x * 10 + c - '0';
    c = getchar();
  }
  x *= neg;
  return x;
}
const int N = 10000010;
bool a[N + 10], has_seven[N + 10];
inline bool seven(int x) {
  if (x % 7 == 0) return false;
  while (x) {
    if (x % 10 == 7) return false;
    x /= 10;
  }
  return true;
}
int tot = 0, tbl[N + 10], nxt[N + 10];
void init() {
  for (int i = 7; i <= N; i++) if (!seven(i)) has_seven[i] = true;
  for (int i = 7; i <= N; i++) {
    if (has_seven[i]) {
      for (int j = i; j <= N; j += i) {
        a[j] = true;
      }
    } 
  }
  for (int i = 1; i <= N; i++) if (!a[i]) {
    tbl[++tot] = i;
    nxt[tbl[tot - 1]] = i;
  }
}
int main() {
#ifndef LILYWHITE
  freopen("number.in", "r", stdin);
  freopen("number.out", "w", stdout);
#endif
//  freopen("numtable.txt", "w", stdout);
  init();
  int T; rd(T);
  while (T--) {
    int x; rd(x); if (a[x]) puts("-1"); else printf("%d\n", nxt[x]);
  }
  return 0;
}

