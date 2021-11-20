#include <bits/stdc++.h>
#define N 150000
#define int long long
const int mod = 998244353;
using namespace std;
int n, m, k, v[35], dp[N][35], mi[20], ans;
int lowbit(int x){return x & -x; }
int count(int x){
	int ct = 0;
	while(x) x -= lowbit(x), ct++;
	return ct;
}
signed main(){
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k); 
	mi[0] = 1; for(int i = 1; i < 20; ++i) mi[i] = mi[i - 1] * 2;
	for(int i = 0; i <= m; ++i) scanf("%lld", &v[i]);
	dp[0][0] = 1;
	for(int i = 1; i <= n; ++i){
		for(int s = 0; s < min((long long)N, n * mi[m] + 1); ++s){
			for(int j = 0; j <= m; ++j){
				if(s < mi[j]) break;
				dp[s][i] = (dp[s][i] + dp[s - mi[j]][i - 1] * v[j]) % mod;
			}
		}
	}
	for(int s = 0; s < N; ++s) if(count(s) <= k) ans = (ans + dp[s][n]) % mod;
	printf("%lld", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
30 12 20
1 1 1 1 1 1 1 1 1 1 1 1 1
5 1 1
2 1
*/
