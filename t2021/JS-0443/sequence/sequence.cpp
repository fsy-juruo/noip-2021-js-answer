#include <bits/stdc++.h>
#define rep(i, a, b) for (int i(a); i <= b; ++i)
#define per(i, a, b) for (int i(a); i >= b; --i)
#define mem(a, b) memset(a, b, sizeof(a))
#define pqueue priority_queue
#define umap unordered_map
#define pb push_back
#define mp make_pair
#define int long long

using namespace std;
int n, m, kk, aa[105], ans, v[105], dp[105][35][105][35];
const int mod = 998244353;
int fac[105], inv[105], tmp[105];

template <typename _T>
void rd(_T &x) {
	int f = 1; x = 0;
	char s = getchar();
	while (s < '0' || s > '9') {if (s == '-') f = -1; s = getchar();}
	while (s >= '0' && s <= '9') x = (x<<1)+(x<<3)+(s^48), s = getchar();
	x *= f;
}
int qpow(int x, int b) {
	int ret = 1ll, base = x;
	while (b) {
		if (b&1) ret = ret*base%mod;
		base = base*base%mod;
		b >>= 1;
	}
	return ret;
}

inline int C(int n, int m) {
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}

void dfs(int step, int lst) {
	if (step > n) {
//		rep(i, 1, n) printf("%lld ", aa[i]); puts("");
		int s = 0;
		rep(i, 1, n) s += (1ll<<aa[i]);
		int tt = 0;
		tmp[++tt] = 1;
		rep(i, 2, n) if (aa[i] != aa[i-1]) tmp[++tt] = 1; else ++tmp[tt];
		int ss = 0;
		rep(i, 0, 55) if (s&(1ll<<i)) ++ss;
//		printf("%lld(%lld)\n", ss, s);
		if (ss <= kk) {
//			puts("haha");
			int sss = 1ll;
			rep(i, 1, n) sss = sss*v[aa[i]]%mod;
			int ssss = 1ll;
			int ttt = n;
			rep(i, 1, tt-1) {
				ssss = ssss*C(ttt, tmp[i]);
//				printf("%lld %lld\n", ttt, tmp[i]);
				ttt -= tmp[i];
			}
//			printf("%lld %lld\n", sss, ssss);
			ans = (ans+sss*ssss%mod)%mod;
		}
		return ;
	}
	rep(i, lst, m) {
		aa[step] = i;
		dfs(step+1, i);
	}
	return ;
}

void slv1() {
	dfs(1, 0);
	printf("%lld", ans);
	return ;
}

void slv2() { // f
	rep(i, 0, n) {
		rep(j, 0, i) {
			dp[0][i][j][1] = v[0]*i%mod;
		} 
	}
	rep(i, 1, m) {
		rep(j, 1, n) {
			rep(k, 0, j) {
				rep(p, 0, n) {//qian i, xuanle j, dangqiancaozuo k, you p
					int s = 0;
					rep(l, 0, n) { //i-1 caozuo
						int t = k;
						if (l%4 >= 2) --t;
						t = j-t;
						if (t > j || t < 0) continue;
						s += dp[i-1][t][l][p-(k&1)], s %= mod;
					}
					s = s*v[i]%mod*k%mod;
					dp[i][j][k][p] = s;
				}
			}
		}
	}
//	rep(i, 0, 3) rep(j, 0, kk) {
//		printf("%lld\n", dp[1][5][i][])
//	}
	int ans = 0;
	rep(i, 0, kk) {
		rep(j, 0, n) ans = (ans+dp[m][n][j][i])%mod;
//		printf("%lld\n", ans);
	}
	printf("%lld", ans);
	return ;
}


signed main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	rd(n), rd(m), rd(kk);
	fac[0] = inv[0] = 1ll;
	rep(i, 1, n) fac[i] = fac[i-1]*i%mod, inv[i] = qpow(fac[i], mod-2);
//	printf("%lld\n", C(5, 2));
	rep(i, 0, m) rd(v[i]);
	if (n <= 8) {
		slv1();
		return 0;
	}
	slv2();
	return 0;
}

