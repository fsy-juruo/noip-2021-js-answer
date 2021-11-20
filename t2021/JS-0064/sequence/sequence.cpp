#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MN = 35 , MM = 105 , mod = 998244353;

int N , M , K , pw[MM][MN] , dp[MM][MN][MN][MN] , inv[MM] , bits[MM] , val[MM];

inline void inc(int &x , int y) {
	x = x + y < mod ? x + y : x + y - mod;
}
inline void dec(int &x , int y) {
	x = x - y >= 0 ? x - y : x - y + mod;
}
int main() {
	
	#ifndef evenbao
	freopen("sequence.in" , "r" , stdin);
	freopen("sequence.out" , "w" , stdout);
	#endif
	
	scanf("%d%d%d" , &N , &M , &K);
	for (int i = 1; i <= M + 1; ++i) {
		scanf("%d" , &val[i]); pw[i][0] = 1; 
		for (int j = 1; j <= N; ++j) pw[i][j] = 1ll * pw[i][j - 1] * val[i] % mod;
	}
	inv[0] = inv[1] = 1;
	for (int i = 2; i <= N; ++i) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	for (int i = 1; i <= N; ++i) inv[i] = 1ll * inv[i - 1] * inv[i] % mod;
	bits[0] = 0;  
	for (int i = 1; i < 32; ++i) bits[i] = bits[i >> 1] + (i & 1);
	dp[0][0][0][0] = 1;
	for (int i = 0; i <= M; ++i)
	for (int j = 0; j <= N; ++j)
	for (int k = 0; k <= K; ++k)
	for (int l = 0; l <= N; ++l) {
		if (!dp[i][j][k][l]) continue;
		for (int tak = 0; j + tak <= N; ++tak) {
			int new_i = i + 1 , new_j = j + tak , new_l = l + tak , new_k = k; 
			if (new_l & 1) ++new_k; new_l >>= 1;
			inc(dp[new_i][new_j][new_k][new_l] , 1ll * dp[i][j][k][l] * inv[tak] % mod * pw[new_i][tak] % mod);
		}
	}
	int ans = 0 , fac = 1;
	for (int i = 1; i <= N; ++i) fac = 1ll * fac * i % mod;
	for (int k = 0; k <= K; ++k) 
	for (int l = 0; l < 32; ++l) 
		if (k + bits[l] <= K) inc(ans , dp[M + 1][N][k][l] % mod);
	printf("%d\n" , 1ll * fac * ans % mod);
	return 0;
}
