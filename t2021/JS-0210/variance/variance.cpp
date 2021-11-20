#include <bits/stdc++.h>

using namespace std;

bool START;

int n;
long long a[10043];
long long b[10043];
long long ans;

bool END;

void Update() {
  long long sum = 0, cur = 0;
  for (int i = 1; i <= n; ++i) {
    cur += n * b[i] * b[i];
    sum += b[i];
  }
  ans = min(ans, cur - sum * sum);
}

int main() {
  freopen("variance.in", "r", stdin);
  freopen("variance.out", "w", stdout);
  // printf("%.3f\n", (&END - &START) * 1.0 / 1024 / 1024);
  scanf("%d", &n);
  long long sum = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
    ans += n * a[i] * a[i];
    sum += a[i];
  }
  ans -= sum * sum;
  if (n == 1 || n == 2) {
    printf("%lld\n", ans);
  } else if (n == 3) {
    for (int i = 1; i <= n; ++i) {
      b[i] = a[i];
    }
    b[2] = b[1] + b[3] - b[2];
    Update();
    printf("%lld\n", ans);
  } else if (n == 4) {
    for (int i = 1; i <= n; ++i) {
      b[i] = a[i];
    }
    for (int i = 1; i <= 100000; ++i) {
      if (i % 2 == 1) {
        b[2] = b[1] + b[3] - b[2];
        Update();
      } else {
        b[3] = b[2] + b[4] - b[3];
        Update();
      }
    }
    for (int i = 1; i <= n; ++i) {
      b[i] = a[i];
    }
    for (int i = 1; i <= 100000; ++i) {
      if (i % 2 == 1) {
        b[3] = b[2] + b[4] - b[3];
        Update();
      } else {
        b[2] = b[1] + b[3] - b[2];
        Update();
      }
    }
    printf("%lld\n", ans);
  } else {
    printf("%lld\n", ans);
  }
  return 0;
}

