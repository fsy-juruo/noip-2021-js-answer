#include <bits/stdc++.h>

using namespace std;

const int maxn = 35;
const int maxm = 105;
const int INF = 998244353;

int n, m, bnd;
int v[maxm], binom[maxn][maxn], f[maxm][maxn][maxn][maxn];

int main(){
  freopen("sequence.in", "r", stdin);
  freopen("sequence.out", "w", stdout);
  
  scanf("%d%d%d", &n, &m, &bnd);
  for(int i = 0; i <= m; ++i)
    scanf("%d", v + i);

  for(int i = 0; i <= n; ++i){
    binom[i][0] = 1;
    for(int j = 1; j <= i; ++j)
      binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1]) % INF;
  }
  
  f[0][0][0][0] = 1;
  for(int j = 0; j <= m; ++j)
    for(int i = 0; i <= n; ++i)
      for(int k = 0; k <= n; ++k)
	for(int l = 0; l <= bnd; ++l)
	  if(f[j][i][k][l]){
	    int pw = 1;
	    for(int i_ = 0; i_ + i <= n; ++i_){
	      (f[j + 1][i + i_][(k + i_) >> 1][l + ((k + i_) & 1)]
		+= 1ll * f[j][i][k][l] * pw % INF * binom[i + i_][i_] % INF) %= INF;
	      pw = 1ll * pw * v[j] % INF;
	    }
	  }

  int ans = 0;
  for(int k = 0; k <= n; ++k){
    int cnt = 0;
    for(int x = k; x; x >>= 1)
      cnt += (x & 1);
    for(int l = 0; l <= bnd - cnt; ++l)
      (ans += f[m + 1][n][k][l]) %= INF;
  }

  printf("%d\n", ans);
  return 0;
}
