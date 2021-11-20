#include <bits/stdc++.h>

#define int long long
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
#ifdef LILYWHITE
#define eprintf(...) ;//fprintf(stderr, __VA_ARGS__)
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
int n, m, k;
const int N = 110;
int v[N];
const int mod = 998244353;
// returns the number of permutaion generated using $vec
inline ll qpow(ll a, ll b, ll p = mod) 
{
  ll ans = 1;
  for (; b; b >>= 1) {
    if (b & 1) ans = ans * a % p;
    a = a * a % p;
  }
  return ans;
}
int factorial[N];

namespace bf {
int ans = 0;
vector<int> vec;ll calc() {
  vector<int> cnt(m + 1, 0);
  for (auto x: vec) {
 //   eprintf("Reimu %lld\n", x);
    cnt[x]++;
 //   eprintf("%lld\n", cnt[x]);
  }
  ll ans = factorial[n];
 // eprintf("%lld\n", ans);
  for (auto x: cnt) {
    if (x > 1) {
      ans = ans * qpow(factorial[x], mod - 2, mod) % mod;
    }
  }
  return ans;
}

bool check() {
  ll res = 0;
  for (auto x: vec) res += (1LL << x);
  return __builtin_popcountll(res) <= k;
}


void dfs(int dep) {
 // eprintf("%lld\n", dep);
 // for (auto x : vec) eprintf("%lld ", x); eprintf("\n");
  if (dep == n + 1) {
    if (check()) {
    //  eprintf("Lily! ");
   //   for (auto x : vec) eprintf("%lld ", x); eprintf("\n");
      int num = calc();
    //  eprintf("num = %lld\n", num);
      int val = 1;
      for (auto x: vec) val = val * v[x] % mod;
      val = val * num % mod;
      ans += val;
      ans %= mod;
    }
    return;
  }
  for (int i = vec.back(); i <= m; i++) {
    vec.push_back(i);
    dfs(dep + 1);
    vec.pop_back();
  }
}

void solve() {
  for (int i = 0; i <= m; i++) {
    vec.clear();
    vec.push_back(i);
    dfs(2);
  }
  printf("%lld\n", ans);
}
}

signed
main() {
#ifndef LILYWHITE
  freopen("sequence.in", "r", stdin);
  freopen("sequence.out", "w", stdout);
#endif                    
  rd(n); rd(m); rd(k);
  factorial[0] = factorial[1] = 1;
  for (int i = 2; i <= n; i++)
    factorial[i] = (factorial[i - 1] * i) % mod; 
  for (int i = 0; i <= m; i++) {
    rd(v[i]);
  }
  bf::solve();
  return 0;
}

