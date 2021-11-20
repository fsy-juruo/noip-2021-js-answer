#include<bits/stdc++.h>
#define VI vector<int>
#define pii pair<int, int>
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define per(i, a, b) for(int i = (b); i >= (a); --i)
#define fi first
#define se second
#define pb push_back
#define N
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define ll long long
using namespace std;
const int mod = 998244353;
int n, m, K, v[125], dp[125][35][35][20], C[35][35], pd[125][35];
void inc(int &x, int y) {
	x += y;
	if(x >= mod) x -= mod;
}
int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &K);
	rep(i, 1, m + 1) {
		scanf("%d", &v[i]);
		pd[i][0] = 1;
		rep(j, 1, n) pd[i][j] = (ll) pd[i][j - 1] * v[i] % mod;
	}
	rep(i, m + 2, m + 6) pd[i][0] = 1;
	rep(i, 0, n) {
		C[i][0] = 1;
		rep(j, 1, i) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
	}
	dp[0][0][0][0] = 1;
	rep(i, 0, m + 5) rep(j, 0, n) rep(k, 0, n) rep(l, 0, n / 2) {
		if(dp[i][j][k][l] == 0) continue;
//		printf("%d %d %d %d: %d\n", i, j, k, l, dp[i][j][k][l]);
		int rb = i <= m ? n - j : 0;
		rep(a, 0, rb) {
			inc(dp[i + 1][j + a][k + ((l + a) % 2)][(l + a) / 2], (ll) dp[i][j][k][l] * pd[i + 1][a] % mod * C[j + a][a] % mod);
		}
	}
	int ans = 0;
	rep(k, 0, K) inc(ans, dp[m + 6][n][k][0]);
	printf("%d", ans);
	return 0;
}

