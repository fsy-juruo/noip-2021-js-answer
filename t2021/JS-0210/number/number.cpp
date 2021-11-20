#include <bits/stdc++.h>

using namespace std;

bool START;

int T;
int mark[10000043];
int pre[10000043];

bool END;

int Read() {
  char ch = getchar();
  int x = 0, w = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') {
      w = -1;
    }
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * w;
}

void Prepare() {
  for (int i = 1; i <= 10000000; ++i) {
    if (mark[i] == 1) continue;
    int x = i;
    bool flag = false;
    while (x > 0) {
      if (x % 10 == 7) {
        flag = true;
        break;
      }
      x /= 10;
    }
    if (flag) {
      for (int j = i; j <= 10000000; j += i) {
        mark[j] = true;
      }
    }
  }
  for (int i = 1; i <= 10000000; ++i) {
    pre[i] = pre[i - 1] + mark[i];
  }
}

int main() {
  freopen("number.in", "r", stdin);
  freopen("number.out", "w", stdout);
  // printf("%.3f\n", (&END - &START) * 1.0 / 1024 / 1024);
  Prepare();
  T = Read();
  while (T--) {
    int x = Read();
    if (mark[x] == 1) {
      printf("-1\n");
    } else {
      int low = x + 1, high = 10000000, ans = 10000001;
      while (low <= high) {
        int mid = (low + high) >> 1;
        if (mid - x > pre[mid] - pre[x]) {
          ans = mid;
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}

