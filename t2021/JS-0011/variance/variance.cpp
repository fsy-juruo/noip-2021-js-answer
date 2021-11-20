#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 5;
const long long INF = 0x3f3f3f3f3f3f3f3f;

mt19937 rnd(2226701);

int n;
int a[maxn], b[maxn];

namespace Solve1{ // bitmask dp
  const int myMaxn = 16;
  const int myMaxs = 505;

  long long f[1 << myMaxn][myMaxs];

  inline void work(){
    int sum = a[n] * n;
    memset(f, 0x3f, sizeof(f));
    f[0][0] = 0;
    for(int S = 0; S < (1 << n); ++S){
      int cnt = 0;
      for(int T = S; T; T >>= 1)
	cnt += (T & 1);
      cnt = n - cnt;
      for(int s = 0; s <= sum; ++s)
	if(f[S][s] < INF){
	  //printf("S = %d s = %d cnt = %d f = %lld\n", S, s, cnt, f[S][s]);
	  for(int i = 0; i < n; ++i)
	    if(!(S >> i & 1) && (i == n - 1 || cnt != n)){
	      long long res = f[S][s] + 1ll * cnt * (n - cnt) * b[i + 1] * b[i + 1] + 2ll * cnt * b[i + 1] * s;
	      f[S ^ (1 << i)][s + (n - cnt) * b[i + 1]] = min(f[S ^ (1 << i)][s + (n - cnt) * b[i + 1]], res);
	    }
	}
    }
    long long ans = INF;
    for(int s = 0; s <= sum; ++s)
      ans = min(ans, f[(1 << n) - 1][s]);
    printf("%lld\n", ans);
    return;
  }
}

inline long long calc(){
  long long ans = 0;
  for(int j = 1; j <= n; ++j){
    ans += 1ll * (n - j) * j * b[j] * b[j];
    for(int k = j + 1; k <= n; ++k)
      ans += 2ll * (n - k) * j * b[j] * b[k];
  }
  return ans;
}

int main(){
  freopen("variance.in", "r", stdin);
  freopen("variance.out", "w", stdout);
  scanf("%d", &n);
  /*
  for(int i = 1; i <= n; ++i)
    scanf("%d", b + i);
  long long ans = 0;
  for(int j = 1; j <= n; ++j){
    ans += 1ll * (n - j) * j * b[j] * b[j];
    for(int k = j + 1; k <= n; ++k)
      ans += 2ll * (n - k) * j * b[j] * b[k];
  }
  printf("%lld\n", ans);

  return 0;
  */
  for(int i = 1; i <= n; ++i)
    scanf("%d", a + i), b[i] = a[i] - a[i - 1];
  reverse(b + 1, b + n + 1);

  if(n == 1){
    puts("0");
    return 0;
  }
  
  if(n <= 15 && n * a[n] <= 400)
    Solve1::work();
  else{
    long long cur = calc(), ans = cur;
    for(double T = 1.0; T > 1e-9; T *= 0.999){
      int p = rnd() % (n - 1), q;
      for(q = rnd() % (n - 1); q == p; q = rnd() % (n - 1));
      ++p, ++q;
      swap(b[p], b[q]);
      long long dlt = calc() - cur;
      if(exp(-dlt / T) > 1.0 * (rnd() % 1000000000) / 1000000000)
	cur += dlt, ans = min(ans, cur);
      else
	swap(b[p], b[q]);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
