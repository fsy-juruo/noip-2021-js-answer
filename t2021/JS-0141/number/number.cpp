
#include <bits/stdc++.h>
using namespace std;
#ifdef _LOCAL_JUDGE
#define eprintf(...) ({ fprintf(stderr, __VA_ARGS__); fflush(stderr); })
#else
#define eprintf(...)
#endif

static constexpr int Maxn = 1.005e7 + 5;

bool bad7[Maxn], bad[Maxn];
int nxt[Maxn];

int main(void) {
  freopen("number.in", "r", stdin);
  freopen("number.out", "w", stdout);

  register int i, j;
  static constexpr int N = 1.005e7;
  memset(bad7, false, sizeof(bad7));
  memset(bad, false, sizeof(bad));
  for (i = 1; i <= N; ++i)
    bad7[i] = (bad7[i / 10] | (i % 10 == 7));
  int c = 0;
  for (i = 1; i <= N; ++i) {
    if (bad7[i]) {
      for (j = 1; j * i <= N; ++j)
        bad[j * i] = true;
    }
  }
  for (i = 1; i <= N; i = j)
    if (!bad[i]) {
      for (j = i + 1; bad[j]; ++j);
      nxt[i] = j;
    }
  
  int tests; scanf("%d", &tests);
  while (tests--) {
    int x; scanf("%d", &x);
    if (bad[x]) {
      printf("%d\n", -1);
    } else {
      printf("%d\n", nxt[x]);
    }
  }

  exit(EXIT_SUCCESS);
} // main

