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
const int N = 10100;
int a[N], b[N];
#define sqr(x) ((x) * (x))
int main() {
#ifndef LILYWHITE
  freopen("variance.in", "r", stdin);
  freopen("variance.out", "w", stdout);
#endif
  int n; rd(n);
  repn(i, n) {
    rd(a[i]);
    b[i] = a[i];
  }
  int sum = 0;
  repn(i, n) sum += a[i];
  int hdc = sum;
  while (true) {
    bool br = false;
    double best = 1e9;
    int besti = -1;
    for (int i = 2; i <= n - 1; i++) {
      if (a[i - 1] + a[i + 1] - a[i] != a[i]) {
        br = true;
        int nai = a[i - 1] + a[i + 1] - a[i];
        double avg = sum * 1.0 / n, navg = (sum - a[i] + nai) * 1.0 / n;
        double dV = (navg * navg - avg * avg) * (n - 1) - 2 * (navg - avg) * (sum - a[i]);
        dV += sqr(navg - nai) - sqr(avg - a[i]);
        if (dV < best) {
          best = dV;
          besti = i;
        }
      }
    }
  //  cerr << "best: " << best << endl;
    if (!br) break;
    if (best > 0) break;
    int i = besti;
    sum += (a[i - 1] + a[i + 1] - 2 * a[i]);
    a[i] = a[i - 1] + a[i + 1] - a[i];
  }
  double ans = 0;
  sum = 0; repn(i, n) sum += a[i];
  repn(i, n) {
    ans += n * (a[i] - 1.0 * sum / n) * (a[i] - 1.0 * sum / n);
  }
 // eprintf("[%d", a[1]);
 // repn(i, n) if (i > 1)eprintf(",%d", a[i]); eprintf("]\n");
  cout << ans << endl;
  return 0;
}
/*
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
const int N = 404;
int a[N];
long double dp[N][N][3];
int n;
#define sqr(x) ((x) * (x))
int main() {
#ifndef LILYWHITE
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
#endif
  rd(n);
  repn(i, n) rd(a[i]);
  repn(i, n) repn(j, n) {
    dp[i][j][0] = 1e9;
    dp[i][j][1] = 0;
  }
  
  repn(i, n) {
    dp[i][i][0] = 0;
    dp[i][i][1] = dp[i][i][2] = a[i];
  }
  
  repn(i, n) {
    for (int j = i + 1; j <= n; j++) {
      dp[i][j][1] = dp[i][j - 1][1] + a[j];
    }
  }
  for (int len = 2; len <= n; len++) {
    for (int l = 1; l + len - 1 <= n; l++) {
      int r = l + len - 1;
      // r-1 -> r, no change
      long double sum = dp[l][r - 1][1], D = dp[l][r - 1][0];
      long double avg = (long double)sum / (len - 1);
      long double navg = (long double)(sum + a[r]) / (len);
      long double nD = D + (len - 1) * (sqr(navg) - sqr(avg)) - 2 * sum * (navg - avg);
      nD += sqr(a[r] - navg);
      cerr << 1 << ' ' << l << ' ' << r << ' ' << nD << endl;
      if (nD < dp[l][r][0]) {
        dp[l][r][0] = nD;
        dp[l][r][1] = sum + a[r];
      }
      // r-1 -> r, change
      if (r + 1 <= n) {
         
         int nar = (dp[l][r - 1][1] - dp[l][r - 2][1] + 
                    dp[l][r + 1][1] - dp[l][r][1] - 
                    (dp[l][r][1] - dp[l][r - 1][1]));
         navg = (long double)(sum + nar) / len;
         nD = D + (len - 1) * (sqr(navg) - sqr(avg)) - 2 * sum * (navg - avg);
         nD += sqr(nar - navg);
         if (nD < dp[l][r][0]) {
           dp[l][r][0] = nD;
           dp[l][r][1] = sum + nar;
         }
      }
      // l+1 -> l, no change
      sum = dp[l + 1][r][1], D = dp[l + 1][r][0];
      avg = (long double)(sum) / (len - 1);
      navg = (long double)(sum + a[l]) / len;
      nD = D + (len - 1) * (sqr(navg) - sqr(avg)) - 2 * sum * (navg - avg);
      nD += sqr(a[l] - navg);
      if (nD < dp[l][r][0]) {
        dp[l][r][0] = nD;
        dp[l][r][1] = sum + a[l];
      }
      // l+1 -> l, change
      if (l - 1 >= 1) {
        int nar = (dp[l - 1][r][1] - dp[l][r][1]
                 + dp[l + 1][r][1] - dp[l + 2][r][1]
                 - (dp[l][r][1] - dp[l + 1][r][1]));
        navg = (long double)(sum + nar) / len;
        nD = D + (len - 1) * (sqr(navg) - sqr(avg)) - 2 * sum * (navg - avg);
        nD += sqr(nar - navg);
        if (nD < dp[l][r][0]) {
          dp[l][r][0] = nD;
          dp[l][r][1] = sum + nar;
        }
      }
    }
  }
  cout << dp[1][n][0] * n << endl;
  return 0;
}
*/
