#include<bits/stdc++.h>
#define VI vector<int>
#define pii pair<int, int>
#define SZ(x) ((int) x.size())
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
int n, a[10015], b[10015];
namespace sub1 {
	map<pii, int> dp[405][405];
	void solve() {
		dp[0][0][mp(0, 0)] = 0;
		rep(i, 0, n - 1) rep(j, 0, n - 1 - i - 1) {
			for(auto _ : dp[i][j]) {
				pii u = _.fi, nu = u;
				int c = b[i + j + 1], val = _.se, nval;
				#define calc(x) (val + 2 * (n - (x)) * u.fi * c + 2 * (x) * u.se * c + (x) * (n - (x)) * c * c)
				// i + 1
				nu.fi += (i + 1) * c;
				nval = calc(i + 1);
				if(dp[i + 1][j].count(nu) == 0 || dp[i + 1][j][nu] > nval) dp[i + 1][j][nu] = nval;
				// j + 1
				nu = u;
				nu.se += (j + 1) * c;
				nval = calc(n - j - 1);
				if(dp[i][j + 1].count(nu) == 0 || dp[i][j + 1][nu] > nval) dp[i][j + 1][nu] = nval;
				#undef calc(x)
			}
		}
		int ans = inf;
		rep(i, 0, n - 1) {
			for(auto _ : dp[i][n - i - 1]) {
				ans = min(ans, _.se);
			}
		}
		printf("%d\n", ans);
		exit(0);
	}

}
namespace sub2 { // 4 ^ sqrt(V) * n
	int A[10015], B[10015], ans = inf, L, R;
	void calc() {
		int res = 0, sum = 0;
		A[1] = a[1];
		rep(i, 2, n) A[i] = A[i - 1] + B[i];
		rep(i, 1, n) res += A[i] * A[i], sum += A[i];
		res = n * res - sum * sum;
		ans = min(ans, res);
	}
	vector<pii> vec;
	void dfs(int lvl) {
		if(lvl >= SZ(vec)) return calc();
		int oL = L, oR = R, val = vec[lvl].fi, len = vec[lvl].se;
		int l = max(0, len / 2 - 1), r = min(len, len / 2 + 2);
		rep(_, 1, l) B[L++] = val;
		rep(_, 1, len - l) B[R--] = val;
		rep(i, l, r) {
			dfs(lvl + 1);
			B[++R] = 0;
			B[L++] = val;
		}
		L = oL;
		R = oR;
	}
	void solve() {
		for(int l = 1, r; l <= n - 1; l = r + 1) {
			r = l;
			while(r < n - 1 && b[r + 1] == b[l]) r++;
			vec.pb(mp(b[l], r - l + 1));
		}
		L = 2;
		R = n;
		dfs(0);
		printf("%d\n", ans);
		exit(0);
	}
}
int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, n - 1) b[i] = a[i + 1] - a[i];
	sort(b + 1, b + n);
	reverse(b + 1, b + n);
	if(n <= 50) sub1::solve();
	else sub2::solve();
	return 0;
}
