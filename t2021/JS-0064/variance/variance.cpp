/*
	Simulate Anneling?!!!!!!
	the worst problem ever
	fuck your mom , problemsetter.
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MN = 455;
const LL INF = 1e16;
const double eps = 1e-10;

int N , A[MN] , B[MN] , M , bits[1 << 15] , mx;
LL dp[1 << 15][405] , sum[1 << 15];

inline void chkmin(LL &x , LL y) {
	x = min(x , y);
}

namespace DP {
	inline void solve()	{
		for (int s = 0; s < (1 << M); ++s)
		for (int i = 0; i <= mx * N; ++i)
			dp[s][i] = INF;
		for (int s = 0; s < (1 << M); ++s)
		for (int i = 0; i < M; ++i) 
			if (s >> i & 1) {
				sum[s] += (LL) B[i];
				++bits[s];
			}
		dp[0][A[1] * N] = A[1] * A[1];
		for (int s = 0; s < (1 << M); ++s)
		for (int i = 0; i <= mx * N; ++i) 
		for (int j = 0; j < M; ++j) {
			if (s >> j & 1) continue; if (dp[s][i] == INF) continue;
			chkmin(dp[s | (1 << j)][i + B[j] * (M - bits[s])] , 1LL * dp[s][i] + 1LL * (A[1] + sum[s | (1 << j)]) * (A[1] + sum[s | (1 << j)]));
		} 
		LL ans = INF;
		for (int i = 0; i <= mx * N; ++i) 
			chkmin(ans , 1LL * N * dp[(1 << M) - 1][i] - 1LL * i * i);
		printf("%lld\n" , ans);
	}
} ;

inline LL calc() {
	LL pw = 1LL * A[1] * A[1] , sm = A[1] , now = A[1];
	for (int i = 0; i < M; ++i) {
		now += B[i];
		pw += 1LL * now * now;
		sm += now;
	}
	return 1LL * N * pw - 1LL * sm * sm;
}

int main() {
	
	#ifndef evenbao
	freopen("variance.in" , "r" , stdin);
	freopen("variance.out" , "w" , stdout);
	#endif
	
	scanf("%d" , &N);
	for (int i = 1; i <= N; ++i) scanf("%d" , &A[i]) , mx = max(mx , A[i]);
	for (int i = 2; i <= N; ++i) B[M++] = A[i] - A[i - 1];
	if (N <= 15 && N * mx <= 400) {
		DP :: solve();
		return 0;
	}
	sort(B + 1 , B + M);
	double cur = INT_MAX; srand(time(0)); LL res = calc();
	while (cur > eps) {
		int x = rand() % M , y = rand() % M;
		LL now_val = calc();
		swap(B[x] , B[y]);
		LL new_val = calc(); chkmin(res , new_val);
		if (now_val < new_val || (exp((now_val - new_val) / INT_MAX) > cur)) {
			cur *= 0.99998; 
			continue;
		} else swap(B[x] , B[y]);
		cur *= 0.99998; 
	}
	printf("%lld\n" , res);
	return 0; 
}
