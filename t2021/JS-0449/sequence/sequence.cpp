#include<bits/stdc++.h>
using namespace std;
const int N = 105, mod = 998244353;
int n, m, k, ans, val[105];
int ones[1 << 13], fac[15], s[15], h[15];
inline void work(int sum){
	int sta = 0, cnt = fac[n];
	memset(h, 0, sizeof h);
	for (int i = 1; i <= n; ++i){
		++h[s[i]];
		sta += 1 << s[i];
	}
	if (ones[sta] > k) return;
	for (int i = 0; i <= m; ++i) cnt /= fac[h[i]];
	ans = (ans + 1ll * cnt * sum % mod) % mod;
}
void dfs(int u, int last, int sum){
	if (u > n){
		work(sum); return;
	}
	for (int i = last; i <= m; ++i){
		s[u] = i;
		dfs(u + 1, i, 1ll * sum * val[i] % mod);
	}
}
int main(){
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	fac[0] = 1;
	for (int i = 1; i <= 13; ++i)
		fac[i] = fac[i - 1] * i;
	for (int i = 1; i < 1 << 13; ++i)
		ones[i] = ones[i - (i & -i)] + 1;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i <= m; ++i)
		scanf("%d", val + i);
	if (n <= 8 && m <= 9){
		dfs(1, 0, 1);
		printf("%d\n", ans);
	}
	return 0;
}

