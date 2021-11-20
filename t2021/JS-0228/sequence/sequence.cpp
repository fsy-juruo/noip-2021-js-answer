#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
#define mp make_pair
typedef long long ll;
template <class T>
T read(T& x) {
	x = 0; T sign = 1, ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') { sign = -1, ch = getchar(); }
	while(isdigit(ch)) {
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	x *= sign;
	return x;
}
int popcount(int x) {
	int cnt = 0;
	while(x) { cnt += (x & 1); x >>= 1; }
	return cnt;
}
// long long !!!!!
const ll MOD = 998244353;
const ll N = 40, M = 40, VAL = 200010;
ll n, m, k, v[M], f[N][VAL], ans = 0;
int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	read(n); read(m); read(k);
	for(ll i = 0; i <= m; i ++ ) read(v[i]);
	for(ll i = 0; i <= m; i ++ ) f[1][1 << i] = v[i];
	for(ll i = 2; i <= n; i ++ )
		for(ll j = 0; j <= n * (1 << m) + 10; j ++ )
			for(ll k = 0; (1 << k) <= j && k <= m; k ++ )
				f[i][j] = (f[i][j] + f[i - 1][j - (1 << k)] * v[k]) % MOD;
	for(ll i = n; i <= n * (1 << m); i ++ )
		if(popcount(i) <= k) ans = (ans + f[n][i]) % MOD;
	printf("%lld\n", ans);
	return 0;
}

