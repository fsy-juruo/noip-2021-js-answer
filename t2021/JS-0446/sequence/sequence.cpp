#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 30 + 3, M = 100 + 3, Mod = 998244353;
ll n = 0, m = 0, k = 0, v[M] = {}, pwv[M][N] = {};
ll dp[M][N][N][N] = {}, C[N][N] = {}, ans = 0;

ll cnt(ll x){
	ll res = 0;
	while(x){
		if(x & 1) res ++;
		x >>= 1;
	}
	return res;
}

int main(){
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	scanf("%lld %lld %lld", &n, &m, &k);
	for(ll i = 0 ; i <= m ; ++ i) scanf("%lld", &v[i]);
	for(ll i = 0 ; i <= n ; ++ i){
		C[0][i] = 1;
		for(ll j = 1 ; j <= i ; ++ j) C[j][i] = (C[j - 1][i - 1] + C[j][i - 1]) % Mod;
	}
	for(ll i = 0 ; i <= m ; ++ i){
		pwv[i][0] = 1;
		for(ll j = 1 ; j <= n ; ++ j) pwv[i][j] = pwv[i][j - 1] * v[i] % Mod;
	}
	dp[0][0][0][0] = 1;
	for(ll i = 0 ; i <= m ; ++ i) for(ll j = 0 ; j <= n ; ++ j) for(ll p = 0 ; p <= k ; ++ p) for(ll q = 0 ; q <= n ; ++ q) for(ll d = 0 ; j + d <= n ; ++ d){
		dp[i + 1][j + d][p + (d + q) % 2][(d + q) / 2] += dp[i][j][p][q] * pwv[i][d] % Mod * C[d][j + d];
		dp[i + 1][j + d][p + (d + q) % 2][(d + q) / 2] %= Mod;
	}
	for(ll p = 0 ; p <= k ; p ++) for(ll q = 0 ; q <= n ; q ++) if(p + cnt(q) <= k) ans = (ans + dp[m + 1][n][p][q]) % Mod;
	printf("%lld", ans);
	return 0;
}

